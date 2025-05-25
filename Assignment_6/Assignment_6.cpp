#include <iostream>
#include <vector>
using namespace std;

// �������������
void printMatrix(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Warshall �㷨���㴫�ݱհ�
void warshall(vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    // ʹ���м�ڵ� k ���¹�ϵ����
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // ��� i->k �� k->j ����·������ i->j Ҳ��·��
                matrix[i][j] = matrix[i][j] || (matrix[i][k] && matrix[k][j]);
            }
        }
    }
}

int main() {
    int n;
    cout << "������������: ";
    cin >> n;
    
    vector<vector<int>> matrix(n, vector<int>(n));
    
    // �����������
    for (int i = 0; i < n; i++) {
        cout << "���������ĵ� " << i << " ��Ԫ�أ�Ԫ���Կո�ָ�����";
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // ���㴫�ݱհ�
    warshall(matrix);
    
    // ������ݱհ����
    cout << "���ݱհ���Ĺ�ϵ����" << endl;
    printMatrix(matrix);

    return 0;
}

