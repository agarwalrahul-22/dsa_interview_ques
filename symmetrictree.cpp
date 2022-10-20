class Solution {
public:
    bool is(TreeNode* a, TreeNode* b){
        if(a==nullptr && b==nullptr) return true;
        else if(a==nullptr || b==nullptr || a->val!=b->val) return false;
        
        
        if(is(a->left,b->right) && is(a->right,b->left)) return true;
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root->left==nullptr && root->right==nullptr) return true;
        // if(root->left->val != root->right->val) return false;
        if(is(root->left,root->right)) return true;
        
        return false;
    }
};
