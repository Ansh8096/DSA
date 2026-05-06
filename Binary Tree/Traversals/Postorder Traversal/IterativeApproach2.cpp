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
vector<int> postorderIterativeTraversal(TreeNode* root) {
    TreeNode* temp;
    TreeNode* curr = root;
    stack<TreeNode*> stk;
    vector<int>ans;

    while (curr != NULL || !stk.empty())
    {
        if(curr != NULL){
            stk.push(curr);
            curr = curr->left;
        }
        else{
            temp = stk.top()->right;
            if(temp == NULL){
                temp = stk.top();
                stk.pop();
                ans.push_back(temp->val);
                while (!stk.empty() && temp == stk.top()->right)
                {
                    temp = stk.top();
                    stk.pop();
                    ans.push_back(temp->val);
                }
            }
            else curr = temp;
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

    // Call preorder traversal
    vector<int> result = postorderIterativeTraversal(root);

    // Print result
    cout << "Postorder Traversal: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;


    return 0;
}
