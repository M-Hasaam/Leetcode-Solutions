class Solution {
public:
    string removeKdigits(string num, int k) {

        string st;

        for (char n : num) {
            while (k > 0 && !st.empty() && st.back() > n) {
                st.pop_back();
                k--;
            }
            st.push_back(n);
        }

        while (k > 0 && !st.empty()) {
            st.pop_back();
            k--;
        }

        int pos = 0;
        while (pos < st.size() && st[pos] == '0')
            pos++;

        string ans = st.substr(pos);
        return ans.empty() ? "0" : ans;
    }
};

// class Solution {
// public:
//     string removeKdigits(string num, int k) {

//         using P = pair<char, int>;
//         struct cmp {
//             bool operator()(const P& a, const P& b) const {
//                 if (a.first == b.first)
//                     return a.second > b.second;
//                 return a.first < b.first;
//             }
//         };

//         priority_queue<P, vector<P>, cmp> pq;

//         for (int i = 0; i < num.size(); i++)
//             pq.push({num[i], i});

//         for (int i = 0; i < k; i++) {
//             auto [top, top_i] = pq.top();
//             pq.pop();

//             num.erase(num.find(top), 1);
//         }

//         return num;
//     }
// };