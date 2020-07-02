#include "cspobject.h"

CSpObject::CSpObject()
{

}

void CSpObject::ShowObject()
{
    if (this->Dimension==1)
        cout<<"This object is a line."<<endl;
    else if (this->Dimension==2)
        cout<<"This object is a plane."<<endl;
    cout<<"This object consists of "<<this->PointCapacity<<" points."<<endl;
    for (int Counter=0;Counter<this->PointCapacity;Counter++)
        this->GEOPoint[Counter].ShowPoint();
}
