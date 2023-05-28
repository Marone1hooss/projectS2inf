//function prototype

typedef struct skill
{
    int skill;
    int level;
}skill;


typedef struct employee
{
    int id;
    char*name;
    int nskils;
    int available;
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
    double grad;
    int delevered;
}project;

typedef struct delevered
{ 
    int prjID;
    int* devIDs;
} delevered;
 

void intmergeSort(int arr[], int left, int right);
void strmergeSort(char **arr, int left, int right) ;
int strbinarySearch(char** arr, int left, int right, char *target) ;
void prjmergeSort(project* arr, int left, int right);
double grade(project prj,int time);
int max(int a,int b);
int min(int a,int b);
