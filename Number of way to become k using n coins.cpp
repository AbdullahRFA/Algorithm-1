#include <bits/stdc++.h>
using namespace std;

const int MAX_K = 100000;
const int MAX_COINS = 110;

int dp[MAX_COINS][MAX_K];

int coinChangeWays(vector<int>& coins, int n, int amount) {
    if (amount == 0) return 1;
    if (n <= 0 || amount < 0) return 0;
    if (dp[n][amount] != -1) return dp[n][amount];
    int nibona=coinChangeWays(coins,n,amount-coins[n-1]);
    int nibo=coinChangeWays(coins,n-1,amount);
    //int ways = coinChangeWays(coins, n - 1, amount) + coinChangeWays(coins, n, amount - coins[n - 1]);
    int ways=nibo+nibona;

    return dp[n][amount] = ways;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    memset(dp, -1, sizeof(dp));

    int totalWays = coinChangeWays(coins, n, k);
    cout << "Total ways to make " << k << " using given coins: " << totalWays << endl;

    return 0;
}
