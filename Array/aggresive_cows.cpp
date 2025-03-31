#include <iostream>
using namespace std;

int countStalls(int space, int a[], int n){
	int cows = 1;
	int dist =0;
	for(int i=1;i<n;i++){
		if(dist+(a[i]-a[i-1])<=space){
			dist += (a[i]-a[i-1]);
		}else{
			dist = 0;
			cows++;
		}
	}
	return cows;
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
		int n ;
		int c;
		cin>>n>>c;
		int a[n];
		int l=INT_MAX ,r=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		
		for(int i=1;i<n;i++){
			if(l>a[i]-a[i-1]){
				l = a[i]-a[i-1];
			}
		}
		r = a[n-1]-a[0];
		cout<<l<<" "<<r<<endl;
		int ans =-1;
		while(l<=r){
			int mid = (l+r)/2;
			int cows = countStalls(mid, a, n);
			cout<<" how many for mid "<<cows<<" "<<mid<<endl;

			if(cows<c){
				ans = mid;
				r = mid-1;
			}else{
				l = mid+1;
			}
			
		}

		cout<<ans<<endl;
		
		
	}

}