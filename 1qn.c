#include<stdio.h>
int fact(int n){
    if(n<=1){
        return 1;
    }
    else{
        return n*fact(n-1);
    }
}
int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d",&num);
    int ans = fact(num);
    printf("Factorial of %d is: %d", num, ans);
    return 0;
}