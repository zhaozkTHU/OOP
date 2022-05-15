#include <stdio.h>
#include<iostream>
#include<vector>
#include<tuple>
#include <string.h>
#include <assert.h>

const int INF = 0x3fffffff;
const int MAXN = 40;

int inline min(int a, int b) { return a < b ? a : b; }

//
// 记录结点标号（结点编号从 1 开始）
// direction[u] = 1 表示标号为正，-1 表示标号为负，0 表示未标号
// from[u] 表示结点 u 是因为哪个结点才得到标号的
// delta[u] 表示从源到 u 的增流路径上最大的可增流量
//
int direction[MAXN + 1], from[MAXN + 1], delta[MAXN + 1];

int n, m, s, t;

class Graph {
public:
    //终点、容量、流量
    std::vector<std::tuple<int, int, int>> edge[MAXN + 1];
    //起点、容量、流量
    std::vector<std::tuple<int, int, int>> _edge[MAXN + 1];

    // 返回指定边的流量
    int Flow(int u, int v) {
        for(auto i = edge[u].begin(); i != edge[u].end(); i++) {
            if(std::get<0>(*i) == v) return std::get<2>(*i);
        }
        return -1;
    }

    // 返回指定边的容量
    int Capacity(int u, int v) {
        for(auto i = edge[u].begin(); i != edge[u].end(); i++) {
            if(std::get<0>(*i) == v) return std::get<1>(*i);
        }
        return -1;
    }

    void AddEdge(int u, int v, int c, int f) {
        edge[u].push_back(std::make_tuple(v, c, f));
        _edge[v].push_back(std::make_tuple(u, c, f));
    }
} G;

//
// 适用于 Ford-Fulkerson 算法的标号过程，基于深度优先搜索给所有结点标号
//
void label_dfs(int u) {
    for (auto tmp : (G.edge[u])) {
        int v = std::get<0>(tmp);
        // 如果 v 访问过，跳过该结点
        if (direction[v] != 0)
            continue;
        int c = G.Capacity(u, v);
        int f = G.Flow(u, v);
        if (c > f) {
            // TODO: 更新标号
            direction[v] = 1;
            from[v] = u;
            delta[v] = c - f;
            label_dfs(v); // 从 v 出发，搜索邻接的未标号结点
        }
    }
    for (auto tmp : G._edge[u]) {
        // TODO: 仿照以上代码补全反向标号过程
        int v = std::get<0>(tmp);
        if(direction[v] != 0)
            continue;
        int f = G.Flow(v, u);
        if(f > 0) {
            direction[v] = -1;
            from[v] = u;
            delta[v] = f;
            label_dfs(v);
        }
    }
}

//
// Ford-Fulkerson 及 Edmonds-Karp 算法中的标号过程。
//
bool label() {
    label_dfs(s);
    return direction[t] != 0;
}

void printPath() {
    int size = delta[t];
    int pathLength = 0;
    static int Path[MAXN + 1];
    // 根据记录的 from 数组，从汇点倒推出增流路径
    for (int v = t; v != s; v = from[v]) {
        Path[pathLength++] = v;
        if(delta[v] < size) size = delta[v];
    }
    // TODO: 按照题目要求向标准输出中打印结果
    std::cout << pathLength + 1 << " " << size << std::endl << s << " ";
    for(int i = pathLength - 1; i >= 0; i--) std::cout << Path[i] << " ";
}

void init() {
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 0; i < m; i++) {
        int u, v, c, f;
        scanf("%d%d%d%d", &u, &v, &c, &f);
        G.AddEdge(u, v, c, f);
    }
}

int main() {
    init();
    if (label()) {
        printPath();
    } else {
        printf("-1\n");
    }
}