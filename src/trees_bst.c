#include "dsa/trees_bst.h"
#include <stdio.h>
#include <stdlib.h>

TreeNode* tree_create_node(int val) {
    TreeNode *node = malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void tree_free(TreeNode *root) {
    if(!root) return;
    tree_free(root->left);
    tree_free(root->right);
    free(root);
}

void traversal_preorder(const TreeNode *root) {
    if (!root) return;
    printf("%d ", root->val);
    traversal_preorder(root->left);
    traversal_preorder(root->right);
}

void traversal_inorder(const TreeNode *root) {
    if (!root) return;
    traversal_inorder(root->left);
    printf("%d ", root->val);
    traversal_inorder(root->right);
}

void traversal_postorder(const TreeNode *root) {
    if (!root) return;
    traversal_postorder(root->left);
    traversal_postorder(root->right);
    printf("%d ", root->val);
}

void traversal_level_order(const TreeNode *root) {
    if (!root) return;
    TreeNode *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = (TreeNode*)root;

    while (front < rear) {
        TreeNode *curr = queue[front++];
        printf("%d ", curr->val);
        if (curr->left)  queue[rear++] = curr->left;
        if (curr->right) queue[rear++] = curr->right;
    }
}

int tree_height(const TreeNode *root) {
    if (!root) return 0;
    int lh = tree_height(root->left);
    int rh = tree_height(root->right);
    return 1 + (lh > rh ? lh : rh);
}

int tree_leaf_count(const TreeNode *root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return tree_leaf_count(root->left) + tree_leaf_count(root->right);
}

void tree_mirror(TreeNode *root) {
    if (!root) return;
    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    tree_mirror(root->left);
    tree_mirror(root->right);
}

TreeNode* bst_insert(TreeNode *root, int val) {
    if (!root) return tree_create_node(val);
    if (val < root->val) root->left = bst_insert(root->left, val);
    else if (val > root->val) root->right = bst_insert(root->right, val);
    return root;
}

TreeNode* bst_search(TreeNode *root, int val) {
    if (!root || root->val == val) return root;
    if (val < root->val) return bst_search(root->left, val);
    return bst_search(root->right, val);
}

TreeNode* bst_min(TreeNode *root) {
    while (root && root->left) root = root->left;
    return root;
}

TreeNode* bst_max(TreeNode *root) {
    while (root && root->right) root = root->right;
    return root;
}

TreeNode* bst_delete(TreeNode *root, int val) {
    if (!root) return NULL;
    if (val < root->val) root->left = bst_delete(root->left, val);
    else if (val > root->val) root->right= bst_delete(root->right, val);
    else {
        if (!root->left) {
            TreeNode *temp = root->right;
            free(root);
            return temp;
        } else if (!root->right) {
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }
        TreeNode *temp = bst_min(root->right);
        root->val = temp->val;
        root->right = bst_delete(root->right, temp->val);
    }
    return root;
}

int bst_range_sum(const TreeNode *root, int low, int high) {
    if (!root) return 0;
    int sum = 0;
    if (root->val >= low && root->val <=high) sum += root->val;
    if (root->val > low) sum += bst_range_sum(root->left, low, high);
    if (root->val < high) sum += bst_range_sum(root->right, low, high);
    return sum;
}
