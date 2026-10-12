/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> p;
        Node* cur = head;
        // Phase 1: 建立每個舊 Node 對應的新 Node
        while(cur)
        {
            p[cur] = new Node(cur -> val);
            cur = cur -> next;
        }
        cur = head;
        // Phase 2: 根據舊 Node 的 next / random，連接對應的新 Node
        while(cur)
        {
            p[cur] -> next = p[cur -> next];
            p[cur] -> random = p[cur -> random];
            cur = cur -> next;
        }
        return p[head];
        
    }
};
