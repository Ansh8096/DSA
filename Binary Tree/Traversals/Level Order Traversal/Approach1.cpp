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
vector<vector<int>> levelOrder(TreeNode* root) {
    if(root == NULL) return {};
    queue<TreeNode*> q;
    vector<vector<int>> ans;
    q.push(root);
    while (!q.empty()){
        int size = q.size();
        vector<int> temp;
        for (int i = 0; i < size; i++){
            temp.push_back(q.front()->val);
            if(q.front()->left) q.push(q.front()->left);
            if(q.front()->right) q.push(q.front()->right);
            q.pop();
        }
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

    vector<vector<int>> result = levelOrder(root);

    // Print result
    cout << "Level Order Traversal:\n";
    for(auto &level : result) {
        for(int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
