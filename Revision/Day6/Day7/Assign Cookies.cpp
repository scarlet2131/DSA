//Simple think greedy, to get the best solution
class Solution{    
    public:
    int findMaximumCookieStudents(vector<int>& student, vector<int>& cookie){
        sort(student.begin(),student.end() );
        sort(cookie.begin(),cookie.end());
        int l=0,r=0;
        while(l<student.size() && r<cookie.size()){
                if(student[l]<=cookie[r]){
                    l++;
                }
                r++;

        }
        return l;
    }
};