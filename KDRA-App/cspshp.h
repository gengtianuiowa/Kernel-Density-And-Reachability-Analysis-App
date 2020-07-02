#ifndef CSPSHP_H
#define CSPSHP_H
#include "ogrsf_frmts.h"
#include"csppoint.h"
#include "CSpField.h"
#define PAI 3.1415926

class CSpShp
{
public:
    CSpShp();
    const char* shpPath;
    const char* layerName;
    bool LoadShp();
    bool loadStatus=false;
    bool SDCal();//计算标准距离
    bool DmCal();//计算与平均中心距离中位数
    bool toCenterDisCal();//计算与平均中心距离
    bool knldCal(int width,int height);//计算核密度,需要输入计算范围（也即tab标签的大小）
    float findMaxKnld(int width,int height);
    bool SRCal();//计算带宽
    float disCal(CSpPoint p1,CSpPoint p2);//正常计算距离
    float disWithWindowCal(CSpPoint p1,CSpPoint p2);//算图中像素与 ！图中点！的距离（要经过坐标变换），前面一个传入图内像素，后一个传入点
    float xchange(float ordinalx);//坐标变换，必须和画图类保持一致
    float ychange(float ordinaly);
    float maxX,minX,maxY,minY;

    CSpPoint* showChange(int weight, int height);//坐标变换，必须和画图类保持一致

    CSpField getField(const char* fieldName);

    int fieldCount;//字段数
    CSpField* fields;
    int pointCount;//总点数
    CSpPoint* shpPoints;//储存所有点
    float* disToCenter;//所有点和平均中心的距离
    CSpPoint avgCenter;//平均中心
    float SD;//公式中的标准距离
    float Dm;//与平均中心距离的中位数
    float SearchRadius;//带宽
    float** knlds;//二维矩阵存储核密度
};

#endif // CSPSHP_H
