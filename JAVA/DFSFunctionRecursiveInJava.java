// Author: Samrat Mitra
class Solution
{
    //Function to return a list containing the DFS traversal of the graph.
    public ArrayList<Integer> dfsOfGraph(int V, ArrayList<ArrayList<Integer>> adj)
    {
        ArrayList<Integer> solution = new ArrayList<>();
        boolean seen[] = new boolean[V];
        dfs(adj, solution, 0, seen);
        return solution;
    }
    public void dfs(ArrayList<ArrayList<Integer>> adj, ArrayList<Integer> solution, int V, boolean seen[]) {
        if(seen[V]) return;
        seen[V] = true;
        solution.add(V);
        for(Integer adjacent: adj.get(V)) {
            if(!seen[adjacent]) dfs(adj, solution, adjacent, seen);
        }
    }
}
