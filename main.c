#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<string.h>
#include"sorting.h"


int main(int argc,char*argv)
{
    int N,M;
    scanf("%d %d",&N,&M);

    char ** devnames=(char**)malloc(N*sizeof(char*));
    for(int i=0;i<N;i++){devnames[i]=(char*)malloc(21*sizeof(char));}

    char ** listproj=(char**)malloc(M*sizeof(char*));
    for(int i=0;i<M;i++){listproj[i]=(char*)malloc(21*sizeof(char));}
    employee*employers=(employee*)malloc(N*sizeof(employee));

    for (int i =0;i<N;i++)
    {
        char name[20];
        int n;
        scanf("%s",name);
        scanf("%d",&n);
        //devnames[i]=name;
        for (int k=0;k<20+1;k++)
        {
            devnames[i][k]=name[k];
        }
        employee test1;
        test1.name=(char*)malloc(strlen(name)*sizeof(char)+1);
        for (int j=0;j<strlen(name)+1;j++){test1.name[j]=name[j];}
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
    for (int i=0;i<N;i++)
{

    printf("%s\n",devnames[i]);

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
         for (int k=0;k<20+1;k++)
        {
            listproj[i][k]=name[k];
        }
 
        project test1;
        test1.name=(char*)malloc(strlen(name)*sizeof(char)+1);
        for (int j=0;j<strlen(name)+1;j++){test1.name[j]=name[j];}
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
strmergeSort(devnames,0,N-1);
strmergeSort(listproj,0,M-1);


for (int i=0;i<N;i++)
{
    employers[i].id=strbinarySearch(devnames,0,N-1, employers[i].name);
    
}
for (int i=0;i<M;i++)
{
    projects[i].id=strbinarySearch(listproj,0,M-1 , projects[i].name);
    projects[i].grad=grade(projects[i],0);
}
prjmergeSort(projects,0,M-1);

for (int i=0;i<M;i++)
{
    printf("%s\n",projects[i].name);
    printf("%d\n",projects[i].grad);
    printf("%d\n",projects[i].id);
}

int day=0;
/* while(true)
{

}
 */


/// freee everything !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}

/* 3 3
meryem 1
C 2
ahmad 2
HTML 5
CSS 5
Maria 1
Python 3
p1 5 10 5 1
C 3
p2 7 10 7 2
HTML 3
C 2
p3 10 20 20 2
Python 3
HTML 3 */