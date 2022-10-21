class Solution {
private:
    int find(vector<int>& slices, int index, int slicePending, int endIndex, vector<vector<int>>& dp){
        if(index >= endIndex || slicePending == 0)
            return 0;
        
        if(dp[index][slicePending] != -1)
            return dp[index][slicePending];
        
        int take = slices[index] + find(slices, index + 2, slicePending - 1, endIndex, dp);
        int notTake = find(slices, index + 1, slicePending, endIndex, dp);
        
        return dp[index][slicePending] = max(take, notTake);
    
    }
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        
        int k = n / 3;
        vector<vector<int>> dp1(n + 1, vector<int>(k + 1, -1));
        int pizzaSize1 = find(slices, 0, k, n - 1, dp1);
        vector<vector<int>> dp2(n + 1, vector<int>(k + 1, -1));
        int pizzaSize2 = find(slices, 1, k, n, dp2);
        
        return max(pizzaSize1, pizzaSize2);
    }
};