
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    vector<int> wt(n), p(n);

    cout << "Enter weight and profit of each item:\n";
    for(int i = 0; i < n; i++) {
        cin >> wt[i] >> p[i];
    }

    cout << "Enter knapsack capacity: ";
    cin >> W;

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for(int i = 1; i <= n; i++) {
        for(int w = 0; w <= W; w++) {

            if(wt[i-1] <= w) {
                dp[i][w] = max(p[i-1] + dp[i-1][w-wt[i-1]],
                               dp[i-1][w]);
            }
            else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    cout << "Maximum Profit = " << dp[n][W];

    cout << "\nSelected Items: ";
    int w = W;

    for(int i = n; i >= 1; i--) {
        if(dp[i][w] != dp[i-1][w]) {
            cout << i << " ";
            w -= wt[i-1];
        }
    }

    return 0;
    
}
