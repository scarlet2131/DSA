//Optimal if O(n) + O(n), this second n will never run because the array says it always
// has a majority element
// Moore's voting algo, the intution is assume ele to be majority if count is 
// 0 and keep incrementing the count if got tht ele and decrease if somehting else
// if there is a mjority ele you will always have it at the end as majority el

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele= nums[0];
        int count =0;

        for(int i=0;i<nums.size();i++){
            if(count==0){
                ele = nums[i];
            }

            if(nums[i]==ele){
                count++;
            }else{
                count--;
            }
            
        }
        count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ele){
                count++;
            }
        }
        if(count>nums.size()/2) return ele;
        return -1;
    }
};