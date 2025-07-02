//Bruteforce, 
class Solution {
public:
    int kDistinctChar(string& s, int k) {
        int n = s.length();
        int ans =0;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp.clear();
            for(int j=i;j<n;j++){
                mp[s[j]]++;
                if(mp.size()>k){
                   break;
                }
                int len = j-i+1;
                ans = max(ans,len);
            }
        }
        return ans;
        
    }
};

//optimal with sliding window 
class Solution {
public:
    int kDistinctChar(string& s, int k) {
        int n = s.length();
        int ans =0;
        map<int,int> mp;
        int l=0,r=0;

        while(r<n){
           mp[s[r]]++;
           if(mp.size()>k){
                mp[s[l]]--;
                if(mp[s[l]]==0){
                    mp.erase(s[l]);
                }
                l++;
            }
            int len = r-l+1;
            ans = max(ans,len);
            r++;

        }
        return ans;
        
    }
};

//optimal 
