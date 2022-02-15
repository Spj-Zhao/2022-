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
            while(root){
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            ans.push_back(root->val);
            root = root->right;
        }
    }

    void postorder(TreeNode* root){
        //s1装中右左,再装到s2即为左右中
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root);
        while(s1.empty()){

        }
        while(!s2.empty()){
            TreeNode* node = s2.top();
            s2.pop();
            ans.push_back(node->val);
        }
    }


};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
