#include <stdio.h>
int main()
{
    int i,n,pos;
    printf("Enter number of elements : ");   
    scanf("%d",&n);
    int a[n];
    printf("Enter %d integers: \n",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter position of the new Element : ");
    scanf("%d",&pos);
    for(i=n-1;i>=pos-1;i--)
        a[i+1]=a[i];
    printf("Enter value to insert : ");
    scanf("%d",&a[pos-1]);
    printf("Updated list is : ");
    for(i=0;i<=n;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}