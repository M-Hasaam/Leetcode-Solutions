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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {

        ListNode dummy(0, list1);

        ListNode* pre1 = &dummy;
        ListNode* curr1 = list1;
        {
            int i = a;
            while (i > 0) {
                pre1 = curr1;
                curr1 = curr1->next;
                i--;
            }
        }

        ListNode* curr2 = curr1;
        ListNode* pre2 = pre1;
        {

            int j = b;
            while (j > a - 1) {
                pre2 = curr2;
                curr2 = curr2->next;
                j--;
            }

            pre2->next = nullptr;
        }

        {
            pre1->next = list2;

            while (pre1->next) {
                pre1 = pre1->next;
            }

            pre1->next = curr2;
        }

        while (curr1) {
            ListNode* toDel = curr1;
            curr1 = curr1->next;
            delete toDel;
        }

        return dummy.next;
    }
};