#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),right(right) {}
};

class traverse{
public:
    vector<int> ans;
public:
    void preorder(TreeNode* root){
        stack<TreeNode*> s;
        while(root || !s.empty()){
            while(root){
                s.push(root);
                ans.push_back(root->val);
                root = root->left;
            }
            root = s.top();
            s.pop();
            root = root->right;
        }
    }

    void inorder(TreeNode* root){
        stack<TreeNode*> s;
        while(root || !s.empty()){
            s.push(root);

        }
    }


};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
