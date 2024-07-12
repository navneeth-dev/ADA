void inOrder(struct TreeNode* root,int arr[],int *i){
    if(root==NULL) return;
    inOrder(root->left,arr,i);
    arr[(*i)++] = root->val;
    inOrder(root->right,arr,i);
}
int kthSmallest(struct TreeNode* root, int k) {
    int *arr = (int *)malloc(sizeof(int)*10000),i = 0;
    inOrder(root,arr,&i);
    return arr[k-1];
}
