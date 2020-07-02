#include "CSpE00.h"

CSpE00::CSpE00()
{

}



CSpE00::CSpArc::CSpArc()
{

}


CSpE00::CSpLink::CSpLink()
{

}

int CSpE00::countLinks(int compass,string data)
{
    int length=data.length();
    int scout=compass;
    while(scout<length)
    {
        if (data[scout]=='\n')
        {
           string temp=data.substr(compass,scout-compass);
           int length=temp.length();
           int result=atoi(temp.substr(54,length-54).c_str());
           return result;
        }
        scout++;
    }
    return 0;
}

int CSpE00::countFields(int compass, string data)
{
    int length=data.length();
    int scout=compass;
    while(scout<length)
    {
        if (data[scout]=='\n')
        {
           string temp=data.substr(compass,scout-compass);
           int result=atoi(temp.substr(37,1).c_str());
           return result;
        }
        scout++;
    }
    return 0;
}

void CSpE00::shortpathFloyd(int origin,int destination)
{
    this->createMatrixs();
    int v, w, k;
    int vexNum=this->vexNum;
    float** matrix=this->matirx;
    int** P=this->pathMatirx;
    float** D=this->shortPath;
    //初始化floyd算法的两个矩阵
    for(v = 0; v < vexNum; v++)
    {
        for(w = 0; w < vexNum; w++)
        {
            D[v][w] = matirx[v][w];
            P[v][w] = w;
        }
    }

    //这里是弗洛伊德算法的核心部分
    //k为中间点
    for(k = 0; k < vexNum; k++)
    {
        //v为起点
        for(v = 0 ; v < vexNum; v++)
        {
            //w为终点
            for(w =0; w < vexNum; w++)
            {
                if(D[v][w] > (D[v][k] + D[k][w]))
                {
                    D[v][w] = D[v][k] + D[k][w];//更新最小路径
                    P[v][w] = P[v][k];//更新最小路径中间顶点
                }
            }
        }
    }

    //shuchu suoyou matric
//    for(int i=0;i<vexNum;i++)
//        for(int j=0;j<vexNum;j++)
//            cout<<matrix[i][j]<<" "<<endl;
    //求最小路径
    //因为数组中存储的编号和实际编号相差1，故在所有打印的地方都+1
    printf("\n%d -> %d 的最小路径为：%f\n", origin+1, destination+1, D[origin][destination]);
    k = P[origin][destination];
    printf("path: %d", origin+1);//打印起点
    int passPointCount=0;
    while(k != destination)
    {
        printf("-> %d", k+1);//打印中间点
        k = P[k][destination];
        passPointCount++;
    }

    passPoints=new int[passPointCount];//包括while上面那个，+1
    this->passPointCount=passPointCount;
    k = P[origin][destination];
    int i=0;
    while(k != destination)
    {
        passPoints[i]=k+1;
        k = P[k][destination];
        i++;
//        cout<<passPoints[i]<<endl;
    }
    printf("-> %d\n", destination+1);
}

void CSpE00::createMatrixs()
{
    this->countVex();//数点数
    this->matirx=new float*[vexNum];
    //生成matrix
    for(int i=0;i<vexNum;i++)//动态生成一个vex*vex大小的矩阵
    {
        this->matirx[i]=new float[vexNum];
    }

    //为matrix赋值
    for(int i=0;i<vexNum;i++)
        for(int j=0;j<vexNum;j++)
        {
            this->matirx[i][j]=1000;//先给每一个数组元素赋一个大值（1000），代表距离无穷大
        }

    CSpLink* links=this->links;
    for(int i=0;i<linksCount;i++)
    {
        //如果某两点之间联通的话，用length取代1000
        int m=links[i].fromNode;
        int n=links[i].toNode;
        this->matirx[m-1][n-1]=links[i].length;
        this->matirx[n-1][m-1]=links[i].length;
    }

    //初始化pathmatrix和shortpath
    this->pathMatirx=new int*[vexNum];
    for(int i=0;i<vexNum;i++)//动态生成一个vex*vex大小的矩阵
    {
        this->pathMatirx[i]=new int[vexNum];
    }

    this->shortPath=new float*[vexNum];
    //生成matrix
    for(int i=0;i<vexNum;i++)//动态生成一个vex*vex大小的矩阵
    {
        this->shortPath[i]=new float[vexNum];
    }
}

void CSpE00::countVex()
{
    int temp=0;
    CSpLink* links=this->links;
    for(int i=0;i<this->linksCount;i++)
    {
        if(links[i].fromNode>temp)
            temp=links[i].fromNode;
    }
    for(int i=0;i<this->linksCount;i++)
    {
        if(links[i].toNode>temp)
            temp=links[i].toNode;
    }
    this->vexNum=temp;
}
