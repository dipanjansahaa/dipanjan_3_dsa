#include <stdio.h>

int linearSearch(int arr[],int n,int x) {
    int i;
    for(i=0;i<n;i++) {
        if (arr[i]==x) {
            return i+1;
        }
    }
    return -1;
}

int main() {
    int a[100],val,n,i,res;
    printf("enter the number of element: ");
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        printf("enter element: ");
        scanf("%d",&a[i]);
    }
    printf("enter the value you want to search: ");
    scanf("%d",&val);
    res=linearSearch(a,n,val);
    if(res==-1) {
        printf("searching element is not present in the array. \n");
    }
    else {
        printf("searching element is present at %d position of array. \n",res);
    }
    return 0;
}
