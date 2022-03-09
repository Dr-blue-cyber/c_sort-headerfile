#ifndef intro_sort 

void InsertSort(int *arr,int n){
    
    for(int i=1; i<=n; i++){
        int value = arr[i];
        int j=i;
        while (j>0 & arr[j-1]>value)
        {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j]=value;
        
    }
}

void maxHeapify(int *arr,int heapSize,int index){
    int largest = 0;
    int left = (index +1)*2 -1;
    int right = (index+1)*2; 

    if(left < heapSize && arr[left]>arr[index]) 
        largest = left ; 
    else 
        largest = index;

    if(right < heapSize && arr[right]>arr[largest])  
        largest = right; 

    if(largest != index){
        int temp = arr[index];
        arr[index] = arr[largest];
        arr[largest] = temp; 

        maxHeapify(arr,heapSize,largest);
    }
} 

void heapSort(int *arr,int n){
    int heapSize = n;

    for(int p=(heapSize-1)/2;p>=0;--p){
        maxHeapify(arr,heapSize,p);
    }

    for(int i=n-1;i>0;--i){

        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp; 

        --heapSize;
        maxHeapify(arr,heapSize,0);
    }
}


#define intro_sort 
#endif