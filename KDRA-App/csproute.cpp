#include "csproute.h"
CSpRoute::CSpRoute(QWidget *parent):QLabel(parent)
{
    setStartPoint=false;
    setEndPoint=false;
    routePaint=false;
}

void CSpRoute::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event);
    QPainter p(this);
//    p.rotate(30);//转180度
//    p.scale(-1,1);
//    p.setWindow(-50,-50, 100,100);

    CSpFile myfile=CSpRoute::drawdata;
    QRect windowRect=p.window();
    this->labelWidth=p.window().width();
    this->labelHeight=p.window().height();
    int height=windowRect.height();
    p.translate(0,height);//向下平移等于label宽度的距离

    QPen pen;
    pen.setWidth(3);
    pen.setCapStyle(Qt::RoundCap);
    p.setPen(pen);
    for(int i=0;i<myfile.e00File.arcsCount;i++)//画弧
        for(int j=0;j<myfile.e00File.arcs[i].pointCount-1;j++)
        {
            float x1=xchange(myfile.e00File.arcs[i].arcPoint[j].fX);
            float y1=ychange(myfile.e00File.arcs[i].arcPoint[j].fY);
            float x2=xchange(myfile.e00File.arcs[i].arcPoint[j+1].fX);
            float y2=ychange(myfile.e00File.arcs[i].arcPoint[j+1].fY);
            if(j==0)
            {
                QString temp = QString::number(myfile.e00File.arcs[i].fromId, 10);
                p.drawText(QPoint(x1+5,y1+3),temp);
            }
            if(j==myfile.e00File.arcs[i].pointCount-2)
            {
                QString temp = QString::number(myfile.e00File.arcs[i].toId, 10);
                p.drawText(QPoint(x2+5,y2+3),temp);
            }
            p.drawLine(x1,y1,x2,y2);
        }
    if(routePaint)//规划好路径后，绘制路径
    {
        QPen pen;
        pen.setWidth(4);
        pen.setCapStyle(Qt::RoundCap);
        pen.setColor(Qt::red);
        p.setPen(pen);
        int* passPoints=myfile.e00File.passPoints;
        int routePointCount=this->drawdata.e00File.passPointCount+2;//算经过点数量
        int* route=new int[routePointCount];//生成经过的端点的点集
        for(int i=0;i<routePointCount;i++)
        {
            if(i==0)
                route[i]=originId;
            if(i==routePointCount-1)
                route[i]=destinationId;
            if(i>0&&i<routePointCount-1)
                route[i]=passPoints[i-1];
        }
//        for(int i=0;i<routePointCount;i++)
//        {
//            cout<<route[i];
//        }
        for(int i=0;i<myfile.e00File.arcsCount;i++)
        {
            for(int j=0;j<routePointCount-1;j++)
            {
                int fromId=myfile.e00File.arcs[i].fromId;int toId=myfile.e00File.arcs[i].toId;
                if((fromId==route[j]&&toId==route[j+1])|| (toId==route[j]&&fromId==route[j+1]))
                {
                    for(int j=0;j<myfile.e00File.arcs[i].pointCount-1;j++)
                    {
                        float x1=xchange(myfile.e00File.arcs[i].arcPoint[j].fX);
                        float y1=ychange(myfile.e00File.arcs[i].arcPoint[j].fY);
                        float x2=xchange(myfile.e00File.arcs[i].arcPoint[j+1].fX);
                        float y2=ychange(myfile.e00File.arcs[i].arcPoint[j+1].fY);
                        p.drawLine(x1,y1,x2,y2);
                    }
                }
            }
        }
        routePaint=false;
    }
}

void CSpRoute::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        QString cursorAppend;
        QPoint cursorPoint;//记录鼠标坐标
        QString labelX;
        QString labelY;
        QString dataX;
        QString dataY;
        QString id;
        cursorPoint = QCursor::pos();//获取当前光标的位置
        QPoint cursorpos(cursorPoint.x(),cursorPoint.y());//注意这个转换！将全局坐标转换为相对于label 的坐标
        QPoint poschange=QLabel::mapFromGlobal(cursorpos);
        float cursorx=xBackChange(poschange.x());//实现坐标逆变换，换算为在数据中的坐标
        float cursory=yBackChange(poschange.y());
        if(drawdata.e00State)
        {
            if(!setStartPoint)
            {
                if(findPointId(cursorx,cursory))
                {
                    cursorAppend.append(QStringLiteral("当前坐标为："));
                    cursorAppend.append(" X ");
                    labelX.setNum(poschange.x());
                    cursorAppend.append(labelX);
                    cursorAppend.append(" Y ");
                    labelX.setNum(poschange.y());
                    cursorAppend.append(labelX);
                    cursorAppend.append(QStringLiteral("检索坐标为："));
                    cursorAppend.append(" X ");
                    dataX.setNum(cursorx);
                    cursorAppend.append(dataX);
                    cursorAppend.append(" Y ");
                    dataY.setNum(cursory);
                    cursorAppend.append(dataY);
                    cursorAppend.append(QStringLiteral("\n设置起点成功，此点ID为："));
                    originId=findPointId(cursorx,cursory);
                    id.setNum(originId);
                    cursorAppend.append(id);
                    setStartPoint=true;
                }
            }
            else
            {
                if(!setEndPoint)
                {
                    if(findPointId(cursorx,cursory))
                    {
                        cursorAppend.append(QStringLiteral("当前坐标为："));
                        cursorAppend.append(" X ");
                        labelX.setNum(poschange.x());
                        cursorAppend.append(labelX);
                        cursorAppend.append(" Y ");
                        labelX.setNum(poschange.y());
                        cursorAppend.append(labelX);
                        cursorAppend.append(QStringLiteral("检索坐标为："));
                        cursorAppend.append(" X ");
                        dataX.setNum(cursorx);
                        cursorAppend.append(dataX);
                        cursorAppend.append(" Y ");
                        dataY.setNum(cursory);
                        cursorAppend.append(dataY);
                        cursorAppend.append(QStringLiteral("\n设置终点成功，此点ID为："));
                        destinationId=findPointId(cursorx,cursory);
                        id.setNum(destinationId);
                        cursorAppend.append(id);
                        setEndPoint=true;
                        drawdata.e00File.shortpathFloyd(originId-1,destinationId-1);
                        setStartPoint=false;
                        setEndPoint=false;
                        routePaint=true;
                        this->repaint();
                    }
                }
            }
            QToolTip::showText(QCursor::pos(),cursorAppend);//做一个小标签显示鼠标位置
        }
    }
}

float CSpRoute::xchange(float ordinalx)
{
    CSpFile myfile=CSpRoute::drawdata;
    float minX=100000;
    for(int i=0;i<myfile.e00File.arcsCount;i++)
        for(int j=0;j<myfile.e00File.arcs[i].pointCount;j++)
        {
           if(myfile.e00File.arcs[i].arcPoint[j].fX<minX)
               minX=myfile.e00File.arcs[i].arcPoint[j].fX;
        }
    this->minX=minX;
    float resultX=(ordinalx-minX)*150000+100;
    return resultX;
}

float CSpRoute::ychange(float ordinaly)
{
    CSpFile myfile=CSpRoute::drawdata;
    float minY=100000;
    for(int i=0;i<myfile.e00File.arcsCount;i++)
        for(int j=0;j<myfile.e00File.arcs[i].pointCount;j++)
        {
           if(myfile.e00File.arcs[i].arcPoint[j].fY<minY)
               minY=myfile.e00File.arcs[i].arcPoint[j].fY;
        }
    this->minY=minY;
    float resultY=-(ordinaly-minY)*150000-70;
    return resultY;
}

float CSpRoute::xBackChange(float ordinalx)
{
    float resultX=float((ordinalx-100)/150000)+minX;
    return resultX;
}

float CSpRoute::yBackChange(float ordinaly)
{
    float resultY=float(-(ordinaly-labelHeight+70)/150000)+minY;
    return resultY;
}

int CSpRoute::findPointId(float x,float y)
{
    CSpE00 e00file=CSpRoute::drawdata.e00File;
    for(int i=0;i<e00file.arcsCount;i++)
    {
        //分别找弧段的第一个点和最后一个点
        int pointCount=e00file.arcs[i].pointCount;
        float judgeX=abs(e00file.arcs[i].arcPoint[0].fX-x);
        float judgeY=abs(e00file.arcs[i].arcPoint[0].fY-y);
        if(judgeX<0.0001&&judgeY<0.0001)
            return e00file.arcs[i].fromId;
        judgeX=abs(e00file.arcs[i].arcPoint[pointCount-1].fX-x);
        judgeY=abs(e00file.arcs[i].arcPoint[pointCount-1].fY-y);
        if(judgeX<0.0001&&judgeY<0.0001)
            return e00file.arcs[i].toId;
    }
    return 0;//未成功则输出0
}
