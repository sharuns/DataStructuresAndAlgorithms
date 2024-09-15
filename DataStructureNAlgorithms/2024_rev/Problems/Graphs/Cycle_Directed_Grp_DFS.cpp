//how to detect cycle in directed graph

#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>

using namespace std;
//n vertices and M edges
bool isCyclicDFS(int src ,int par, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &grp,
                unordered_map<int, bool> &DfsVis)
{
   vis[src] =1;
   DfsVis[src] = 1;
    
    for(auto i: grp[src])
    {
        if((vis[i] == false))
        {
           bool detected =  isCyclicDFS(i,src,vis,grp,DfsVis);
        
           if(detected)
           {
                return true;
           }
               
        }
        else if((vis[i] == true) && (DfsVis[i] == true))
        {
            return true;
        }        
    }
    DfsVis[src] = 0;
    return false;
}


string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    unordered_map<int, list<int>> grp;
    
    for(int i = 0 ; i < m ; i++)
    {
        grp[edges[i][0]].push_back(edges[i][1]);
        //grp[edges[i][1]].push_back(edges[i][0]);
    }
 #if 0 
    for(auto i: grp)
    {
        printf("%d : ",i.first);
        for(auto j : i.second)
        {
            printf("%d, ",j);
        }
        printf("\n");
    }
#endif
    //DFS
    unordered_map<int, bool> vis;
    unordered_map<int, bool> visDFS;
    //to handle components 
    for(int i =0; i < n ; i++)
    {
        if(vis[i] == false)
        {
            if(isCyclicDFS( i ,-1,vis,grp,visDFS))
            {
                return "Yes";
            }
        }
    }
    return "No";
}

int main()
{
   
    vector<vector<int>> el = {{1,2},{2,4},{4,5},{5,6},{4,6},{2,3},{3,7},{3,8},{8,7}};
    
    string res = cycleDetection(el,8,9);
    
    cout << res << endl;
}