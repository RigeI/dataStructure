/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /*
     * @param : the root of tree
     * @param : the target sum
     * @return: two number from tree witch sum is n
     */
    vector<int> twoSum(TreeNode* root, int n)
    {
        vector<int> tmp;
        if (root == NULL)
            return tmp;
        // 查找第一个小于n的节点
        while (root->val >= n) {
            root = root->left;
        }

        // 将该节点记录
        int first = root->val;
        int second = 0;
        ;
        // 修改n
        n = n - first;
        // root非空则继续
        while (root) {
            if (root->val > n) {
                root = root->left;
            } else if (root->val < n) {
                root = root->right;
            } else {
                second = root->val;
                break;
            }
        }

        tmp.push_back(first);
        tmp.push_back(second);
        return tmp;
    }
};
