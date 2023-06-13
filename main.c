#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<string.h>
#include"sorting.h"
#include"AVL.h"

int main(int argc,char*argv)
{
 
FILE *fl;


fl = fopen("input1.txt","r");

if(fl == NULL)
   {
      printf("Error!");   
      exit(1);             
   }


int N,M;
fscanf(fl,"%d %d",&N,&M);

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
    char name[21];
    int n;
    fscanf(fl,"%s",name);
    fscanf(fl,"%d",&n);

    for (int k=0;k<20+1;k++)
    {
        devnames[i][k]=name[k];
    }
    employee test1;
    test1.name=(char*)malloc(strlen(name)*sizeof(char)+1);
    for (int j=0;j<strlen(name)+1;j++){test1.name[j]=name[j];}
    test1.nskils=n;
    test1.skilles=(skill*)malloc(n*sizeof(skill));
    test1.strskills=(char**)malloc(n*sizeof(char**));
    for (int k=0;k<n;k++){test1.strskills[k]=(char*)malloc((21)*sizeof(char));}
    for (int j=0;j<n;j++)
    {
        char *skillname=(char*)malloc(21*sizeof(char));
        int level;
        fscanf(fl,"%s",skillname);
        fscanf(fl,"%d",&level);
        skill testskill;
        testskill.level=level;
        for(int b=0;b<strlen(skillname)+1;b++){test1.strskills[j][b]=skillname[b]; }
        testskill.skill=-1;
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

//sorting the skilles 
char ** listskills=(char**)malloc((S)*sizeof(char*));
for(int i=0;i<S;i++){listskills[i]=(char*)malloc(21*sizeof(char));}
for(int i=0;i<S;i++)
{
    for (int k=0;k<21;k++)
    {
        listskills[i][k]=listskills0[i][k];
    }
} 

free(listskills0);
strfreeTree(root); 
strmergeSort(listskills,0,S-1);



project*projects=(project*)malloc(M*sizeof(project));
for (int i =0;i<M;i++)
{
    char *name=(char*)malloc(21*sizeof(char));
    int days,score,bestb,nofemp;
    fscanf(fl,"%s",name);
    fscanf(fl,"%d",&days);
    fscanf(fl,"%d",&score);
    fscanf(fl,"%d",&bestb);
    fscanf(fl,"%d",&nofemp);
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
        fscanf(fl,"%s",skillname);
        fscanf(fl,"%d",&level);
        skill testskill;
        testskill.level=level;
        testskill.skill=strbinarySearch(listskills,0,S-1,skillname);
        test1.requirement[j]=testskill;
    }
    projects[i]=test1;
}
strmergeSort(devnames,0,N-1);
strmergeSort(listproj,0,M-1);

for (int i=0;i<N;i++)
{
    employers[i].id=strbinarySearch(devnames,0,N-1, employers[i].name);
    for (int k=0;k<employers[i].nskils;k++)
    {   
        employers[i].skilles[k].skill=strbinarySearch(listskills,0,S-1,employers[i].strskills[k]);
    }
    free(employers[i].strskills);
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
        int ip=list[j].skill;
        SkillNode * root=skilltree[ip];
        root=insertSkillNode(root,i,list[j].level);
        skilltree[ip]=root;
    }
} 

delevered*deleveredprojects=(delevered*)malloc(M*sizeof(delevered));//A list of delevered projects
int D=0;//The number deleveres projects
int finale_score=0;
int Time=0;//the numbere of days 

int *availableat=(int*)malloc(N*sizeof(int));

for (int k=0;k<N;k++) availableat[k]=-1;

while(true)
{
    for (int k=0;k<M;k++)
    {
        projects[k].grad=grade(projects[k],Time);
    }
    prjmergeSort(projects,0,M-1);
    if (projects[0].grad==0) break;
    if (projects[0].delevered!=0) break;
    for(int p=0;p<M;p++)
    {
        int*mentorship=malloc(S*sizeof(int));
        for(int k=0;k<S;k++) mentorship[k]=0;
    
        project prj0=projects[p];
        if (prj0.delevered!=0) break ;
        int days=prj0.days;
        skill* arr=prj0.requirement;
        int n=prj0.numbre_of_employeres;
        delevered test;
        test.prjID=p;
        test.devIDs=(int *)malloc(n*sizeof(int));
        test.ndev=n;
        int c=0;//counter 
        for(int i=0;i<n;i++)
        {
            int ip=arr[i].skill;
            int lvl=arr[i].level;

            if (mentorship[ip]>=lvl)
                lvl-=1;
            SkillNode*root=skilltree[ip];
            SkillNode *org=best_condidate(root,lvl,employers,Time,availableat);
            if (org==NULL) break;
            SkillNode target=*org;
            if (target.lvl==lvl) 
            {
                skilltree[ip]= skillDeleteNode(skilltree[ip],target.lvl,target.id);
                skilltree[ip]= insertSkillNode(skilltree[ip],target.id,lvl+1);
            }    
            for (int k=0;k<employers[target.id].nskils;k++)
            {
                int a=employers[target.id].skilles[k].skill;//the id of the skill
                mentorship[a]=max(employers[target.id].skilles[k].level,mentorship[a]);//adding the skilles of the developer to the skilles that can be mentored
            } 
 
            test.devIDs[c]=target.id;
            c++;
        }

        if (c==n)
        {
            for(int k=0;k<test.ndev;k++)
            {
                availableat[test.devIDs[k]]=Time+days;
            }
            projects[p].delevered=1;
            deleveredprojects[D]=test;
            finale_score += min(prj0.score,prj0.score+prj0.best_befor-(Time+prj0.days));
            D++;
        }
        free(mentorship);
    }
    Time++;
}
/* for(int k=0;k<D;k++)
{
    printf("%s\n",listproj[deleveredprojects[k].prjID]);
    for (int n=0;n<deleveredprojects[k].ndev;n++)
    {
        printf("%s\n",devnames[deleveredprojects[k].devIDs[n]]);
    }
} */
printf("%d\n",finale_score);

// freee everything !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
return 0;
}
