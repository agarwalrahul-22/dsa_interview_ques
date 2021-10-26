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
    int isB(TreeNode* node){
        if(node==nullptr) return 0;
        
        int l = isB(node->left)+1;
        int r = isB(node->right)+1;
        
        return max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr) return true;
        
        int l = isB(root->left);
        int r = isB(root->right);   
        
        int il = isBalanced(root->left);
        int ir = isBalanced(root->right);
        
        if(abs(r-l)<=1 && ir && il) return true;
        
        return false;
    }
};
