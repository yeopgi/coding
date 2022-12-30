#include<stdio.h>

void lis(int a[], int d[], int n);
void reverseLis(int a[], int r[], int n);
int find(int d[], int r[], int n);

int main() {
	int i, n, a[1000], d[1000], r[1000];
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	lis(a, d, n); reverseLis(a, r, n);
	printf("%d", find(d, r, n));

    return 0;
}

void lis(int a[], int d[], int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		d[i] = 1;
		for (j = 0; j <= i; j++)
			if (a[j] < a[i] && d[i] < d[j] + 1)
				d[i]++;
	}
}
void reverseLis(int a[], int r[], int n) {
	int i, j;
	for (i = n - 1; i >= 0; i--) {
		r[i] = 1;
		for (j = n - 1; j >= i; j--)
			if (a[j] < a[i] && r[i] < r[j] + 1)
				r[i]++;
	}
}
int find(int d[], int r[], int n) {
	int i, res = 0;
	for (i = 0; i < n; i++) if (res < d[i] + r[i]) res = d[i] + r[i];
	return res - 1;
}
//[출처] [백준] 11054 - 가장 긴 바이토닉 부분 수열|작성자 occidere