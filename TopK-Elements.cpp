class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> dict;
        for(int num: nums){
            dict[num]++;
        }

        auto cmp = [](pair<int,int> a, pair<int,int> b){ return a.first > b.first; };

        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);

        for(auto &[num, f]: dict){
            pq.push({f, num});
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<int>ret;
        while(!pq.empty()){
            ret.push_back(pq.top().second);
            pq.pop();
        }
        return ret;
    }
};