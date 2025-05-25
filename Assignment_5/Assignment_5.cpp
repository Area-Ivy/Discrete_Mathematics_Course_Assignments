#include <iostream>
#include <vector>
#include <memory>  // 用于智能指针

using namespace std;

// 定义树节点结构
struct TreeNode {
    int num;            // 节点的频率
    shared_ptr<TreeNode> Lnode;    // 左子树（智能指针）
    shared_ptr<TreeNode> Rnode;    // 右子树（智能指针）

    // 构造函数初始化节点
    TreeNode(int val) : num(val), Lnode(nullptr), Rnode(nullptr) {}
};

// 全局变量
vector<shared_ptr<TreeNode>> fp;  // 保存树节点（使用智能指针）
char s[2 * 13];  // 存储前缀码（数组长度可以根据实际需要调整）

// 初始化树节点
void init_node(const vector<int>& f) {
    for (int i = 0; i < f.size(); ++i) {
        fp.push_back(make_shared<TreeNode>(f[i])); // 创建叶子节点
    }
}

// 排序函数：将第 N-n 个点插入到已排序的序列中
void sort(vector<shared_ptr<TreeNode>>& array) {
    for (size_t i = 0; i < array.size() - 1; ++i) {
        for (size_t j = i + 1; j < array.size(); ++j) {
            if (array[i]->num > array[j]->num) {
                swap(array[i], array[j]);
            }
        }
    }
}

// 构建赫夫曼树
shared_ptr<TreeNode> construct_tree(const vector<int>& f) {
    int n = f.size();
    vector<shared_ptr<TreeNode>> nodes = fp;

    for (int i = 1; i < n; ++i) {
        // 创建一个新的父节点
        shared_ptr<TreeNode> pt = make_shared<TreeNode>(nodes[i - 1]->num + nodes[i]->num);
        pt->Lnode = nodes[i - 1];  // 左子树
        pt->Rnode = nodes[i];      // 右子树

        // 替换掉原来的节点
        nodes[i] = pt;
        sort(nodes);  // 重新排序
    }

    return nodes[n - 1]; // 返回赫夫曼树的根节点
}

// 前序遍历赫夫曼树并生成编码
void preorder(shared_ptr<TreeNode> p, int k, char c) {
    if (p != nullptr) {
        // 生成前缀码
        s[k] = (c == '1') ? '0' : '1';

        // 如果是叶子节点，输出其频率和编码
        if (p->Lnode == nullptr && p->Rnode == nullptr) {
            cout << p->num << ": ";
            for (int j = 0; j <= k; ++j) {
                cout << s[j];
            }
            cout << endl;
        }

        // 递归遍历左右子树
        preorder(p->Lnode, k + 1, '1'); // Lnode 是 shared_ptr<TreeNode>
        preorder(p->Rnode, k + 1, 'r'); // Rnode 是 shared_ptr<TreeNode>
    }
}

int main() {
    int n;
    cout << "请输入节点个数(必须是正整数): ";
    cin >> n;

    vector<int> f(n);
    cout << "请输入节点的频率(以空格分隔): ";
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
    }

    // 初始化树节点并构建赫夫曼树
    init_node(f);
    shared_ptr<TreeNode> head = construct_tree(f);

    // 遍历赫夫曼树并输出前缀码
    preorder(head, 0, '1');

    return 0;
}
