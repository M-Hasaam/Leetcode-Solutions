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

                    for (int j = 0; j < n; j++) {
                        if (!visited[j] && isConnected[node][j]) {
                            q.push(j);
                            visited[j] = true;
                        }
                    }
                }
            }
        }

        return c;
    }
};