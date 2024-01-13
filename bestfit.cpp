#include<bits/stdc++.h>
#include<iostream>
using namespace std;
 
int main()
{
  int no_blocks,no_process,temp,lowest=9999;
  int a1[20],a2[20],block[20],process[20];

  cout<<"Enter number of blocks ";
  cin>>no_blocks;
  cout<<"Enter number of processes ";
  cin>>no_process;
  
  cout<<"Enter size of each block"<<endl;
  for(int i=1;i<=no_blocks;i++)
    {
        cout<<"Block "<<i<<"-";
        cin>>block[i];
    }
  
  cout<<"\nEnter size of each process."<<endl;
  for(int i=1;i<=no_process;i++)
    {
        cout<<"Process "<<i<<"-";
        cin>>process[i];
    }
  
  for(int t=1;t<=no_process;t++)
  {
    for(int q=1;q<=no_blocks;q++)
    {
      if(a1[q]!=1)
      {
        temp=block[q]-process[t];
        if(temp>=0)
          if(lowest>temp)
          {
            a2[t]=q;
            lowest=temp;
          }
      }
    }
    a1[a2[t]]=1;
    lowest=10000;
  }
  
  cout<<endl<<"Process number\tProcess size\tBlock number\tBlock size";
  for(int i=1;(i<=no_process and a2[i]!=0);i++)
  {
    cout<<endl<<i<<"\t\t"<<process[i]<<"\t\t"<<a2[i]<<"\t\t"<<block[a2[i]];
  }
  return 0;
}

/*OUTPUT
Enter number of blocks 4
Enter number of processes 4
Enter size of each block
Block 1-5
Block 2-8
Block 3-9
Block 4-5
Enter size of each process.
Process 1-3
Process 2-2
Process 3-8
Process 4-6
Process number	Process size	Block number	Block size
1		3		1		5
2		2		4		5
3		8		2		8
4		6		3		9
*/
