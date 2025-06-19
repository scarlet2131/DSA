// Bruteforce will be O(n**3), two loop to fix start and end and move with third loop
//to take sum
//Better will be carrying running sum and then find max difference o(n**2)
//Kadane's algo, O(n)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = INT_MIN;
        int sum = 0;

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>maxsum){
                maxsum = sum;
            }
            if(sum<0){
                sum = 0;
            }
            
        }
        return maxsum;
    }
};