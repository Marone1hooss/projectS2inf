
typedef struct Node0 {
    char* key;
    struct Node0* left;
    struct Node0* right;
    int height;
} strNode;




strNode* strinsertNode(strNode* node, char* key);
strNode* strfindMinNode(strNode* node);
strNode* strdeleteNode(strNode* root, char* key);
void inOrderTraversal(strNode* root);
void strfreeTree(strNode* root);
strNode* strfindNode(strNode* node, char* key);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct SkillNode {
    int id;
    int lvl;
    struct SkillNode* left;
    struct SkillNode* right;
    int height;
} SkillNode;

SkillNode* findSkillNode(SkillNode* node, int lvl);
SkillNode* insertSkillNode(SkillNode* node, int id, int lvl);
void sklinOrderTraversal(SkillNode* node);
void freeSkillTree(SkillNode* node);
SkillNode* findvalide(SkillNode* node, int lvl);