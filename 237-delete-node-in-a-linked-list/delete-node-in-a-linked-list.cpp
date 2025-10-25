/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {

        ListNode* pre = nullptr;
        while (node->next) {
            pre = node;
            node->val = node->next->val;
            node = node->next;
        }

        delete pre->next;
        pre->next = nullptr;
    }
};