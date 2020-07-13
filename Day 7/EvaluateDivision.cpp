class Solution {
public:
    unordered_map<string, vector<pair<string,double>>> graph;
    int flag = 0;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        unordered_set<string> visited;
        for(int i = 0 ; i < equations.size(); ++i){
            graph[equations[i][0]].push_back(make_pair(equations[i][1],values[i]));
            graph[equations[i][1]].push_back(make_pair(equations[i][0],1/values[i]));
        }
        for(int i = 0 ; i < queries.size(); ++i){
            visited.clear();
            flag = 0;
            ans.push_back(queries[i][0] == queries[i][1] && graph.find(queries[i][0]) != graph.end()? 1 : dfs(queries[i][0], queries[i][1],visited, 1));
        }
        return ans;
    }
    
    double dfs( string s1, string s2,unordered_set<string>& visited, double prod){
            if(visited.count(s1) == 0){
                visited.insert(s1);
                for(auto it : graph[s1]){
                    auto temp = prod * it.second;
                    if(it.first == s2){
                        flag = 1;
                        return temp;
                    }
                    auto answer = dfs(it.first, s2,visited, temp);
                    if(flag == 1)
                        return answer;
                }
            }
        return -1;
    }
};