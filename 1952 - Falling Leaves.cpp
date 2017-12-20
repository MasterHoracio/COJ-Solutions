#include <bits/stdc++.h>

using namespace std;

struct Btree{
    char data;
    Btree *left;
    Btree *right;
};

Btree *createNode(char ch){
    Btree *node = new Btree;
    node->left = node ->right = NULL;
    node->data = ch;
    return node;
}

void preOrder(Btree *root){
    if(root){
        cout << root->data;
        preOrder(root->left);
        preOrder(root->right);
    }
}

Btree *insertNode(char ch, Btree *root){
    Btree *leaf = root;

    if(root == NULL){
        root = createNode(ch);
        return root;
    }

    while(leaf){
        if(leaf->data > ch){
            if(leaf->left == NULL){
                leaf->left = createNode(ch);
                break;
            }else{
                leaf = leaf->left;
            }
        }else{
            if(leaf->right == NULL){
                leaf->right = createNode(ch);
                break;
            }else{
                leaf = leaf->right;
            }
        }
    }

    return root;
}


int main(){
    string cad, order = "";
    Btree *root = NULL;

    while(getline(cin, cad)){
        if(cad.length() == 1 && cad[0] == '$'){
            for(int i = order.length() - 1; i >= 0; i--)
                root = insertNode(order[i], root);
            preOrder(root);
            cout << endl;
            break;
        }else if(cad.length() == 1 && cad[0] == '*'){
            for(int i = order.length() - 1; i >= 0; i--)
                root = insertNode(order[i], root);
            preOrder(root);
            cout << endl;
            root = NULL;
            order = "";
        }else{
            order += cad;
        }
    }

    return 0;
}