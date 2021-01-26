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

//using inorder
class Solution {
public:
    int prev;
    bool flag;
    int minNum = 987654321;

    int getMinimumDifference(TreeNode* root) {
        flag = false;
        inorder(root);

        return minNum;
    }

    void inorder(TreeNode* root)
    {
        if (root == nullptr) {
            return;
        }

        inorder(root->left);

        if (flag == false) {
            flag = true;        // 가장 작은 수를 가진 노드를 찾으면 true
        } else {
            minNum = min(minNum, abs(root->val - prev));
        }

        prev = root->val;
        inorder(root->right);
    }
};