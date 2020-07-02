#ifndef CSPRA_H
#define CSPRA_H
#include<QLabel>
#include"qpainter.h"
#include"cspshp.h"
#include"csppoint.h"
#include"cspanlztools.h"

class CSpRA: public QLabel
{
public:
    CSpRA();
    explicit CSpRA(QWidget *parent=0);//初始化这个对象，格式固定（来自百度）。记得在.cpp里修改构造函数
    virtual void paintEvent(QPaintEvent *event) override;
    CSpPoint **TwoShpsShowChange(int width, int height, CSpShp lastShp, CSpShp inputShp);
    static CSpShp* shp;
    static bool drawLineStatus;
    QColor quantileColorSet(double data,int quantileCount,double max,double min);
};

#endif // CSPRA_H
