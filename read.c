#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<string.h>
typedef struct skill
{
    char*skill;
    int level;
}skill;


typedef struct employee
{
    char*name;
    int nskils;
    skill * skilles;
}employee;

typedef struct project
{
    char* name;
    int days;
    int score ;
    int best_befor;
    int numbre_of_employeres;
    skill* requirement;
}project;



int main(int argc,char*argv)
{
    int N,M;
    scanf("%d %d",&N,&M);
    employee*employers=(employee*)malloc(N*sizeof(employee));
    for (int i =0;i<N;i++)
    {
        char name[20];
        int n;
        scanf("%s",name);
        scanf("%d",&n);
        employee test1;
        test1.name=name;
        test1.nskils=n;
        test1.skilles=(skill*)malloc(n*sizeof(skill));
        for (int j=0;j<n;j++)
        {
            char skillname[20];
            int level;
            scanf("%s",skillname);
            scanf("%d",&level);
            skill testskill;
            testskill.level=level;
            testskill.skill=skillname;
            test1.skilles[j]=testskill;
        }
        employers[i]=test1;
    }

    project*projects=(project*)malloc(M*sizeof(project));
    for (int i =0;i<M;i++)
    {
        char name[20];
        int days,score,bestb,nofemp;
        scanf("%s",name);
        scanf("%d",&days);
        scanf("%d",&score);
        scanf("%d",&bestb);
        scanf("%d",&nofemp);


        project test1;
        test1.name=name;
        test1.days=days;
        test1.score=score;
        test1.best_befor=bestb;
        test1.numbre_of_employeres=nofemp;
        test1.requirement=(skill*)malloc(nofemp*sizeof(skill));
        for (int j=0;j<nofemp;j++)
        {
            char skillname[20];
            int level;
            scanf("%s",skillname);
            scanf("%d",&level);
            skill testskill;
            testskill.level=level;
            testskill.skill=skillname;
            test1.requirement[j]=testskill;
        }
        projects[i]=test1;
    }

for (int i=0;i<N;i++)
{
    printf("%d\n",employers[i].nskils);
    printf("%d\n",projects[i].days);
}
}