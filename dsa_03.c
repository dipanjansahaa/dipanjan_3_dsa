#include <stdio.h>

void swap(int *xp, int *yp) {
    int temp=*xp;
    *xp=*yp;
    *yp=temp;
}

void bubbleSort(int arr[], int n) {
    int i,j;
    for(i=0;i<n-1;i++) {
        for(j=0;j<n-i-1;j++) {
            if(arr[j]>arr[j+1]) {
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

int main() {
    int arr[100],n,i;
    printf("enter no. of elements: ");
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        printf("enter element no. %d: ",(i+1));
        scanf("%d",&arr[i]);
    }
    bubbleSort(arr, n);
    printf("sorted array is: \n");
    for(i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
    return 0;
}
