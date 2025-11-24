class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {

        unordered_set<string> have(supplies.begin(), supplies.end());
        unordered_map<string, vector<string>> need;
        unordered_map<string, int> indegree;

        for (int i = 0; i < recipes.size(); i++) {
            indegree[recipes[i]] = ingredients[i].size();
            for (string ing : ingredients[i]) {
                need[ing].push_back(recipes[i]);
            }
        }

        queue<string> q;

        for (string sup : supplies)
            q.push(sup);

        vector<string> ans;
        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            for (string rec : need[curr]) {
                if (--indegree[rec] == 0) {
                    ans.push_back(rec);
                    q.push(rec);
                }
            }
        }

        return ans;
    }
};