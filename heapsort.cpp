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
void heap(int a[], int n)
{
	int i, j, temp, x;
	x = a[1];
	a[1] = a[n];
	i = 1;
	j = 2 * i;
	while (j < n)
	{
		if (a[j] < a[j + 1])
		{
			j = j + 1;
		}
		if (a[i] < a[j])
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i = j;
			j = j * 2;
		}
		else
			break;
	}
	a[n] = x;
}
void insert(int a[], int n)
{
	int i = n, temp;
	temp = a[n];
	while (i > 1 && temp > a[i / 2])
	{
		a[i] = a[i / 2];
		i = i / 2;
	}
	a[i] = temp;
}

// void solve()
// {
// 	// int n;
// 	// int a[n];
// 	// for (int i = 1; i <= n; ++i)
// 	// {
// 	// 	cin >> a[i];
// 	// }
// 	// for (int i = 2; i <= n ; ++i)
// 	// {
// 	// 	insert(a, i);
// 	// }
// 	// for (int i = n; i >= 1; i--)
// 	// {
// 	// 	heap(a, i);
// 	// }
// 	// for (int i = 1; i <= n; ++i)
// 	// {
// 	// 	cout << a[i] << " ";

// 	// }





// }






int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// int t;
	// cin >> t;

	// while (t--)
	// {

	// 	solve();

	// }
	int n;
	cin >> n;
	int a[n];
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 2; i <= n ; ++i)
	{
		insert(a, i);
	}
	for (int i = n; i >= 1; i--)
	{
		heap(a, i);
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << a[i] << " ";

	}


	return 0;

}

