class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {

        sort(people.begin(), people.end(),
             [](const vector<int>& A, const vector<int>& B) {
                 return A[0] > B[0] || (A[0] == B[0] && A[1] < B[1]);
             });

        vector<vector<int>> result;
        for (vector<int> P : people) {
            result.insert(result.begin() + P[1], P);
        }

        return result;
    }
};