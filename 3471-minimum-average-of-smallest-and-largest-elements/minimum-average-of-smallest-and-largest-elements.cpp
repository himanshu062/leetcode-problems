class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        int n = nums.size();
        int left = 0,  right = n-1;
        vector<double> avg;
        sort(nums.begin(),nums.end());
        while(left<right){
            double res = (nums[left] +nums[right]) / 2.0;
            avg.push_back(res);
            left++;
            right--;
            
        }
        double ans = *min_element(avg.begin(),avg.end());
        return ans;
    }
};