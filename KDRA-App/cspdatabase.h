#ifndef CSPDATABASE_H
#define CSPDATABASE_H
#include <csplayer.h>
#include <iostream>
using namespace std;

class CSpDatabase
{
public:
    CSpDatabase();
    int Left;
    int Right;
    int Top;
    int Bottom;
    int LayerCapacity;
    CSpLayer* GEOLayer;
    void ShowDatabase();
};

#endif // CSPDATABASE_H
