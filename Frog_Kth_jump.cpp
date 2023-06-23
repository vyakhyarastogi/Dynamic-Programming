#include <cstdlib>
#include <iostream>
#include <limits.h>

#include <vector>
using namespace std;

int solveUsingMem(int index, vector<int> heights, vector<int> &dp, int k)
{
    // base case
    if (index == 0)
    {
        return 0;
    }

    if (dp[index] != -1)
    {
        return dp[index];
    }

    int minSteps = INT_MAX;

    for (int j = 1; j <= k; j++)
    {
        if (index - j >= 0)
        {

            int jump = solveUsingMem(index - j, heights, dp, k) + abs(heights[index] - heights[index - j]);

            minSteps = min(minSteps, jump);
        }
    }
    return dp[index] = minSteps;
}

int solveUsingBottomUp(vector<int> &heights, int n, int k)
{
    vector<int> dp(n + 1, -1);

    // base case
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int minSteps = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                int jump = dp[i - j] + abs(heights[i] - heights[i - j]);
                minSteps = min(minSteps, jump);
            }
        }
        dp[i] = minSteps;
    }
    return dp[n - 1];
}

int solve(int n, vector<int> &heights, int k)
{
    vector<int> dp(n + 1, -1);
    return solveUsingBottomUp(heights, n, k);
}

int main()
{
    vector<int> heights{30, 10, 60, 10, 60, 50};
    int n = heights.size();
    int k = 2;

    vector<int> dp(n + 1, -1);
    cout << "Min energy consumed is:" << solve(n, heights, k);
}