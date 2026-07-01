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
void printTree(TreeNode* root, int space = 0, int gap = 5){

    if(root == NULL) return;

    // Increase distance between levels
    space += gap;

    // Print right subtree first
    printTree(root->right, space);

    // Print current node
    cout << endl;

    for(int i = gap; i < space; i++){
        cout << " ";
    }

    cout << root->val << "\n";

    // Print left subtree
    printTree(root->left, space);
}
void morrisInorderTraversal(TreeNode* root, vector<int>&inorder){
    TreeNode* curr = root;
    while (curr){
        if(curr->left == NULL){
            inorder.push_back(curr->val);
            curr = curr->right;
        }
        else{
            TreeNode* t = curr->left;
            while (t->right && t->right != curr){
                t = t->right;
            }

            if(t->right == NULL){
                t->right = curr;
                curr = curr->left;
            }
            else if (t->right == curr){
                t->right = NULL;
                inorder.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    
}
bool findTarget_BR(TreeNode* root, int k) {
    vector<int>inorder;
    morrisInorderTraversal(root,inorder);

    int i = 0, j = inorder.size()-1;
    while (i<j)
    {
        if(inorder[i]+inorder[j] < k) i++;
        else if(inorder[i]+inorder[j] > k) j--;
        else return true;
    }
    
    return false;
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

    cout << "BST:\n";
    printTree(root);

    int target = 17;

    cout << "\nTarget = " << target << endl;

    if(findTarget_BR(root, target))
        cout << "Pair exists.\n";
    else
        cout << "Pair does not exist.\n";

    return 0;
}
