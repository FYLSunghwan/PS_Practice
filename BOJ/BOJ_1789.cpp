//BOJ 1789
#include <cstdio>
#include <cmath>
long long int c;
int main() {
    scanf("%lld",&c);
    printf("%lld",((long long int)(sqrt(1+8*c))-1)/2);
    return 0;
}