bool dfs(vector<vector<int>> &adj, vector<bool> &visited, int start, int dest)
{
    visited[start] = true;
    if(start == dest) return true;
    for(int i = 0; i<adj[start].size(); i++){
        if(!visited[adj[start][i]])
        {
            if(dfs(adj, visited, adj[start][i], dest))
             return true;
        }
    }
    return false;
}

int Solution::solve(int A, vector<vector<int>> &B) {
    vector<vector<int>> adj(A+1);
    for(int i = 0; i<B.size(); i++)
    {
        adj[B[i][0]].push_back(B[i][1]);
    }
    vector<bool> visited(A+1, false);
    return dfs(adj, visited, 1, A);
}
