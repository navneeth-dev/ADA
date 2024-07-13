/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int A[10000];
int i=0;
void inorder(struct TreeNode* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    A[i++] = root->val;
    inorder(root->right);

}
int getMinimumDifference(struct TreeNode* root) {
    i=0;
    inorder(root);
    int min = INT_MAX;
    for(int j=0; j<i-1; j++){
        if(A[j+1]-A[j]<min){
            min = abs(A[j+1]-A[j]);
        }
    }
    return min;
}
