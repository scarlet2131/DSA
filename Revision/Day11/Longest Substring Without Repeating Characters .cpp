class Solution{
  public:
    int longestNonRepeatingSubstring(string& s){
        //your code goes here
        // sliding window
        int n = s.length();
        int l=0,r=0, ans=0;
        vector<int> hash(255,-1);

        while(r<n){
            if(hash[s[r]]!=-1){
                //here we are keeping track of window lets suppose l occured before 
                // but at an index less than l then the value of l will stay as l
                l =  max(hash[s[r]]+1, l);
            }

            int len = r-l+1;
            ans = max(ans, len);

            hash[s[r]]=r;
            r++;


        }
        return ans;
    }
};