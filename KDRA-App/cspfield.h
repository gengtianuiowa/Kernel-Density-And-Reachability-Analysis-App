#ifndef CSPFIELD_H
#define CSPFIELD_H
#include <stdio.h>

class CSpField
{
public:
    CSpField();
    const char* fieldName=NULL;
    const char* typeName=NULL;
    int* intData=NULL;
    double* doubleData=NULL;
    const char** stringData=NULL;
};


#endif // CSPFIELD_H
