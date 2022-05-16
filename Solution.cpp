
#include <algorithm>
using namespace std;


class Solution {
    
public:
    int deepestLeavesSum(TreeNode* root) {
        return sumDeepestLeaves(root, maxHeight(root));
    }
    
private:
    int sumDeepestLeaves(TreeNode* root, int height) {
        if (root == nullptr) {
            return 0;
        }
        if (height == 1) {
            return root->val;
        }
        int sum = sumDeepestLeaves(root->left, height - 1) + sumDeepestLeaves(root->right, height - 1);
        return sum;
    }

    int maxHeight(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int max = std::max(maxHeight(root->left) + 1, maxHeight(root->right) + 1);
        return max;
    }
};

/*
Struct TreeNode is in-built in the solution file on leetcode.com. 
When running the code on the website, do not include this struct.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right){}
};
