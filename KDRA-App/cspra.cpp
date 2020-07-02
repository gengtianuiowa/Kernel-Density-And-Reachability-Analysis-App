#include "cspra.h"

CSpRA::CSpRA(QWidget *parent):QLabel(parent)
{

}

void CSpRA::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event);
    QPainter p(this);
    QPen pen;QBrush brush;
    CSpShp* thisShp=CSpRA::shp;

    //0是小区，1是公园
    //绘制绿地与小区的连线
    if(thisShp[0].loadStatus&&thisShp[1].loadStatus)
    {
        //注意！为了使两个图层在同一个尺度下显示，必须采用同样的标准（范围）！
        CSpPoint** showPoints=this->TwoShpsShowChange(this->width(),this->height(),thisShp[0],thisShp[1]);
        if(CSpRA::drawLineStatus)
        {
            CSpAnlzTools tool;
            pen.setColor(Qt::black);
            p.setPen(pen);
            for(int i=0;i<thisShp[1].pointCount;i++)
            {
                CSpField serveRadius=thisShp[1].getField("ServeRa");
                CSpField greenSize=thisShp[1].getField("Shape_Area");
                if(greenSize.typeName!=NULL)
                {
                    for(int j=0;j<thisShp[0].pointCount;j++)
                    {
                        if(serveRadius.typeName!=NULL)
                        {
                            //                            int ra=serveRadius.intData[i];
                            //                            float fX1=thisShp[1].shpPoints[i].fX;
                            //                            float fY1=thisShp[1].shpPoints[i].fY;
                            //                            float fX2=thisShp[0].shpPoints[j].fX;
                            //                            float fY2=thisShp[0].shpPoints[j].fY;
                            //                            float cal=tool.disCal(thisShp[1].shpPoints[i],thisShp[0].shpPoints[j]);
                            if(tool.disCal(thisShp[1].shpPoints[i],thisShp[0].shpPoints[j])<=serveRadius.intData[i])
                            {
                                p.drawLine(showPoints[1][i].fX,showPoints[1][i].fY,showPoints[0][j].fX,showPoints[0][j].fY);
                            }
                        }
                        else
                        {
                            printf("未正确获取服务半径字段");
                            break;
                        }
                    }
                }else
                {
                    printf("未正确获取绿地面积字段");
                    break;
                }
            }
        }

        thisShp[0].showChange(this->width(),this->height());
        thisShp[1].showChange(this->width(),this->height());

        //画公园门数据的样式
        pen.setColor(Qt::blue);
        brush.setColor(Qt::blue);
        brush.setStyle(Qt::SolidPattern);
        p.setBrush(brush);
        p.setPen(pen);
        for(int i=0;i<thisShp[1].pointCount;i++)//画点
        {
            //其实并没有画点，为了显眼画的是圆
            //printf("%f,%f\n",showPoints[i].fX,showPoints[i].fX);
            p.drawEllipse(showPoints[1][i].fX,showPoints[1][i].fY,4,4);
        }

        //先创建工具
        RATool RACalTool(thisShp[0],thisShp[1]);
        if(RACalTool.RAAnalyze())//做服务区分析
        {
            //开始画小区
            //设置颜色
            double max=-1,min=9999999999;
            for(int i=0;i<thisShp[0].pointCount;i++)
            {
                if(RACalTool.RA[i]>max)
                    max=RACalTool.RA[i];
                if(RACalTool.RA[i]<min)
                    min=RACalTool.RA[i];
            }
            for(int i=0;i<thisShp[0].pointCount;i++)
            {
                //其实并没有画点，为了显眼画的是圆
//                pen.setColor(QColor(255*(RACalTool.RA[i]/max),255*(1-RACalTool.RA[i]/max),0));
//                brush.setColor(QColor(255*(RACalTool.RA[i]/max),255*(1-RACalTool.RA[i]/max),0));
                QColor colorSet=this->quantileColorSet(RACalTool.RA[i],8,max,min);
                pen.setColor(colorSet);
                brush.setColor(colorSet);
                brush.setStyle(Qt::SolidPattern);
                p.setBrush(brush);
                p.setPen(pen);
                p.drawEllipse(showPoints[0][i].fX,showPoints[0][i].fY,3,3);
            }
        }
    }
}

CSpPoint** CSpRA::TwoShpsShowChange(int width, int height, CSpShp lastShp,CSpShp inputShp)
{
    float widthf=(float) width;
    float heightf=(float) height;
    //求商 然后缩放所有点
    float maxX,maxY,minX,minY;
    if(lastShp.maxX>inputShp.maxX)
        maxX=lastShp.maxX;
    else
        maxX=inputShp.maxX;
    if(lastShp.maxY>inputShp.maxY)
        maxY=lastShp.maxY;
    else
        maxY=inputShp.maxY;
    if(lastShp.minX<inputShp.minX)
        minX=lastShp.minX;
    else
        minX=inputShp.minX;
    if(lastShp.minY<inputShp.minY)
        minY=lastShp.minY;
    else
        minY=inputShp.minY;

    float xStrink=(maxX-minX)/(widthf-40);
    float yStrink=(maxY-minY)/(heightf-40);

    CSpPoint** resultP=new CSpPoint*[2];
    resultP[0]=new CSpPoint[lastShp.pointCount];
    for(int i=0;i<lastShp.pointCount;i++)
    {
        //实际和显示距离的比
        resultP[0][i].fX=(lastShp.shpPoints[i].fX-minX)/xStrink;
        //要用高度减，否则生成的是倒的图像,根据最大长/宽比窗口长/宽生成的，想清楚比例关系
        resultP[0][i].fY=height-5-(lastShp.shpPoints[i].fY-minY)/yStrink;//再向上平移一点，避免最低点压盖
    }

    resultP[1]=new CSpPoint[inputShp.pointCount];
    for(int i=0;i<inputShp.pointCount;i++)
    {
        //实际和显示距离的比
        resultP[1][i].fX=(inputShp.shpPoints[i].fX-minX)/xStrink;
        //要用高度减，否则生成的是倒的图像,根据最大长/宽比窗口长/宽生成的，想清楚比例关系
        resultP[1][i].fY=height-5-(inputShp.shpPoints[i].fY-minY)/yStrink;//再向上平移一点，避免最低点压盖
    }
    return resultP;
}

QColor CSpRA::quantileColorSet(double data,int quantileCount,double max,double min)
{

    double quantileBreak=(max-min)/((double)quantileCount);
    double cut=1/(double)quantileCount;
    for(int i=0;i<quantileCount;i++)
    {
        if(min+i*quantileBreak<=data&&data<=min+(i+1)*quantileBreak)
            return QColor(255*(cut*(i+1)),255*(1-cut*(i+1)),0);
    }
}
