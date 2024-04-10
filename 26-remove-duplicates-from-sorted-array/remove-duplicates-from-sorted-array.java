class Solution {
    public int removeDuplicates(int[] nums) {
     int n = nums.length;
     int a =0;
     for(int i =0;i<n;i++)
     {
        if(nums[a] != nums[i])
        a++;
        nums[a] = nums[i];
     } 
     return a+1;  
    }
}