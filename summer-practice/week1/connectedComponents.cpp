class Solution {
  public:
    int findNumberOfComponent(int V, vector<vector<int>> &edges) {
        unordered_map<int, vector<int>> adjList;
        for (const auto &edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        int cnt = 0;
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (visited[i])
                continue;

            cnt++;
            queue<int> bfs;
            bfs.push(i);
            while (!bfs.empty()) {
                int x = bfs.front();
                bfs.pop();
                visited[x] = true;
                for (int neighbor : adjList[x]) {
                    if (!visited[neighbor])
                        bfs.push(neighbor);
                }
            }
        }

        return cnt;
    }
};
