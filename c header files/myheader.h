#ifndef myheader
#include<stdio.h>
#include <math.h>
#include<stdlib.h>
// #include <algorithm>
#define swap(x,y,temp) temp=x; x=y; y=temp;


int temp;
void Swap(int *x,int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}




void insertionSort(int a[],int low,int high)
{
    
    for(int i=low+1; i<high; i++)
    {
        int value = a[i];
        int j = i;

        while(j>low && a[j-1]>value)
        {
            a[j] = a[j-1];
            j--;
        }

        a[j]=value;

    }
}

int lPartition(int a[],int low,int high)
{
    int i,pivot=a[high];
    int j=low-1;
    for(i=low; i<high; i++)
    {
        
        if(a[i]<pivot)
            j++;
            
            Swap(&a[i],&a[j]);
    }
    Swap(&a[j+1],&a[high]);

   
    return j+1;
}

int randomPartition(int a[],int l,int h)
{
    int pivot;
    pivot = rand() % (h - l +1) + l;
    Swap(&a[pivot],&a[h]);

    return lPartition(a,l,h);
}

int DeleteHeap(int A[], int n)
{
    int i,j,temp,val,x ;
    val=A[1];
    x=A[n];
    A[1]=A[n];

    A[n]=val;

    i=1;j=i*2;

    while (j<n-1)
    {
        if(A[j+1]>A[j])
        j=j+1;

        if(A[i]<A[j])
        {
            temp=A[i];          //swap
            A[i]=A[j];
            A[j]=temp;
            i=j;
            j=2*j;      //move into left child
        }
        else    
            break;
    }
    
    return val;

}

int temp;  
  
void heapify(int arr[], int size, int i)  
{  
int largest = i;    
int left = 2*i + 1;    
int right = 2*i + 2;    
  
if (left < size && arr[left] >arr[largest])  
largest = left;  
  
if (right < size && arr[right] > arr[largest])  
largest = right;  
  
if (largest != i)  
{  
temp = arr[i];  
    arr[i]= arr[largest];   
    arr[largest] = temp;  
heapify(arr, size, largest);  
}  
}  
  
void heeapSort(int arr[], int size)  
{  
int i;  
for (i = size / 2 - 1; i >= 0; i--)  
heapify(arr, size, i);  
for (i=size-1; i>=0; i--)  
{  
temp = arr[0];  
    arr[0]= arr[i];   
    arr[i] = temp;  
heapify(arr, i, 0);  
}  
}  
  


void insertHeap(int A[],int n)
{
    int i=n, temp;
    temp = A[i];

    while(i>1 && temp>A[i/2])           //camparing with parent 
    {
        A[i] = A[i/2];           //copy the parent value that is copy the element from A[i/2]
        i=i/2;                        //i shold be move to parent
    }       
    A[i]=temp;          //move to the right place
}

  
void heapSort(int a[],int l,int n)
{
    for(int i=2;i<=n;i++)
        insertHeap(a,i);
    for(int i=n;i>1;i--)
        DeleteHeap(a,n);
    
}

void csort(int a[],int *low,int *high,int max)
{
    
     // perform insertion sort if partition size is 16 or smaller
    if((high-low)<16){
        insertionSort(a,low, high);
    } 

     // perform heapsort if the maximum depth is 0
    else if(max==0){
        heeapSort(a,(high)-1);
    }
    else{
        // otherwise, perform Quicksort

        int pivot = randomPartition(a,low ,high ); 
        csort(a,low,a + pivot - 1, max-1); 
        csort(a, a+ pivot +1, high, max -1);
    }

}

#define myheader
#endif


