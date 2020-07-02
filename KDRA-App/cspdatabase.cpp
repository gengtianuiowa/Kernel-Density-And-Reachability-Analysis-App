#include "cspdatabase.h"

CSpDatabase::CSpDatabase()
{

}

void CSpDatabase::ShowDatabase()
{
    cout<<"Database range:"<<endl
        <<"Left:"<<this->Left<<endl
        <<"Right:"<<this->Right<<endl
        <<"Top:"<<this->Top<<endl
        <<"Bottom:"<<this->Bottom<<endl;
    cout<<"This database has "<<this->LayerCapacity<<" layers."<<endl;
    for (int Counter=0;Counter<this->LayerCapacity;Counter++)
        this->GEOLayer[Counter].ShowLayer();
}
