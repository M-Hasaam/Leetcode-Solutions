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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        ListNode* dummy = new ListNode(0, head);
        ListNode* pre = dummy;

        while (temp) {

            bool dup = false;
            while (temp->next && temp->next->val == temp->val) {
                dup = true;

                ListNode* del = temp->next;
                temp->next = temp->next->next;
                delete del;
            }

            if (dup) {
                ListNode* del = temp;

                pre->next = temp->next;
                temp = temp->next;

                delete del;
            } else {
                pre = temp;
                temp = temp->next;
            }

            // if(temp)
            // temp = temp->next;
        }

        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};