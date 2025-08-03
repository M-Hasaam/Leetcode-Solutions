// class Solution {
// public:
//     int n;
//     vector<bool> keys_founded;

//     int maxCandies(vector<int>& status, vector<int>& candies,
//                    vector<vector<int>>& keys,
//                    vector<vector<int>>& containedBoxes,
//                    vector<int>& initialBoxes) {

//         int n = status.size();

//         keys_founded.assign(n - 1, false);

//         auto dfs[&]()->int {}
//     }
// };

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<  int>>& containedBoxes,
                   vector<int>& initialBoxes) {
        
        int n = status.size();

        vector<bool> hasBox(n, false);   
        vector<bool> canOpen(n, false);  
        vector<bool> used(n, false);       
        
        queue<int> q;

        for (int box : initialBoxes) {
            hasBox[box] = true;
            if (status[box] == 1) {
                q.push(box);
                used[box] = true;
            }
        }

        int totalCandies = 0;

        while (!q.empty()) {
            int box = q.front(); q.pop();
            totalCandies += candies[box];

            // adding keys found in this box
            for (int key : keys[box]) {
                if (!status[key]) {
                    status[key] = 1;
                    if (hasBox[key] && !used[key]) {
                        q.push(key);
                        used[key] = true;
                    }
                }
            }

            // adding new boxes found inside this box
            for (int inner : containedBoxes[box]) {
                hasBox[inner] = true;
                if (status[inner] == 1 && !used[inner]) {
                    q.push(inner);
                    used[inner] = true;
                }
            }
        }

        return totalCandies;
    }
};
