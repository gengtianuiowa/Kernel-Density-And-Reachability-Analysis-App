#include "cspproperty.h"

CSpProperty::CSpProperty()
{

}

void CSpProperty::ShowProperty()
{
    cout<<"This property is named: "<<this->LayerType<<endl<<"Property type: ";
    if (this->IsLinear==true&&this->IsPlanar==false)
    {
        cout<<"Line"<<endl
            <<"Line width: "<<this->Width<<endl
            <<"Line color: RGB("
            <<this->LineColor.Red<<','
            <<this->LineColor.Green<<','
            <<this->LineColor.Blue<<')'<<endl;
    }
    else if (this->IsPlanar==true)
    {
        if (this->IsLinear==true)
            cout<<"Plane (with boundary)"<<endl
                <<"Boundary width: "<<this->Width<<endl
                <<"Boundary color: RGB("
                <<this->LineColor.Red<<','
                <<this->LineColor.Green<<','
                <<this->LineColor.Blue<<')'<<endl
                <<"Plane color: RGB("
                <<this->PlaneColor.Red<<','
                <<this->PlaneColor.Green<<','
                <<this->PlaneColor.Blue<<')'<<endl;
        else
            cout<<"Plane"<<endl
                <<"Plane color: RGB("
                <<this->PlaneColor.Red<<','
                <<this->PlaneColor.Green<<','
                <<this->PlaneColor.Blue<<')'<<endl;
    }
}
