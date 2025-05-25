#include <iostream>
#include <vector>
using namespace std;

// 函数：输出矩阵
void printMatrix(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Warshall 算法计算传递闭包
void warshall(vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    // 使用中间节点 k 更新关系矩阵
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // 如果 i->k 和 k->j 都有路径，则 i->j 也有路径
                matrix[i][j] = matrix[i][j] || (matrix[i][k] && matrix[k][j]);
            }
        }
    }
}

int main() {
    int n;
    cout << "请输入矩阵阶数: ";
    cin >> n;
    
    vector<vector<int>> matrix(n, vector<int>(n));
    
    // 逐行输入矩阵
    for (int i = 0; i < n; i++) {
        cout << "请输入矩阵的第 " << i << " 行元素（元素以空格分隔）：";
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // 计算传递闭包
    warshall(matrix);
    
    // 输出传递闭包结果
    cout << "传递闭包后的关系矩阵：" << endl;
    printMatrix(matrix);

    return 0;
}

