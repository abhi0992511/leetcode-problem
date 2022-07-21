#include <vector>
using namespace std;
class priority_queue1{
private:
	vector<int>pq;
	public:

		priority_queue1()
		{

		}
		
		bool isEmpty()
		{
			return pq.size()==0;
		}
		int getsize()
		{
			return pq.size();
		}
		int getmin()
		{    
			if (isEmpty())
			{
			return 0;
			}
			return pq[0];
		}
		void insert(int data)
		{
			pq.push_back(data);
			int childindex=pq.size()-1;
			int parentindex=(childindex-1)/2;
          while(childindex>0)
          {

			if (pq[childindex]<pq[parentindex])
			{
				int temp=pq[childindex];
				pq[childindex]=pq[parentindex];
				pq[parentindex]=temp;
			}
			else break;
			childindex=parentindex;

          }
		}
		int remove_min()
		{
         int ans=pq[0];
           pq[0]=pq[pq.size()-1];
           pq.pop_back();
           int parentindex=0;
           int lc=parentindex*2+1;
           int rc=parentindex*2+2;
           int minindex;
           while(lc<pq.size())
           {
           	minindex =parentindex;
           	if (rc<pq.size()&&pq[minindex]>pq[rc])
           	{
           		minindex=rc;

           	}

           	if (pq[minindex]>pq[lc])
           	{
               minindex =lc;
           	}
           	if (minindex==parentindex)
           	{
           		break;
           	}
           int temp=pq[minindex];
           		pq[minindex]=pq[parentindex];
           		pq[parentindex]=temp;
         
          	parentindex=minindex;
             lc=parentindex*2+1;
           	rc=parentindex*2+2;
           }
           return ans;

		}
// 	
	
};