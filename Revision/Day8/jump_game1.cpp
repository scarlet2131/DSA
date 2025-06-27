class Solution {
public:
    bool canJump(vector<int>& nums) {
        //your code goes here
        int n = nums.size();
        int maxIndex = 0;
        for(int i=0;i<n;i++){
            //if maximndex till this point hasnt moved ahead of curr means somewhere there was 0 which affected
             
            if(i>maxIndex){
                return false;
            }

            maxIndex = max(maxIndex,  i+ nums[i]);
        }

        return true;

    }
};