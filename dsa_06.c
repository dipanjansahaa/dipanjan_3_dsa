#include <stdio.h>

int partition(int array[], int low, int high) {
    int pivot=array[high];
    int i=(low-1), t;
    for(int j=low;j<high;j++) {
        if(array[j]<=pivot) {
            i++;
            t=array[i];
            array[i]=array[j];
            array[j]=t;
        }
    }
    t=array[i+1];
    array[i+1]=array[high];
    array[high]=t;
    return (i+1);
}

void quickSort(int array[],int low,int high) {
    if (low<high) {
        int pi=partition(array,low,high);
        quickSort(array,low,pi-1);
        quickSort(array,pi+1,high);
    }
}

int main() {
    int arr[100],n,i;
    printf("enter no. of elements: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("enter element no. %d: ",(i+1));
        scanf("%d",&arr[i]);
    }
    quickSort(arr, 0, n - 1);
    printf("sorted array is: \n");
    for(i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
    return 0;
}
