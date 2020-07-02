#ifndef CSPPROPERTY_H
#define CSPPROPERTY_H
#include <string>
#include <cspcolor.h>
#include<iostream>
using namespace std;

class CSpProperty
{
public:
    CSpProperty();
    string LayerType;
    bool IsLinear;
    float Width;
    CSpColor LineColor;
    bool IsPlanar;
    CSpColor PlaneColor;
    void ShowProperty();
};

#endif // CSPPROPERTY_H
