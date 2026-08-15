class Solution {
public:
    vector<vector<int>> constructadj(int V, vector<vector<int>> &edges){
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        return adj;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        queue<int> q;
        for(int i=0;i<prerequisites.size();i++){
            indegree[prerequisites[i][0]]++;
        }

        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<vector<int>> adj = constructadj(numCourses, prerequisites);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }

        for(int i=0;i<numCourses;i++){
            if(indegree[i]>0){
                return false;
            }
        }

        return true;
    }
};
