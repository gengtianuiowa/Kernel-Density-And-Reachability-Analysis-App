#ifndef CSPCITIES_H
#define CSPCITIES_H
#include <string>
#include <csppoint.h>
#include <iostream>


class CSpCities
{
public:
    CSpCities();
    string CityName;
    CSpPoint Position;
    void ShowCity();
};

#endif // CSPCITIES_H
