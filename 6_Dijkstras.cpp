#include<iostream>
#include<string.h>
using namespace std;
#define MAX 10

class djs
{
	public:
	int i, j, k, a, b, u, v, n, ne;
	int min, mincost, cost[MAX][MAX], process[MAX]; 
	void shortestpath(int ,int);
	void displaygraph();
	void create();
	djs() {
		//initialize cost[][]		
		for (int i = 1; i <= MAX; i++)
			for(int j = 1; j <= MAX; j++)
			cost[i][j]=999;		
	}//constructor
};

void djs :: create()
{
	int n,wt,dist[MAX][MAX];
	char ch;
	cout<<"Enter the number of vertices:"<<endl;
	cin>>n;
	for (int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			cout<<"Is there a link between"<<i<<"and"<<j<<"? press y if yes and n if no";
			cin>>ch;
			if (ch=='y')
			{
				cout<<"enter the weight"<<endl;
				cin>>wt;
				cost[i][j]=cost[j][i]=wt;			
			}
			
		}
	}
}
void djs :: displaygraph()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<cost[i][j]<<"\t";
		}
	cout<<"\n"<<endl;
	}
}

void djs :: shortestpath(int s, int t)
{
	int newdist, dist[MAX],dc,processed[MAX],preced[MAX],curr,smalldist,k,path[MAX];
	for (int i=1;i<=n;i++)
	{
		processed[i]=preced[i]=0;
		dist[i]=999;
	}
	
	processed[s]=1;
	dist[s]=0;
	curr = s;
	
	while(curr!=t)
		{
			smalldist=999;
			dc=dist[curr];
			
			for(int i=1;i<=n;i++)
			{
				if(processed[i]==0)
				{
					newdist= dc + cost[curr][i];
				}
				
				if (newdist<dist[i])
				{
					smalldist=newdist;
					preced[i]=curr;
					k=i;
				}
			}
			
		curr = k;
		processed[curr]=1;
		
		}
		int j=0;
		int p = t;
		path[j++]=p;
		while(p!=s)
		{
			p = preced[p];
			path[j++] = p;
		}
		cout<<"shortestpath :";
		for(int i = j-1;i>=0;i--)
		{
			cout<<path[i];
		}
		
		cout<<"Shortest Distance:"<<dist[t];
}

int main()
{
	int s,t;
	djs obj;  //constructor will be called and initialization are made
	obj.create();
	obj.displaygraph();
	cout << "\n Enter start and target vertices: ";
	cin >> s;
	cin >> t;
	obj.shortestpath(s, t);
	return 0;
}
