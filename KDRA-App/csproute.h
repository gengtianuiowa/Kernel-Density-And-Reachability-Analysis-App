#ifndef CSPROUTE_H
#define CSPROUTE_H
#include"cspfile.h"
#include"cspmap.h"
#include"qpainter.h"

class CSpRoute: public QLabel
{
public:
    explicit CSpRoute(QWidget *parent=0);//初始化这个对象，格式固定（来自百度）
    virtual void paintEvent(QPaintEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *event) override;
    static CSpFile drawdata;
    float xchange(float ordinalx);
    float ychange(float ordinaly);
    float xBackChange(float ordinalx);
    float yBackChange(float ordinaly);
    float minX;
    float minY;
    int labelWidth;
    int labelHeight;
    int findPointId(float x,float y);
    int originId;//找到点击的点对应的id，存入下列两个变量中，然后进行路径规划
    int destinationId;
    bool setStartPoint;
    bool setEndPoint;
    bool routePaint;
};

#endif // CSPROUTE_H
