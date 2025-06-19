//Bruteforce is just sort the array o(nlogn)
//Better is store the count of 0,1 and 2 and then reun through the array andf make it tht

//Optimal soln
class Solution {
public:
    void sortZeroOneTwo(vector<int>& nums) {
        int low=0,mid=0,high=nums.size()-1;

        //Dutch flag algo , only mid to high is unsorted half 
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            }
            else if(nums[mid]==1){
                mid++;
            }else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
        return ;
    }
};