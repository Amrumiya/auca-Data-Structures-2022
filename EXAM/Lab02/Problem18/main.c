#include <stdio.h>
#include <stdlib.h>

#define M 5
#define N 4

void readArray(int *beg, int n);
void reverse(int *beg, int *end);
void printArray(int *beg, int *end);

int main(void)
{
    int *data = NULL;
    size_t sz = 0;
    size_t cp  = 0;

    int n;
   while(scanf("%d", &n) == 1)
   {
    if(cp == sz)
    {
        cp = (cp == 0) ? 1 : 2 * cp;
        int *Data = (int *)malloc(cp * sizeof(int));

        for(size_t i  = 0; i < sz; i++)
        {
            Data[i] = data[i];
        }
        free(data);
        data = Data;
    }
    data[sz++] = n;
   } 

   printArray(data, data + sz);

   reverse(data, data + sz);
   printArray(data, data + sz);






}

void printArray(int *beg, int *end)
{
    while(beg != end)
    {
        printf("%d", *beg++);
    }
    printf("\n");

}

void readArray(int *beg, int n)
{
    while(n--)
    {
        scanf("%d", beg++);
    }
}

void reverse(int *beg, int *end)
{
    for(;;)
    {
        if(beg == end) break;

        --end;

        if(beg == end) break;

        int t = *beg;
        *beg = *end;
        *end = t;

        beg++;
    }
}

