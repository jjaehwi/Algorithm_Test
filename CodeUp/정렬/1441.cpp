// 버블 정렬
#include <stdio.h>
int a[10001];
int n, i, j, temp;
int main()
{
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    // for (i = 1; i < n; i++) 는 필요없어도 될 듯.
    for (i = 1; i < n; i++)
    {
        for (j = 0; j <= n - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    for (i = 1; i <= n; i++)
        printf("%d\n", a[i]);
    return 0;
}