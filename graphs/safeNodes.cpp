/*
LEETCODE PROBLEM #802: Find Eventual Safe States

There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array
graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads
to a terminal node.

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.


*/


#include <iostream>
#include <bits/stdc++.h>
using namespace std;


//GRAPH COLORING APPROACH to detect cycles and nodes having path to that cycle
class Solution {
public:
    
    void dfs(int node,vector<vector<int>>& graph,int color[],int sf[])
    {
        
        color[node] = 1;
        for(auto child : graph[node])
        {
           
            if(color[child] == 1)
            {
                sf[child] = 0;
                sf[node] = 0;
            }
            else if(!sf[child])
            {
                sf[node] = 0;
            }
            else
            {
                if(color[child] == 2)
                    continue;
                
                dfs(child,graph,color,sf);
                if(!sf[child])
                {
                    sf[node] = 0;
                }
            }
        }
        
        color[node] = 2;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        
        int color[n];
        memset(color,0,sizeof(color));
        
        int sf[n];
        for(int i=0;i<n;i++)
            sf[i] = 1;
        
        for(int i=0;i<n;i++)
        {
            if(color[i] == 0)
            {
                dfs(i,graph,color,sf);
            }
        }
        
        vector<int> safeSet;
        for(int i=0;i<n;i++)
        {
            if(sf[i])
                safeSet.push_back(i);
        }
        
        return safeSet;
        
    }
};


int main()
{
    return 0;
}