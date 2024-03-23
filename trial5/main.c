#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s{
    char *key;
    struct node_s *left, *right;
} node_t;

void preorder(node_t *root){
    if (root == NULL)
        exit(EXIT_FAILURE);
    printf("%s\n", root->key);
    preorder(root->left);
    preorder(root->right);
}

void inorder(node_t *root){
    if (root==NULL)
        exit(EXIT_FAILURE);
    inorder(root->left);
    printf("%s\n", root->key);
    inorder(root->right);
}

void postorder(node_t *root){
    if (root == NULL)
        exit(EXIT_FAILURE);
    postorder(root->left);
    postorder(root->right);
    printf("%s\n", root->key);
}
int count(node_t *root){
    int l, r;
    if (root==NULL){
        return 0;
    }
    l = count(root->left);
    r = count(root->right);
    return (l+r+1);
}

int height(node_t *root){
    int l, r;
    if (root == NULL)
        return -1;

    l = height(root->left);
    r = height(root->right);

    if (l>r)
        return l+1;
    else
        return r+1;
}

node_t *new_node(char *key, node_t *left, node_t *right){
    node_t *new = (node_t *) malloc(sizeof(node_t));
    if (new == NULL) exit(EXIT_FAILURE);
    strcpy(new->key, key);
    new->left = left;
    new->right = right;
    return new;
}

node_t *insert(node_t *root, char *key){
    if (root == NULL)
        return new_node(key, NULL, NULL);
    if (strcmp(key, root->key)<0)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    
}

int main() {
    int *a;
    printf("%d", sizeof(int));
    printf("%d", sizeof(char));
    printf("%d", sizeof(float));
    printf("%d", sizeof(a));
    return 22;
}
