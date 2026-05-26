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
void mapParentNodes(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent){
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()){
        int size = q.size();
        for (int i = 0; i < size; i++){
            auto node = q.front();
            q.pop();
            if(node->left) {
                q.push(node->left);
                parent[node->left] = node;
            }
            if(node->right) {
                q.push(node->right);
                parent[node->right] = node;
            }
        }
    }   
}
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*> parent;
    mapParentNodes(root,parent);

    queue<TreeNode*>q;
    q.push(target);
    unordered_map<int,bool> vis;
    vis[target->val] = true;
    int dis = 0;
    while (!q.empty()){
        int size = q.size();
        dis++;
        for (int i = 0; i < size; i++){
            auto node = q.front();
            q.pop();
            if(parent.find(node) != parent.end() && vis[parent[node]->val] == false){
                q.push(parent[node]);
                vis[parent[node]->val] = true;
            }
            if(node->left && vis[node->left->val] == false) {
                q.push(node->left);
                vis[node->left->val] = true;
            }
            if(node->right && vis[node->right->val] == false) {
                q.push(node->right);
                vis[node->right->val] = true;
            }
        }
        if(dis == k) break;
    }
    
    vector<int>ans;
    while (!q.empty()){
        auto node = q.front();
        q.pop();
        ans.push_back(node->val);
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
    TreeNode* target = new TreeNode(4);
    root->left->left = target;
    root->left->right = new TreeNode(5);


    vector<int>ans = distanceK(root,target,2);

    for (int i = 0; i < ans.size(); i++) cout<<ans[i]<<" ";

    return 0;
}
