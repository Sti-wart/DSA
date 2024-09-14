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
   
    //logic for sorting(Bubble Sort)

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }


    printf("\nThe array after sorting : ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);

    return 0; 

}