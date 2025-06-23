//Better approach 

//optimal the intution is try to pick elements from both of the array and compare them to see if sorted   

class Solution {
public:
   
    double median(vector<int> &arr1, vector<int> &arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();

        if(n2<n1){
            return median(arr2, arr1);
        }

        int ind1 = (n1+n2+1)/2;

        int l = 0;
        int r = n1;
        int ans1=0, ans2=0;
        while(l<=r){
            int mid = (l+r)/2;

            int l1 =  mid>0 ? arr1[mid-1] : INT_MIN;
            int r1 = mid<n1 ? arr1[mid]: INT_MAX;

            int ind2 = ind1-mid;
            int l2 = (ind2 > 0) ? arr2[ind2-1] : INT_MIN;
            int r2 = (ind2 < n2) ? arr2[ind2]: INT_MAX;
            
           
            if( l1<=r2 && l2<=r1){
                ans1 = max(l1,l2);
                ans2 = min(r1,r2);
                if((n1+n2)%2==0) return ((double)ans1+ans2)/2;
                else return max(l1,l2);
            }
            else if(l1>r2){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
       
        return -1;
    }
};