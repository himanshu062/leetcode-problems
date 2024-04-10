class Solution {
    public int maximumWealth(int[][] accounts) {
        int ans = Integer.MIN_VALUE;
     for(int persons =0;persons<accounts.length;persons++)
     {
        int sum =0;
        for(int account =0;account<accounts[persons].length;account++){
            sum += accounts[persons][account];
        }
        if(sum>ans)
        ans = sum;
     }
     return ans;   
    }
}