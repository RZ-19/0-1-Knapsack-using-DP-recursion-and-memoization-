#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int val[N],wt[N];
int dp[N][N];

// Here I did two types of solution the first one is recursive and the second one is memoization dp
int knapsack(int n,int w){
	
	if(w<=0){
		return 0;
	}
	if(n<=0){
		return 0;
	}
	if(dp[n][w]!=-1) return dp[n][w];
	
	if(wt[n-1]>w)
	{
		 dp[n][w]= knapsack(n-1,w);
	}
	else dp[n][w]=max(knapsack(n-1,w),knapsack(n-1,w-wt[n-1])+ val[n-1]);
	/*
	if(wt[n-1]>w)
	{
		return knapsack(n-1,w);
	}
	return max(knapsack(n-1,w),knapsack(n-1,w-wt[n-1])+ val[n-1]);
	*/
	return dp[n][w];
	
}

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			dp[i][j]=-1;
		}
	}
	for(int i=0;i<n;i++)
	{
		cin>>wt[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>val[i];
	}
	int w;
	cin>>w;
	cout<<knapsack(n,w)<<endl;
	
	return 0;
}

/*

3
15 30 45
60 100 150
50

*/





