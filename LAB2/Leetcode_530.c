void inOrder(struct TreeNode* root, int arr[], int *i) {
    if (root == NULL) return;
    inOrder(root->left, arr, i);
    arr[(*i)++] = root->val;
    inOrder(root->right, arr, i);
}

int getMinimumDifference(struct TreeNode* root) {
    int arr[10000],i = 0,diff = INT_MAX;
    inOrder(root, arr, &i);
    for (int j = 1; j < i; j++) if (arr[j] - arr[j - 1] < diff) diff = arr[j] - arr[j - 1];
    return diff;
}
