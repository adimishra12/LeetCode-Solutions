//sort,call,basecase,skipping duplicates,prune,choose,backtrack(each used once),backtrack
class Solution {
public:
    vector<vector<int>> ans;
    void backtracking(vector<int> &candidates,int target,int start,vector<int> &path){
        
        if(target==0){
            ans.push_back(path);
            return;
        }
        for (int i = start;i<candidates.size();i++)
        {
            if(i>start && candidates[i]==candidates[i-1]){
                continue;
            }
            if(candidates[i]>target)
            break;
            path.push_back(candidates[i]);
            backtracking(candidates,target-candidates[i],i+1,path);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
        sort(candidates.begin(),candidates.end());
        vector<int> path;
        backtracking(candidates,target,0,path);
        return ans;
    }
};