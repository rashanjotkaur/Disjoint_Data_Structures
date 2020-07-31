// https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-flood-1/

// Fatland is a town that started with N distinct empires, namely empires 1, 2, ..., N. But over time, the armies of some of these empires have taken over other ones. 
// Each takeover occurred when the army of empire i invaded empire j. After each invasion, all of empire j became part of empire i, and empire j was renamed as empire i.

// Empire Huang, leader of Badland, wants to invade Fatland. To do this, he needs to calculate how many distinct empires still remain in Fatland after all the takeovers. 
// Help him with this task.

// Input:

// The first line contains an integer N, the number of empires that were originally in Fatland.

// The second line contains an integer K, denoting the number of takeovers that took place.

// Each of the next K lines contains 2 space-separated integers i, j, representing that the army of empire i took over that of empire j. 
// As a result, empire j does not exist anymore and is now renamed as empire i. It is guaranteed that empire i still exists.

// Output: Output one integer, the number of empires that exist in Fatland.

// Constraints:
// 1 <= N <= 105
// 1 <= K <= 105

// SAMPLE INPUT 
// 4
// 2
// 1 2
// 4 1
// SAMPLE OUTPUT 
// 2
// Explanation
// Fatland started with empires 1, 2, 3, 4. First, empire 1 invaded empire 2, so empire 2 was renamed to empire 1. Then, empire 4 invaded empire 1. 
// So what were at the beginning empires 1 and 2 were renamed to empire 4. Now, only empires 3 and 4 remain, so the answer is 2.

#include <bits/stdc++.h>
using namespace std;
int root(int des,vector <int> p){
	int src=p[des];
	while(des!=src){
		des=p[src];
		src=p[des];
	}
	return src;
}
void union_fun(vector <int> &p,vector <int> &b,int src,int des){
	int w=root(src,p);
	int l=root(des,p);
	if(w==l) return;
	else{
		p[l]=w;
		b[w]=b[w]+b[l];
		b[l]=0;
	}
	
}
int main(){
	int n,k; //no.of takeovers==no. of edges
	cin>>n;
	cin>>k;
	vector <int> p(n+1);
	for(int i=1;i<=n;i++)
		p[i]=i;
	vector <int> b(n+1,1);
	int src,des;
	for(int i=1;i<=k;i++){
		cin>>src>>des;
		union_fun(p,b,src,des);
	}
	int count=0;
	for(int i=1;i<=n;i++){
		if(b[i]!=0){
			count++;
		}
	}
	cout<<count<<endl;
	return 0;
}

