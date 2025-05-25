#include <iostream>
#include <vector>

using namespace std;  

class MatrixOperations {
private:
    vector<vector<int>> matrix; // 矩阵
    int n, d, z; // n为行数，d为列数，z为用户选择的操作序号

    // 输出矩阵
    void output(const vector<vector<int>>& mat) {
        std::cout << "所求关系矩阵为:"<<endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < d; ++j) {
                std::cout << mat[i][j] << " "; // 输出每个元素
            }
            cout << endl;
        }
    }

    // 自反闭包
    void zifan() {
        for (int i = 0; i < n; ++i) {
            matrix[i][i] = 1; // 对角线元素置为1
        }
        output(matrix); // 输出结果
        select(); // 重新选择操作
    }

    // 对称闭包
    void duichen() {
        // 创建一个新的矩阵 s1 用来存储转置后的矩阵
        vector<vector<int>> s1(n, vector<int>(d));
        // 矩阵转置
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < d; ++j) {
                s1[j][i] = matrix[i][j];
            }
        }
        // 对称闭包运算：矩阵和转置矩阵的元素相加，结果大于1则置为1
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < d; ++j) {
                matrix[i][j] = matrix[i][j] + s1[i][j];
                if (matrix[i][j] > 1) {
                    matrix[i][j] = 1;
                }
            }
        }
        output(matrix); // 输出结果
        select(); // 重新选择操作
    }

    // 传递闭包
    void chuandi() {
        // 创建矩阵m，a和t来进行操作
        vector<vector<int>> m(n, vector<int>(d));
        vector<vector<int>> a(n, vector<int>(d));
        vector<vector<int>> t(n, vector<int>(d));

        // 初始化矩阵m、a和t
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < d; ++j) {
                a[i][j] = 0;
                t[i][j] = matrix[i][j];
                m[i][j] = matrix[i][j];
            }
        }

        // 进行传递闭包操作
        for (int h = 0; h < n; ++h) {
            // 遍历每个元素，进行传递计算
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

            // 更新矩阵 m 和 t
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

        output(t); // 输出结果
        select(); // 重新选择操作
    }

    // 选择操作
    void select() {
        cout << "请输入矩阵的行数: ";
        cin >> n;
        cout << "请输入矩阵的列数: ";
        cin >> d;
        matrix.resize(n, vector<int>(d)); // 调整矩阵大小

        cout << "请输入关系矩阵:\n";
        for (int i = 0; i < n; ++i) {
            cout << "请输入矩阵的第" << i << "行元素(元素以空格分隔): ";
            for (int j = 0; j < d; ++j) {
                cin >> matrix[i][j]; // 输入矩阵元素
            }
        }

        // 提供选择算法
        cout << "输入对应序号选择算法\n1: 自反闭包\n2: 传递闭包\n3: 对称闭包\n4: 退出\n";
        cin >> z;

        switch (z) {
            case 1: zifan(); break; // 自反闭包
            case 2: chuandi(); break; // 传递闭包
            case 3: duichen(); break; // 对称闭包
            case 4: exit(0); break; // 退出
            default: 
			cout << "无效的选择，请重新输入。"<<endl; 
			select(); 
			break; // 无效输入
        }
    }

public:
    // 构造函数初始化
    MatrixOperations() : n(0), d(0), z(0) {}

    // 运行程序
    void run() {
        select();
    }
};

int main() {
    MatrixOperations m; // 创建 MatrixOperations 对象
    m.run(); // 启动程序
    return 0;
}
