class Solution {
public:
    int maxSum(vector<int>& nums) {

        int mn = INT_MIN;
        unordered_map<int, bool> um;

        int sum = 0;

        for (auto& val : nums) {
            if (!um.count(val)) {
                if (val >= 0) {
                    sum += val;
                } else {
                    mn = max(mn, val);
                }
            }

            um[val] = true;
        }
        if (sum == 0 and !um.count(0)) {
            return mn;
        }

        return sum;
    }
};