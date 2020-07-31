Monk is having a hard time teaching the  standard students. 
He wants to divide the students into small groups so that he can conduct some fun-filled 
activities for them. But students also want their friends in the same group. 
So, if student A is a friend of student B, and student B is a friend of student C, 
then the students A,B and C must be in the same group, otherwise they will start crying. 
After dividing the students, he will choose a leader from each group who will lead their 
respective groups. Now he wants to know the number of ways he can choose the group leaders 
from all the groups. Print this answer modulo .

Note: Two ways A and B will be considered different if at least 1 person is a leader 
in group A, and is not a leader in group B, or vice-versa.

Input:
The first line consists of two integers N and M denoting the number of students and the number 
of relationships respectively. The next M lines consists of two integers u and v denoting that 
student u and student v are friends. u and v can never be equal and relationships 
are not repeated.

Output:
Print the answer modulo  in a single line.

SAMPLE INPUT 
5 4
1 2
2 3
1 3
4 5
SAMPLE OUTPUT 
6
Explanation
According to the sample test case,
1, 2 and 3 must be in the same group.
4 and 5 must be in the same group.
So, number of ways to choose leaders from these groups is 3*2=6

#include <bits/stdc++.h>
using namespace std;
int root(vector <long long int> p,vector <long long int> b,int des){
	int src=p[des];
	while(des!=src){
		des=p[src];
		src=p[des];
	}
	return src;
}
void union_fun(vector <long long int> &p,vector <long long int> &b,int src,int des){
	int m=root(p,b,src);
	int n=root(p,b,des);
	if(m==n)	return;
	if(b[m]>=b[n]){
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
	long long int mod=1e9+7;
	int v,e;
	cin>>v>>e;
	vector <long long int> p(v+1);
	for(int i=1;i<=v;i++)
		p[i]=i;
	vector <long long int> b(v+1,1);
	int src,des;
	for(int i=1;i<=e;i++){
		cin>>src>>des;
		union_fun(p,b,src,des);
	}
	long long int cn=1;
	for(int i=1;i<=v;i++){
		if(b[i]!=0){
			cn=((cn%mod)*(b[i]%mod))%mod;
		}
	}
	cout<<cn<<endl;
	return 0;
}
