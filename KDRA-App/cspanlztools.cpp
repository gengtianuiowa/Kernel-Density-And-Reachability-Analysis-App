#include "cspanlztools.h"

CSpAnlzTools::CSpAnlzTools()
{

}
RATool::RATool(CSpShp inputShp1, CSpShp inputShp2)
{
    this->workShps=new CSpShp[2];
    this->workShps[0]=inputShp1;
    this->workShps[1]=inputShp2;
}

float CSpAnlzTools::disCal(CSpPoint p1, CSpPoint p2)
{
    return sqrt(pow(p1.fX-p2.fX,2)+pow(p1.fY-p2.fY,2));
}



bool RATool::RAAnalyze()
{
    if(!workShps[0].loadStatus||!workShps[1].loadStatus)
        return false;
    else
    {
        this->RA=new double[workShps[0].pointCount];
        for(int i=0;i<workShps[0].pointCount;i++)
        {
            this->RA[i]=0;
        }
        this->CCPNCal();
        for(int i=0;i<workShps[0].pointCount;i++)
        {
            for(int j=0;j<workShps[1].pointCount;j++)
            {
                CSpField serveRadius=workShps[1].getField("ServeRa");
                //距离小于等于500，则所有的公园都要算入
                if(this->disCal(workShps[0].shpPoints[i],workShps[1].shpPoints[j])<=500)
                {
                    //对于每一个公园店，需要在CCPN中加上供需比乘上两步移动搜索法的值
                    double TSFCAMCoefficient_500=(double)this->TSFCAMCoefficientCal(serveRadius.intData[j],500);
                    this->RA[i]+=this->CCPN[j]*TSFCAMCoefficient_500;
                    //cout<<TSFCAMCoefficient_500<<endl;
                }
                if(this->disCal(workShps[0].shpPoints[i],workShps[1].shpPoints[j])>500&&this->disCal(workShps[0].shpPoints[i],workShps[1].shpPoints[j])<=1000&&serveRadius.intData[j]>500)
                {
                    //对于每一个公园店，需要在CCPN中加上供需比乘上两步移动搜索法的值
                    double TSFCAMCoefficient_1000=(double)this->TSFCAMCoefficientCal(serveRadius.intData[j],1000);
                    this->RA[i]+=this->CCPN[j]*TSFCAMCoefficient_1000;
                    //cout<<TSFCAMCoefficient_1000<<endl;
                }
                if(this->disCal(workShps[0].shpPoints[i],workShps[1].shpPoints[j])>1000&&this->disCal(workShps[0].shpPoints[i],workShps[1].shpPoints[j])<=2000&&serveRadius.intData[j]>1000)
                {
                    //对于每一个公园店，需要在CCPN中加上供需比乘上两步移动搜索法的值
                    double TSFCAMCoefficient_2000=(double)this->TSFCAMCoefficientCal(serveRadius.intData[j],2000);
                    this->RA[i]+=this->CCPN[j]*TSFCAMCoefficient_2000;
                    //cout<<TSFCAMCoefficient_2000<<endl;
                }
                if(this->disCal(workShps[0].shpPoints[i],workShps[1].shpPoints[j])>2000&&this->disCal(workShps[0].shpPoints[i],workShps[1].shpPoints[j])<=5000&&serveRadius.intData[j]>2000)
                {
                    //对于每一个公园店，需要在CCPN中加上供需比乘上两步移动搜索法的值
                    double TSFCAMCoefficient_5000=(double)this->TSFCAMCoefficientCal(serveRadius.intData[j],5000);
                    this->RA[i]+=this->CCPN[j]*TSFCAMCoefficient_5000;
                   //cout<<TSFCAMCoefficient_5000<<endl;
                }
            }
            //cout<<this->RA[i]<<endl;
        }
        return true;
    }
}

float *RATool::CCPNCal()
{
    if(!this->workShps[0].loadStatus||!this->workShps[1].loadStatus)
    {
        printf("未正确导入CCPN的工作shp");
        return NULL;
    }
    else
    {
        //1是公园，0是小区
       this->CCPN=new float[this->workShps[1].pointCount];
       for(int i=0;i<this->workShps[1].pointCount;i++)
       {
           CSpField serveRadius=this->workShps[1].getField("ServeRa");
           CSpField greenSize=this->workShps[1].getField("Shape_Area");
           if(greenSize.typeName!=NULL)
           {
               double peopleCount=0;
               for(int j=0;j<this->workShps[0].pointCount;j++)
               {
                   if(serveRadius.typeName!=NULL)
                   {
                       if(this->disCal(this->workShps[1].shpPoints[i],this->workShps[0].shpPoints[j])<=serveRadius.intData[i])
                       {
                           CSpField people=this->workShps[0].getField("people");
                           peopleCount+=people.doubleData[j];
                       }
                   }
                   else
                   {
                       printf("未正确获取服务半径字段");
                       return NULL;
                   }
               }
               this->CCPN[i]=peopleCount/greenSize.doubleData[i];
               //cout<<"CCPN:"<<this->CCPN[i]<<endl;
           }else
           {
               printf("未正确获取绿地面积字段");
               return NULL;
           }
       }
       return this->CCPN;
    }
}

double RATool::TSFCAMCoefficientCal(int searchRadius, int coefficient)
{
    double srf=(double)searchRadius,cff=(double)coefficient;
    return exp((-0.5)*(cff/srf)*(cff/srf))/(1-exp(-0.5));
}
