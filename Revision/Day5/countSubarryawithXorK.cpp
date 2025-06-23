// briteforce is n**3, create all subarrya 
// better instead of storing them try to take running xor and it is n**2

// Optiomal is just a logic like 2 sum , x^y = k , if we know xor till curr element then
// x^y = xr(xor till current element), xor by y both the sides x = xr ^ y, so if we have to basically
// if we have already got this x int the map or not 

class Solution{
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
       int n = nums.size();
       map<int,int> mp;
       int xr =0;
       mp[xr]++; // no xor by now 
       int count=0;
       for(int i=0;i<n;i++){
            xr = xr ^ nums[i];
            int y = xr ^ k;

            if(mp.find(y)!=mp.end()){
                count+= mp[y];
            }
            mp[xr]++;
       }
       
       return count;
    }
};