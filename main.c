#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<string.h>
#include"sorting.h"
#include"AVL.h"

int main(int argc,char*argv)
{
    int N,M;
    scanf("%d %d",&N,&M);

    char ** devnames=(char**)malloc(N*sizeof(char*));
    for(int i=0;i<N;i++){devnames[i]=(char*)malloc(21*sizeof(char));}

    char ** listproj=(char**)malloc(M*sizeof(char*));
    for(int i=0;i<M;i++){listproj[i]=(char*)malloc(21*sizeof(char));}

    char ** listskills0=(char**)malloc(N*10*sizeof(char*));
    for(int i=0;i<N*10;i++){listskills0[i]=(char*)malloc(21*sizeof(char));}

    strNode * root=NULL;
    int S=0;//the number of skilles
    employee*employers=(employee*)malloc(N*sizeof(employee));


    for (int i =0;i<N;i++)
    {
        char name[20];
        int n;
        scanf("%s",name);
        scanf("%d",&n);

        for (int k=0;k<20+1;k++)
        {
            devnames[i][k]=name[k];
        }
        employee test1;
        test1.name=(char*)malloc(strlen(name)*sizeof(char)+1);
        for (int j=0;j<strlen(name)+1;j++){test1.name[j]=name[j];}
        test1.available=0;
        test1.nskils=n;
        test1.skilles=(skill*)malloc(n*sizeof(skill));
        for (int j=0;j<n;j++)
        {
            char *skillname=(char*)malloc(21*sizeof(char));
            int level;
            scanf("%s",skillname);
            scanf("%d",&level);
            skill testskill;
            testskill.skill=(char*)malloc((strlen(skillname)+1)*sizeof(char));
            testskill.level=level;
            for(int b=0;b<strlen(skillname)+1;b++){testskill.skill[b]=skillname[b]; }
            test1.skilles[j]=testskill;
            if (strfindNode(root,skillname)==NULL)
            {
                root=strinsertNode(root,skillname);
            for (int k=0;k<20+1;k++)
            {
                listskills0[S][k]=skillname[k];
            }
                S++;
            }
        }
        employers[i]=test1;
    }


    project*projects=(project*)malloc(M*sizeof(project));
    for (int i =0;i<M;i++)
    {
        char *name=(char*)malloc(21*sizeof(char));
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
        test1.delevered=0;
        test1.numbre_of_employeres=nofemp;
        test1.requirement=(skill*)malloc(nofemp*sizeof(skill));
        for (int j=0;j<nofemp;j++)
        {
            char* skillname=(char*)malloc(21*sizeof(char));
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

employee*employers1=(employee*)malloc(N*sizeof(employee));
for(int i=0;i<N;i++)
{
    employers1[employers[i].id]=employers[i];
}
free(employers);
employers=employers1;

for (int i=0;i<M;i++)
{
    projects[i].id=strbinarySearch(listproj,0,M-1 , projects[i].name);
    projects[i].grad=grade(projects[i],0);
}



//sorting the skilles 
char ** listskills=(char**)malloc((S)*sizeof(char*));
for(int i=0;i<S;i++){listskills[i]=(char*)malloc(21*sizeof(char));}
for(int i=0;i<S;i++){
    for (int k=0;k<21;k++)
    {

        listskills[i][k]=listskills0[i][k];
    }
    } 

free(listskills0);
strfreeTree(root); 
strmergeSort(listskills,0,S-1);


SkillNode **skilltree=(SkillNode**)malloc(S*sizeof(SkillNode**));
for(int k=0;k<S;k++){
    skilltree[k]=NULL;
}


for(int i=0;i<N;i++)
{
    skill*list=employers[i].skilles;
    int n=employers[i].nskils;
    for(int j=0;j<n;j++)
    {
        int ip=strbinarySearch(listskills,0,S-1,list[j].skill);
        SkillNode * root=skilltree[ip];
        root=insertSkillNode(root,i,list[j].level);
        skilltree[ip]=root;
    }
} 


delevered*deleveredprojects=(delevered*)malloc(M*sizeof(delevered));//A list of delevered projects
int D=0;//The number deleveres projects

int Time=1;//the numbere /of days 
while(true)
{
    for (int k=0;k<M;k++)
    {
        projects[k].grad=grade(projects[k],Time);
    }
    prjmergeSort(projects,0,M-1);
    if (projects[0].grad==0) break;
    for(int p=0;p<M;p++)
    {
        
        project prj0=projects[p];
        if (prj0.delevered!=0) continue;;
        int days=prj0.days;
        skill* arr=prj0.requirement;
        int n=prj0.numbre_of_employeres;
        delevered test;
        test.prjID=p;
        test.devIDs=(int *)malloc(n*sizeof(int));
        int c=0;//counter 
        for(int i=0;i<n;i++)
        {
            char*skill=arr[i].skill;
            printf("%d %s\n",i,skill);
            int lvl=arr[i].level;
            int ip=strbinarySearch(listskills,0,S-1,skill);
            SkillNode*root=skilltree[ip];
            SkillNode*target=findSkillNode(root,lvl);


            if (target!=NULL)
            {
                employers[target->id].available=days+Time;
            }
            else 
            {
                target=NULL;
                target=findvalide(root,lvl,employers,Time);
                if (target==NULL) break;
                else employers[target->id].available=days+Time; 
            }
            test.devIDs[c]=target->id;c++;
        }

        if (c==n)
        {
            projects[p].delevered=1;
            deleveredprojects[D]=test;
            D++;
        }
    }
    Time++;
}

printf("%d\n",D);
for(int i=0;i<D;i++)
{
    printf("%s\n",listproj[deleveredprojects[i].prjID]);
}


// freee everything !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
return 0;
}

/* 3 3
meryem 1
C 2
ahmad 2
HTML 5
CSS 5
maria 1
Python 3
batata 5 10 5 1
C 3
maticha 7 10 7 2
HTML 3
C 2
floss 10 20 20 2
Python 3
HTML 3 */