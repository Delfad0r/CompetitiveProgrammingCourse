/*
We implement a new function isBST0 that checks whether the tree rooted
at root is a BST and additionally all its vertices have values in the
range [low,high]. Then the recursive implementation if BST0 is straightforward.
*/

bool isBST0(Node* root, int low = 0, int high = 1 << 30) {
    if(!root) {
        return true;
    }
    if(root->data < low or root->data > high) {
        return false;
    }
    return isBST0(root->left, low, min(high, root->data))
        and isBST0(root->right, max(low, root->data), high);
}   

bool isBST(Node* root) {
    return isBST0(root);
}
