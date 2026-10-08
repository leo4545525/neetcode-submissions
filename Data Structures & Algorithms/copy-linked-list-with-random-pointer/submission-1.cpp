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
        dic[NULL] = NULL; // 空的複製人就是空
        Node* cur = head;

        while(cur)
        {
            dic[cur] = new Node(cur -> val);
            cur = cur -> next;
        }

        cur = head;

        while(cur)
        {
            dic[cur] -> next = dic[cur -> next];
            dic[cur] -> random = dic[cur -> random];
            cur = cur -> next;
        }

        return dic[head];

    }
};
