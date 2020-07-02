#ifndef CSPANLZTOOLS_H
#define CSPANLZTOOLS_H
#include "cspshp.h"
#include "cspfield.h"

class CSpAnlzTools
{
public:
    CSpAnlzTools();
    CSpShp* workShps;
    float disCal(CSpPoint p1,CSpPoint p2);//正常计算欧式距离
};

class RATool:public CSpAnlzTools
{
public:
    RATool(CSpShp inputShp1, CSpShp inputShp2);
    bool RAAnalyze();
    double* RA;
private:
    float* CCPN;//coefficient of provision and need供需比
    float* CCPNCal();//算供需比
    double TSFCAMCoefficientCal(int searchRadius,int coefficient);//two-step floating catchment area method,一个是服务半径，一个是算"coefficient"系数
};
#endif // CSPANLZTOOLS_H
