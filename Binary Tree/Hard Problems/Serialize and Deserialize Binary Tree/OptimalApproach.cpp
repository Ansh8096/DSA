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
string serialize(TreeNode* root) {
    if(!root) return "";
    string ans = "";
    queue<TreeNode*> q;
    q.push(root);
    ans.append(to_string(root->val) + ',');
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++){
            TreeNode* node = q.front();
            q.pop();

            if(node->left){
                q.push(node->left);
                ans.append(to_string(node->left->val)+',');
            }
            else ans.append("#,");
            
            if(node->right){
                q.push(node->right);
                ans.append(to_string(node->right->val)+',');
            }
            else ans.append("#,");
        }
    }
    return ans;
}
TreeNode* deserialize(string str){
    if(str.empty()) return NULL;
    
    stringstream s(str);
    getline(s,str,',');

    TreeNode* root = new TreeNode(stoi(str));
    queue<TreeNode*>q;
    q.push(root);
    while (!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        getline(s,str,',');
        if(str != "#"){
            node->left = new TreeNode(stoi(str));
            q.push(node->left);
        }
        
        getline(s,str,',');
        if(str != "#"){
            node->right = new TreeNode(stoi(str));
            q.push(node->right);
        }   
    }
    return root; 
}
int main(){
    
    // Constructing tree:
    //
    //         3
    //        / \
    //       9   20
    //          /  \
    //         15   7

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << "Original Tree:\n";
    printTree(root);

    // Serialize
    string serialized = serialize(root);

    cout << "\n\nSerialized String:\n";
    cout << serialized << endl;

    // Deserialize
    TreeNode* newRoot = deserialize(serialized);

    cout << "\nDeserialized Tree:\n";
    printTree(newRoot);

    
    return 0;
}
