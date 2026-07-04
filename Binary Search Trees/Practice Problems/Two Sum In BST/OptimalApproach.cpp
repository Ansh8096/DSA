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
class BstNextIterator{
    private:
    stack<TreeNode*>stk;
    void pushAllLeft(TreeNode* root){
        TreeNode* node = root;
        while (node){
            stk.push(node);
            node = node->left;
        }
    }

    public:
    BstNextIterator(TreeNode* root){
        pushAllLeft(root);
    }

    int next(){
        TreeNode* node = stk.top();
        stk.pop();
        if(node->right) pushAllLeft(node->right);
        return node->val;
    }

    bool hasNext(){
        return !stk.empty();
    }
};
class BstPrevIterator{
    private:
    stack<TreeNode*>stk;
    void pushAllRight(TreeNode* root){
        TreeNode* node = root;
        while (node){
            stk.push(node);
            node = node->right;
        }
    }

    public:
    BstPrevIterator(TreeNode* root){
        pushAllRight(root);
    }
    
    int prev(){
        TreeNode* node = stk.top();
        stk.pop();
        if(node->left) pushAllRight(node->left);
        return node->val;
    }

    bool hasPrev(){
        return !stk.empty();
    }
};
bool findTarget_OP(TreeNode* root, int k) {
    if(!root) return false;
    BstNextIterator bstNext = BstNextIterator(root);
    BstPrevIterator bstPrev = BstPrevIterator(root);
    int val1 = bstNext.next();
    int val2 = bstPrev.prev();
    while (val1<val2){
        if(val1+val2 < k) {
            if(bstNext.hasNext())val1 = bstNext.next();
            else val1 = -1;
        }
        else if(val1+val2 > k) {
            if(bstPrev.hasPrev())val2 = bstPrev.prev();
            else val2 = -1;
        }
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

    int target = 19;

    cout << "\nTarget = " << target << endl;

    if(findTarget_OP(root, target))
        cout << "Pair exists.\n";
    else
        cout << "Pair does not exist.\n";

    return 0;
}
