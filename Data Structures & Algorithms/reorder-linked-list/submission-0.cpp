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
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head -> next;
        while(fast && fast -> next)
        {
            slow = slow -> next;
            fast = fast -> next -> next; 
        }

        ListNode* pre = nullptr;
        ListNode* cur = slow -> next;
        ListNode* tmp;

        slow -> next = nullptr;

        while(cur)
        {
            tmp = cur -> next;
            cur -> next = pre;
            pre = cur;
            cur = tmp;
        }

        ListNode* first = head;
        ListNode* second = pre;

        while(second)
        {
            ListNode* firstNext = first -> next;
            ListNode* secondNext = second -> next;
            first -> next = second;
            second -> next = firstNext;
            first = firstNext;
            second = secondNext;
        }
        
        
    }
};
