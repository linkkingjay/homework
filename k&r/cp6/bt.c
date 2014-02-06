#include <stdio.h>
#include <stdlib.h>

struct tnode {
    int val;
    int count;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *addtree(struct tnode *p, int v) {
    if (p == NULL) {
        p = (struct tnode *) malloc (sizeof (struct tnode));
        p->val = v;
        p->count = 1;
        p->left = p->right = NULL;
    } else if (p->val == v)
        p->count++;
    else if (p->val > v)
        p->left = addtree(p->left, v);
    else
        p->right = addtree(p->right, v);
    return p;
}

void treeprint(struct tnode *p) {
    if (p != NULL) {
        treeprint(p->left);
        printf("%d: %d\n", p->val, p->count);
        treeprint(p->right);
    }
}

int main() {
    int i;
    int qq[9] = {3, 6, 1, 6, 2, 6, 0, 9, 8};
    struct tnode *root;
    root = NULL;

    for (i = 0; i < 9; i++)
        root = addtree(root, qq[i]);

    treeprint(root);
    return 0;
}
