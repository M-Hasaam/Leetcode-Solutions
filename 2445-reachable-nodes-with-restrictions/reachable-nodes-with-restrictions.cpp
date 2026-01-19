class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges,
                       vector<int>& restricted) {

        unordered_set<int> res;
        res.insert(restricted.begin(), restricted.end());

        vector<vector<int>> graph(n);

        for (const auto& e : edges) {
            if (res.count(e[0]) || res.count(e[1]))
                continue;

            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        queue<int> q;
        vector<bool> visited(n,false);
        q.push(0);
        visited[0] = true;
        int count = 1;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int nxt : graph[curr]) {
                if (visited[nxt])
                    continue;

                visited[nxt] = true;
                count++;
                q.push(nxt);
            }
        }

        return count;
    }
};