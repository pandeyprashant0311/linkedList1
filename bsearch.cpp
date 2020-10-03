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
int bsearch(int a[], int l, int h, int k)
{
	if (l == h)
	{
		if (a[l] == k)
			return l;
		else
			return -1;
	}
	else {
		int mid;
		mid = l + (h - l) / 2;
		if (a[mid] == k)
		{
			return mid;
		}
		if (a[mid] > k)
		{
			return bsearch(a, l, mid - 1, k);
		}
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
	int k;
	cin >> k;
	int result = bsearch(a, 0, n - 1, k);
	(result == -1) ? cout << "Element is not present in array"
	                      : cout << "Element is present at index " << result + 1;




}






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

	solve();

	// }
	return 0;

}

