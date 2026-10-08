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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // fast 先走 n+1 步
        // ↓
        // fast 到 NULL
        // ↓
        // slow 就在 target 前一個
        // ↓
        // slow->next = slow->next->next
        ListNode dummy(114514, head);
        ListNode* slow = &dummy;
        ListNode* fast = &dummy;
        for(int i = 0; i < n + 1; i++)
        {
            fast = fast -> next;
        }
        while(fast) //slow 停在「要刪除節點的前一個」。
        {
            fast = fast -> next;
            slow = slow -> next;
        }
        
        slow -> next = slow -> next -> next;
        return dummy.next;

    }
};
