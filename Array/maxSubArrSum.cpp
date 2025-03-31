#include "stdc++.h"
using namespace  std;

int main(){
	int n ;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int maxSum=0;
	for(int i=0;i<n;i++){
		for(int j=1;j<n;j++){
			int currSum =0;
			for(int k=i;k<j;k++){
				currSum+=arr[k];
			}
			maxSum = maxSum<currSum?currSum: maxSum;
		}
	}
	cout<<"ans : " <<maxSum<<endl;
}



int findLargestElement(vector<int>& nums) {
    int maxElement = INT_MIN;
    for (int i=0; i<nums.size(); i++) {
        if (nums[i] > maxElement) {
            maxElement = nums[i];
        }
    }
    return maxElement;
}


def move_zeroes_optimized(nums):
    last_non_zero_found_at = 0
    for i in range(len(nums)):
        if nums[i] != 0:
            nums[last_non_zero_found_at], nums[i] = nums[i], nums[last_non_zero_found_at]
            last_non_zero_found_at += 1

nums = [0, 1, 0, 3, 12]
move_zeroes_optimized(nums)
print("Array after moving zeroes (Optimized):", nums)
