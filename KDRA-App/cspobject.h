#ifndef CSPOBJECT_H
#define CSPOBJECT_H
#include <csppoint.h>
#include <iostream>


class CSpObject
{
public:
    CSpObject();
    int Dimension;
    int PointCapacity;
    CSpPoint* GEOPoint;
    void ShowObject();
};

#endif // CSPOBJECT_H
