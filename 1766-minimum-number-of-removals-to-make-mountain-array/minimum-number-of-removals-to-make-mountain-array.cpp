class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        const vector<int> l = lengthOfLIS(nums);
        const vector<int> r = reversed(lengthOfLIS(reversed(nums)));
        int maxMountainSeq = 0;

        for (int i = 0; i < nums.size(); ++i)
            if (l[i] > 1 && r[i] > 1)
                maxMountainSeq = max(maxMountainSeq, l[i] + r[i] - 1);

        return nums.size() - maxMountainSeq;
    }

private:
    vector<int> lengthOfLIS(vector<int> nums) {
        vector<int> tails;
        vector<int> dp;
        for (const int num : nums) {
            if (tails.empty() || num > tails.back())
                tails.push_back(num);
            else
                tails[firstGreaterEqual(tails, num)] = num;
            dp.push_back(tails.size());
        }
        return dp;
    }

    int firstGreaterEqual(const vector<int>& A, int target) {
        return ranges::lower_bound(A, target) - A.begin();
    }

    vector<int> reversed(const vector<int>& nums) {
        return {nums.rbegin(), nums.rend()};
    }
};