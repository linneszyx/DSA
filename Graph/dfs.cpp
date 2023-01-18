#include<bits/stdc++.h>
using namespace std;
class Graph{
    int V;
    list<int> *l;
    public:
    Graph(int v){
        V = v;
        l = new list<int>[V];
    } 
    /**
     * It adds an edge between the vertices i and j
     * 
     * @param i The first node
     * @param j The node to which the edge is to be added.
     * @param undir If the graph is undirected or not.
     */
    void addEdge(int i,int j,bool undir=true){
        l[i].push_back(j);
        if(undir){
            l[j].push_back(i);
        }
    }
   /**
    * It takes a node and a boolean array as input and marks the node as visited and then recursively
    * calls the function for all the unvisited neighbours of the node
    * 
    * @param node The node which we are currently visiting.
    * @param visited This is a boolean array which keeps track of the nodes which have been visited.
    * 
    * @return nothing.
    */
    void dfs_helper(int node,bool *visited){
        visited[node] = true;
        cout<<node<<",";
        for(int nbr:l[node]){
            if(!visited[nbr]){
                dfs_helper(nbr,visited);
            }
        }
        return;
    }
    /**
     * A function to perform DFS on a graph.
     * 
     * @param source The source node from where we want to start the DFS.
     */
    void dfs(int source){
        bool *visited = new bool[V]{0};
        dfs_helper(source,visited);
    }
}; 
int main(){
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(2,1);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.dfs(1);
    return 0;
}