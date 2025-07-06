class Solution {

    bool dfs(string curr, string target, unordered_set<string>& visited,
             double& ans, double product) {

        if (curr == target) {
            ans = product;
            return true;
        }

        visited.insert(curr);

        for (pair<string, double> B_V : Graph[curr]) {

            string neighbor = B_V.first;
            double val = B_V.second;

            if (!visited.count(neighbor)) {
                if (dfs(neighbor, target, visited, ans, product * val))
                    return true;
            }
        }

        ans = -1.0;
        return false;
    }

    unordered_map<string, vector<pair<string, double>>> Graph;

public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {

        int n = equations.size();

        // filling Graph
        // "A" -> { "B" , A/B }
        // "B" -> { "A" , B/A }

        for (int i = 0; i < n; i++) {
            vector<string> A_B = equations[i];

            string A = A_B[0], B = A_B[1];
            double val = values[i];

            Graph[A].push_back({B, val});
            Graph[B].push_back({A, 1 / val});
        }

        int n2 = queries.size();
        vector<double> answer(n2, 0);

        for (int i = 0; i < n2; i++) {

            vector<string> A_B = queries[i];

            string A = A_B[0], B = A_B[1];

            if (Graph.count(A)) {
                if (A == B)
                    answer[i] = 1.0;
                else {
                    unordered_set<string> visited;

                    // recursive dfs
                    //  A/D = A/B * B/C * C/D
                    dfs(A, B, visited, answer[i], 1.0);
                }
            } else
                answer[i] = -1.0;
        }

        return answer;
    }
};