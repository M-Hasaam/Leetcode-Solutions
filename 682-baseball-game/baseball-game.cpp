class Solution {
public:
    int calPoints(vector<string>& operations) {

        stack<int> s;

        for (const string& op : operations) {

            if (op == "+") {
                int pre_1 = s.top();
                s.pop();
                int sum = pre_1 + s.top();

                s.push(pre_1);
                s.push(sum);

            } else if (op == "D") {
                s.push(s.top() * 2);
            } else if (op == "C") {
                s.pop();
            } else if (!op.empty()) {
                s.push(stoi(op));
            }
        }

        int answer = 0;
        while (!s.empty()) {
            answer += s.top();
            s.pop();
        }

        return answer;
    }
};