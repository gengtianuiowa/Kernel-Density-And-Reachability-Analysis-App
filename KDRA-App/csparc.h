#ifndef CSPARC_H
#define CSPARC_H
#include"csppoint.h"

class CSpArc
{
public:
    CSpArc();
    int arcInfo;
    int arcId;
    int fromId;
    int toId;
    int leftPolygon;
    int rightPolygon;
    int pointCount;
    CSpPoint* arcPoint;
};

#endif // CSPARC_H
