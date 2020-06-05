/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 
// Time:  O(n)
// Space: O(h) 
// Approach1 : Simple Recursive solution.
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr){
            return nullptr;
        }
        else{
            TreeNode* tt = new TreeNode;
            invertTree(root->left);
            invertTree(root->right);
            tt = root->left;			//swap(root->left, root->right);
            root->left = root->right;
            root->right = tt;
            return root;
        }
    }
};


// Time:  O(n)
// Space: O(max number of nodes at any level)
// Approach2 : BFS on tree solution.
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root != nullptr) {
            queue<TreeNode*> nodes;	//DFS on tree- stack<TreeNode*> nodes; -- Space: O(height)
            nodes.emplace(root);
            while (!nodes.empty()) {
                auto node = nodes.front();
                nodes.pop();
                swap(node->left, node->right);
                if (node->left != nullptr) {
                    nodes.emplace(node->left);
                }
                if (node->right != nullptr) {
                    nodes.emplace(node->right);
                }
            }
        }
        return root;
    }
};
