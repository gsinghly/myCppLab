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
        ListNode start(-1);
        ListNode *temp = &start;
        int carry = 0;
        while(l1 || l2 || carry){
            auto x = l1 ? l1->val : 0;
            auto y = l2 ? l2->val : 0;
            int val = x+y+carry;
            temp->next = new ListNode(val%10);
            carry = val/10;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
            temp = temp->next; 
        }
        return start.next;
    }
};