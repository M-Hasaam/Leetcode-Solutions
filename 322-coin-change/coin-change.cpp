class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int size = coins.size();

        reverse(coins.begin(), coins.end());

        using P = pair<int, int>;
        priority_queue<P, vector<P>, greater<>> q;

        vector<bool> visited_amount(amount + 1, false);

        q.emplace(0, amount);
        visited_amount[amount] = true;

        while (!q.empty()) {

            auto [no_of_coins, curr_amount] = q.top();
            q.pop();

            if (curr_amount == 0) {
                return no_of_coins;
            }

            for (int curr_coin : coins) {
                int left_amount = curr_amount - curr_coin;

                if (left_amount >= 0 && !visited_amount[left_amount]) {
                    visited_amount[left_amount] = true;
                    q.emplace(no_of_coins + 1, left_amount);
                }
            }
        }
        return -1;
    }
};