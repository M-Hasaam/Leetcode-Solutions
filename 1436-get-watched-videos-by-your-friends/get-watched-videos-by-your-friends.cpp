class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos,
                                          vector<vector<int>>& friends, int id,
                                          int level) {
        int n = friends.size();

        queue<int> q;
        vector<bool> visited(n, false);

        q.push(id);
        visited[id] = true;

        int k = 0;

        unordered_map<string, int> M;

        while (!q.empty()) {

            int size = q.size();

            for (int i = 0; i < size; i++) {

                int curr = q.front();
                q.pop();

                if (k == level) {
                    for (string V : watchedVideos[curr]) {
                        M[V]++;
                    }
                    continue;
                }

                for (int f : friends[curr]) {
                    if (visited[f])
                        continue;
                    visited[f] = true;
                    q.push(f);
                }
            }

            k++;
        }

        vector<pair<string, int>> vids;
        for (auto& p : M) {
            vids.push_back(p);
        }

        sort(vids.begin(), vids.end(), [](auto& a, auto& b) {
            if (a.second != b.second)
                return a.second < b.second;
            return a.first < b.first;
        });

        vector<string> ans;
        for (auto& p : vids) {
            ans.push_back(p.first);
        }

        return ans;
    }
};