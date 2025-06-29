/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

struct Node {
    string val;
    Node *next = nullptr, *back = nullptr;
    Node(string v) { val = v; }
};

class BrowserHistory {
public:
    Node* curr = nullptr;

    BrowserHistory(string homepage) { curr = new Node(homepage); }

    void visit(string url) {
        Node* next = curr->next;

        // while (next) {
        //     Node* del = next;
        //     next = next->next;

        //     delete del;
        // }

        curr->next = new Node(url);
        curr->next->back = curr;

        curr = curr->next;
    }

    string back(int steps) {
        while (curr->back && steps > 0) {
            curr = curr->back;
            steps--;
        }
        return curr->val;
    }

    string forward(int steps) {
        while (curr->next && steps > 0) {
            curr = curr->next;
            steps--;
        }
        return curr->val;
    }
};

// 28 ms
// class BrowserHistory {
// public:
//     vector<string> history;
//     int curr;

//     BrowserHistory(string homepage) {

//         history.push_back(homepage);
//         curr = 0;
//     }

//     void visit(string url) {

//         history.erase(history.begin() + curr + 1, history.end());

//         history.push_back(url);
//         curr++;
//     }

//     string back(int steps) {
//         curr = max(0, curr - steps);
//         return history[curr];
//     }

//     string forward(int steps) {
//         curr = min((int)history.size() - 1, steps + curr);
//         return history[curr];
//     }
// };
