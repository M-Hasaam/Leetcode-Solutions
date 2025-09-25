class Solution { // 349ms
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for (int i = 1; i < n; i++) {

            if (intervals[i][0] <= ans.back()[1]) {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }

        return ans;

    }
};

class Solution_349ms { // 349ms
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<vector<int>> ans;

        int n = intervals.size();

        for (int i = 0; i < n; i++) {

            // int start = -1, end = -1;

            int start_i = intervals[i][0], end_i = intervals[i][1];

            if (start_i == -1 || end_i == -1)
                continue;

            for (int j = i + 1; j < n; j++) {
                int start_j = intervals[j][0], end_j = intervals[j][1];

                if (start_j == -1 || end_j == -1)
                    continue;

                if ((start_i <= start_j && start_j <= end_i) ||
                    (start_i <= end_j && end_j <= end_i) ||
                    (start_j <= start_i && start_i <= end_j) ||
                    (start_j <= end_i && end_i <= end_j)) {

                    start_i = min(start_i, start_j);
                    end_i = max(end_i, end_j);

                    intervals[j][0] = -1;
                    intervals[j][1] = -1;

                    j = i;
                }
            }

            ans.push_back({start_i, end_i});
        }

        return ans;
    }
};
