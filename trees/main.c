#include <stdio.h>

#define MAX 5

//   NODE STRUCTURE FOR BINARY TREE
typedef struct node_sa {
    char key[MAX];

    struct node_sa *l, *r;
} node_ta;

// COMPUTE THE NUMBER OF NODES OF A "BINARY TREE"
int count (node_ta *root){
    int left, right;
    if (root == NULL)
        return 0;

    left = count(root->l);
    right = count(root->r);

    return (left+right+1);
}
// COMPUTE THE HEIGHT OF A "BINARY TREE"
int height (node_ta *root){
    int l, r;
    if (root == NULL)
        return -1;

    l = height(root->l);
    r = height(root->r);

    return (l>r) ? (l+1) : (r+1);
}

// NODE STRUCTURE FOR N-ARY TREE
typedef struct node_sb {
    char key[MAX];

    int degree;

    struct node_sb **children, *c, *s;
} node_tb;

// COMPUTE THE NUMBER OF NODES OF "THE N-ARY TREE"
int countb (node_tb *root){
    int c, i;
    if (root == NULL)
        return 0;

    for (c=0, i=0; i<root->degree; i++)
        c += countb(root->children[i]);

    return (c+1);
}

// COMPUTE THE HEIGHT OF "THE N-ARY TREE"

int heightb (node_tb *root){
    int i, c, max=-1;
    if (root == NULL)
        return -1;

    for (i=0; i<root->degree; i++){
        c = heightb(root->children[i]);
        if (c>max)
            max = c;
    }
    return (max+1);
}

int main() {



    return 0;
}
