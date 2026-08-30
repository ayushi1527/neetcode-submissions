class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefProd(n);
        vector<int> suffProd(n);

        prefProd[0] = 1;
        suffProd[n-1] = 1;

        for(int i = 1; i<n; i++){
            prefProd[i] = prefProd[i-1]* nums[i-1];
        }

        for(int i = n-2; i>=0; i--){
            suffProd[i] = suffProd[i+1]* nums[i+1];
        }
        vector<int> ans;
        for(int i = 0; i<n; i++){
            int prod = prefProd[i] * suffProd[i];
            ans.push_back(prod);
        }
        return ans;
    }
};
