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
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> dic;
        Node* cur = head;
        Node* copy;

        while(cur)
        {
            dic[cur] = new Node(cur -> val);
            cur = cur -> next;
        }

        cur = head;

        while(cur)
        {
            copy = dic[cur];
            copy -> next = dic[cur -> next];
            copy -> random = dic[cur -> random];
            cur = cur -> next;
            // dic[cur] -> next = dic[cur -> next];
            // dic[cur] -> random = dic[cur -> random];
            // cur = cur -> next;
        }

        return dic[head];

    }
};
