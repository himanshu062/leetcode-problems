class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        const int n = nums.size();
        unordered_map<int, int> freq;
        freq.reserve(n);
        long long ans = 0, cnt = 0;

        for (int r = 0, l = 0; r < n; r++) {
            const int x = nums[r];
            cnt += freq[x]++;
            while (cnt >= k) {
                ans += (n - r);
                cnt -= --freq[nums[l]];
                l++;
            }
        }
        return ans;
    }
};