#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 边的结构体，用于存储边的信息
struct Edge {
    int u, v, weight;
    
    // 用于排序边的比较函数
    bool operator<(const Edge &e) const {
        return weight < e.weight; // 按权重升序排列
    }
};

// 查找集合的根节点，使用路径压缩优化
int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent, parent[i]);
}

// 合并两个集合，按秩合并优化
void unionSets(int parent[], int rank[], int u, int v) {
    int rootU = find(parent, u);
    int rootV = find(parent, v);
    
    if (rootU != rootV) {
        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

void kruskal(int n, int m, vector<Edge> &edges) {
    vector<Edge> mst; // 存储最小生成树的边
    int totalCost = 0; // 存储最小生成树的总耗费
    
    // 初始化并查集
    int parent[n + 1], rank[n + 1];
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    
    // 按边的权值升序排序
    sort(edges.begin(), edges.end());
    
    // Kruskal 算法主体
    for (const Edge &e : edges) {
        int u = e.u, v = e.v;
        
        // 判断是否会形成环
        if (find(parent, u) != find(parent, v)) {
            // 如果没有环，选中该边，并合并集合
            mst.push_back(e);
            totalCost += e.weight; // 累加当前边的权值到总耗费
            unionSets(parent, rank, u, v);
        }
    }
    
    // 输出最小生成树的边
    for (const Edge &e : mst) {
        cout <<"最小耗费是: "<< e.u << "和" << e.v << endl;
    }
    
    // 输出最小生成树的总耗费
    cout << "最小生成树的总耗费为: " << totalCost << endl;
}

int main() {
    int n, m; // 顶点数和边数
    cout << "请输入所求图的顶点数目和边的数目(以空格分隔): ";
    cin >> n >> m;
    
    vector<Edge> edges; // 存储图的边
    
    cout << "请输入两条边的节点信号以及它们的权值(以空格分隔各个数): "<<endl;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w}); // 添加边
    }
    
    // 调用 Kruskal 算法求最小生成树
    kruskal(n, m, edges);
    
    return 0;
}
