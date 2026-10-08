/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
typedef ListNode* Node;

class Solution {
public:
    Node reverseList(Node head) {
        Node pre = NULL;
        Node cur = head;
        Node tmp ;
        while(cur)
        {
            tmp = cur -> next;
            cur -> next = pre;
            pre = cur;
            cur = tmp;
        }

        return pre;
        
    }
};
