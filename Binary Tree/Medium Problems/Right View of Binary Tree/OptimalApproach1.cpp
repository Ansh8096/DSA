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
vector<int>rightViewOfBinaryTreeIterative_OP1(TreeNode* root){
    if(root == NULL) return {};
    queue<pair<TreeNode*,int>> visited;
    map<int,int> mpp;
    visited.push({root,0});

    while (!visited.empty()){
        auto poped = visited.front();
        visited.pop();
        TreeNode* node = poped.first;   
        int x = poped.second; // vertical level...
        mpp[x] = node->val; // updating the level nodes... 
        if(node->left) visited.push({node->left,x+1});
        if(node->right) visited.push({node->right,x+1});

    }
    
    vector<int>ans;
    for(auto itt: mpp){
        ans.push_back(itt.second);
    }

    return ans;
}
int main(){

    // Constructing tree:
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

    vector<int> result = rightViewOfBinaryTreeIterative_OP1(root);

    // Print result
    cout << "Right view of Binary Tree: " << endl;
    for(auto val : result) {
        cout << val << " ";
    }

    return 0;
}
