#include<iostream>
using namespace std;
int main()
{
	cout<<"\n\n......NEXT FIT......"<<endl;
	cout<<"Enter total number of processes"<<endl;
	int n;
	cin>>n;
    cout<<"enter total number of partitions"<<endl;
    int pn;
    cin>>pn;
	string pr[n];
	int size[n];
	int block[n];
	int partion[pn];
	string fit[pn];
	int alloc[pn];
	int addr[pn+1];
	float total=0;
    float used=0;
	addr[0]=0;
	for(int i=0;i<n;i++)
	{
		block[i]=-1;
	}
	//cout<<"Enter memory partition"<<endl;
	for(int i=0;i<pn;i++)
	{
		partion[i]=i+1;
	}
	
	//cout<<"Enter memory partition"<endl;
	for(int i=0;i<pn;i++)
	{
		fit[i]='E';
	}

    //cout<<"Enter memory partition size"<<endl;
	for(int i=0;i<pn;i++)
	{
		cout<<"Enter partition size of partition["<<i+1<<"]: ";
		cin>>alloc[i];	
	}
	
	cout<<"Enter processes"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter pr["<<i+1<<"]: ";
		cin>>pr[i];	
	}
	
	cout<<"Enter processes size"<<"k"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter size of pr["<<i+1<<"]: ";
		cin>>size[i];
	}
	
	for(int i=1;i<pn+1;i++)
	{
		addr[i]=addr[i-1]+alloc[i-1];
		total=addr[i];
	}
	
    int p=0;
    int select[pn];
    int temp=0;
    int temp1=0;
    for(int j=0;j<pn;j++)
    {
        select[j]=0;
    }
    
	while(p<n)
    {
        for(int i=temp;i<pn;i++)
        {
            if(alloc[i]>=size[p] && select[i]!=1)
            {
                fit[i]=pr[p];
				used=used+size[p];
				block[p]=i;
                temp=i+1;
                select[i]=1;
                break;
            }
            
        }
		if(temp>=pn)
		{
			temp=0;
		}
        p++;
    }
    cout<<"processes"<<"\t"<<"size"<<"\t"<<"partition no."<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<pr[i]<<"\t\t"<<size[i]<<"k\t\t"<<block[i]<<endl;
			
	}cout<<endl;
	cout<<"partition"<<"\t"<<"Allocation"<<"\t\t"<<"Address"<<endl;
	int m=0;
	while(m<pn+1)
	{
		for(int i=m;i<m+1;i++)
		{
            if(i<pn)
            {
                cout<<partion[i]<<"\t\t";
            }
            else{
                cout<<"\t\t";
            }
			
		}
		for(int j=m;j<m+1;j++)
		{
            if(m<pn)
            {
                cout<<fit[j]<<"   ["<<alloc[j]<<"k]\t\t";
            }
            else{
                cout<<"\t\t\t";
            }
			
		}
		for(int k=m;k<m+1;k++)
		{
			cout<<addr[k]<<"k";
		}
		cout<<endl;
		m++;
		
	}
	cout<<"\n memory used="<<used;
    cout<<"\n total memory="<<total;
    cout<<"\n Memory utlized= "<<used/total;
	return 0;	
}
