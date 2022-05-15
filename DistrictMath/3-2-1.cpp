//色数

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int calculate(vector<int> left_n, bool edge[][16]) {
    for(auto i = left_n.begin(); i != left_n.end(); i++) {
        for(auto j = i + 1; j != left_n.end(); j++) {
            //两点不相邻
            if((edge[*i][*j] || edge[*j][*i]) == false) {
                bool newedge[16][16];
                //两点添加边
                memcpy(newedge, edge, sizeof(newedge));
                newedge[*i][*j] = true; newedge[*j][*i] = true;
                int a = calculate(left_n, newedge);
                // 两点合并，删去j
                memcpy(newedge, edge, sizeof(newedge));
                for(int k = 1; k <= 15; k++) {
                    if(edge[*j][k] == true) {
                        newedge[*i][k] = true;
                        newedge[k][*i] = true;
                    }
                }
                left_n.erase(j);
                int b = calculate(left_n, newedge);
                //取最小值
                return min(a, b);
            }
        }
    }
    return left_n.size();
}

int main() {
    vector<int> left_n;
    bool edge[16][16] = { 0 };
    int N; //节点数
    int M; //边数
    cin >> N >> M;
    for(int i = 1; i <= N; i++) left_n.push_back(i);
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        edge[a][b] = true; edge[b][a] = true;
    }
    cout << calculate(left_n, edge);
}