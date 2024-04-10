class Solution {
    public int findNumbers(int[] nums) {
      int n = nums.length;
      int count =0;
      for(int num:nums){
        if(even(num) )
        count++;
      }  
      return count;
    }
    static boolean even(int num){
        int numberofDigits = digits(num);
        return numberofDigits %2 == 0;
    }
    static int digits(int num){
        if(num<0)
        num*= -1;
        if(num ==0)
        return 1;
        // return (int)(Math.log(num))+1;
        int count =0;
        while(num>0){
            count++;
            num/=10;
        }
        return count;

    }
}