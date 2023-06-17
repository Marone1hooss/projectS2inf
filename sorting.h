//function prototype

typedef struct skill
{
    int skill;
    int level;
}skill;

typedef struct devloper
{
    int id;//the id of the devloper
    int lvl;//his level in this skill
} dev ;


typedef struct employee
{
    int id;
    char*name;
    int nskils;
    skill * skilles;
    char**strskills;
}employee;

typedef struct project
{
    char* name;
    int id;
    int days;
    int score ;
    int best_befor;
    int numbre_of_employeres;
    skill* requirement;
    long long int grad;
    int delevered;
}project;

typedef struct delevered
{ 
    int prjID;
    int* devIDs;
    int ndev;
    int starting_day;
    int days;
} delevered;
 
typedef struct mentored
{
    int id;//the id of the employer
    int ip;//the ip of the skill
    int lvl;//the lvl of the employee for this skill
}mentored;

typedef struct AVLNode {
    int data;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
} AVLNode;

void intmergeSort(int arr[], int left, int right);
void strmergeSort(char **arr, int left, int right) ;
int strbinarySearch(char** arr, int left, int right, char *target) ;
void prjmergeSort(project* arr, int left, int right);
long long int grade(project prj,int time);
void sklmergeSort(skill* arr, int left, int right);
int max(int a,int b);
int min(int a,int b);



void devmerge(dev arr[], int left, int mid, int right);
void devmergeSort(dev arr[], int left, int right) ;
int binarySearch(dev arr[], int left, int right, int target);
int findSmallestGreaterOrEqual(dev arr[], int size, int N);
int best_dev(dev* list, int lvl,employee*  employers,int Time,int *availableat,int number_of_employeres,AVLNode*curently_selected);
void Upgrade(dev*list,mentored target,int n );
