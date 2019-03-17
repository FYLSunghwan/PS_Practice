//BOJ 10828
#include <stdio.h>
#include <string.h>
int stack[10000000],pe,n,t;

void push(int k) { stack[++pe]=k; }
void pop() {
    if(pe) printf("%d\n",stack[pe--]);
    else printf("-1\n");
}
int size() { return pe; }
int empty() { return !pe; }
int top() {
    if(pe) return stack[pe];
    return -1;
}

int main() {
    scanf("%d",&n);
    while(n--) {
        //printf("pe: %d, stack[pe]: %d",pe,stack[pe]);
        char input[10];
        scanf("%s",input);
        if(!strcmp("push",input)) {
            scanf("%d",&t);
            push(t);
        }
        if(!strcmp("pop",input)) pop();
        if(!strcmp("size",input)) printf("%d\n",size());
        if(!strcmp("empty",input)) printf("%d\n",empty());
        if(!strcmp("top",input)) printf("%d\n",top());
    }
    return 0;
}