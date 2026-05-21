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
void printTree(TreeNode* root, int space = 0, int gap = 6) {
    if(root == NULL) return;

    space += gap;

    printTree(root->right, space);

    cout << endl;
    for(int i = gap; i < space; i++)
        cout << " ";
    cout << root->val << "\n";

    printTree(root->left, space);
}
bool traverseToNode(TreeNode* root, int val, vector<int>&ans){
    if(root == NULL){
        return false;
    }
    if(root->val == val){
        ans.push_back(val);
        return true;
    }
    ans.push_back(root->val);
    int l = traverseToNode(root->left,val,ans);
    if(l) return true;
    
    int r = traverseToNode(root->right,val,ans);
    if(r) return true;

    ans.pop_back();
    return false;
}
vector<int> rootToNode(TreeNode* root, int val){
    vector<int>ans;
    traverseToNode(root,val,ans);
    return ans;
}
int main(){

    // Constructing tree:-
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int>ans = rootToNode(root,5);

    for (int i = 0; i < ans.size(); i++) cout<<ans[i]<<" ";
    

    return 0;
}
