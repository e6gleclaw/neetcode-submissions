class KthLargest {
    vector<int>nums;
    int k;
    priority_queue<int,vector<int>,greater<int>>pq;
public:
    KthLargest(int k, vector<int>& nums) {
        this->nums=nums;
        this->k=k;
        for(auto ele:nums){
            pq.push(ele);
            if(pq.size()>k){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
      nums.push_back(val);
      pq.push(val);
      if(pq.size()>k){
        pq.pop();
      }
      return pq.top();
    }
};
