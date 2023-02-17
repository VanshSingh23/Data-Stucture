#include<stdio.h>
void main(){
    printf("Vansh Singh IT-C 2100320130190\n");
    int n;
    printf("Enter number of terms:\n");
    scanf("%d",&n);
    printf("Enter Array:\n");
    int A[n];
    for(int i=0;i<n;i++){
            scanf("%d",&A[i]);
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(A[j]>A[j+1]){
                int swap=A[j];
                A[j]=A[j+1];
                A[j+1]=swap;
            }
        }
    }
printf("Sorted Array:\n");
for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
}    