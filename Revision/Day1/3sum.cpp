
// Bruteforce is simple 3 loop and condition check TC - O(n**3)

// Better soln TC - O(n**2 * M), if M is the size of set

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        set<vector<int>> st;
        int n = nums.size();

        for(int i=0;i<n;i++){
            set<int> temp;
            
            for(int j=i+1;j<n;j++){
                int num = -(nums[i]+nums[j]);
                if(temp.find(num) != temp.end()){
                    vector<int> t1 =  {num, nums[i], nums[j]};
                    sort(t1.begin(), t1.end());
                    st.insert(t1);
                }
                temp.insert(nums[j]);
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};


//Optimal soln TC - O(nlogn) +O(n**2)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i >0 && nums[i]==nums[i-1]) continue;
            int left = i+1;
            int right = n-1;
           
            while(left<right){
                
                int k = nums[i] + nums[left] + nums[right];
                if(k<0){
                    left++;
                }else if(k>0){
                    right--;
                }else{
                    vector<int> temp = {nums[i], nums[left], nums[right]};
                    ans.push_back(temp);

                    left++;
                    right--;

                    while(left<right && nums[left]==nums[left-1]  ) left++;
                    while(left<right && nums[right]==nums[right+1] && left<right ) right--;
                   
                }

            }
        }
        return ans;
    }
};

