#include<stdio.h>

int main()
{
    int n,arr[100],i;
    printf("Enter the number of elements : ");
    scanf("%d",&n);

    printf("Enter the array elements : ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);    // scanning array elements

    printf("The array is : ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);   // displaying array elements

    int pos;
    printf("\nEnter the position to be deleted : ");
    scanf("%d",&pos);           // taking position from user    

    //logic for deletion
    for(i=pos;i<n;i++)
    {
        arr[i]=arr[i+1];        
    }             
    n = n-1;

    printf("The array after deletion is : ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);

    return 0; 

}