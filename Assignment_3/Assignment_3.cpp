#include <iostream>
#include <vector>

using namespace std;  

class MatrixOperations {
private:
    vector<vector<int>> matrix; // ����
    int n, d, z; // nΪ������dΪ������zΪ�û�ѡ��Ĳ������

    // �������
    void output(const vector<vector<int>>& mat) {
        std::cout << "�����ϵ����Ϊ:"<<endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < d; ++j) {
                std::cout << mat[i][j] << " "; // ���ÿ��Ԫ��
            }
            cout << endl;
        }
    }

    // �Է��հ�
    void zifan() {
        for (int i = 0; i < n; ++i) {
            matrix[i][i] = 1; // �Խ���Ԫ����Ϊ1
        }
        output(matrix); // ������
        select(); // ����ѡ�����
    }

    // �ԳƱհ�
    void duichen() {
        // ����һ���µľ��� s1 �����洢ת�ú�ľ���
        vector<vector<int>> s1(n, vector<int>(d));
        // ����ת��
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < d; ++j) {
                s1[j][i] = matrix[i][j];
            }
        }
        // �ԳƱհ����㣺�����ת�þ����Ԫ����ӣ��������1����Ϊ1
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < d; ++j) {
                matrix[i][j] = matrix[i][j] + s1[i][j];
                if (matrix[i][j] > 1) {
                    matrix[i][j] = 1;
                }
            }
        }
        output(matrix); // ������
        select(); // ����ѡ�����
    }

    // ���ݱհ�
    void chuandi() {
        // ��������m��a��t�����в���
        vector<vector<int>> m(n, vector<int>(d));
        vector<vector<int>> a(n, vector<int>(d));
        vector<vector<int>> t(n, vector<int>(d));

        // ��ʼ������m��a��t
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < d; ++j) {
                a[i][j] = 0;
                t[i][j] = matrix[i][j];
                m[i][j] = matrix[i][j];
            }
        }

        // ���д��ݱհ�����
        for (int h = 0; h < n; ++h) {
            // ����ÿ��Ԫ�أ����д��ݼ���
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < d; ++j) {
                    if (m[i][j] == 1) {
                        for (int k = 0; k < n; ++k) {
                            if (matrix[j][k] == 1) {
                                a[i][k] = 1;
                            }
                        }
                    }
                }
            }

            // ���¾��� m �� t
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < d; ++j) {
                    m[i][j] = a[i][j];
                    t[i][j] += a[i][j];
                    a[i][j] = 0;
                    if (t[i][j] > 1) {
                        t[i][j] = 1;
                    }
                }
            }
        }

        output(t); // ������
        select(); // ����ѡ�����
    }

    // ѡ�����
    void select() {
        cout << "��������������: ";
        cin >> n;
        cout << "��������������: ";
        cin >> d;
        matrix.resize(n, vector<int>(d)); // ���������С

        cout << "�������ϵ����:\n";
        for (int i = 0; i < n; ++i) {
            cout << "���������ĵ�" << i << "��Ԫ��(Ԫ���Կո�ָ�): ";
            for (int j = 0; j < d; ++j) {
                cin >> matrix[i][j]; // �������Ԫ��
            }
        }

        // �ṩѡ���㷨
        cout << "�����Ӧ���ѡ���㷨\n1: �Է��հ�\n2: ���ݱհ�\n3: �ԳƱհ�\n4: �˳�\n";
        cin >> z;

        switch (z) {
            case 1: zifan(); break; // �Է��հ�
            case 2: chuandi(); break; // ���ݱհ�
            case 3: duichen(); break; // �ԳƱհ�
            case 4: exit(0); break; // �˳�
            default: 
			cout << "��Ч��ѡ�����������롣"<<endl; 
			select(); 
			break; // ��Ч����
        }
    }

public:
    // ���캯����ʼ��
    MatrixOperations() : n(0), d(0), z(0) {}

    // ���г���
    void run() {
        select();
    }
};

int main() {
    MatrixOperations m; // ���� MatrixOperations ����
    m.run(); // ��������
    return 0;
}
