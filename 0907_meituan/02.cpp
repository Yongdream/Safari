#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 定义树的节点结构
struct TreeNode {
    int soncount = 0;               // 子节点数量
    vector<int> children;           // 子节点列表
};

void dfs(int node, int parent, vector<TreeNode>& tree) {
    // 遍历所有子节点
    for (int child : tree[node].children) {
        if (child != parent) {  // 防止回到父节点
            dfs(child, node, tree); // 递归DFS子节点
            tree[node].soncount += 1; // 计算直接子节点数量
        }
    }
}

int count_similar_nodes(int n, vector<TreeNode>& tree) {
    unordered_map<int, int> son_count_map;

    // 统计所有节点的子节点数量
    for (int i = 1; i <= n; ++i) {
        son_count_map[tree[i].soncount]++;
    }

    // 计算相似节点对数
    int similar_pairs = 0;
    for (auto& entry : son_count_map) {
        int count = entry.second;
        if (count > 1) {
            similar_pairs += (count * (count - 1)) / 2; // C(count, 2) 组合数公式
        }
    }
    return similar_pairs;
}

int main() {
    int T; // 数据组数
    cin >> T;

    while (T--) {
        int n; // 节点数量
        cin >> n;

        vector<TreeNode> tree(n + 1); // 树节点从1开始编号

        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            tree[u].children.push_back(v);
            tree[v].children.push_back(u);
        }

        // 从根节点1开始进行DFS遍历计算子节点数量
        dfs(1, -1, tree);

        // 输出相似节点对数
        cout << count_similar_nodes(n, tree) << endl;
    }

    return 0;
}
