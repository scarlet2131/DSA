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

// or this 

class Solution {
public:
    vector<int> majorityElementTwo(vector<int>& nums) {
        map<int,int> mp;
        vector<int> ans;
        int maj = nums.size()/3+1;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            if(mp[nums[i]]==maj){
                ans.push_back(nums[i]);
                mp[nums[i]]=INT_MIN;
            }
            if(ans.size()==2) break;
        }
        return ans;
    }
};

// optimal soln - remove the extra space of map , in worst case it will O(n)


class Solution {
public:
    vector<int> majorityElementTwo(vector<int>& nums) {
       int ele1 =0,ele2=0;
       int count1=0,count2=0;
       
       int n = nums.size();

       for(int i=0;i<n;i++){
            if(count1==0 and nums[i]!=ele2){
                ele1 = nums[i];
                count1=1;
            }
            else if(count2==0 and nums[i]!=ele1){
                ele2 = nums[i];
                count2 = 1;
            }
            else if(ele1==nums[i]) count1++;
            else if(ele2==nums[i]) count2++;
            else{
                count1--;
                count2--;
            }
       }
       vector<int> ans;

       //check for answer
       count1=0;
       count2=0;
       for(int i=0;i<n;i++){
            if(nums[i]==ele1) count1++;
            else if(nums[i]==ele2) count2++;
       }
       if(count1> n/3) ans.push_back(ele1);
       if(count2> n/3) ans. push_back(ele2);
       
       return ans;
    }
};




