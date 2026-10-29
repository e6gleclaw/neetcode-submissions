class Solution:
    def f(self,nums:List[int],temp:List[int],ans:List[List[int]],ind):
        if(ind==len(nums)):
            ans.append(temp[:])
            return
        
        for i in range(ind,len(nums)):
            temp[i],temp[ind]=temp[ind],temp[i];
            self.f(nums,temp,ans,ind+1)
            temp[i],temp[ind]=temp[ind],temp[i];

    def permute(self, nums: List[int]) -> List[List[int]]:
        temp=nums
        ans=[]
        self.f(nums,temp,ans,0)
        return ans;


        