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

    int key,index,found=0;
    printf("\nEnter the key to be searched : ");
    scanf("%d",&key);           // taking key from user for search   

    //logic for searching
    for(i=0;i<n;i++)
    {
        if(key==arr[i])
        {
            found=1;
            index=i;
            break;
        }
    }

    if(found)
    {
        printf("The key %d is found at index %d",key,index);
    }
    else
    {
        printf("The key %d is not found in an array",key);
    }
    
    return 0; 

}