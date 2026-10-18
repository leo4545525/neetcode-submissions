/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    // Old Node -> New Node
    // 同時用來避免 Graph 有 cycle 時重複 DFS
    unordered_map<Node*, Node*> mp;

    Node* dfs(Node* node) {

        // 1. 如果這個舊 Node 已經複製過
        //    直接回傳它對應的新 Node
        if (mp.count(node))
        {
            return mp[node];
        }

        // 2. 建立目前 Node 的複製品
        Node* copy = new Node(node->val);

        // 3. 先記錄 Old -> New
        //    一定要在 DFS neighbors 前存，避免 cycle 無限遞迴
        mp[node] = copy;

        // 4. 複製所有鄰居
        //    dfs(nei) 會回傳「舊鄰居對應的新 Node」
        for (Node* nei : node->neighbors)
        {
            copy->neighbors.push_back(dfs(nei));
        }

        // 回傳目前 Node 的複製品
        return copy;
    }

    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;

        // DFS 從起點開始複製整張 Graph
        return dfs(node);
    }
};
