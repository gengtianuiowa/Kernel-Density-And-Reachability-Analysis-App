#ifndef CSPKERNEL_H
#define CSPKERNEL_H
#include<QLabel>
#include"qpainter.h"
#include"cspshp.h"

class CSpKernel: public QLabel
{
public:
    //项目开发至此，深深感觉到file类由于当时组织不当过于庞大了。并没有合理设置派生类
    //导致若现在讲核密度数据读取、存储集成至内，非常不利于认读和修改，也会浪费诸多内存
    //因此核密度在此独立于
    explicit CSpKernel(QWidget *parent=0);//初始化这个对象，格式固定（来自百度）。记得在.cpp里修改构造函数
    virtual void paintEvent(QPaintEvent *event) override;
    static CSpShp shp;
    //注意，坐标转换因为shp内也需要转换的问题，移植到shp中
};

#endif // CSPKERNEL_H
