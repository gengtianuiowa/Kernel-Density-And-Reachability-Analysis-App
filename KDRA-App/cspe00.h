#ifndef CSPE00_H
#define CSPE00_H
#include <csppoint.h>

class CSpE00
{
public:
    CSpE00();
    string HeadInfo;
    int ArcType;
    int labType;
    int tolType;
    int prjType;
    int ifotype;
    class CSpArc
    {
    public:
        CSpArc();
        int arcInfo;
        int arcId;
        int fromId;
        int toId;
        int leftPolygon;
        int rightPolygon;
        int pointCount;
        CSpPoint* arcPoint;
    };
    CSpArc* arcs;
    class CSpLink
    {
    public:
        CSpLink();
        int fromNode;
        int toNode;
        float length;
    };
    CSpLink* links;
    int countLinks(int compass,string data);
    int countFields(int compass,string data);
    int arcsCount;//弧段数
    int linksCount;//links数即边数
    int fieldsCount;

    //接下来的数据结构用于路径规划，来源百度
    int vexNum;//顶点数
    int edgNum;//边数
    float** matirx;//邻接矩阵，由于不清楚点个数，需要稍后动态创建,后面的数组同
    int** pathMatirx;//记录最小路径前驱点
    float** shortPath;//记录顶点间的最小路径值
    void shortpathFloyd(int origin, int destination);//路径规划——弗洛伊德算法
    void createMatrixs();//根据连通性，将数组转化到二维数组中,初始化三个数组
    void countVex();//数点数，不用数边数，因为linkscount即为
    int* passPoints;//经过的点集
    int passPointCount;
};

#endif // CSPE00_H
