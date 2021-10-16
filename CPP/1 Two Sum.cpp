#include<iostream>
#include<unordered_map>

#define vi vector<int>



using namespace std;

vi twoSum(vector<int>& nums,int t)
{
	vi ans;
	unordered_map<int,int> mp; //creating map
	int i=0;
	
	for(i=0;i<nums.size();++i)
	{
		if(mp.count(t-nums[i])==1) 
		{
			ans.push_back(mp[t-nums[i]]);
			ans.push_back(i);
			break;
		}
		else 
		{
			mp[nums[i]]=i;
		}
	}
	return ans;
}

int main()
{
	vi v={3,1,34,5,6};
	int n=2;
	vi ans=twoSum(v,n);
	for(auto k:ans)
	cout<<k<<" ";
}
