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