/*
LEETCODE PROBLEM #787: Cheapest flights Within K stops

There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei]
indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops.
If there is no such route, return -1.

*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//BFS APPROACH
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>> graph(n);
        for(auto flight : flights)
        {
            int from = flight[0];
            int to = flight[1];
            int cost = flight[2];
            graph[from].push_back(make_pair(to,cost));
        }
        
        queue<pair<int,int>> q;
        q.push(make_pair(src,0));
        
        int min_cost = INT_MAX;
        
        int costof[n];
        for(int i=0;i<n;i++)
            costof[i] = INT_MAX;
        
        for(int i=0;i<=k;i++)
        {
            int qsize = q.size();
            for(int j=0;j<qsize;j++)
            {
                pair<int,int> curr = q.front();
                q.pop();
                
                for(auto child : graph[curr.first])
                {
                    int to = child.first;
                    int cost = child.second + curr.second;
                    if(to == dst)
                    {
                        min_cost = min(min_cost,cost);
                    }
                    
                    if(cost > min_cost)
                        continue;
                    
                    if(cost < costof[to])
                    {
                        costof[to] = cost;
                        q.push(make_pair(to,cost));
                    }
                }
            }
        }
        
        return (min_cost == INT_MAX ? -1 : min_cost);
        
        
    }


//DYNAMIC PROGRAMMING APPROACH
int findCheapestPrice_dp(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        int cost[n][k+2]; // cost[i][j] : Min cost from src to ith node with atmost k edges
        memset(cost,-1,sizeof(cost));
        cost[src][0] = 0;
        for(int edges=1;edges<=k+1;edges++)
        {
            cost[src][edges] = 0;
            
            for(auto flight : flights)
            {
                int from = flight[0];
                int to  = flight[1];
                int weight = flight[2];
                
                if(cost[from][edges-1] != -1)
                {
                    if(cost[to][edges] != -1)
                        cost[to][edges] = min(cost[to][edges],cost[from][edges-1] + weight);
                    else
                        cost[to][edges] = cost[from][edges-1] + weight;
                }
                
            }
        }
        
        return cost[dst][k+1];
        
    }



int main()
{
    return 0;
}