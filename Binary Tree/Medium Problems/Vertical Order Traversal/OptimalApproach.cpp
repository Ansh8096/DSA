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
vector<vector<int>> verticalTraversal(TreeNode* root) {
    queue<pair<TreeNode*,pair<int,int>>> visited;
    visited.push({root,{0,0}});

    map<int,map<int,vector<int>>> nodes;
    while (!visited.empty()){
       auto obj = visited.front();
       visited.pop();
       TreeNode* node = obj.first;
       int x = obj.second.first;
       int y = obj.second.second;
       // inserting the node in the map correspondibg to his vertical and level...
       nodes[x][y].push_back(node->val);

       if (node->left){
           visited.push({node->left, {x - 1, y + 1}});
       }
       if (node->right){
           visited.push({node->right, {x + 1, y + 1}});
       }
    }
    
    vector<vector<int>> ans;
    for (auto vertical:nodes){
        vector<int>col;
        for(auto level:vertical.second){
            col.insert(col.end(),level.second.begin(),level.second.end());
        }
        ans.push_back(col);
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

    vector<vector<int>> result = verticalTraversal(root);

    // Print result
    cout << "Vertical Traversal: " << endl;
    for(auto itr : result) {
        for (auto val : itr){
            cout << val << " ";
        }
        cout<<endl;
    }

    return 0;
}
