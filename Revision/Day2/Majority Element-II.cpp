// BruteForce - O (n**2) two loop nd check counts 
// Better - O(nlogn) + O(n), space - O(2*n) if max size of ans is n
// or we can also use map to store the counts and at the end return the ans from map
// these use extra space so we will optmize is further
class Solution {
public:
    vector<int> majorityElementTwo(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int majorityCount = nums.size()/3;
        int count = 0;
        set<int> ans;
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]){
                count++;
            }
            else{
                count=1;
            }
            if(count>majorityCount){
                    ans.insert(nums[i]);
            }
            
            } 
            vector<int> fin(ans.begin(), ans.end());
            return fin;
    }
};

// Better soln - TC- O(n) and space Complexity - O(n)

class Solution {
public:
    vector<int> majorityElementTwo(vector<int>& nums) {
        map<int,int> mp;
        vector<int> ans;
        int maj = nums.size()/3;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>maj){
                ans.push_back(nums[i]);
                mp[nums[i]]=INT_MIN;
            }
        }
        return ans;
    }
};

or this 



// optimal soln



