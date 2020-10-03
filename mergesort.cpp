#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
#include<string.h>
#include<stdio.h>
using namespace std;
#define ll long long
#define db double
#define S second
#define MOD 1000000007
ll gcd (ll a, ll b) {return ( a ? gcd(b % a, a) : b );}
ll power(ll a, ll n) {ll p = 1; while (n > 0) {if (n % 2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll power(ll a, ll n, ll mod) {ll p = 1; while (n > 0) {if (n % 2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}
void merge(int a[], int l, int m, int h)
{
	int x, y;
	x = m - l + 1;
	y = h - m;
	int p[x];
	int q[y];
	for (int i = 0; i < x; ++i)
	{
		p[i] = a[l + i];
	}
	for (int i = 0; i < y; ++i)
	{
		q[i] = a[m + 1 + i];
	}
	int k = l;
	int j = 0;
	int i = 0;
	while (i < x && j < y) {
		if (p[i] <= q[j]) {
			a[k] = p[i];
			i++;
		}
		else {
			a[k] = q[j];
			j++;
		}
		k++;
	}



	while (i < x) {
		a[k] = p[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	   are any */
	while (j < k) {
		a[k] = q[j];
		j++;
		k++;
	}
}

void msort(int a[], int l, int h)
{
	if (l < h)
	{
		int mid = (l + h) / 2;
		msort(a, l, mid - 1);
		msort(a, mid + 1, h);
		merge(a, l, mid, h);
	}
}
void solve()
{	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	msort(a, 0, n - 1);
	for (int i = 0; i < n; ++i)
	{
		cout << a[i];
	}
}
int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;

	while (t--)
	{

		solve();

	}
	return 0;
}

