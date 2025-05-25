#include <iostream>
#include <vector>
#include <memory>  // ��������ָ��

using namespace std;

// �������ڵ�ṹ
struct TreeNode {
    int num;            // �ڵ��Ƶ��
    shared_ptr<TreeNode> Lnode;    // ������������ָ�룩
    shared_ptr<TreeNode> Rnode;    // ������������ָ�룩

    // ���캯����ʼ���ڵ�
    TreeNode(int val) : num(val), Lnode(nullptr), Rnode(nullptr) {}
};

// ȫ�ֱ���
vector<shared_ptr<TreeNode>> fp;  // �������ڵ㣨ʹ������ָ�룩
char s[2 * 13];  // �洢ǰ׺�루���鳤�ȿ��Ը���ʵ����Ҫ������

// ��ʼ�����ڵ�
void init_node(const vector<int>& f) {
    for (int i = 0; i < f.size(); ++i) {
        fp.push_back(make_shared<TreeNode>(f[i])); // ����Ҷ�ӽڵ�
    }
}

// ������������ N-n ������뵽�������������
void sort(vector<shared_ptr<TreeNode>>& array) {
    for (size_t i = 0; i < array.size() - 1; ++i) {
        for (size_t j = i + 1; j < array.size(); ++j) {
            if (array[i]->num > array[j]->num) {
                swap(array[i], array[j]);
            }
        }
    }
}

// �����շ�����
shared_ptr<TreeNode> construct_tree(const vector<int>& f) {
    int n = f.size();
    vector<shared_ptr<TreeNode>> nodes = fp;

    for (int i = 1; i < n; ++i) {
        // ����һ���µĸ��ڵ�
        shared_ptr<TreeNode> pt = make_shared<TreeNode>(nodes[i - 1]->num + nodes[i]->num);
        pt->Lnode = nodes[i - 1];  // ������
        pt->Rnode = nodes[i];      // ������

        // �滻��ԭ���Ľڵ�
        nodes[i] = pt;
        sort(nodes);  // ��������
    }

    return nodes[n - 1]; // ���غշ������ĸ��ڵ�
}

// ǰ������շ����������ɱ���
void preorder(shared_ptr<TreeNode> p, int k, char c) {
    if (p != nullptr) {
        // ����ǰ׺��
        s[k] = (c == '1') ? '0' : '1';

        // �����Ҷ�ӽڵ㣬�����Ƶ�ʺͱ���
        if (p->Lnode == nullptr && p->Rnode == nullptr) {
            cout << p->num << ": ";
            for (int j = 0; j <= k; ++j) {
                cout << s[j];
            }
            cout << endl;
        }

        // �ݹ������������
        preorder(p->Lnode, k + 1, '1'); // Lnode �� shared_ptr<TreeNode>
        preorder(p->Rnode, k + 1, 'r'); // Rnode �� shared_ptr<TreeNode>
    }
}

int main() {
    int n;
    cout << "������ڵ����(������������): ";
    cin >> n;

    vector<int> f(n);
    cout << "������ڵ��Ƶ��(�Կո�ָ�): ";
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
    }

    // ��ʼ�����ڵ㲢�����շ�����
    init_node(f);
    shared_ptr<TreeNode> head = construct_tree(f);

    // �����շ����������ǰ׺��
    preorder(head, 0, '1');

    return 0;
}
