// Bruteforce O(n**2)
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                 if(nums[i]> 2*nums[j]){
                    ans++;
                 }
            }
        }
        return ans;
    }
};

//Optimal count inversion logic ( merge logic just dont sort) o(nlogn) and space o(n)
class Solution {
public:
    void merge(vector<int>& nums, int l, int mid, int r, int& ans) {
        int left  = mid - l + 1;
        int right = r - mid;

        vector<int> a(left);
        vector<int> b(right);

        for (int i = 0; i < left; ++i)  a[i] = nums[l + i];
        for (int j = 0; j < right; ++j) b[j] = nums[mid + 1 + j];

        // count reverse pairs
        int i = 0, j = 0;
        while (i < left && j < right) {
            if (static_cast<long long>(a[i]) > 2LL * b[j]) {
                ans += left - i;      // every remaining a[i..] forms a pair with b[j]
                ++j;
            } else {
                ++i;
            }
        }

        // merge step
        i = j = 0;
        int k = l;                    // write back into the correct window
        while (i < left && j < right)
            nums[k++] = (a[i] <= b[j]) ? a[i++] : b[j++];
        while (i < left)  nums[k++] = a[i++];
        while (j < right) nums[k++] = b[j++];
    }

    void countPairs(vector<int>& nums, int l, int r, int& ans) {
        if (l >= r) return;
        int mid = l + (r - l) / 2;
        countPairs(nums, l, mid, ans);
        countPairs(nums, mid + 1, r, ans);
        merge(nums, l, mid, r, ans);
    }

    int reversePairs(vector<int>& nums) {
        int ans = 0;
        countPairs(nums, 0, static_cast<int>(nums.size()) - 1, ans);
        return ans;
    }
};
