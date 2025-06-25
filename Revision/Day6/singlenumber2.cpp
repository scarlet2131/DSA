
//intution is becuase all the number appears 3 times means tht if we count all the
// set bit for a particular bit in 32 bit integer thern if it is mutiple of 3 means
// in our ans it is not set if it not a mutiple of 3 means it is set
class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int ans =0;
        for(int i=0;i<32;i++){
             int count =0;
             for(int j=0;j<nums.size();j++){
                 if(nums[j] & (1<<i)){
                        count++;
                 }
             }
             if(count%3==1){
                ans = ans | (1<<i);
             }

        }
        return ans;
    }
};