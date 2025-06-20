//Bruteforce n3
//Better n**2,simple just keep multiplying while moving in subarrays
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        for(int i=0;i<n;i++){
            int prod = 1;
            for(int j=i;j<n;j++){
                prod = prod * nums[j];

                ans = max(ans, prod);
            }
        }
        return ans;
    }
};

//Optimal 
//Intution for this comes from observation 
// 1. All positive number , product of all is max;
// 2. Event enegative num same as all positive
// 3. Odd number of negative if we take multiplication from start till tht and after 
// tht till end basically prefix of the negative and suffix of tht our ans is there 
// 4. If zero means we got to exclude this if zero we will make the suffix and prefix as 1
// meaning starting new array after tht

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int ans= INT_MIN;
        int n = nums.size();
        int prefix =1, suffix=1;

        for(int i=0;i<n;i++){
            
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;

            prefix = prefix * nums[i];
            suffix = suffix * nums[n-i-1];

            ans = max(ans,max(prefix,suffix));
        }
        return ans;
        
    }
};