#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<string.h>
#include"sorting.h"

void sklmerge(skill* arr, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Create temporary arrays
    //project* L=(project*)malloc(n1*sizeof(project));
    //project* R=(project*)malloc(n2*sizeof(project));
    skill L[n1];
    skill R[n2];
    
    // Copy data to temporary arrays
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    // Merge the temporary arrays back into arr
    i = 0;
    j = 0;
    k = left;
    
    while (i < n1 && j < n2) {
        if (L[i].level <= R[j].level) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void sklmergeSort(skill* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        // Sort first and second halves
        sklmergeSort(arr, left, mid);
        sklmergeSort(arr, mid + 1, right);
        
        // Merge the sorted halves
        sklmerge(arr, left, mid, right);
    }
}



void prjmerge(project* arr, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Create temporary arrays
    //project* L=(project*)malloc(n1*sizeof(project));
    //project* R=(project*)malloc(n2*sizeof(project));
    project L[n1];
    project R[n2];
    
    // Copy data to temporary arrays
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    // Merge the temporary arrays back into arr
    i = 0;
    j = 0;
    k = left;
    
    while (i < n1 && j < n2) {
        if (L[i].grad >= R[j].grad) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void prjmergeSort(project* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        // Sort first and second halves
        prjmergeSort(arr, left, mid);
        prjmergeSort(arr, mid + 1, right);
        
        // Merge the sorted halves
        prjmerge(arr, left, mid, right);
    }
}

void intmerge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Create temporary arrays
    int L[n1], R[n2];
    
    // Copy data to temporary arrays
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    // Merge the temporary arrays back into arr
    i = 0;
    j = 0;
    k = left;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void intmergeSort(int * arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        // Sort first and second halves
        intmergeSort(arr, left, mid);
        intmergeSort(arr, mid + 1, right);
        
        // Merge the sorted halves
        intmerge(arr, left, mid, right);
    }
}


void strmerge(char **arr, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    char **L = (char **)malloc(n1 * sizeof(char *));
    char **R = (char **)malloc(n2 * sizeof(char *));

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (strcmp(L[i], R[j]) <= 0) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void strmergeSort(char **arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        strmergeSort(arr, left, mid);
        strmergeSort(arr, mid + 1, right);
        strmerge(arr, left, mid, right);
    }
}

int strbinarySearch(char** arr, int left, int right, char *target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(arr[mid], target);

        if (cmp == 0) {
            return mid;  // Found the target at index mid
        } else if (cmp < 0) {
            left = mid + 1;  // Target is in the right half
        } else {
            right = mid - 1;  // Target is in the left half
        }
    }

    return -1;  // Target was not found
}


int min(int a,int b)
{
    if (a<b) return a;
    else return b;
}

int Max(int a,int b)
{
    if (a>b) return a;
    else return b;
}

void devmerge(dev arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    dev leftArr[n1], rightArr[n2];

    // Copy data to temporary arrays
    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[]
    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i].lvl >= rightArr[j].lvl) { // Compare in descending order
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArr[], if any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArr[], if any
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void devmergeSort(dev arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort the left and right halves
        devmergeSort(arr, left, mid);
        devmergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        devmerge(arr, left, mid, right);
    }
}

int binarySearch(dev arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid].lvl == target) {
            return mid; // Found the target
        } else if (arr[mid].lvl < target) {
            right = mid - 1; // Target is in the left half
        } else {
            left = mid + 1; // Target is in the right half
        }
    }

    return -1; // Target not found
}

int findSmallestGreaterOrEqual(dev arr[], int size, int N) {
    int left = 0;
    int right = size - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid].lvl >= N) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return result;
}

int intfindNode(AVLNode* node, int key) {
    if (node == NULL)
        return -1;
    if (key < node->data)
        return intfindNode(node->left, key);
    else if (key > node->data)
        return intfindNode(node->right, key);
    else
        return node->data;
}


unsigned long  int employeegrade(dev temp,int lvl,employee*employers)
{

    return employers[temp.id].nskils*(temp.lvl-lvl+1);
}

int best_dev(dev* list, int lvl,employee*employers,int Time,int *availableat,int number_of_employeres,AVLNode*curently_selected)
{
    if (lvl>list[0].lvl) return-1;
    int index=findSmallestGreaterOrEqual(list,number_of_employeres,lvl);
   // while(index>0 && ( list[index-1].lvl == list[index].lvl ) ) index--;
    while(index<number_of_employeres-1 && ( list[index+1].lvl >= lvl ) ) index++;

    //if (list[index].lvl==lvl && availableat[list[index].id]<=Time && intfindNode(curently_selected,list[index].id)==-1) return index; 
    int temp=-1;
    int min =1000000000;

    for (int k=index;k>=0;k--)
    {
        if (employeegrade(list[k],lvl,employers)<min && availableat[list[k].id]<=Time && intfindNode(curently_selected,list[k].id)==-1)
        {
            temp=k;
            min=employeegrade(list[k],lvl,employers);
        }
    }
    return temp;
}

void Upgrade(dev*list,mentored target,int n )
{
    int index=binarySearch(list,0,n-1,target.lvl);
    int i=0;
    int left=index;
    int right=index;
    while(list[left].id!=target.id && list[right].id!=target.id)
    {
        if(list[left-1].lvl==target.lvl) left--;
        if(list[right+1].lvl==target.lvl) right++;
    }
    if (list[left].id!=target.id) left=right;
    index=left;

    list[index].lvl++;
    if (index>0)
    {
        if (list[index-1].lvl< target.lvl+1)
        {
            devmergeSort(list,0,n-1);
        }
    }
}


long long int grade(project prj,int time)
{
    if (prj.delevered == 1) return -1;
    int d=prj.days;
    int n=prj.numbre_of_employeres;
    int best=prj.best_befor;
    int s=min(prj.score,Max(0,prj.score+best-(time+d)));
    if (s==0) return 0;
    float grade=10000*s/(n*d);
    return ((long long int)(grade));
}
