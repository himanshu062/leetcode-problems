class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        const int n = arr.size();
        int l = 0, r = n - 1;
        while (l < n - 1 && arr[l + 1] >= arr[l])
            ++l;
        while (r > 0 && arr[r - 1] <= arr[r])
            --r;
        int ans = min(n - 1 - l, r), i = l, j = n - 1;
        while (i >= 0 && j >= r && j > i) {
            if (arr[i] <= arr[j])
                --j;
            else
                --i;
            ans = min(ans, j - i);
        }
        return ans;
    }
};