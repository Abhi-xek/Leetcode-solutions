class Solution {
public:
    int maxArea(vector<int>& nums) {
       int i = 0; 
       int j = nums.size()-1;
       int ans = 0;

       while(i<j){
           int width = j-i;
           int height = min(nums[i], nums[j]);
           int area = width * height;

           if(nums[i]>nums[j]) j--;
           else if(nums[i]<nums[j]) i++;
           else i++;

           ans = max (ans, area);
       }

       return ans;
    }
};