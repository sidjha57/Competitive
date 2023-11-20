// https://leetcode.com/problems/two-sum/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findIndex(int low, int high, vector<vector<int>> &sortedNums, int target)
{
    int mid;
    while (low < high)
    {
        mid = (low + high) / 2;
        if (sortedNums[mid][0] == target)
        {
            return sortedNums[mid][1];
        }
        if (sortedNums[mid][0] > target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
vector<int> twoSum(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<vector<int>> sortedNums(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        sortedNums[i] = {nums[i], i};
    }
    sort(sortedNums.begin(), sortedNums.end());
    for (int i = 0; i < n; i++)
    {
        int foundIndex = findIndex(i + 1, n, sortedNums, target - sortedNums[i][0]);
        if (foundIndex != -1)
        {
            return {i, foundIndex};
        }
    }
    return {0, 0};
}


int main () {
    vector<int> nums = {2,7,9};
    
    twoSum(nums, 9);
    cout << "complted";
}