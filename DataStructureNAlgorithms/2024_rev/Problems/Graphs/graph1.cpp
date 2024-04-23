//Graph there are 2 ways to implement a graph 
/*
	1. Matrix representation 
	2. Adjacancey List

	Lest see the implementation of the second first as thats the one used the most
	best data structure to represnt this arrangement is using a map
	
	map<int, list<int>>;
*/

#include <bits/stdc++.h>
#include <string.h>
using namespace std;

class graph
{
    public :
    
    unordered_map<int, list<int>> adj;
    
    void addEdge(int u, int v, bool direction)
    {
        // 0 undirectional, 1 directional
        adj[u].push_back(v);
        
        if(!direction){
            adj[v].push_back(u);
        }
    }
    
    void printList()
    {
        for(auto itr : adj)
        {
            printf("%d : ", itr.first);
            
            for(auto jtr : itr.second )
            {
                printf("%d ->", jtr);
            }
            printf("\n");
        }
    }
};

int main()
{
    int n = 3;
    int m = 3;
    graph g;
   
        g.addEdge(0,1, false);
        g.addEdge(0,2, false);
        g.addEdge(1,2, false);
        

    g.printList();
    
}


/*
Also sometimes the format in which the question is given  maybe differ 

for eg 

for a given n->node  and m ->edge
here is the edge list 
vector<vector<int>> edge

so in that case how we can convert this into a adjacency list is also needed to remember

we can do so by doing something like this 


vector<int> arr[n];
for(int i = 0 ; i < m ; i++)
{
	int u = edge[i][0];
	int v = edge[i][1];
	
	arr[u].push_back(v);
	arr[v].push_back(u);
	
}

after this we can add our own adj list data struct 

vector<vector<int>> Adj;

for(int i = 0 ; i < n ; i++)
{
	adj[i].push_back(i);
	
	for(int j = 0 ; j < arr[i].size() ; j ++)
	{
		adj[i].push_back(arr[i][j]);
	}
	
}


*/



