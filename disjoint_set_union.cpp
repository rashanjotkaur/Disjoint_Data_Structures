// Disjoint Set Union
// You are given number of nodes, N, and number of edges, M, of a undirected connected graph. After adding each edge, 
// print the size of all the connected components (in increasing order).

// Input:
// First line contains two integers, N and M, number of nodes and number of edges.
// Next M lines contains two integers each, X and Y, denoting that there is an edge between X and Y.

// Output:
// For each edge, print the size of all the connected components (in increasing order) after adding that edge.

// SAMPLE INPUT 
// 5 4
// 1 2
// 3 4
// 4 5
// 1 3
// SAMPLE OUTPUT 
// 1 1 1 2
// 1 2 2
// 2 3
// 5

#include <bits/stdc++.h>
using namespace std;
int p[1001],b[1001];
void init(int n){
	for(int i=1;i<=n;i++){
		p[i]=i;
		b[i]=1;
	}
}
int root(int des){
	int src=p[des];
	while(des!=src){
		des=p[src];
		src=p[des];
	}
	return src;
}
void union_fuc(int x,int y){
	int m=root(x);
	int n=root(y);
	if(m==n)
		return;
	if(b[m]>b[n]){
		p[n]=m;
		b[m]=b[m]+b[n];
		b[n]=0;
	}
	else{
		p[m]=n;
		b[n]=b[n]+b[m];
		b[m]=0;
	}
}
int main(){
	int v,e;
	cin>>v>>e;
	init(v);
	while(e--){
		int x,y;
		cin>>x>>y;
		union_fuc(x,y);
		vector <int> c; //to store count of elements in connected components
		for(int i=1;i<=v;i++)
			c.push_back(b[i]);
		sort(c.begin(),c.end());
		for(int i=1;i<=v;i++){
			if(c[i]!=0)
				cout<<c[i]<<" ";
		}
		cout <<endl;
	}
	return 0;
}
