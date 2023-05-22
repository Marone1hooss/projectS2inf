#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<string.h>
#include"sorting.h"

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

int max(int a,int b)
{
    if (a>b) return a;
    else return b;
}

int grade(project prj,int time)
{
    int d=prj.days;
    int n=prj.numbre_of_employeres;
    int best=prj.best_befor;
    int s=min(prj.score,max(0,prj.score+best-(time+d)));
    int grade=s/(n*d);
    return grade;
}

