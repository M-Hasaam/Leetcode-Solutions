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

        stack<int> S1, S2;

        for (ListNode* t = l1; t; t = t->next)
            S1.push(t->val);
        for (ListNode* t = l2; t; t = t->next)
            S2.push(t->val);

        ListNode* head = nullptr;
        int carry = 0;

        while (!S1.empty() || !S2.empty() || carry != 0) {
            int sum = carry;
            if (!S1.empty()) {
                sum += S1.top();
                S1.pop();
            }
            if (!S2.empty()) {
                sum += S2.top();
                S2.pop();
            }

            ListNode* newNode = new ListNode(sum % 10, head);
            head = newNode;

            carry = sum / 10;
        }

        return head;
    }
};