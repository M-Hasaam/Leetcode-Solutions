class Solution {
public:
    string decodeString(string s) {

        stack<string> st;

        for (char ch : s) {

            if (ch == '[') {
                st.push(string(1, ch));
            } else if (ch == ']') {

                string subst;

                while (st.top() != "[") {
                    subst = st.top() + subst;
                    st.pop();
                }

                st.pop(); // [

                int reps = stoi(st.top()); // number
                st.pop();

                string ans;
                for (int i = 0; i < reps; i++)
                    ans += subst;

                st.push(ans);

            } else if (isdigit(ch)) {
                if (!st.empty() && isdigit(st.top()[0])) {
                    string top = st.top();
                    st.pop();

                    top += ch;
                    st.push(top);
                } else {
                    st.push(string(1, ch));
                }
            } else if (isalpha(ch)) {
                st.push(string(1, ch));
            }
        }

        string result;

        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }

        return result;
    }
};