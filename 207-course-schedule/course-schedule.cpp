class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        int n = numCourses;
        vector<vector<int>> graph(n);

        for (auto p : prerequisites) {
            graph[p[0]].push_back(p[1]);
        }

        vector<int> state(n, 0);

        function<bool(int)> hasCycle = [&](int curr) {
            if (state[curr] == 1)
                return true;
            if (state[curr] == 2)
                return false;

            state[curr] = 1;

            for (int nxt : graph[curr]) {
                if (hasCycle(nxt))
                    return true;
            }

            state[curr] = 2;

            return false;
        };

        for (int i = 0; i < n; i++)
            if (hasCycle(i))
                return false;

        return true;
    }
};