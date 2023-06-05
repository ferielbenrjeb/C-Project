#include<stdio.h>
#include<string.h>
#include"../library.h"


int main(int argc, char *argv[])
{

pr p1 = extract(argv[1]);

tri_croissant_DA(p1.proc, p1.sz);

p1.proc[0].TR = p1.proc[0].DA + p1.proc[0].TE;

for(int i=1;i<p1.sz;i++)  //trouvé date de sortie pour chaue processus
{
	if(p1.proc[i-1].TR>p1.proc[i].DA)
	{	
		p1.proc[i].TR = p1.proc[i-1].TR + p1.proc[i].TE;
		}
	else{
	p1.proc[i].TR = p1.proc[i].DA + p1.proc[i].TE;
	}
}


affichage(p1.proc, p1.sz);
gantt_chart_non_preemptif(p1.proc, p1.sz);
}
