class Solution {

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp;

        for (string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());

            mp[key].push_back(s);
        }

        vector<vector<string>> ans;

        for (auto& p : mp)
            ans.push_back(p.second);

        return ans;
    }
};

class Solution_TLE {
    bool isAnagram(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 == s2;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<bool> visited(n, false);

        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                vector<string> V;
                V.push_back(strs[i]);
                for (int j = i + 1; j < n; j++) {
                    if (isAnagram(strs[i], strs[j])) {
                        visited[j] = true;
                        V.push_back(strs[j]);
                    }
                }

                ans.push_back(V);
            }
        }

        return ans;
    }
};