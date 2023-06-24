#include <iostream>
#include <vector>
using namespace std;

int solveUsingMem(int index, vector<int> &arr, vector<int> &dp)
{
    // base case
    if (index == 0)
    {
        return arr[0];
    }
    if (index < 0)
    {
        return 0;
    }

    int pick = arr[index] + solveUsingMem(index - 2, arr, dp);

    int notPick = 0 + solveUsingMem(index - 1, arr, dp);

    return dp[index] = max(pick, notPick);
}

int solveUsingTab(vector<int> &arr, int n)
{
    vector<int> dp(n, -1);
    dp[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        int pick = arr[i];
        if (i > 1)
        {
            pick += dp[i - 2];
        }
        int nonPick = 0 + dp[i - 1];

        dp[i] = max(pick, nonPick);
    }

    return dp[n - 1];
}

int spaceOptimisation(int n, vector<int> &arr)
{
    int prev = arr[0];
    int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        int pick = arr[i];
        if (i > 1)
        {
            pick += prev2;
        }
        int notPick = 0 + prev;

        int curr = max(pick, notPick);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int solve(int n, vector<int> &arr)
{
    vector<int> dp(n, -1);
    return solveUsingMem(n - 1, arr, dp);
}

int main()
{
    vector<int> arr{2, 1, 4, 9};
    int n = arr.size();
    cout << "maximum sum of non adjacent element is:" << solve(n, arr) << endl;
}
