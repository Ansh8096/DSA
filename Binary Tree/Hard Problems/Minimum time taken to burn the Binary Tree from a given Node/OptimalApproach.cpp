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
int minTimeToBurnBinaryTree(TreeNode* root, TreeNode* node){
    unordered_map<TreeNode*, TreeNode*> parent;
    mapParentNodes(root, parent);

    queue<pair<TreeNode*, int>>q;
    unordered_map<TreeNode*,bool>vis;
    vis[node] = true;
    int time = 0;
    q.push({node,time});
    while (!q.empty()){
        int size = q.size();
        for (int i = 0; i < size; i++){
            TreeNode* poped = q.front().first;
            time = q.front().second;
            q.pop();

            if(parent.find(poped) != parent.end() && vis[parent[poped]] == false){
                q.push({parent[poped],time+1});
                vis[parent[poped]] = true;
            }
            if(poped->left && vis[poped->left] == false){
                q.push({poped->left, time+1});
                vis[poped->left] = true;
            }
            if(poped->right && vis[poped->right] == false){
                q.push({poped->right, time+1});
                vis[poped->right] = true;
            }
        }
        
    }
    return time;
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

    cout<<minTimeToBurnBinaryTree(root,target);

    return 0;
}
