#ifndef MYLABEL_H
#define MYLABEL_H
#include <QPaintEvent>
#include<QLabel>
#include "cspfile.h"
#include<cspcities.h>
#include<QTextCodec>
#include<QToolTip>

//期望在QLabel中绘制地图。故在design界面中将对应label右键选中“提升为”，再在此类中重写其paintevent方法
class cspmap : public QLabel
{
public:
    explicit cspmap(QWidget *parent=0);//初始化这个对象，格式固定（来自百度）
    virtual void paintEvent(QPaintEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *event) override;
    static CSpFile drawdata;
    int xchange(int x);
    int ychange(int y);
    static bool searchingState;
    static CSpCities searchCity;
};

#endif // MYLABEL_H
