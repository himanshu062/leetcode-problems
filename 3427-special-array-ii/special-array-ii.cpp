class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums,
                                vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> pref(n);
        pref[0] = 1;
        for (int i = 1; i < n; i++) {
            if ((nums[i] & 1) != (nums[i - 1] & 1)) {
                pref[i] = pref[i - 1] + 1;
            } else {
                pref[i] = 1;
            }
        }
        vector<bool> ans;
        for (const auto& it : queries) {
            int s = it[0], e = it[1];
            int len = e - s + 1;
            ans.push_back(pref[e] >= len);
        }
        return ans;
    }
};