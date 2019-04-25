/*
Consider that a system has P resources of same type. These resources are shared by Q processes time to time. 
All processes request and release the resources one at a time. Generate a solution to demonstrate that, the system is in safe state 
when following conditions are satisfied.
Conditions:
a.) Maximum resource need of each process is between 1 and P.		                 
b.) Summation of all maximum needs is less than P+Q
*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
	
int q,p,smax,sflag=0;
int i=0,j,flag[10],n=0,kill=0,sum=0,available=0;
int ui[10];
int max[10],alloc[10],need[10];
printf("Enter the no of processes:"); 
scanf("%d",&q);
printf("Enter the no of resources:");
scanf("%d",&p);
smax=p+q;

for(i=0;i<q;i++)
{
if(i==0)
{
max[i]=p-1;
}
else
{
max[i]=1;
}
}

for(i=0;i<q;i++)
{
if(i==0)
{
alloc[i]=p-2; 
}
else
{alloc[i]=0;}
}

for(i=0;i<q;i++)
{
sum=alloc[i]+sum;
}
available=q-sum;
for(i=0;i<q;i++)
{
need[i]=max[i]-alloc[i];
}

while(n<=q)
{
for(i=0;i<q;i++)
{
if(need[i]<available)
{
available=available+need[i];
flag[i]=1;
n=n+1;
}

else
{flag[i]=0;}
}
for(i=0;i<q;i++)
{
if(flag[i]==1)
sflag=sflag+1;
}
if(sflag==0)
{
n=q+1;
kill=1;
}
}

if(kill==1){printf("Unsafe or Deadlock occured");}

else
{
	printf("Safe State");
}
}

 
