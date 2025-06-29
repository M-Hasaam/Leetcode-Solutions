class BrowserHistory {
public:
    vector<string> history;
    int curr;

    BrowserHistory(string homepage) {

        history.push_back(homepage);
        curr = 0;
    }

    void visit(string url) {

        history.erase(history.begin() + curr + 1, history.end());

        history.push_back(url);
        curr++;
    }

    string back(int steps) {
        curr = max(0, curr - steps);
        return history[curr];
    }

    string forward(int steps) {
        curr = min((int)history.size() - 1, steps + curr);
        return history[curr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */