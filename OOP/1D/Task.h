#include<cstring>
#pragma once
class Task {
public:
    bool finish;
    int location[100] =  {0}; //占用显卡的编号
    char s[30] = {0}; //任务名
    int n = 0; //显卡使用数
    int m = 0; //每张卡使用的显存大小
    int d = 0; //使用时长T
    Task()
    {
        memset(location,0,sizeof(location));
        memset(s,0,sizeof(s));
        n=m=d=0;
        finish = true;
    }
    Task(char* S, int D, int N, int M) {
        strcpy(s, S);
        n = N;
        m = M;
        d = D;
        finish = false;
    }
};