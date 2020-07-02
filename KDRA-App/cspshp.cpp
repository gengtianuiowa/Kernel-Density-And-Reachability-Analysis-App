#include "cspshp.h"

CSpShp::CSpShp()
{

}

bool CSpShp::LoadShp()
{
    //读文件代码（来自百度）
    GDALAllRegister();

    GDALDataset *poDS;
    //poDS = (GDALDataset*)GDALOpenEx(@"E:\Documents\TIAN\personal materials\2018 SPRING\GIS Software Development\pointtest.shp", GDAL_OF_VECTOR, NULL, NULL, NULL);
    poDS = (GDALDataset*)GDALOpenEx(this->shpPath, GDAL_OF_VECTOR, NULL, NULL, NULL);

    if (poDS == NULL)
    {
        printf("Open failed.\n");
        exit(1);
    }
    OGRLayer  *poLayer;
    poLayer = poDS->GetLayerByName(this->layerName);

    OGRFeature *poFeature;
    poLayer->ResetReading();
    int fCount=poLayer->GetFeatureCount();
    this->shpPoints=new CSpPoint[fCount];
    this->pointCount=fCount;
    int pointI=0;
    OGRFeatureDefn *poFDefn = poLayer->GetLayerDefn();
    int iField;
    int i = poFDefn->GetFieldCount();
    this->fields=new CSpField[i];
    this->fieldCount=poFDefn->GetFieldCount();

    int featureI=0;
    if(fCount==0)
        return false;
    else{
        //获取字段名
        for (int i=0; i < poFDefn->GetFieldCount(); i++)
        {
            this->fields[i].fieldName=poFDefn->GetFieldDefn(i)->GetNameRef();
            this->fields[i].typeName=poFDefn->GetFieldDefn(i)->GetFieldTypeName(poFDefn->GetFieldDefn(i)->GetType());
            printf("%s:",this->fields[i].fieldName);
            printf("%s，",this->fields[i].typeName);
        }
        printf("\n");
        while ((poFeature = poLayer->GetNextFeature()) != NULL)
        {
            //新建字段，将数据全部存储至内存中。
            //获得字段的数目，本实例返回5，不包括前两个字段（FID,Shape），这两个字段在arcgis里也不能被修改;
            for (iField = 0; iField < poFDefn->GetFieldCount(); iField++)
            {
                OGRFieldDefn *poFieldDefn = poFDefn->GetFieldDefn(iField);
                //根据字段值得类型，选择对应的输出
                //int t=poFDefn->GetFieldIndex("people");
                //得到字段名
              if (poFieldDefn->GetType() == OFTInteger)
              {
                  if(this->fields[iField].intData==NULL)
                      this->fields[iField].intData=new int[poLayer->GetFeatureCount()];
                  this->fields[iField].intData[featureI]=poFeature->GetFieldAsInteger(iField);
                  printf("%d,", poFeature->GetFieldAsInteger(iField));
              }
              else if (poFieldDefn->GetType() == OFTReal)
              {
                  if(this->fields[iField].doubleData==NULL)
                      this->fields[iField].doubleData=new double[poLayer->GetFeatureCount()];
                  this->fields[iField].doubleData[featureI]=  poFeature->GetFieldAsDouble(iField);
                  printf("%.3f,", poFeature->GetFieldAsDouble(iField));
              }
              else if (poFieldDefn->GetType() == OFTString)
              {
                  //注意string数组的创建
                  if(this->fields[iField].stringData==NULL)
                      this->fields[iField].stringData=new const char* [poLayer->GetFeatureCount()];
                  this->fields[iField].stringData[featureI]=  poFeature->GetFieldAsString(iField);
                  printf("%s,", poFeature->GetFieldAsString(iField));
              }
              else
              {
                  if(this->fields[iField].stringData==NULL)
                      this->fields[iField].stringData=new const char* [poLayer->GetFeatureCount()];
                  this->fields[iField].stringData[featureI]=  poFeature->GetFieldAsString(iField);
                  printf("%s,", poFeature->GetFieldAsString(iField));
              }
            }

            OGRGeometry *poGeometry;
            poGeometry = poFeature->GetGeometryRef();
            if (poGeometry != NULL)
            {
                OGRwkbGeometryType pGeoType = poGeometry->getGeometryType();
                if (pGeoType == wkbPoint)
                {
                    OGRPoint *poPoint = (OGRPoint *)poGeometry;
                    this->shpPoints[pointI].fX=poPoint->getX();
                    this->shpPoints[pointI].fY=poPoint->getY();
                    printf("坐标为：");
                    printf("%.3f,%.3f\n",this->shpPoints[pointI].fX, this->shpPoints[pointI].fY);
                    pointI++;
                }
                else if (pGeoType == wkbPolygon)
                {
                    //OGRPolygon *pPolygon = (OGRPolygon*)poGeometry->clone();
                    //OGRLinearRing * poLR = pPolygon->getExteriorRing();
                    //int Num = poLR->getNumPoints()
                    return false;
                }
                else if (pGeoType == wkbMultiPolygon)  //这里就是带空洞多边形判断
                {
//                    OGRMultiPolygon *pMulPolygon = (OGRMultiPolygon*)poGeometry;
//                    OGRPolygon *pPolygon = NULL;
//                    for (int i = 0; i < pMulPolygon->getNumGeometries(); i++)
//                    {
//                        pPolygon = (OGRPolygon*)pMulPolygon->getGeometryRef(i);
//                    }
                    return false;
                }
                else
                {
                    printf("no point geometry\n");
                }
            }
            OGRFeature::DestroyFeature(poFeature);
            featureI++;
        }
        //system("pause");
        return true;
    }
}

bool CSpShp::SDCal()
{
    float pointCount=(float) this->pointCount;
    if(pointCount==0)
        return false;
    else
    {
        float xSum=0,ySum=0;
        for(int i=0;i<pointCount;i++)
        {
            xSum+=this->shpPoints[i].fX;
            ySum+=this->shpPoints[i].fY;
        }
        this->avgCenter.fX=xSum/pointCount;
        this->avgCenter.fY=ySum/pointCount;
        float xsSum=0,ysSum=0;
        for(int i=0;i<pointCount;i++)
        {
            xsSum+=pow(this->shpPoints[i].fX-this->avgCenter.fX,2);
            ysSum+=pow(this->shpPoints[i].fY-this->avgCenter.fY,2);
        }
        this->SD=sqrt(xsSum/pointCount+ysSum/pointCount);
        return true;
    }
}

bool CSpShp::DmCal()
{
    if(pointCount==0||!toCenterDisCal())
        return false;
    else
    {
        //为了计算距离的中位数，先给距离排序
        for(int i=0;i<this->pointCount;i++)
        {
            for(int j=0;j<this->pointCount-i;j++)
            {
                if(this->disToCenter[j]>this->disToCenter[j+1])
                {
                    float temp;
                    temp=this->disToCenter[j];
                    this->disToCenter[j]=this->disToCenter[j+1];
                    this->disToCenter[j+1]=temp;
                }
            }
        }
        if(this->pointCount%2==0)//若个数是偶数
        {
            float i=2;int p=this->pointCount/2;
            //中位数为中间两个数除以2
            this->Dm=(this->disToCenter[p]+this->disToCenter[p-1])/i;
            return true;
        }
        else//若个数是奇数
        {
            int p=this->pointCount/2;
            this->Dm=(float)this->disToCenter[p];
            return true;
        }
    }
}

bool CSpShp::toCenterDisCal()
{
    if(this->avgCenter.fX==0||this->avgCenter.fX==0||pointCount==0)
        return false;
    else
    {
        this->disToCenter=new float[pointCount];
        for(int i=0;i<pointCount;i++)
        {
            this->disToCenter[i]=disCal(this->avgCenter,shpPoints[i]);
        }
        return true;
    }
}

bool CSpShp::knldCal(int width, int height)
{
    if(!this->SRCal())
        return false;
    else
    {
        //为每个像素计算核密度（先初始化二维数组）
        this->knlds=new float*[width];
        for(int i=0;i<width;i++)
        {
            this->knlds[i]=new float[height];
            for(int j=0;j<height;j++)
            {
                knlds[i][j]=0;
                for(int k=0;k<this->pointCount;k++)//sum(K)
                {
                    CSpPoint tempP;
                    tempP.fX=i;tempP.fY=j;
                    float relativeDis=this->disWithWindowCal(tempP,this->shpPoints[k])/this->SearchRadius;//(x-X)/h
                    if(relativeDis<1)
                    {
                        this->knlds[i][j]+=3*pow(1-pow(relativeDis,2),2)/PAI;//K2(x)
//                        cout <<this->knlds[i][j]<<endl;
                    }
                }
                //其实没有除nd^2,因为除后结果过小。不除不影响结果。可以除后再标准化，结果一样
                //this->knlds[i][j]/=this->pointCount*pow(this->SearchRadius,2); //1/nd^2
//                if(this->knlds[i][j]==0)
//                cout<<"第"<<i<<","<<j<<"个像素的核密度为："<<this->knlds[i][j]<<endl;
            }
        }
        return true;
    }
}

float CSpShp::findMaxKnld(int width,int height)
{
    if(this->knlds!=NULL)
    {
        float max=0;
        for(int i=0;i<width;i++)
            for(int j=0;j<height;j++)
            {
                if(this->knlds[i][j]>max)
                    max=this->knlds[i][j];
            }
        return max;
    }else
        return -1;
}

bool CSpShp::SRCal()
{
    if(this->SDCal()&&this->DmCal())//计算标准距离和距离中位数成功
    {
        float min;
        if(this->SD>this->Dm*sqrt(1/log(2)))
            min=Dm*sqrt(1/log(2));
        else
            min=SD;
        this->SearchRadius=0.9*min*pow(this->pointCount,-0.2);
        return true;
    }else
        return false;
}

float CSpShp::disCal(CSpPoint p1, CSpPoint p2)
{
    return sqrt(pow(p1.fX-p2.fX,2)+pow(p1.fY-p2.fY,2));
}

float CSpShp::disWithWindowCal(CSpPoint p1, CSpPoint p2)
{
    return sqrt(pow(p1.fX-xchange(p2.fX),2)+pow(p1.fY-ychange(p2.fY),2));
}

float CSpShp::xchange(float ordinalx)
{
    return (ordinalx+300);
}

float CSpShp::ychange(float ordinaly)
{
    return (ordinaly+200);
}

CSpPoint *CSpShp::showChange(int width,int height)
{
    if(!this->loadStatus)
        return NULL;
    else{
        //求点阵范围
        float maxX=0;float maxY=0;float minX=99999999999;float minY=99999999999;
        for(int i=0;i<this->pointCount;i++)
        {
            if(this->shpPoints[i].fX>maxX)
                maxX=this->shpPoints[i].fX;
            if(this->shpPoints[i].fX<minX)
                minX=this->shpPoints[i].fX;
            if(this->shpPoints[i].fY>maxY)
                maxY=this->shpPoints[i].fY;
            if(this->shpPoints[i].fY<minY)
                minY=this->shpPoints[i].fY;
        }
        this->maxX=maxX;this->maxY=maxY;this->minX=minX;this->minY=minY;
        float widthf=(float) width;
        float heightf=(float) height;
        //求商 然后缩放所有点
        float xStrink=(maxX-minX)/(widthf-40);
        float yStrink=(maxY-minY)/(heightf-40);
        CSpPoint* resultP=new CSpPoint[pointCount];
        for(int i=0;i<pointCount;i++)
        {
            //实际和显示距离的比
            resultP[i].fX=(this->shpPoints[i].fX-minX)/xStrink;
            //要用高度减，否则生成的是倒的图像,根据最大长/宽比窗口长/宽生成的，想清楚比例关系
            resultP[i].fY=height-5-(this->shpPoints[i].fY-minY)/yStrink;//再向上平移一点，避免最低点压盖
        }
        return resultP;
    }
}


CSpField CSpShp::getField(const char *fieldName)
{
    if(this->fieldCount!=0)
    {
        string s1=fieldName;
        for(int i=0;i<this->fieldCount;i++)
        {
            string s2=this->fields[i].fieldName;
            if(s1==s2)
                return this->fields[i];
        }
    }
    CSpField noField;
    printf("未能正确获取字段%s",fieldName);
    return noField;
}

