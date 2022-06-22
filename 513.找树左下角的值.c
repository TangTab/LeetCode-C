/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
//递归查找二叉树深度，并将更新深度时的第一个value设置成leftval
int Depth = -1;
int LeftVal = 0;

void dfs(struct TreeNode* root, int depth)
{
    if(NULL == root)
        return;
    if (depth > Depth)
    {
        Depth = depth;
        LeftVal = root->val;
    }
    dfs(root->left, depth + 1);
    dfs(root->right, depth + 1);
    return;
}

int findBottomLeftValue(struct TreeNode* root){
    Depth = -1;
    LeftVal = 0;
    dfs(root, 1);
    return LeftVal;
}