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
    ListNode* mergeTwo(ListNode* a, ListNode* b) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (a && b) {
            if (a->val < b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }

            tail = tail->next;
        }

        tail->next = a ? a : b;

        return dummy.next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        while(lists.size() > 1)
        {
            vector<ListNode*> merged;
            for(int i = 0; i < lists.size(); i += 2)
            {        
                ListNode* l1 = lists[i];
                ListNode* l2;
                if(i + 1 < lists.size())
                    l2 = lists[i + 1];
                else
                    l2 = NULL;
                merged.push_back(mergeTwo(l1, l2));
            }

            lists = merged;
        }

        return lists[0];


        
    }
};
