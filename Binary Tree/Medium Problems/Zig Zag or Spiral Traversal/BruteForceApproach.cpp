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
vector<vector<int>> zigzagLevelOrder_BR(TreeNode* root) {
    if(root == NULL) return {};
    int flag = 0;
    vector<vector<int>>ans;
    queue<TreeNode*>q;
    q.push(root);
    while (!q.empty()){
        int size = q.size();
        vector<int>temp;
        while (size>0){
            TreeNode* top = q.front();
            q.pop();
            temp.push_back(top->val);
            if(top->left != NULL) q.push(top->left);
            if(top->right != NULL) q.push(top->right);
            size--;
        }

        if(flag == 1){
            reverse(temp.begin(),temp.end());
        }
        flag = (flag==0)? 1 : 0;
        ans.push_back(temp);
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
    
    vector<vector<int>> ans = zigzagLevelOrder_BR(root);
    for (auto itt: ans){
        for ( auto itr : itt){
            cout<<itr<<" ";
        }
        cout<<endl;
    }

    return 0;
}
