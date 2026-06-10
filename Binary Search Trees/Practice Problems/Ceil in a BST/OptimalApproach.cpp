#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val1){
        val = val1;
        left = NULL;
        right = NULL;
    }
};
int ceilInBst(TreeNode* root, int key){
    TreeNode* curr = root;
    int ans = -1;
    while (curr){
        if(curr->val < key) curr = curr->right;
        else{
            ans = curr->val;
            curr = curr->left;
        }
    }
    return ans;
}
int main(){

    // Constructing BST:
    //
    //          8
    //        /   \
    //       3     10
    //      / \      \
    //     1   6      14
    //        / \     /
    //       4   7   13

    TreeNode* root = new TreeNode(8);

    root->left = new TreeNode(3);
    root->right = new TreeNode(10);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);

    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);

    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);

    int target = 11;

    int result = ceilInBst(root, target);

    if(result == -1){
        cout << "No ceil exists for " << target << endl;
    }
    else{
        cout << "Ceil of " << target
            << " in BST is: "
            << result << endl;
    }

    return 0;
}
