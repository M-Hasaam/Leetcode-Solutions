class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last(26, 0);
        vector<bool> used(26, false);

        for (int i = 0; i < s.size(); i++)
            last[s[i] - 'a'] = i;

        string result;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (used[ch - 'a'])
                continue;

            while (!result.empty() && result.back() > ch && last[result.back() - 'a'] > i) {
                used[result.back() - 'a'] = false;
                result.pop_back();
            }

            result.push_back(ch);
            used[ch - 'a'] = true;
        }

        return result;
    }
};
