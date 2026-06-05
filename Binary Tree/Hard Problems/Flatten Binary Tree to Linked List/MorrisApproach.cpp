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
void flattenToLL_morris(TreeNode* root){
    TreeNode* curr = root;
    while (curr){
        if(curr->left != NULL){
            TreeNode* temp = curr->left;
            while (temp->right)
            {
                temp = temp->right;
            }
            temp->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }   
}
int main(){
    
    // Constructing tree:-
    //
    //         3
    //        / \
    //       9   20
    //          /  \
    //         15   7

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    cout << "Original Tree:\n";
    printTree(root);

    flattenToLL_morris(root);

    cout << "\n\nFlattened Linked List:\n";

    TreeNode* curr = root;

    while(curr){
        cout << curr->val;

        if(curr->right){
            cout << " -> ";
        }

        curr = curr->right;
    }

    cout << endl;

 
    
    return 0;
}
