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
void traverseAndInsertNode(TreeNode* root, int val){
    if(!root) return;
    TreeNode* curr = root;
    while (curr){
        if(val<curr->val){
            if(!curr->left){
                TreeNode* newNode = new TreeNode(val);
                curr->left = newNode;
                break;
            }
            curr = curr->left;
        }

        else{
            if(!curr->right){
                TreeNode* newNode = new TreeNode(val);
                curr->right = newNode;
                break;
            }
            curr = curr->right;
        }
    }
}
TreeNode* bstFromPreorder_BR(vector<int>& pre) {
    if(pre.empty()) return NULL;

    TreeNode* root = new TreeNode(pre[0]);
    for (int i = 1; i < pre.size(); i++){
        traverseAndInsertNode(root,pre[i]);
    }

    return root;
}
int main(){

    // Preorder traversal of a BST
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    cout << "Preorder Array:\n";
    for(int x : preorder){
        cout << x << " ";
    }
    cout << "\n\n";

    TreeNode* root = bstFromPreorder_BR(preorder);

    cout << "Constructed BST:\n";
    printTree(root);

    return 0;
}
