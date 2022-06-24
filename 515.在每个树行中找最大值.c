/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_SIZE 10000

int* largestValues(struct TreeNode* root, int* returnSize)
{
    struct TreeNode **queue = (struct TreeNode**)malloc(sizeof(struct TreeNode *)*MAX_SIZE);
    memset(queue, 0, sizeof(struct TreeNode *)*MAX_SIZE);
    int *res = (int *)malloc(sizeof(int) * MAX_SIZE);
    memset(res, 0, sizeof(int)*MAX_SIZE);
    if(root == NULL)
    {
        *returnSize = 0;
        return NULL;
    }
    int tail = 0, head = 0;
    int level = 0;
    queue[tail++] = root;
    int maxValue = INT_MIN;
    while(tail != head)
    {
        int cnt = tail - head;
        for(int i = 0; i < cnt; i++)
        {
            struct TreeNode *node  = queue[head++];

            if(node->val >= maxValue)
            {
                res[level] = node->val;
                maxValue = node->val;
            }
            if(node->left)
            {
                queue[tail++] = node->left;
            }
            if(node->right)
            {
                queue[tail++] = node->right;
            }
        }
        level++;
        maxValue = INT_MIN;
    }
    *returnSize = level;
    return res;
}

