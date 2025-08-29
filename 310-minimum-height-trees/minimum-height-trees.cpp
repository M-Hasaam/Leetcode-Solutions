class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1)
            return {0};

        int MIN = INT_MAX;

        vector<vector<int>> graph(n);
        vector<int> degree(n, 0);

        for (const auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }

        vector<int> ans;
        queue<int> q;

        for (int i = 0; i < n; i++)
            if (degree[i] == 1)
                q.push(i);

        while (!q.empty()) {

            int size = q.size();

            ans.clear();

            for (int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();
                
                ans.push_back(curr);

                for (int nei : graph[curr]) {
                    degree[nei]--;
                    if (degree[nei] == 1)
                        q.push(nei);
                }
            }
        }

        return ans;
    }
};

class Solution_67_70_TLE {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
if (n == 1) return {0};

        int MIN = INT_MAX;

        vector<vector<int>> graph(n);

        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> heights(n, 0);

        for (int i = 0; i < n; i++) {

            queue<int> q;
            q.push(i);

            vector<bool> visited(n, false);
            visited[i] = true;

            int depth = -1;

            while (!q.empty()) {
                int size = q.size();

                for (int j = 0; j < size; j++) {
                    int curr = q.front();
                    q.pop();

                    for (int neighbor : graph[curr]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }

                 depth ++;
            }

            MIN = min(MIN,  depth );

            heights[i] =  depth ;
        }

        vector<int> ans;

        for (int i = 0; i < n; i++)
            if (heights[i] == MIN)
                ans.push_back(i);

        return ans;
    }
};