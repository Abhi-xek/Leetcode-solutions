class Solution {
public:
    vector<int> leftMax(vector<int>& height, int n){
        vector<int>temp(n, 0);
        temp[0] = height[0];

        for(int i = 1; i<n; i++){
            temp[i] = max(temp[i-1], height[i]);
        }

        return temp;
    }

    vector<int> rightMax(vector<int>& height, int n){
        vector<int>temp(n, 0);

        temp[n-1] = height[n-1];

        for(int i = n-2; i>=0; i--){
            temp[i] = max(temp[i+1], height[i]);
        }

        return temp;
    }

    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>left_max = leftMax(height, n);
        vector<int>right_max = rightMax(height, n);
        
        int sum = 0;
        for(int i = 0; i<n; i++){
            int width = min(left_max[i], right_max[i]) - height[i];
            sum += width;
        }

        return sum;
    }
};