//Intution is because there cant be any more than 1 queen in a column so we can
// start our recusion with just omne corrdinate and for all the rows in tht coln
// we will check if there is a queen in tht or not 

// BECAUSE PRUNING IS HAPPEING SO VERY IMPOSSIBLE TO Find the time complexity
// still we can assume o(n^n)

class Solution {
public:
     bool isSafe(vector<string>& temp, int row, int col, int n){
        // row safety 
        for(int i=col-1;i>=0;i--){
            if(temp[row][i]=='Q') return false;
        }
        
        //diag safety
        for(int j=col-1,i=row-1;j>=0 && i>=0;j--,i--){
            if(temp[i][j]=='Q') return false;
        }
        for(int j=col-1,i=row+1;j>=0 && i<n;j--,i++){
             if(temp[i][j]=='Q') return false;
        }

        return true;
    }
    void nQueens(int n, vector<string>& temp, int col, vector<vector<string>>& mat){
        if(col>=n){
            mat.push_back(temp);
            return;
        }
        for(int i=0;i<n;i++){
            if(isSafe(temp, i,col,n)){
                temp[i][col] = 'Q';
                nQueens(n,temp,col+1,mat);
                temp[i][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> temp;
        string str = "";
        for(int i=0;i<n;i++){
            str+='.';
        }
        for(int i=0;i<n;i++){
            temp.push_back(str);
        }
        vector<vector<string>> mat;
        nQueens(n,temp,0,mat);
        

        return mat;
    }
};
