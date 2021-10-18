bool dfs(int u,vector<vector<int>>&adj,vector<int>&vis)
{
 vis[u]=1;
for(auto v:adj[u])
{
if(!vis[v])
{
if(dfs(v,adj,vis))
return true;
}
else if(vis[v]) 
return true;
}
 vis[u]=2;
return false;
}
int Solution::solve(int A, vector<vector<int> > &B) {
vector<int>vis(A+1,0);
vector<vector<int>>adj(A+1);
for(auto i:B)
adj[i[0]].push_back(i[1]);
for(int i=1;i<=A;i++)
{
if(!vis[i])
{
 if(dfs(i,adj,vis)) 
 return true;
}
}
 return false;
}

