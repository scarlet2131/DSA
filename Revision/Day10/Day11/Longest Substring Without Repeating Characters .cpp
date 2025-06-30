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