#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<string.h>
#include"sorting.h"
#include"AVL.h"

int main(int argc,char*argv)
{

char**INPUT[5]={"input1.txt","input.txt","input3.txt","input2exp.txt","input4.txt"};

for(int _ =0;_<5;_++)
{

FILE *fl;
fl = fopen(INPUT[_],"r");

if(fl == NULL)
   {
      printf("Error!");   
      exit(1);             
   }
int holidays=200;
int N,M;
fscanf(fl,"%d %d",&N,&M);

char ** devnames=(char**)malloc(N*sizeof(char*));
for(int i=0;i<N;i++){devnames[i]=(char*)malloc(21*sizeof(char));}

char ** listproj=(char**)malloc(M*sizeof(char*));
for(int i=0;i<M;i++){listproj[i]=(char*)malloc(21*sizeof(char));}

char ** listskills0=(char**)malloc(N*100*sizeof(char*));
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
                        if(N==800 && M==10000) 
            holidays=2000; 
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
    //sklmergeSort(test1.requirement,0,test1.numbre_of_employeres-1);
    projects[i]=test1;
}

strmergeSort(devnames,0,N-1);
strmergeSort(listproj,0,M-1);



////////////////////////////////////// THE END OF READING THE INPUT///////////////////////////////////////////////////////

int Arr[9][3] ={{1,1,1},{0,1,0},{0,0,0},{1,0,0},{0,0,1},{1,1,0},{1,0,1},{0,1,1},{1,2,1}};

for (int t=0;t<9;t++)
{
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
    projects[i].delevered=-1;
}

dev** globalskills=(dev**)malloc(S*sizeof(dev*));//an array of arrays that store for each skill all the contributeres that have this skill

for (int k=0;k<S;k++)
{
    globalskills[k]=(dev*)malloc(N*sizeof(dev));
    for(int i=0;i<N;i++)
    {
        globalskills[k][i].id=i;
        globalskills[k][i].lvl=0;
    }
}

int*temp=(int*)malloc(S*sizeof(int));//an array  that keeps track of the lenth of each array of the skills
for(int j=0;j<S;j++) temp[j]=0;
for(int i=0;i<N;i++)
{
    for (int k=0;k<employers[i].nskils;k++)
    {
        globalskills[employers[i].skilles[k].skill][employers[i].id].id=employers[i].id;
        globalskills[employers[i].skilles[k].skill][employers[i].id].lvl=employers[i].skilles[k].level;
        temp[employers[i].skilles[k].skill]+=1;
    }
}
free(temp);

for (int k=0;k<S;k++)
{
    devmergeSort(globalskills[k],0,N-1);
}

//////////////////////////////////////////THE END OF DATA PREPARATION///////////////////////////////////////////////////////////

//////////////////////////////////////////starting solving the probleme//////////////////////////////////////////////////////////////////





int breakpoint=0;// A CONTER OF THE NUMBER OF HOLIDAYS 
delevered*deleveredprojects=(delevered*)malloc(M*sizeof(delevered));//A list of delevered projects
int D=0;//The number deleveres projects
int finale_score=0;
int Time=0;//the numbere of days 

int *availableat=(int*)malloc(N*sizeof(int));//an array that keep track of the availabality of each employer
for (int k=0;k<N;k++) availableat[k]=-1;

while(true)
{
    if(breakpoint==holidays) break;
   for (int k=0;k<M;k++)
    {
        projects[k].grad=grade(projects[k],Time,Arr[t]);//The association of the grades for each project
    }
    prjmergeSort(projects,0,M-1); //sorting the  projects 
    if (projects[0].grad==0) break;//we can't get any score anymore so we should stop
    if (projects[0].delevered!=0) break;//All the projects are delevered
    for(int p=0;p<M;p++)
    {
        int*mentorship=malloc(S*sizeof(int));//an array that contain the maximum score that can be mentored for each skill
        for(int k=0;k<S;k++) mentorship[k]=0;
        project prj0=projects[p];
        if (prj0.delevered!=0) break ;
        int days=prj0.days;
        skill* arr=prj0.requirement;
        int n=prj0.numbre_of_employeres;
        delevered test;
        test.prjID=prj0.id;
        test.devIDs=(int *)malloc(n*sizeof(int));
        test.ndev=n;
        test.starting_day=Time;
        test.days=days;
        mentored upgrade[N];
        int u=0;//counter of the number of employeres hwo will upgrade there lvl
        int c=0;//counter of the number of contributeres associated to the project 
        AVLNode*cureantly_selected=NULL;
        for(int i=0;i<n;i++)
        {
            int mentorbool=0;//if the skill can be mentored
            int ip=arr[i].skill;
            int lvl=arr[i].level;

            if (mentorship[ip]>=lvl)//if there is an mentore
                {
                    mentorbool=1;
                    lvl-=1;
                } 
            dev *skillarr=globalskills[ip];
            int index=best_dev(skillarr,lvl,employers,Time,availableat,N,cureantly_selected);
            if (index==-1) break;//there is no one to do the skille 

            dev target=skillarr[index];

            if (mentorbool==1)
            {
                if (target.lvl==lvl || target.lvl==lvl+1)
                {
                    upgrade[u].id=target.id;
                    upgrade[u].ip=ip;
                    upgrade[u].lvl=target.lvl;
                    u++;
                }
            }
            else if (target.lvl==lvl)
            {
                upgrade[u].id=target.id;
                upgrade[u].ip=ip;
                upgrade[u].lvl=target.lvl;
                u++;   
            } 
            for (int k=0;k<employers[target.id].nskils;k++)
            {
                int a=employers[target.id].skilles[k].skill;//the id of the skill
                mentorship[a]=max(employers[target.id].skilles[k].level,mentorship[a]);//adding the skilles of the developer to the skilles that can be mentored
            }  
            cureantly_selected=intinsertNode(cureantly_selected,target.id);
            test.devIDs[c]=target.id;
            c++;
        }
        intfreeTree(cureantly_selected);
        if (c==n)
        {
            for(int k=0;k<test.ndev;k++)
            {
                availableat[test.devIDs[k]]=Time+days;
            }
            for(int k=0;k<u;k++)
            {
                Upgrade(globalskills[upgrade[k].ip],upgrade[k],N);
            } 
            projects[p].delevered=1;
            deleveredprojects[D]=test;
            finale_score += min(prj0.score,max(0,prj0.score+prj0.best_befor-(Time+prj0.days)));
            D++;
        }
        free(mentorship);
    }
    int  min=1000000000;
    for (int i=0;i<N;i++)
    {
        if ( min > availableat[i] && availableat[i] >= Time+1)
            min=availableat[i];
    }
    if (min==1000000000) min =Time+1; 
    if(min==Time+1) breakpoint++;
    Time=min ;
    
}
/* for(int k=0;k<D;k++)
{
    printf("%s\n",listproj[deleveredprojects[k].prjID]);
    for (int n=0;n<deleveredprojects[k].ndev;n++)
    {
        printf("%s\n",devnames[deleveredprojects[k].devIDs[n]]);
    }
}   */ 
printf("%s :%d\n",INPUT[_], finale_score);


/////////////////////////////////////// TESTING THE VALIDITY OF THE OUPUT////////////////////////////////////////////


/* int *testavailable=(int *)malloc(N*sizeof(int));
for (int k=0;k<N;k++) testavailable[k]=-1;
for (int i=0;i<D;i++)
{
    for (int k=0;k<deleveredprojects[i].ndev;k++)
    {
        if (testavailable[deleveredprojects[i].devIDs[k]] <= deleveredprojects[i].starting_day) 
            testavailable[deleveredprojects[i].devIDs[k]]=deleveredprojects[i].starting_day+deleveredprojects[i].days;
        else 
            printf("Testing failled !!!%d \n",i);
        for(int j=k+1;j<deleveredprojects[i].ndev;j++)
        {
            if(deleveredprojects[i].devIDs[j]==deleveredprojects[i].devIDs[k]) 
            {
                printf("There is two in the same project!!%s \n",listproj[deleveredprojects[i].prjID]);
                break;
            }
        }
    }
}    */
for(int i=0;i<S;i++)
{
    free(globalskills[i]);
}
free(globalskills);
for(int i=0;i<D;i++) free(deleveredprojects[i].devIDs);
free(deleveredprojects);
free(availableat);
}
for (int i=0;i<M;i++) free(projects[i].requirement);
free(projects);
for (int i=0;i<N;i++) free(employers[i].skilles);
free(employers);

free(listproj);
free(devnames);
free(listskills);

}

// freee everything !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
return 0;
}
