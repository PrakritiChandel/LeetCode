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
 class FindElements {
public:
    /**
     * Recursively restores the values of the tree nodes.
     * - The root starts with value `0`.
     * - The left child of a node with value `x` is assigned `2 * x + 1`.
     * - The right child of a node with value `x` is assigned `2 * x + 2`.
     */
    void solve(TreeNode* root) {
        if (root == NULL) {
            return;  // Base case: If the node is NULL, stop the recursion
        }

        // Store the restored value in the list
        values_list.push_back(root->val);

        // Process left child (if exists)
        if (root->left != NULL) {
            root->left->val = root->val * 2 + 1;  // Assign new value
        }
        solve(root->left);

        // Process right child (if exists)
        if (root->right != NULL) {
            root->right->val = root->val * 2 + 2;  // Assign new value
        }
        solve(root->right);
    }

    vector<int> values_list;  // Stores recovered values of the tree

    /**
     * Constructor initializes the recovery process of the tree.
     * - The root node is set to `0`.
     * - Calls `solve()` to restore the entire tree.
     */
    FindElements(TreeNode* root) {
        root->val = 0;  // Initialize root value to 0
        solve(root);
    }

    /**
     * Checks if a given `target` value exists in the recovered tree.
     * - Uses linear search to find the target in `values_list`.
     * - Returns `true` if found, otherwise `false`.
     */
    bool find(int target) {
        for (int i = 0; i < values_list.size(); i++) {
            if (target == values_list[i]) return true;  // Target found
        }
        return false;  // Target not found
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */