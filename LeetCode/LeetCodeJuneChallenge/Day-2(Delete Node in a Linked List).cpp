/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Time:  O(1)
// Space: O(1)
class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node && node->next){
            auto tt = node->next;
            node->val = node->next->val;
            node->next = node->next->next;
            delete tt;
        }
    }
};
