class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();

        // -1 (empty) || 1 or 0 (two possible opposite color)
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {

            if (color[i] == -1) { // search from it if it is not reached
                // true for ( First BFS Search ) && ( Disconnected Graph )

                queue<int> q;

                q.push(i); // BFS

                color[i] = 0; // initial color is 0

                while (!q.empty()) {

                    int node = q.front();
                    q.pop();

                    for (int neighbor : graph[node]) {
                        if (color[neighbor] == -1) {

                            // neighbors should have opposite colors
                            // for 0 -> 1 for 1 -> 0
                            color[neighbor] = 1 - color[node];

                            q.push(neighbor);

                        } else if (color[neighbor] == color[node])
                            return false;
                    }
                }
            }
        }

        return true;
    }
};