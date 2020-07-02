#include "cspkernel.h"

CSpKernel::CSpKernel(QWidget *parent):QLabel(parent)
{

}

void CSpKernel::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event);
    QPainter p(this);

    //    QRect windowRect=p.window();
    //    int height=windowRect.height();
    //    p.translate(0,height);//向下平移等于label宽度的距离
    QPen pen;
    CSpShp thisShp=CSpKernel::shp;
    if(thisShp.loadStatus)
    {
        thisShp.knldCal(p.window().width(),p.window().height());//求出核密度
        float kdnlMax=thisShp.findMaxKnld(p.window().width(),p.window().height());
        for(int i=0;i<p.window().width();i++)//根据核密度赋值
            for(int j=0;j<p.window().height();j++)
            {
                pen.setColor(QColor((1-thisShp.knlds[i][j]/kdnlMax)*255,(1-thisShp.knlds[i][j]/kdnlMax)*255,(1-thisShp.knlds[i][j]/kdnlMax)*255));
                p.setPen(pen);
                p.drawPoint(i,j);
            }
        //换成红笔
        QBrush brush;
        pen.setColor(Qt::red);
        p.setPen(pen);
        for(int i=0;i<thisShp.pointCount;i++)//画点
        {
            //其实并没有画点，为了现眼画的是圆
            brush.setColor(Qt::red);
            brush.setStyle(Qt::SolidPattern);
            p.setBrush(brush);
            p.drawEllipse(thisShp.xchange(shp.shpPoints[i].fX),thisShp.ychange(shp.shpPoints[i].fY),3,3);
        }
    }
}


//float CSpKernel::xBackChange(float ordinalx)
//{
//    float resultX=float((ordinalx-100)/150000)+minX;
//    return resultX;
//}

//float CSpKernel::yBackChange(float ordinaly)
//{
//    float resultY=float(-(ordinaly-labelHeight+70)/150000)+minY;
//    return resultY;
//}
