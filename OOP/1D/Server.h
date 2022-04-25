#pragma once
#include"Task.h"
class Server {
public:
    int N = 0; //显卡个数
    int M = 0; //显卡显存
    int num = 0; //任务总量
    int storage[101] = {0};//显卡的占用量
    Server(int nn, int mm) {N = nn; M = mm;}
    Task conducting_task[200];
    void tick() {
        for(int i = 0; i < 200; i++) {
            if(conducting_task[i].finish == false) {
                conducting_task[i].d--;
                if(conducting_task[i].d == 0) {
                    for(int j = 0; j < conducting_task[i].n; j++) {
                        storage[conducting_task[i].location[j]] -= conducting_task[i].m;
                    }
                    conducting_task[i].finish = true;
                }
            }
        }
    }
    bool submit_task(Task task) {
        int sum = 0;//满足条件显卡数目
        int* new_location = new int[100];
        for(int i = 0; i < N; i++) {
            if(M - storage[i] >= task.m) {
                new_location[sum] = i;
                sum++;
            }
        }
        if(sum >= task.n) {
            conducting_task[num] = task;
            for(int i = 0; i < task.n; i++) {
                conducting_task[num].location[i] = new_location[i];
            }
            for(int i = 0; i < task.n; i++)
                storage[conducting_task[num].location[i]] += conducting_task[num].m;
            num++;
            delete[] new_location;
            return true;
        }
        delete[] new_location;
        return false;
    }
    bool cancel_task(char s[30]) {
        for(int i = 0; i < 200; i++) {
            if(strcmp(s, conducting_task[i].s) == 0) {
                if(conducting_task[i].finish == true)
                    return false;
                else {
                    conducting_task[i].finish = true;
                    for(int j = 0; j < conducting_task[i].n; j++)
                        storage[conducting_task[i].location[j]] -= conducting_task[i].m;
                    return true;
                }
                break;
            } 
        }
        return false;
    }
};