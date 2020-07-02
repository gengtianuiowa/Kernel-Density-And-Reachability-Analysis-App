#include "csplayer.h"

CSpLayer::CSpLayer()
{

}

void CSpLayer::ShowLayer()
{
    cout<<"Layer Name:"<<this->LayerName<<endl;
    cout<<"This layer has "<<this->ObjectCapacity<<" objects."<<endl;
    for (int Counter=0;Counter<this->ObjectCapacity;Counter++)
        this->GEOObject[Counter].ShowObject();
}
