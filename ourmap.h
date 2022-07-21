#include <string>
using namespace std;
template<typename V>
class mapnode{
public:
	string key;
	V data;
	mapnode* next;
	mapnode(string key,V data)
	{
		this->key=key;
		this->data=data;
		next=NULL;
		

	}
	~mapnode()
		{
			delete next;
		}	
};
template<typename V>
class ourmap{
private:
	mapnode<V>**buckets;
	int numbucket;
	int count;
public:
	ourmap()
	{
		numbucket=5;
		count=0;
		buckets=new mapnode<V>*[numbucket];
		for(int i=0;i<numbucket;i++)
			buckets[i]=NULL;

	}
	~ourmap()
	{
		for (int i = 0; i < numbucket; i++)
		{
			delete buckets[i];
		}
		delete []buckets;
	}
	int size()
	{
		return count;
	}
private:
	int getbucketindex(string key)
	{
       int hashcode=0;
       int currcode=1;
       for (int i = key.length()-1; i >=0 ; i--)
       {
       	hashcode=+key[i]*currcode;
       	hashcode=hashcode%numbucket;
       	currcode=currcode*37;
       	currcode=currcode%numbucket;
       }
       return hashcode%numbucket;
	}
public:
	V getvalue(string key)
	{
     int bucketindex=getbucketindex(key);
       mapnode<V>*head=buckets[bucketindex];
       while(head!=NULL)
       {
       	if (head->key==key)
       	{
       	 return head->data;
       	}
       	head=head->next;
       }
       return 0;

	}
	void rehash()
	{
		mapnode<V>**temp=buckets;
		buckets=new mapnode<V>*[2*numbucket];
		for (int i = 0; i < 2*numbucket; i++)
		{
		  buckets[i]=NULL;
		}
		int oldnumbucket=numbucket;
		numbucket=2*numbucket;
		count=0; 
		for (int i = 0; i < oldnumbucket;i++)
		{
			mapnode<V>*head=temp[i];
			while(head!=NULL)
			{
				 string key= head->key;
				V data= head->data;
				insert(key,data);
				head=head->next;
			}
		}
		for(int i=0;i<oldnumbucket;i++)
			delete temp[i];
		delete []temp;
	}
	double getloadfactor()
       {
       	return (1.0*count)/numbucket;
       }
	void insert(string key,V data)
	{
       int bucketindex=getbucketindex(key);
       mapnode<V>*head=buckets[bucketindex];
       while(head!=NULL)
       {
       	if (head->key==key)
       	{
       		head->data=data;
       	}
       	head=head->next;
       }
         head=buckets[bucketindex];
         mapnode<V>*node=new mapnode<V>(key ,data);
         node->next=head;
         buckets[bucketindex]=node;
         count++;
         double loadfactor=(1.0*count)/numbucket;
         if (loadfactor>0.7)
         {
         	rehash();
         }
       }
       
	V remove(string key)
	{
        int index=getbucketindex(key);
        mapnode<V>*head=buckets[index];
        mapnode<V>*prev=NULL;
        V vale=0;
        while(head!=NULL)
        {
        	if (head->key==key)
        	{  
        		if (prev==NULL)
        	{
        		buckets[index]=head->next;
        	}
        	else{
        		prev->next=head->next;
        		
        	}
        	vale=head->data;
        	head->next=NULL;
        		delete head;
        		count--;
        		return vale;
        		
        	}
              prev=head;
        	head=head->next;
        }
        return 0;
	}

};