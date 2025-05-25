#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// �ߵĽṹ�壬���ڴ洢�ߵ���Ϣ
struct Edge {
    int u, v, weight;
    
    // ��������ߵıȽϺ���
    bool operator<(const Edge &e) const {
        return weight < e.weight; // ��Ȩ����������
    }
};

// ���Ҽ��ϵĸ��ڵ㣬ʹ��·��ѹ���Ż�
int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent, parent[i]);
}

// �ϲ��������ϣ����Ⱥϲ��Ż�
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
    vector<Edge> mst; // �洢��С�������ı�
    int totalCost = 0; // �洢��С���������ܺķ�
    
    // ��ʼ�����鼯
    int parent[n + 1], rank[n + 1];
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    
    // ���ߵ�Ȩֵ��������
    sort(edges.begin(), edges.end());
    
    // Kruskal �㷨����
    for (const Edge &e : edges) {
        int u = e.u, v = e.v;
        
        // �ж��Ƿ���γɻ�
        if (find(parent, u) != find(parent, v)) {
            // ���û�л���ѡ�иñߣ����ϲ�����
            mst.push_back(e);
            totalCost += e.weight; // �ۼӵ�ǰ�ߵ�Ȩֵ���ܺķ�
            unionSets(parent, rank, u, v);
        }
    }
    
    // �����С�������ı�
    for (const Edge &e : mst) {
        cout <<"��С�ķ���: "<< e.u << "��" << e.v << endl;
    }
    
    // �����С���������ܺķ�
    cout << "��С���������ܺķ�Ϊ: " << totalCost << endl;
}

int main() {
    int n, m; // �������ͱ���
    cout << "����������ͼ�Ķ�����Ŀ�ͱߵ���Ŀ(�Կո�ָ�): ";
    cin >> n >> m;
    
    vector<Edge> edges; // �洢ͼ�ı�
    
    cout << "�����������ߵĽڵ��ź��Լ����ǵ�Ȩֵ(�Կո�ָ�������): "<<endl;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w}); // ��ӱ�
    }
    
    // ���� Kruskal �㷨����С������
    kruskal(n, m, edges);
    
    return 0;
}
