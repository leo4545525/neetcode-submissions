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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 用一個 dummy node 建立答案 linked list，cur 指向目前答案尾端。每一輪分別取 l1、l2 當前節點的值，如果其中一條已經走完就當作 0，再加上 上一輪留下來的 carry。總和的個位數 sum % 10 建成新的節點接到答案後面，十位數 sum / 10 留作下一輪的進位。接著 l1、l2 和 cur 都往後移。只要 l1、l2 或 carry 還存在就繼續，最後回傳 dummy.next。
        ListNode dummy(0);
        ListNode* cur = &dummy;
        int carry = 0, digit1, digit2 , sum = 0;
        while(l1 || l2 || carry)
        {
            digit1 = l1 ? l1 -> val : 0;
            digit2 = l2 ? l2 -> val : 0;
            sum = digit1 + digit2 + carry;
            carry = sum / 10;
            cur -> next = new ListNode(sum % 10);
            cur = cur -> next;
            if(l1) l1 = l1 -> next;
            if(l2) l2 = l2 -> next;
        }
        return dummy.next;

    }
};
