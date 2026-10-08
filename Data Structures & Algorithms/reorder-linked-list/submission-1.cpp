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
        ListNode* fast = head -> next; //先走一步

        //1.找中點 
        while(fast && fast -> next)
        {
            slow = slow -> next;
            fast = fast -> next -> next; 
        }
        //even 1 2 3 4 切成 1 2,3 4
        //odd 1 2 3 4 5 切成 1 2 3 ,4 5

        ListNode* pre = nullptr;
        ListNode* cur = slow -> next;
        ListNode* tmp;

        slow -> next = nullptr;

        //2.反轉
        while(cur)
        {
            tmp = cur -> next;
            cur -> next = pre;
            pre = cur;
            cur = tmp;
        }
        //even 1 2 3 4 反轉成 1 2,4 3
        //odd 1 2 3 4 5 反轉成 1 2 3 ,5 4
        ListNode* first = head;
        ListNode* second = pre;

        //3.依照輸出連結
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
