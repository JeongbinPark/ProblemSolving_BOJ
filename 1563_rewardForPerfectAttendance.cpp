
/*
//계산상 음수가 나올 일 없으니 음수 나오면 MOD만큼 더해줌.
#include <iostream>
#define MOD 1000000
using namespace std;

int N;
int R[1001] = { 1, 3 }, L1[1001] = { 0,1 }, A2[1001] = { 0,0 };

int main() {
	cin >> N;
	for (int i = 2; i <= N; i++) {
		R[i] = 3 * R[i - 1] - L1[i - 1] - A2[i - 1];
		R[i] %= MOD;
		while (R[i] < 0) R[i] += MOD;
		L1[i] = L1[i - 1] + R[i - 1];
		if (i>3) L1[i] -= R[i - 4];
		L1[i] %= MOD;
		while (L1[i] < 0) L1[i] += MOD;
		A2[i] = R[i - 2] - (A2[i - 2]) - (A2[i - 1]);
		A2[i] %= MOD;
		while (A2[i] < 0) A2[i] += MOD;
	}
	cout << R[N];
	return 0;
}

*/
/* 참고용 코드..... 이건 이해가 안가...
#include<stdio.h>

const int mod=1000000;
int n, d[1010], sum;

int main(){
	int i;
	scanf_s("%d", &n);
	d[0]=1, d[1]=2, d[2]=4;
	for(i=3; i<=n; i++)d[i]=(d[i-1]+d[i-2]+d[i-3])%mod;
	sum=d[n];
	for(i=0; i<n; i++)sum += (long long)d[i]*d[n-1-i]%mod;
	printf("%d", sum%mod);
	return 0;
}

*/

/* 참고용 코드.
#include <iostream>
#include <string>
#include <cstring> //memset
using namespace std;

const int MOD = 1000000;
const int MAX = 1000 + 1;

int N;
int cache[MAX][MAX][3][2]; //길이, 출석, 결석 연속, 지각

int fullAttendance(int days, int attend, int absent, int late)
{
	//기저 사례
	if (absent == 3 || late == 2)
		return 0;
	if (days == N) //개근상 조건
		return 1;

	int &result = cache[days][attend][absent][late];
	if (result != -1) return result;

	//일수, 출석, 결석, 지각
	//연속 결석 아니면 결석은 0
	result = fullAttendance(days + 1, attend + 1, 0, late) + fullAttendance(days + 1, attend, absent + 1, late) + fullAttendance(days + 1, attend, 0, late + 1);
	result %= MOD; //MOD로 나누기
	return result;
}

int main(void)
{
	cin >> N;
	memset(cache, -1, sizeof(cache));
	cout << fullAttendance(0, 0, 0, 0) % MOD << endl;
	return 0;

}
*/