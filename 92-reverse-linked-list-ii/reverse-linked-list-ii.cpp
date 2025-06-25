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
    ListNode* reverse(ListNode* start, ListNode* end) {

        ListNode *pre = (end ? end->next : nullptr), *curr = start,
                 *next = (start ? start->next : nullptr);

        ListNode* end_next = pre;
        while (curr != end_next) {
            curr->next = pre;

            pre = curr;
            curr = next;
            if (next)
                next = next->next;
        }

        return pre;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right)
            return head;

        ListNode* dummy = new ListNode(0, head);

        ListNode* start = dummy;
        for (int i = 0; i < left - 1; i++)
            start = start->next;
        ListNode* end = start;
        for (int i = left - 1; i < right; i++)
            end = end->next;

        start->next = reverse(start->next, end);

        ListNode* ans = dummy->next;
        delete dummy;

        return ans;
    }
};