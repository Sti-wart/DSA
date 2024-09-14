#include<stdio.h>

int main()
{
    int n,arr[100],i,j;
    printf("Enter the number of elements : ");
    scanf("%d",&n);

    printf("Enter the array elements : ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);    // scanning array elements

    printf("The given array is : ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);   // displaying array elements
   
    //logic for reversing array

    j=n-1;
    for(i=0;i<n/2;i++)
    {
        int temp = arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        j--;
    }


    printf("\nThe array after reversing : ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);

    return 0; 

}