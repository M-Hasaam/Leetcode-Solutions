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
    ListNode* partition(ListNode* head, int x) {

        ListNode* LowerHead = new ListNode(0);
        ListNode* GreaterHead = new ListNode(0);

        ListNode* Lower = LowerHead;
        ListNode* Greater = GreaterHead;

        while (head) {
            if (head->val < x) {
                Lower->next = head;
                Lower = Lower->next;
            } else {
                Greater->next = head;
                Greater = Greater->next;
            }

            head = head->next;
        }

        Greater->next = nullptr;
        Lower->next = GreaterHead->next;

        ListNode* answer = LowerHead->next;

        delete LowerHead;
        delete GreaterHead;

        return answer;
    }
};