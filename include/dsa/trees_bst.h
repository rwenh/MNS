#ifndef DSA_TREES_BST_H
#define DSA_TREES_BST_H

#include <stdbool.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* tree_create_node(int val);
void tree_free(TreeNode *root);

void traversal_preorder(const TreeNode *root);
void traversal_inorder(const TreeNode *root);
void traversal_postorder(const TreeNode *root);
void traversal_level_order(const TreeNode *root);

int tree_height(const TreeNode *root);
int tree_leaf_count(const TreeNode *root);
void tree_mirror(TreeNode *root);

TreeNode* bst_insert(TreeNode *root, int val);
TreeNode* bst_search(TreeNode *root, int val);
TreeNode* bst_delete(TreeNode *root, int val);
TreeNode* bst_min(TreeNode *root);
TreeNode* bst_max(TreeNode *root);
int bst_range_sum(const TreeNode *root, int low, int high);

#endif
