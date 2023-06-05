#include<stdio.h>
#include<string.h>
#include"../library.h"

int main(int argc, char *argv[])
{

pr p1 = extract(argv[1]);
int sz=p1.sz;
int i,j,T[50],k,completed[sz];

tri_croissant_DA(p1.proc,sz);

for(i=0;i<sz;i++)
	{
	completed[i]=0;
	}

int debut=p1.proc[0].DA;
int Ncomplet=sz;
int pos;
while(Ncomplet!=0)
{
	j=-1;
	for(i=0;i<sz;i++)
		{
		if(p1.proc[i].DA<=debut && completed[i]==0)
		{j++;
		T[j]=i;}
		}
	if(j!=-1)
	{	
		for(i=0;i<=j;i++)//tri decroissant par temps d'execution
		{
			for(k=i+1;k<=j;k++)
			{
				if(p1.proc[T[i]].TE>p1.proc[T[k]].TE)
				{
					pos=T[i];
					T[i]=T[k];
					T[k]=pos;
				}
			}
		}
	
		completed[T[0]] = 1;
		Ncomplet = Ncomplet-1;
		debut = debut+p1.proc[T[0]].TE;
		p1.proc[T[0]].TR = debut;
	}

	else{debut++;}
}

tri_croissant_TR(p1.proc, sz);
affichage(p1.proc, sz);
gantt_chart_non_preemptif(p1.proc, sz);
}
