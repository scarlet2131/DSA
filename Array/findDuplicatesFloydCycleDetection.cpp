class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast =nums[0];
        int n = nums.size();
        do{
            slow = nums[slow] ;
            fast = nums[nums[fast]];
        }while(slow!=fast);
        fast = nums[0];
        cout<<slow<<endl;
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;

    }

};