#include <bits/stdc++.h>
using namespace std;

// Example: minimize cash replenishment cost
int minReplenishCost(vector<int>& cost, int n) {
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i] = min(dp[i], dp[i-j] + cost[j-1]);
        }
    }
    return dp[n];
}

int main() {
    vector<int> replenishmentCost = {2, 5, 3, 6}; // cost for 1,2,3,4 ATMs
    int totalATMs = 4;
    cout << "Minimum cash replenishment cost: " << minReplenishCost(replenishmentCost, totalATMs) << "\n";
}
