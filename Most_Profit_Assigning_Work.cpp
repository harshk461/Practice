class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=profit.size();
        int m=worker.size();

        sort(worker.begin(),worker.end(),greater<int>());

        priority_queue<pair<int,int>> pq;

//Difficulty->profit
        for(int i=0;i<n;i++)
        //we have to store values on the basis of highest profit
            pq.push({profit[i],difficulty[i]});

        // for(auto it:worker)cout<<it<<" ";
        // cout<<endl;

        // while(!pq.empty()){
        //     auto top=pq.top();
        //     cout<<top.first<<" "<<top.second<<endl;
        //     pq.pop();
        // }


        int ans=0;
        int i=0;
        while(!pq.empty() && i<m){
            pair<int,int> top=pq.top();

            if(worker[i]>=top.second){
                ans+=top.first;
                i++;
            }else{
                pq.pop();
            }
        }
        return ans;
    }
};