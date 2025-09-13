class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;

        for (string t : tokens) {

            if (t == "+" || t == "-" || t == "*" || t == "/") {
                string N1 = st.top();
                st.pop();
                string N2 = st.top();
                st.pop();

                if (t == "+") {
                    st.push(to_string(stoi(N2) + stoi(N1)));
                } else if (t == "-") {
                    st.push(to_string(stoi(N2) - stoi(N1)));
                } else if (t == "*") {
                    st.push(to_string(stoi(N2) * stoi(N1)));

                } else if (t == "/") {
                    st.push(to_string(stoi(N2) / stoi(N1)));
                }

            } else {
                st.push(t);
            }
        }

        return stoi(st.top());
    }
};