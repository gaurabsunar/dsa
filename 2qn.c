#include <stdio.h>
int main()
{
    int num, i, ans=1;
    printf("Enter num: ");
    scanf("%d",& num);
    if (num >= 1)
    {
        for (i = 1; i <= num; i++)
        {
            ans = ans*i;
        }
    }
    printf("Factorial %d", ans);

    return 0;
}