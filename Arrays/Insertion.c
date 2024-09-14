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

    int pos,data;
    printf("\nEnter the position to be inserted : ");
    scanf("%d",&pos);           // taking position from user    

    printf("Enter the data to be inserted : ");
    scanf("%d",&data);          // taking data to be inserted at specified position

    //logic for insertion
    for(i=n-1;i>=pos;i--)
    {
        arr[i+1]=arr[i];        
    }
    arr[i+1] = data;              
    n = n+1;

    printf("The array after insertion is : ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);

    return 0; 

}