#include <bits/stdc++.h>
using namespace std;


vector<string> threeTop(vector<string> stks, vector<vector<float>> prices){

	vector<string> ans;
	vector<pair<float,string>> avgp;
	int n = prices.size();
	int m = prices[0].size();
	for(int j=0;j<m;j++){
		float currAvg = 0;
		for(int i=0;i<n;i++){
			currAvg+=prices[i][j];
		}
		currAvg /= m;
		avgp.push_back({currAvg,stks[j]});
	}
	sort(avgp.begin(),avgp.end());

	ans.push_back(avgp[avgp.size()-1].second);
	ans.push_back(avgp[avgp.size()-2].second);

	ans.push_back(avgp[avgp.size()-3].second);
	return ans;

}

int main(){

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int m ;
		cin>>m;
		vector<string> stks(n);  // Initialize to hold n strings
        vector<vector<float>> prices(m, vector<float>(n));  // Initialize to hold m rows of n floats each

        for(int i = 0; i < n; i++) {
            cin >> stks[i];
        }

        for(int j = 0; j < m; j++) {
            for(int i = 0; i < n; i++) {
                cin >> prices[j][i];
            }
        }
        
		vector<string> ans = threeTop(stks,prices);
		for(int i=0;i<ans.size();i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
	
}