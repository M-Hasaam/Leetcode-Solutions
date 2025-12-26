class Solution {
    using pq = priority_queue<string, vector<string>, greater<string>>;

    unordered_map<string, pq> graph;
    vector<string> answer;

    void dfs(string airport) {


        while (!graph[airport].empty()) {

            string next_airport = graph[airport].top();
            graph[airport].pop();

            dfs(next_airport);
        }
        answer.push_back(airport);

    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {

        for (auto ticket : tickets) {
            graph[ticket[0]].push(ticket[1]);
        }

        dfs("JFK");

        reverse(answer.begin(), answer.end());

        return answer;
    }
};