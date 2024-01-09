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
public:
   void solve(TreeNode* root, vector<int>& s) {
    if (root == NULL) {
        return;
    }
    
    if (root->left == NULL && root->right == NULL) {
        s.push_back(root->val);
        return;
    }

    solve(root->left, s);
    solve(root->right, s);
}

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> ans1;
    vector<int> ans2;

    solve(root1, ans1);
    solve(root2, ans2);

    // Sort the vectors before comparing to check if they have the same elements
    // sort(ans1.begin(), ans1.end());
    // sort(ans2.begin(), ans2.end());

    return ans1 == ans2;
}
};