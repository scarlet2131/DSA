class Solution {  
public:
    bool isValid(string s) {
        //your code goes here
        int minOpen =0, maxOpen=0;
        for(int i=0;i<s.length();i++){
           if(s[i]=='('){   
                minOpen++;
                maxOpen++;
           }
           else if(s[i]==')'){
                minOpen--;
                maxOpen--;
           }else{
                minOpen--; //closing
                maxOpen++; //opening
           }

            if(maxOpen<0) return false;

            if(minOpen<0) minOpen =0;

        
        }
        
        return minOpen==0; 
    }
};