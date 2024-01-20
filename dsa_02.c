#include <stdio.h>

int binarySearch(int a[],int beg,int end,int val) {
    int mid;
    if(end>=beg) {
        mid=(beg+end)/2;
        if(a[mid]==val) {
            return mid+1;
        }
        else if(a[mid]<val) {
            return binarySearch(a,mid+1,end,val);
        }
        else {
            return binarySearch(a,beg,mid-1,val);
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
    res=binarySearch(a,0,n-1,val);
    if(res==-1) {
        printf("searching element is not present in the array. \n");
    }
    else {
        printf("searching element is present at %d position of array. \n",res);
    }
    return 0;
}
