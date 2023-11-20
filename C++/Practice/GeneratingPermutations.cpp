#include <bits/stdc++.h>

using namespace std;

void permute(int idx, vector<int>& nums) {
        if (idx == nums.size()) {
            for (int i: nums) cout << i << " ";
            cout << "\n";
            return;
        }

        for (int i=idx; i<nums.size(); i++) {
            swap(nums[idx],nums[i]);
            permute(idx+1,nums);
            swap(nums[idx],nums[i]);
        }

}

int main () {
    vector<int> v {1, 2, 3};
    permute(0,v);
}