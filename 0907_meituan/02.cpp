#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// �������Ľڵ�ṹ
struct TreeNode {
    int soncount = 0;               // �ӽڵ�����
    vector<int> children;           // �ӽڵ��б�
};

void dfs(int node, int parent, vector<TreeNode>& tree) {
    // ���������ӽڵ�
    for (int child : tree[node].children) {
        if (child != parent) {  // ��ֹ�ص����ڵ�
            dfs(child, node, tree); // �ݹ�DFS�ӽڵ�
            tree[node].soncount += 1; // ����ֱ���ӽڵ�����
        }
    }
}

int count_similar_nodes(int n, vector<TreeNode>& tree) {
    unordered_map<int, int> son_count_map;

    // ͳ�����нڵ���ӽڵ�����
    for (int i = 1; i <= n; ++i) {
        son_count_map[tree[i].soncount]++;
    }

    // �������ƽڵ����
    int similar_pairs = 0;
    for (auto& entry : son_count_map) {
        int count = entry.second;
        if (count > 1) {
            similar_pairs += (count * (count - 1)) / 2; // C(count, 2) �������ʽ
        }
    }
    return similar_pairs;
}

int main() {
    int T; // ��������
    cin >> T;

    while (T--) {
        int n; // �ڵ�����
        cin >> n;

        vector<TreeNode> tree(n + 1); // ���ڵ��1��ʼ���

        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            tree[u].children.push_back(v);
            tree[v].children.push_back(u);
        }

        // �Ӹ��ڵ�1��ʼ����DFS���������ӽڵ�����
        dfs(1, -1, tree);

        // ������ƽڵ����
        cout << count_similar_nodes(n, tree) << endl;
    }

    return 0;
}
