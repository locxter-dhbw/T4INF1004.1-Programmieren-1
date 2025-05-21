/*#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

Node* newNode(int data);
void insert(Node *root, int data);
void inorder(Node *root);
void deleteTree(Node *root);

int main(void) {
    // Wurzel erstellen
    Node *root = newNode(42);
    // Baum erstellen
    insert(root, 31);
    insert(root, 53);
    insert(root, 30);
    insert(root, 32);
    insert(root, 52);
    insert(root, 54);
    // Baum traversieren
    inorder(root);
    // Speicher wieder freigeben
    deleteTree(root);
    return 0;
}

Node* newNode(int data) {
    Node *node = malloc(sizeof(Node));
    if (node == NULL) exit(-1);
    node->data = data;
    node->leftChild = NULL;
    node->rightChild = NULL;
    return node;
}

// Only works if the root already exists
void insert(Node *root, int data) {
    if (root == NULL) {
        root = newNode(data);
        return;
    }
    if (data < root->data) {
        if (root->leftChild == NULL) {
            root->leftChild = newNode(data);
        } else {
            insert(root->leftChild, data);
        }
    } else {
        if (root->rightChild == NULL) {
            root->rightChild = newNode(data);
        } else {
            insert(root->rightChild, data);
        }
    }
}

void inorder(Node *root) {
    if (root != NULL) {
        if (root->leftChild != NULL) {
            inorder(root->leftChild);
        }
        printf(" %d ", root->data);
        if (root->rightChild != NULL) {
            inorder(root->rightChild);
        }
    }
}

void deleteTree(Node *root) {
    if (root != NULL) {
        if (root->leftChild != NULL) {
            deleteTree(root->leftChild);
        }
        free(root);
        if (root->rightChild != NULL) {
            deleteTree(root->rightChild);
        }
    }
}*/