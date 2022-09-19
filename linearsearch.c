// linear search in c
#include <stdio.h>
int main()
{
    int i,n,search;
    printf("Enter number of elements : ");   
    scanf("%d",&n);
    int a[n];
    printf("Enter %d integers: \n",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter value to find: ");
    scanf("%d",&search);
    for(i=0;i<n;i++)
    {
        if(a[i]==search)
        {
            printf("%d found at location %d.",search,i+1);
            break;
        }
    }
    if(i==n)
        printf("Not found! %d isn't present in the list.",search);
    return 0;
}
