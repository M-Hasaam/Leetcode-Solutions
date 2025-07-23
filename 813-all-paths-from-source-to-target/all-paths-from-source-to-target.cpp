class Solution {
public:
    void dfs(const vector<vector<int>>& graph, int I, vector<int>& pre_path,
             vector<vector<int>>& answer, const int& N_1) {

        pre_path.push_back(I);

        if (I == N_1) {
            answer.push_back(pre_path);
        }

        for (int next : graph[I]) {
            dfs(graph, next, pre_path, answer, N_1);
        }
        pre_path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        vector<vector<int>> answer;

        vector<int> path;
        path.reserve(graph.size());

        dfs(graph, 0, path, answer, graph.size() - 1);

        return answer;
    }
};