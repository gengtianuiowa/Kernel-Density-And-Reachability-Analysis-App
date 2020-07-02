#include "cspcities.h"

CSpCities::CSpCities()
{

}

void CSpCities::ShowCity()
{
    cout<<"City name: "<<this->CityName<<endl;
    this->Position.ShowPoint();
}
