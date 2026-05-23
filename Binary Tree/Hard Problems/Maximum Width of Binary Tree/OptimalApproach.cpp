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
int widthOfBinaryTree(TreeNode* root) {
    if(!root) return 0;
    int ans = 0;
    queue<pair<TreeNode*,long long>>q; 
    q.push({root,0});
    while (!q.empty())
    {
        ans = max(ans,(int)(q.back().second - q.front().second + 1));
        int size = q.size();
        long long  min = q.front().second;
        while (size>0){
            TreeNode* node = q.front().first;
            int idx = q.front().second;
            q.pop();
            if(node->left) q.push({node->left, ((idx-min)*2) + 1});
            if(node->right) q.push({node->right, ((idx-min)*2) + 2});
            size--;
        }
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

    cout<<widthOfBinaryTree(root);
    
    return 0;
}
