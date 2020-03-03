#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int N, M; cin >> N >> M;
    vector<int> arr(N);
    for (int i = 0; i < M; ++i) arr[i] = 1;

    do {
        for(int i = 0; i < N; ++i) {
            if(arr[i])
            {
                cout << i+1 << " ";
            }
            cout << endl;
        }
        cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
    } while (next_permutation(begin(arr), end(arr)));
    return 0;
}