
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack01(vector<pair<int, int>>& arr, int w, int n,
               vector<vector<int>>& dp)
{
    // Base case
    if(w == 0 || n == 0)
    {
        return 0;
    }

    // Return the already calculated answer
    if(dp[n][w] != -1)
    {
        return dp[n][w];
    }

    int wt = arr[n - 1].first;
    int val = arr[n - 1].second;

    // If the object fits in the knapsack
    if(wt <= w)
    {
        // Include the object
        int include = val + knapsack01(arr, w - wt, n - 1, dp);

        // Exclude the object
        int exclude = knapsack01(arr, w, n - 1, dp);

        // Store and return the maximum profit
        dp[n][w] = max(include, exclude);
    }
    else
    {
        // Object does not fit, so exclude it
        dp[n][w] = knapsack01(arr, w, n - 1, dp);
    }

    return dp[n][w];
}

int main()
{
    int knapsackSize, n;

    cout << "Enter the size of the Knapsack: ";
    cin >> knapsackSize;

    cout << "Enter the number of objects: ";
    cin >> n;

    vector<pair<int, int>> arr(n);

    cout << "Enter weight and profit of each object:\n";

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }

    // n + 1 rows and knapsackSize + 1 columns
    vector<vector<int>> dp(n + 1,
                           vector<int>(knapsackSize + 1, -1));

    cout << "Maximum profit is: "
         << knapsack01(arr, knapsackSize, n, dp) << endl;

    return 0;
}
