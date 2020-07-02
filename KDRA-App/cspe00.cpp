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
    //��ʼ��floyd�㷨����������
    for(v = 0; v < vexNum; v++)
    {
        for(w = 0; w < vexNum; w++)
        {
            D[v][w] = matirx[v][w];
            P[v][w] = w;
        }
    }

    //�����Ǹ��������㷨�ĺ��Ĳ���
    //kΪ�м��
    for(k = 0; k < vexNum; k++)
    {
        //vΪ���
        for(v = 0 ; v < vexNum; v++)
        {
            //wΪ�յ�
            for(w =0; w < vexNum; w++)
            {
                if(D[v][w] > (D[v][k] + D[k][w]))
                {
                    D[v][w] = D[v][k] + D[k][w];//������С·��
                    P[v][w] = P[v][k];//������С·���м䶥��
                }
            }
        }
    }

    //shuchu suoyou matric
//    for(int i=0;i<vexNum;i++)
//        for(int j=0;j<vexNum;j++)
//            cout<<matrix[i][j]<<" "<<endl;
    //����С·��
    //��Ϊ�����д洢�ı�ź�ʵ�ʱ�����1���������д�ӡ�ĵط���+1
    printf("\n%d -> %d ����С·��Ϊ��%f\n", origin+1, destination+1, D[origin][destination]);
    k = P[origin][destination];
    printf("path: %d", origin+1);//��ӡ���
    int passPointCount=0;
    while(k != destination)
    {
        printf("-> %d", k+1);//��ӡ�м��
        k = P[k][destination];
        passPointCount++;
    }

    passPoints=new int[passPointCount];//����while�����Ǹ���+1
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
    this->countVex();//������
    this->matirx=new float*[vexNum];
    //����matrix
    for(int i=0;i<vexNum;i++)//��̬����һ��vex*vex��С�ľ���
    {
        this->matirx[i]=new float[vexNum];
    }

    //Ϊmatrix��ֵ
    for(int i=0;i<vexNum;i++)
        for(int j=0;j<vexNum;j++)
        {
            this->matirx[i][j]=1000;//�ȸ�ÿһ������Ԫ�ظ�һ����ֵ��1000����������������
        }

    CSpLink* links=this->links;
    for(int i=0;i<linksCount;i++)
    {
        //���ĳ����֮����ͨ�Ļ�����lengthȡ��1000
        int m=links[i].fromNode;
        int n=links[i].toNode;
        this->matirx[m-1][n-1]=links[i].length;
        this->matirx[n-1][m-1]=links[i].length;
    }

    //��ʼ��pathmatrix��shortpath
    this->pathMatirx=new int*[vexNum];
    for(int i=0;i<vexNum;i++)//��̬����һ��vex*vex��С�ľ���
    {
        this->pathMatirx[i]=new int[vexNum];
    }

    this->shortPath=new float*[vexNum];
    //����matrix
    for(int i=0;i<vexNum;i++)//��̬����һ��vex*vex��С�ľ���
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
