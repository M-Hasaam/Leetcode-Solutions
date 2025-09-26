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
    ListNode* sortList(ListNode* head) { // Merge sort

        int n = getLength(head);

        ListNode dummy(0, head);

        for (int step = 1; step < n; step *= 2) {

            ListNode* curr = dummy.next;
            ListNode* prev = &dummy;

            while (curr) {
                ListNode* left = curr;
                ListNode* right = split(left, step);

                curr = split(right, step);

                prev->next = merge(left, right);
                while (prev->next)
                    prev = prev->next;
            }
        }

        return dummy.next;
    }

private:
    int getLength(ListNode* head) {
        int count = 0;
        for (; head; head = head->next)
            count++;
        return count;
    }

    ListNode* split(ListNode* head, int step) {
        while (--step && head)
            head = head->next;

        if (head) {
            ListNode* second = head->next;
            head->next = nullptr;

            return second;
        }

        return nullptr;
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {

        ListNode dummy;

        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }

            tail = tail->next;
        }

        tail->next = (l1 ? l1 : l2);

        return dummy.next;
    }
};

class Solution_Bubble_Sort {
public:
    ListNode* sortList(ListNode* head) { // Bubble sort

        for (ListNode* i = head; i; i = i->next) {
            for (ListNode* j = i->next; j; j = j->next) {

                if (i->val > j->val) {
                    swap(i->val, j->val);
                }
            }
        }

        return head;
    }
};