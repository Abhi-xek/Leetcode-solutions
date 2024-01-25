/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int dfs(TreeNode* root, vector<int> hash, int oddCount) {
        if (!root) return 0;
        
        hash[root->val] += 1;
        if (hash[root->val] % 2 == 1) oddCount += 1;
        else oddCount -= 1;

        if (!root->left && !root->right) {
            cout << root->val << endl;
            int res = oddCount <= 1;
            hash[root->val] -= 1;
            if (hash[root->val] % 2 == 1) oddCount += 1;
            else oddCount -= 1;
            return res;
        }
        int leftPaths = dfs(root->left, hash, oddCount);
        int rightPaths = dfs(root->right, hash, oddCount);

        hash[root->val] -= 1;
        if (hash[root->val] % 2 == 1) oddCount += 1;
        else oddCount -= 1;

        return leftPaths + rightPaths;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> hash(10, 0);
        return dfs(root, hash, 0);
    }
};