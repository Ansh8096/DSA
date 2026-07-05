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
void TraverseInorderAndRecoverBst(TreeNode* root) {
    TreeNode* first = NULL;
    TreeNode* middle = NULL;
    TreeNode* last = NULL;
    TreeNode* curr = root;
    TreeNode* prev = NULL;
    while (curr) {
        if (curr->left == NULL) {
            if (prev) {
                if (curr->val < prev->val) {
                    if (first) {
                        last = curr;
                    } else {
                        first = prev;
                        middle = curr;
                    }
                }
            }
            prev = curr;
            curr = curr->right;
        } else {
            TreeNode* t = curr->left;
            while (t->right && t->right != curr) {
                t = t->right;
            }
            if (t->right == NULL) {
                t->right = curr;
                curr = curr->left;
            } else if (t->right == curr) {
                t->right = NULL;
                if (prev) {
                    if (curr->val < prev->val) {
                        if (first) {
                            last = curr;
                        } else {
                            first = prev;
                            middle = curr;
                        }
                    }
                }
                prev = curr;
                curr = curr->right;
            }
        }
    }
    if (last) swap(first->val, last->val);
    else swap(first->val, middle->val);
}
void recoverTree_OP(TreeNode* root) {
    TraverseInorderAndRecoverBst(root); 
}
int main(){

    // Constructing a corrupted BST:
    //
    // Original BST:
    //
    //          8
    //        /   \
    //       3     10
    //      / \      \
    //     1   6      14
    //        / \     /
    //       4   7   13
    //
    // Swap 4 and 13
    //
    //          8
    //        /   \
    //       3     10
    //      / \      \
    //     1   6      14
    //        / \     /
    //      13   7    4

    TreeNode* root = new TreeNode(8);

    root->left = new TreeNode(3);
    root->right = new TreeNode(10);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);

    // Swapped values
    root->left->right->left = new TreeNode(13);
    root->left->right->right = new TreeNode(7);

    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(4);

    cout << "Corrupted BST:\n";
    printTree(root);

    recoverTree_OP(root);

    cout << "\n\nRecovered BST:\n";
    printTree(root);

    return 0;
}
