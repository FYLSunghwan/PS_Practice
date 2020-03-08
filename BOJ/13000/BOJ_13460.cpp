#include <bits/stdc++.h>
using namespace std;

struct Cord {
    int y;
    int x;
    Cord(int y_, int x_) : y(y_), x(x_) {}
    Cord() : y(0), x(0) {};
    Cord operator+(const Cord& rhs) {
        Cord cord;
        cord.x = x + rhs.x;
        cord.y = y + rhs.y;
        return cord;
    }
    Cord operator-(const Cord& rhs) {
        Cord cord;
        cord.x = x - rhs.x;
        cord.y = y - rhs.y;
        return cord;
    }    
    Cord& operator+=(const Cord& rhs) {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }
    bool operator==(const Cord& rhs) {
        return x==rhs.x && y==rhs.y;
    }
};

struct State {
    Cord R;
    Cord B;
    Cord O;
};

Cord d[4] = {Cord(0,-1), Cord(0,1), Cord(1,0), Cord(-1,0)};
int N, M;
char board[10][10];

bool IsPos(Cord cord) {
    return cord.y < N && cord.y >=0 && cord.x < M && cord.x >=0 && board[cord.y][cord.x]=='.';
}

int mov(State& state, int dir) {
    int rcnt=0, bcnt=0;
    State upd = state;
    while(IsPos(upd.B+d[dir])) {
        upd.B += d[dir];
        if(upd.B == upd.O) return -1;
        ++bcnt;
    }
    while(IsPos(upd.R+d[dir])) {
        upd.R += d[dir];
        if(upd.R == upd.O) return 1;
        ++rcnt;
    }
    if(upd.R == upd.B) {
        if(rcnt > bcnt) {
            state.R = upd.R - d[dir];
            state.B = upd.B;
        }
        else {
            state.R = upd.R;
            state.B = upd.B - d[dir];
        }
    }
    else {
        state.R = upd.R;
        state.B = upd.B;
    }
    return 0;
}

int main() {
    cin >> N >> M;
    State state;
    for(int i=0;i<N;i++) {
        cin >> board[i];
        for(int j=0;j<M;j++) {
            if(board[i][j]=='R') {
                state.R = Cord(i, j);
                board[i][j]='.';
            }
            if(board[i][j]=='B') {
                state.B = Cord(i ,j);
                board[i][j]='.';
            }
            if(board[i][j]=='O') {
                state.O = Cord(i, j);
                board[i][j]='.';
            }
        }
    }
    queue<pair<int, State> > q;
    q.push(make_pair(0,state));
    while(!q.empty()) {
        int cnt = q.front().first;
        State st = q.front().second;
        q.pop();
        if(cnt==10) {
            cout <<"-1";
            return 0;
        }
        for(int i=0;i<4;i++) {
            State tmpst = st;
            int res = mov(tmpst, i);
            if(res==1){
                cout << cnt+1;
                return 0;
            }
            if(res==0) {
                q.push(make_pair(cnt+1, tmpst));
            }
        }
    }
    return 0;
}