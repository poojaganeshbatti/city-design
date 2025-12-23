#include <bits/stdc++.h>
using namespace std;

int main() {
    int atm = 3;
    int capacity = 10;

    vector<int> cash = {6, 4, 5};
    vector<int> cost = {4, 3, 5};

    vector<vector<int>> dp(atm + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= atm; i++) {
        for (int j = 0; j <= capacity; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= cost[i-1])
                dp[i][j] = max(dp[i][j],
                               dp[i-1][j - cost[i-1]] + cash[i-1]);
        }
    }

    cout << "Maximum cash optimized: " << dp[atm][capacity];
}
