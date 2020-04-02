#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int a;
	vector<int> end;
	while(1)
	{
		cin >> a;
		if(a==-1)
		{
			break;
		} 
		vector<vector<int> >data;
		for(int i=0;i<a;i++)
		{
			vector<int> reg;
			for(int j=0;j<a;j++)
			{
				int x;
				cin >> x;
				reg.push_back(x);
			}	
			data.push_back(reg);
		}
		

		/*for(int i=0;i<a;i++)
		{
			for(int j=0;j<a;j++)
			{
				cout << data[i][j] << " ";
			}
			cout << endl;
		}*/ 
		int count[a];
		vector<int > final;
		vector<vector<int> >compare;
		vector<vector<int> >recheck;
		for(int i=0;i<a;i++)
		{
			vector<int> first;
			count[i]=0;
			final.push_back(0);
			for(int j=0;j<a;j++)
			{
				if(data[i][j]==0 || (data[i][j]==1 && i==j))
				{
					count[i]+=1;
					final[i]+=1;
					first.push_back(j); 
					//recheck.push_back(j);
				}
			} 
			compare.push_back(first);
			recheck.push_back(first);
		}
		/*for(int i=0;i<a;i++)
			cout << count[i] << endl;*/ 
		int size=-1;
		for(int i=0;i<a;i++)
		{
			size++;
			int recount=0;
			for(int j=0;j<count[size];j++)
			{
				for(int z=0;z<count[size];z++)
				{ 
					if(data[compare[i][j]][recheck[i][z]]==1)
					{
						if(j==z)
							continue;
						recount++;
					}
				} 
			}
			//cout << recount << endl;
			recount/=2;
			final[i]-=recount;
		}
		/*for(int i=0;i<a;i++)
			cout << final[i] << " ";*/ 
		sort(final.begin(),final.end()); 
		end.push_back(final[a-1]);
	}
	for(int i=0;i<end.size();i++)
		cout << end[i] << endl;
}
