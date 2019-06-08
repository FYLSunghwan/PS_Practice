//BOJ 10039
#include <iostream>
int k,sum;
int main() {
    for(int i=0;i<5;i++) {
        std::cin>>k;
        sum+=(k>40?k:40);
    }
    std::cout<<sum/5;
    return 0;
}