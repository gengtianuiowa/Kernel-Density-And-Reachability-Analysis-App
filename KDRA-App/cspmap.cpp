#include "cspmap.h"
#include"qpainter.h"
#include "qwidget.h"
#include"cspfile.h"
#include"mainwindow.h"

//注意初始化函数的格式，固定格式，来自百度
cspmap::cspmap(QWidget *parent):QLabel(parent)
{

}

//重写的绘制函数
void cspmap::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event);
    QPainter p(this);
//    QRect windowRect = p.window();
//    int centerx  = windowRect.width();
//    int centery = windowRect.height();
//    p.translate(width/2.0,height/2.0);
//    p.drawLine(0,0,100,100);
    CSpFile myfile=cspmap::drawdata;
    QPolygon polygon;
    if(myfile.datState==true&&myfile.optState==true&&myfile.txtState==true)
    {
    for(int i=0;i<myfile.Database.LayerCapacity;i++)
    {
        for(int j=0;j<myfile.Database.GEOLayer[i].ObjectCapacity;j++)
        {
                //绘制线
                if (myfile.Database.GEOLayer[i].GEOObject->Dimension==1)//判断是否为线
                {
                    //设置线样式
                    for(int m=0;m<myfile.PropertyCapacity;m++)
                    {
                        if(myfile.Database.GEOLayer[i].LayerName==myfile.Properties[m].LayerType)
                        {
                            p.setPen(QPen(QColor(myfile.Properties[m].LineColor.Red,
                                                myfile.Properties[m].LineColor.Green,
                                                myfile.Properties[m].LineColor.Blue),
                                                myfile.Properties[m].Width));
                            for(int m=0;m<myfile.Database.GEOLayer[i].GEOObject[j].PointCapacity-1;m++)
                            {
                                //判断两个点是否是重合的点。因为若包含重合的点，会画出一条斜下的直线
                                if(myfile.Database.GEOLayer[i].GEOObject[j].GEOPoint[m].X!=myfile.Database.GEOLayer[i].GEOObject[j].GEOPoint[m].Y&&myfile.Database.GEOLayer[i].GEOObject[j].GEOPoint[m+1].X!=myfile.Database.GEOLayer[i].GEOObject[j].GEOPoint[m+1].Y)
                                p.drawLine(xchange(myfile.Database.GEOLayer[i].GEOObject[j].GEOPoint[m].X),
                                           ychange(myfile.Database.GEOLayer[i].GEOObject[j].GEOPoint[m].Y),
                                           xchange(myfile.Database.GEOLayer[i].GEOObject[j].GEOPoint[m+1].X),
                                           ychange(myfile.Database.GEOLayer[i].GEOObject[j].GEOPoint[m+1].Y));
                            }
                            break;
                        }
                    }
                 }
                if(myfile.Database.GEOLayer[i].GEOObject->Dimension==2)
                {
                    //设置面样式
                    for(int m=0;m<myfile.PropertyCapacity;m++)
                    {
                        if(myfile.Database.GEOLayer[i].LayerName==myfile.Properties[m].LayerType)
                        {
                            //注意此处用实心填充！因为数据问题，四川省会画的非常大并且被压盖，实心填充能使压盖的线消失，不至于以虚线状态显示
                            QBrush brush(QColor(myfile.Properties[m].PlaneColor.Red,
                                             myfile.Properties[m].PlaneColor.Green,
                                             myfile.Properties[m].PlaneColor.Blue),Qt::SolidPattern);
                            for(int p=0;p<myfile.Database.GEOLayer[i].GEOObject[j].PointCapacity-1;p++)
                            {
                                polygon.push_back(QPoint(xchange(myfile.Database.GEOLayer[i].GEOObject[j].GEOPoint[p].X),
                                                            ychange(myfile.Database.GEOLayer[i].GEOObject[j].GEOPoint[p].Y)));
                            }
                            p.setBrush(brush);
                            p.drawPolygon(polygon);
                            polygon.clear();
                            break;
                        }
                    }
                }
        }
    }
    //在所有绘制完成后又加上了一块图形的绘制！因为经调试发现新疆省的脏线可以通过这一块覆盖
    for(int m=0;m<myfile.PropertyCapacity;m++)
    {
        if(myfile.Database.GEOLayer[0].LayerName==myfile.Properties[m].LayerType)
        {
            //注意此处用实心填充！因为数据问题，四川省会画的非常大并且被压盖，实心填充能使压盖的线消失，不至于以虚线状态显示
            QBrush brush(QColor(myfile.Properties[m].PlaneColor.Red,
                             myfile.Properties[m].PlaneColor.Green,
                             myfile.Properties[m].PlaneColor.Blue),Qt::SolidPattern);
            for(int p=0;p<myfile.Database.GEOLayer[0].GEOObject[1].PointCapacity;p++)
            {
                polygon.push_back(QPoint(xchange(myfile.Database.GEOLayer[0].GEOObject[1].GEOPoint[p].X),
                                            ychange(myfile.Database.GEOLayer[0].GEOObject[1].GEOPoint[p].Y)));
            }
            p.setPen(Qt::NoPen);
            p.setBrush(brush);
            p.drawPolygon(polygon);
            polygon.clear();
            break;
        }
    }
    }
    //绘出城市(包括搜索和不搜索）

    p.setPen(Qt::black);
//        cout<<"running"<<endl;
    QFont font;
    font.setPointSize(10);
    p.setFont(font);
    for(int i=0;i<myfile.CityCapacity;i++)
    {
        string name1=myfile.Cities[i].CityName;
        if(cspmap::searchingState==false)
        {
            //string转化成qstring
            QString name2=QString(QString::fromLocal8Bit(name1.c_str()));
            //坐标变换，统一除了5000并且y坐标增加了100，使地图完全显示，后面所有坐标都进行如下操作
            int x=xchange(myfile.Cities[i].Position.X);
            int y=ychange(myfile.Cities[i].Position.Y);
            p.drawText(x,y,name2);
            //cout<<"dont found"<<endl;
        }
        else
        {
            if(name1==this->searchCity.CityName)
            {
                p.setPen(Qt::red);
                QFont font;
                font.setPointSize(17);
                p.setFont(font);
                QString name2=QString(QString::fromLocal8Bit(name1.c_str()));
                //坐标变换，统一除了5000并且y坐标增加了100，使地图完全显示，后面所有坐标都进行如下操作
                int x=xchange(this->searchCity.Position.X);
                int y=ychange(this->searchCity.Position.Y);
                p.drawText(x,y,name2);
                p.setPen(Qt::black);
            //        cout<<"running"<<endl;
                font.setPointSize(10);
                p.setFont(font);
                //cout<<"found city"<<endl;
            }
            else
            {
                QString name2=QString(QString::fromLocal8Bit(name1.c_str()));
                //坐标变换，统一除了5000并且y坐标增加了100，使地图完全显示，后面所有坐标都进行如下操作
                int x=xchange(myfile.Cities[i].Position.X);
                int y=ychange(myfile.Cities[i].Position.Y);
                p.drawText(x,y,name2);
                //cout<<"found normal"<<endl;
            }
        }
   }
}

//实现在地图中添加小标签
void cspmap::mouseReleaseEvent(QMouseEvent *event)
{
    QString cursorAppend;//组成标签内容的字符串
    QString temp_x;
    QString temp_y;
    QString temp_x2;
    QString temp_y2;
    QPoint cursorPoint;//记录鼠标坐标
    if(event->button()==Qt::LeftButton)
    {
        cursorPoint = QCursor::pos();//获取当前光标的位置
        QPoint cursorpos(cursorPoint.x(),cursorPoint.y());//注意这个转换！将全局坐标转换为相对于label 的坐标
        QPoint poschange=QLabel::mapFromGlobal(cursorpos);
        int cursorx=poschange.x()*5000+cspmap::drawdata.Database.Left;//实现坐标逆变换，换算为在数据中的坐标
        int cursory=cspmap::drawdata.Database.Top-(poschange.y()-150)*5000+cspmap::drawdata.Database.Bottom;
        if(cspmap::drawdata.datState&&cspmap::drawdata.optState&&cspmap::drawdata.txtState)
        if(cspmap::drawdata.cursorPositiontoPoint(cursorx,cursory))
        {
            //把数据扔入标签
            string text3=cspmap::drawdata.cityFromindex.CityName;
            QString appendtext3=QString::fromLocal8Bit(text3.c_str());//把城市名称转化qstring，否则无法添加入标签
            cursorAppend.append("城市名称为：");
            cursorAppend.append(appendtext3);
            temp_x.setNum(cspmap::drawdata.cityFromindex.Position.X);
            temp_y.setNum(cspmap::drawdata.cityFromindex.Position.Y);
            cursorAppend.append("\n城市坐标为：");
            cursorAppend.append(" X ");
            cursorAppend.append(temp_x);
            cursorAppend.append(" Y ");
            cursorAppend.append(temp_y);
            QToolTip::showText(QCursor::pos(),cursorAppend);//做一个小标签显示鼠标位置
        }
    }
}
int cspmap:: xchange(int x)//x坐标的变换操作
{
    return (x-cspmap::drawdata.Database.Left)/5000;
}

int cspmap:: ychange(int y)//y坐标的变换操作
{
    return (cspmap::drawdata.Database.Top-(y-cspmap::drawdata.Database.Bottom))/5000+150;
}

