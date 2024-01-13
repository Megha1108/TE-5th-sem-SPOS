#include<iostream>
 
using namespace std;
 
int main()
{
int bsize[10], psize[10], bno, pno, flags[10], allocation[10], i, j;
 
for(i = 0; i < 10; i++)
{
flags[i] = 0;
allocation[i] = -1;
}
cout<<"Enter no. of blocks: ";
cin>>bno;
cout<<"\nEnter size of each block: ";
for(i = 0; i < bno; i++)
cin>>bsize[i];
 
cout<<"\nEnter no. of processes: ";
cin>>pno;
cout<<"\nEnter size of each process: ";
for(i = 0; i < pno; i++)
cin>>psize[i];
for(i = 0; i < pno; i++)         //allocation as per first fit
for(j = 0; j < bno; j++)
if(flags[j] == 0 && bsize[j] >= psize[i])
{
allocation[j] = i;
flags[j] = 1;
break;
}
//display allocation details
cout<<"\nBlock no.\tsize\t\tprocess no.\t\tsize";
for(i = 0; i < bno; i++)
{
cout<<"\n"<< i+1<<"\t\t"<<bsize[i]<<"\t\t";
if(flags[i] == 1)
cout<<allocation[i]+1<<"\t\t\t"<<psize[allocation[i]];
else
cout<<"Not allocated";
}
return 0;
}

































import java.util.Arrays;
import java.util.Scanner; 
//Implementation of first fit algorithm
class First_fit { 
public void firstFit(int blockSize[], int m, int processSize[], int n)
{ 
 int allocation[] = new int[n]; 
 for (int i = 0; i < allocation.length; i++) 
 allocation[i] = -1; 
 for (int i = 0; i < n; i++) 
 { 
 for (int j = 0; j < m; j++) 
 { 
 if (blockSize[j] >= processSize[i]) 
 { 
 allocation[i] = j; 
 blockSize[j] -= processSize[i];
 break; 
 } 
 } 
 
}
 System.out.println("\nProcess No.\tProcess Size\tBlock no."); 
 for (int i = 0; i < n; i++) 
 { 
 System.out.print(" " + (i+1) + "\t\t" + processSize[i] + "\t\t"); if 
(allocation[i] != -1) 
 System.out.print(allocation[i] + 1); 
 else 
 System.out.print("Not Allocated"); 
 System.out.println(); 
 } 
 } 
}

public class main 
{ 
 public static void main(String[] args) 
 { 
 First_fit first = new First_fit(); 
 Scanner scan = new Scanner(System.in);
 while(true) 
 { 
 int choice; 
 System.out.println();
 System.out.println("Enter the number of Blocks: "); 
 int m = scan.nextInt(); 
 System.out.println("Enter the number of Processes: "); 
 int n = scan.nextInt(); 
 int blockSize[] = new int[m]; 
 int processSize[] = new int[n]; 
 System.out.println("Enter the Size of all the blocks: ");
 for (int i = 0; i<m; i++) 
 { 
 blockSize[i] = scan.nextInt(); 
 
 } 
 System.out.println("Enter the size of all processes: "); 
 for (int i = 0; i<n; i++) 
 { 
 processSize[i] = scan.nextInt(); 
 
 }
 System.out.println(); 

  

 System.out.println("First Fit Output"); 
 first.firstFit(blockSize, m, processSize, n); 

  
 } 
 }
}



