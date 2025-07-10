class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();

        vector<bool> visited(n, false);

        int c = 0;

        for (int i = 0; i < n; i++) {

            if (!visited[i]) {
                c++;

                queue<int> q;

                q.push(i);

                while (!q.empty()) {

                    int node = q.front();
                    q.pop();

                    visited[node] = true;

                    for (int j = 0; j < n; j++) {
                        if (j != i && !visited[j]) {
                            if (isConnected[node][j])
                                q.push(j);
                        }
                    }
                }
            }
        }

        return c;
    }
};