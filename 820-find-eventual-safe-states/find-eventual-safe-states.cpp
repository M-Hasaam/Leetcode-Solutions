// class Solution {
// public:
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

//         vector<int> answer;

//         int n = graph.size();

//         for (int i = 0; i < n; i++) {
//             queue<int> q;
//             int visited[n] = {false};

//             q.push(i);

//             bool isSafe = true;

//             while (!q.empty()) {

//                 int front = q.front();
//                 q.pop();
//                 visited[front] = true;

//                 for (int next : graph[front]) {
//                     if (next != i && !visited[next])
//                         q.push(next);
//                 }
//             }

//             if (isSafe) {
//                 answer.push_back(i);
//             }
//         }
//         return answer;
//     }
// };
class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& state) {
        if (state[node] != 0)
            return state[node] == 2;

        state[node] = 1;

        for (int neighbor : graph[node]) {
            if (state[neighbor] == 2)
                continue;
            if (state[neighbor] == 1)
                return false;
            if (!dfs(neighbor, graph, state))
                return false;
        }

        state[node] = 2;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n, 0);
        vector<int> result;

        for (int i = 0; i < n; ++i) {
            if (dfs(i, graph, state)) {
                result.push_back(i);
            }
        }

        return result;
    }
};
