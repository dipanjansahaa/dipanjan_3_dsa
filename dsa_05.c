#include <stdio.h>

void swap(int *xp, int *yp) {
    int temp=*xp;
    *xp=*yp;
    *yp=temp;
}

void selectionSort(int arr[],int n) {
    int i,j,min;
        for (i=0;i<n-1;i++) {
        min=i;
        for(j=i+1;j<n;j++) {
            if(arr[j]<arr[min]) {
                min=j;
            }
        }
        swap(&arr[min],&arr[i]);
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
    selectionSort(arr, n);
    printf("sorted array is: \n");
    for(i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
    return 0;
}
