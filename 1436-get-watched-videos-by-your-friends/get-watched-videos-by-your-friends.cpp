class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos,
                                          vector<vector<int>>& friends, int id,
                                          int level) {

        int n = friends.size();
        vector<bool> visited(n, false);
        queue<int> q;

        q.push(id);
        visited[id] = true;

        int currLevel = 0;

        while (!q.empty() && currLevel < level) {
            int sz = q.size();
            while (sz--) {
                int u = q.front();
                q.pop();
                for (int v : friends[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
            currLevel++;
        }

        unordered_map<string, int> freq;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (const string& v : watchedVideos[u]) {
                freq[v]++;
            }
        }

        vector<string> ans;
        ans.reserve(freq.size());

        for (auto& p : freq) {
            ans.push_back(p.first);
        }

        sort(ans.begin(), ans.end(), [&](const string& a, const string& b) {
            int fa = freq[a], fb = freq[b];
            if (fa != fb) {
                return fa < fb;
            }
            return a < b;
        });

        return ans;
    }
};
