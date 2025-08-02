// class Solution {
// public:
//     bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

//         vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false));

//         for (const vector<int>& dislike : dislikes) {
//             int a = dislike[0], b = dislike[1];

//             graph[a][b] = graph[b][a] = true;
//         }

//         vector<bool> dislikes_by_1(n + 1, false);

//         for (bool A : graph[1]) {
//             dislikes_by_1[A] = true;
//         }

//         for (int i = 1; i <= n; i++) {
//             if (dislikes_by_1[i]) {
//                 for (int j = i + 1; j <= n; j++) {
//                     if (dislikes_by_1[i] && graph[i][j])
//                         return false;
//                 }
//             } else {
//                 for (int j = i + 1; j <= n; j++) {
//                     if (!dislikes_by_1[i] && graph[i][j])
//                         return false;
//                 }
//             }
//         }

//         return true;
//     }
// };

// By using
// Graph Bipartition using BFS Two-Coloring
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        vector<vector<int>> graph(n + 1);

        for (const auto& A_B : dislikes) {
            graph[A_B[0]].push_back(A_B[1]);
            graph[A_B[1]].push_back(A_B[0]);
        }

        vector<int> color(n + 1, 0); // 1 , -1 two colors (0 for none)

        for (int i = 1; i <= n; i++) {

            if (color[i])
                continue;

            queue<int> q;
            q.push(i);
            color[i] = 1;

            while (!q.empty()) {

                int curr = q.front();
                q.pop();

                for (int neighbor : graph[curr]) {

                    if (!color[neighbor]) {
                        color[neighbor] = -1 * color[curr];

                        q.push(neighbor);
                    } else {
                        if (color[neighbor] == color[curr])
                            return false;
                    }
                }
            }
        }

        return true;
    }
};