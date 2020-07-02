#ifndef CSPFILE_H
#define CSPFILE_H
#include <cspdatabase.h>
#include <cspindex.h>
#include <cspcities.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include"cspe00.h"

class CSpFile
{
public:
    CSpFile();
    CSpDatabase Database;
    int PropertyCapacity;
    CSpProperty* Properties;
    CSpIndex index;
    int CityCapacity;
    CSpCities* Cities;
    CSpE00 e00File;

    bool LoadFile();//读取实习1文件
    bool LoadDat();
    bool LoadOpt();
    bool LoadTxt();
    bool LoadE00();
    void ShowProperties();
    void ShowCities();
    void showArcs();
    void showLinks();

    const char* DAT;
    const char* OPT;
    const char* TXT;
    const char* E00;

    bool datState;
    bool optState;
    bool txtState;
    bool e00State;

    void createIndex();
    bool findInindex(int x,int y);//输入一个点，在索引中实现其点到属性的检索
    bool cursorPositiontoPoint(int x,int y);//在索引中找到鼠标现在的位置对应查询哪一个点
    CSpCities cityFromindex;//从索引中检索到的城市
};

#endif // CSPFILE_H
