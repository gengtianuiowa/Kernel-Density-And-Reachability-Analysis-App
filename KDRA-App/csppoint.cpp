#include "csppoint.h"

CSpPoint::CSpPoint()
{

}

bool CSpPoint::IsEnd()
{
    if (this->X==-99999&&this->Y==-99999)
        return true;
    else
        return false;
}

void CSpPoint::ShowPoint()
{
    cout<<"Coordinate:("<<this->X<<','<<this->Y<<')'<<endl;
}
