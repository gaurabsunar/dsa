#include <stdio.h>
int sum(int n)
{
    if (n > 0)
    {
        return n + sum(n - 1);
    }
}
int main()
{
    int num;
    printf("Enter num: ");
    scanf("%d", &num);
    int ans = sum(num);
    printf("Sum %d", ans);
    return 0;
}