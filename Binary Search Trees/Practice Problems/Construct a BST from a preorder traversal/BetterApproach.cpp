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
TreeNode* traverseAndbuildBst(vector<int>&pre, int preSt, int preEnd, vector<int>&in, int inSt, int inEnd, unordered_map<int,int>& mpp){
    if(inSt>inEnd || preSt>preEnd) return NULL;

    TreeNode* newNode = new TreeNode(pre[preSt]);
    int numsIdx = mpp[pre[preSt]];
    int numsLeft = numsIdx - inSt;

    newNode->left = traverseAndbuildBst(pre,preSt+1,preSt+numsLeft,in,inSt,numsIdx-1,mpp);
    newNode->right = traverseAndbuildBst(pre,preSt+numsLeft+1,preEnd,in,numsIdx+1,inEnd,mpp);

    return newNode;
}
TreeNode* bstFromPreorder_BT(vector<int>& pre) {
    if(pre.empty()) return NULL;
    vector<int> in = pre;
    sort(in.begin(),in.end());

    unordered_map<int,int> mpp;
    int n = pre.size();
    for(int i=0;i<n;i++) mpp[in[i]] = i;

    return traverseAndbuildBst(pre,0,n-1,in,0,n-1,mpp);
}
int main(){

    // Preorder traversal of a BST
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    cout << "Preorder Array:\n";
    for(int x : preorder){
        cout << x << " ";
    }
    cout << "\n\n";

    TreeNode* root = bstFromPreorder_BT(preorder);

    cout << "Constructed BST:\n";
    printTree(root);

    return 0;
}
