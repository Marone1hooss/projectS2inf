#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sorting.h"
typedef struct Node {
    char* key;
    struct Node* left;
    struct Node* right;
    int height;
} strNode;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int getHeight(strNode* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int getBalance(strNode* node) {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}
strNode* createNode(char* key) {
    strNode* newNode = (strNode*)malloc(sizeof(strNode));
    newNode->key = strdup(key);
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

strNode* rotateRight(strNode* y) {
    strNode* x = y->left;
    strNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

strNode* rotateLeft(strNode* x) {
    strNode* y = x->right;
    strNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

strNode* strinsertNode(strNode* node, char* key) {
    if (node == NULL)
        return createNode(key);

    int compare = strcmp(key, node->key);

    if (compare < 0)
        node->left = strinsertNode(node->left, key);
    else if (compare > 0)
        node->right = strinsertNode(node->right, key);
    else
        return node;

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && strcmp(key, node->left->key) < 0)
        return rotateRight(node);

    // Right Right Case
    if (balance < -1 && strcmp(key, node->right->key) > 0)
        return rotateLeft(node);

    // Left Right Case
    if (balance > 1 && strcmp(key, node->left->key) > 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right Left Case
    if (balance < -1 && strcmp(key, node->right->key) < 0) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

strNode* strfindMinNode(strNode* node) {
    strNode* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

strNode* strdeleteNode(strNode* root, char* key) {
    if (root == NULL)
        return root;

    int compare = strcmp(key, root->key);

    if (compare < 0)
        root->left = strdeleteNode(root->left, key);
    else if (compare > 0)
        root->right = strdeleteNode(root->right, key);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            strNode* temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            free(temp);
        } else {
            strNode* temp = strfindMinNode(root->right);
            root->key = temp->key;
            root->right = strdeleteNode(root->right, temp->key);
        }
    }

    if (root == NULL)
        return root;

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rotateRight(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return rotateLeft(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void inOrderTraversal(strNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%s ", root->key);
        inOrderTraversal(root->right);
    }
}

void strfreeTree(strNode* root) {
    if (root != NULL) {
        strfreeTree(root->left);
        strfreeTree(root->right);
        free(root->key);
        free(root);
    }
}

strNode* strfindNode(strNode* node, char* key) {
    if (node == NULL || strcmp(node->key, key) == 0)
        return node;

    int compare = strcmp(key, node->key);

    if (compare < 0)
        return strfindNode(node->left, key);
    else
        return strfindNode(node->right, key);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


typedef struct SkillNode {
    int id;
    int lvl;
    struct SkillNode* left;
    struct SkillNode* right;
    int height;
} SkillNode;

int sklgetHeight(SkillNode* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int sklgetBalance(SkillNode* node) {
    if (node == NULL)
        return 0;
    return sklgetHeight(node->left) - sklgetHeight(node->right);
}

SkillNode* sklcreateSkillNode(int id, int lvl) {
    SkillNode* newNode = (SkillNode*)malloc(sizeof(SkillNode));
    newNode->id = id;
    newNode->lvl = lvl;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

SkillNode* sklrotateRight(SkillNode* y) {

    SkillNode* x = y->left;
    SkillNode* T2 = x->right;
    x->right = y;
    y->left = T2;

    y->height = max(sklgetHeight(y->left), sklgetHeight(y->right)) + 1;
    x->height = max(sklgetHeight(x->left), sklgetHeight(x->right)) + 1;

    return x;
}

SkillNode* sklrotateLeft(SkillNode* x) {
    SkillNode* y = x->right;
    SkillNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(sklgetHeight(x->left), sklgetHeight(x->right)) + 1;
    y->height = max(sklgetHeight(y->left), sklgetHeight(y->right)) + 1;

    return y;
}

SkillNode* insertSkillNode(SkillNode* node, int id, int lvl) {
    if (node == NULL)
        return sklcreateSkillNode(id, lvl);

    if (lvl < node->lvl)
        node->left = insertSkillNode(node->left, id, lvl);
    else if (lvl >= node->lvl)
        node->right = insertSkillNode(node->right, id, lvl);
/*     else if (lvl == node->lvl)
        if(id > node->id)
            node->right = insertSkillNode(node->right, id, lvl);
        else  node->right = insertSkillNode(node->left, id, lvl); */
    else
        return node;

    node->height = max(sklgetHeight(node->left), sklgetHeight(node->right)) + 1;

    int balance = sklgetBalance(node);

    // Left Left Case
    if (balance > 1 && lvl < node->left->lvl)
        return sklrotateRight(node);

    // Right Right Case
    if (balance < -1 && lvl >= node->right->lvl)
        return sklrotateLeft(node);

    // Left Right Case
    if (balance > 1 && lvl >= node->left->lvl) {
        node->left = sklrotateLeft(node->left);
        return sklrotateRight(node);
    }

    // Right Left Case
    if (balance < -1 && lvl < node->right->lvl) {
        node->right = sklrotateRight(node->right);
        return sklrotateLeft(node);
    }

    return node;
}

void sklinOrderTraversal(SkillNode* node) {
    if (node != NULL) {
        sklinOrderTraversal(node->left);
        printf("ID: %d, Level: %d\n", node->id, node->lvl);
        sklinOrderTraversal(node->right);
    }
}

void freeSkillTree(SkillNode* node) {
    if (node != NULL) {
        freeSkillTree(node->left);
        freeSkillTree(node->right);
        free(node);
    }
}
SkillNode* findSkillNode(SkillNode* node, int lvl) {
    if (node == NULL || node->lvl == lvl)
        return node;

    if (lvl < node->lvl)
        return findSkillNode(node->left, lvl);
    else 
        return findSkillNode(node->right, lvl);
}

unsigned long  int employeegrade(SkillNode*node,int lvl,employee*employers)
{
    if (node==NULL) return 10000000000;
    return employers[node->id].nskils*(node->lvl-lvl);
}


SkillNode* best_condidate(SkillNode* node, int lvl,employee*employers,int Time,int*availableat)
{
if (node==NULL) return NULL;

if (lvl > node->lvl) return best_condidate(node->right,lvl,employers,Time,availableat);

else 
{
    SkillNode*right=best_condidate(node->right,lvl,employers,Time,availableat);
    SkillNode*left=best_condidate(node->left,lvl,employers,Time,availableat);
    unsigned long int a=employeegrade(right,lvl,employers);
    unsigned long int b=employeegrade(left,lvl,employers);
    unsigned long int c;
    if (availableat[node->id] <= Time)   
    {
        c=employeegrade(node,lvl,employers);
        if (a<=b && a<=c) return right;
        if (c<=b && c<=a) return node;
        if (b<=a && b<=c) return left;
    }
    else 
    {
        if (a<b) return right;
        else if (b<a) return left;
        else return NULL;
    }
}

}


SkillNode* skillDeleteNode(SkillNode* root, int lvl,int id) {

    if (root == NULL)
        return root;

    if (lvl < root->lvl)
        root->left = skillDeleteNode(root->left,lvl,id);

    else if (lvl>root->lvl)
        root->right = skillDeleteNode(root->right,lvl,id);

    else if (lvl==root->lvl && id > root->id)
        root->right = skillDeleteNode(root->right,lvl,id);
    else if (lvl==root->lvl && id < root->id)
        root->right =skillDeleteNode(root->left,lvl,id);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            SkillNode* temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            free(temp);
        } else {
            SkillNode* temp = root->right;
            while (temp->left != NULL)
                temp = temp->left;

            root->id = temp->id;
            root->lvl = temp->lvl;

            root->right = skillDeleteNode(root->right,lvl,temp->id);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(sklgetHeight(root->left), sklgetHeight(root->right));

    int balance = sklgetBalance(root);

    if (balance > 1 && sklgetBalance(root->left) >= 0)
        return sklrotateRight(root);

    if (balance > 1 && sklgetBalance(root->left) < 0) {
        root->left = sklrotateLeft(root->left);
        return sklrotateRight(root);
    }

    if (balance < -1 && sklgetBalance(root->right) <= 0)
        return sklrotateLeft(root);

    if (balance < -1 && sklgetBalance(root->right) > 0) {
        root->right = sklrotateRight(root->right);
        return sklrotateLeft(root);
    }

    return root;
}
