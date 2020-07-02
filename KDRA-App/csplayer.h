#ifndef CSPLAYER_H
#define CSPLAYER_H
#include <cspobject.h>
#include <cspproperty.h>
#include <string>
#include <iostream>

using namespace std;

class CSpLayer
{
public:
    CSpLayer();
    int NameCapacity;
    string LayerName;
    int ObjectCapacity;
    CSpObject* GEOObject;
    void ShowLayer();
};

#endif // CSPLAYER_H
