#include <iostream>
#define inf 1000000
using namespace std;

int n;
int cnt[100001] = {inf,inf,1,inf,2,1};

int main() {
    cin >> n;
    for(int i = 6; i <= n; i++){
        cnt[i] = cnt[i-2] < cnt[i-5] ? cnt[i-2] : cnt[i-5];        
        if(cnt[i] != inf) cnt[i]++;
    }
    if(cnt[n] == inf) cout << -1;
    else cout << cnt[n];
    return 0;
}
