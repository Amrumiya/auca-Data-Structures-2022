#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    printf("size of array: ");

    int n;
    scanf("%d", &n);

    int *dynArray = (int *) malloc(n * sizeof(int));
    if(dynArray == NULL)
    {
        printf("Not enough memory");
        exit(1);
    }

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &dynArray[i]);
    }

    reverse(dynArray, dynArray + n);

    printfArray(dynArray, dynArray + n);

    free(dynArray);




}