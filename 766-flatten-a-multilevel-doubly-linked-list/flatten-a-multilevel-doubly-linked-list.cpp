/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
    Node* rec(Node* head) {
        Node* curr = head;

        while (curr) {
            if (curr->child) {

                Node* child = rec(curr->child);
                curr->child = nullptr;

                Node* next = curr->next;

                curr->next = child;
                child->prev = curr;

                while (child) {
                    if (!child->next)
                        break;
                    child = child->next;
                }

                if (next) {
                    child->next = next;
                    next->prev = child;
                }
            }

            curr = curr->next;
        }

        return head;
    }

public:
    Node* flatten(Node* head) { return rec(head); }
};