#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* next;
    int data;
    Node(Node* next_, int data_) : next(next_), data(data_) {}
};

int N, M;


int main() {
    cin >> N >> M;
    if(N==1) {
        cout << "<1>";
        return 0;
    }
    if(M==1) {
        cout << "<";
        for(int i=1;i<N;i++) {
            cout << i << ", ";
        }
        cout << N << ">";
        return 0;
    }
    Node* tail = new Node(nullptr, 1);
    Node* head = new Node(tail, 0);
    for(int i=2;i<=N;i++) {
        tail->next = new Node(nullptr, i);
        tail = tail->next;
    }
    tail->next = head->next;
    cout << "<";
    while(--N) {
        for(int i=0;i<M-2;i++)
            head = head->next;
        head = head->next;
        cout << head->next->data << ", ";
        head->next = head->next->next;
    }
    cout << head->data << ">";
    return 0;
}