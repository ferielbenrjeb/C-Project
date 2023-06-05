#include<stdio.h>
#include<stdlib.h>
#include"../library.h"


int NP, quantum, scheduler[1000], time = 0;
pr p1;
rr R; 
int Te_restant[100];
typedef struct element
{
	int val;
	struct element * next;
}Q;

Q * qeue = NULL;


// ajout de l'element d'indexe i a qeue
void addToQeue(int i)
{
	Q *n, *n1;
	n = (Q *)malloc(sizeof(Q));
	n->next = NULL;
	n->val = i;
	if(qeue == NULL) // ajout de l'element d'indexe i a la tete de qeue
	{		
		qeue = n;
	}
	else // ajout de l'element d'indexe i a la fin de qeue
	{
		for(n1 = qeue ; n1->next!=NULL; n1=n1->next);
		n1 -> next = n;
	}
}

//chercher les processus arrivee a date= time ,et s'il existe appele addToQeue pour les ajouter à qeue
void addArrivedProcessesToQeue()
{
	int i;
	for(i=0; i<NP; i++)
	{
		if(p1.proc[i].DA == time)
		{
			addToQeue(i);
		}
	}
}

//retourne l'indexe du processus a la tete de qeue + le supprime de qeue
int getNextProcess()
{
	Q *n;
	int x;
	if(qeue == NULL)
	{
		return -1;
	}
	else
	{
		x = qeue -> val;
		n = qeue;
		qeue = qeue -> next;
		free(n);
		return x;
	}
}

int main(int argc, char *argv[])
{
        printf("\n\n\t\t\t\t\tQuantum: ");
	scanf("%d", &quantum);
	p1 = extract(argv[1]);
	NP = p1.sz;
	R.size=-1;
	int Ncomplet = 0;
	for (int i = 0; i < NP; i++)//initialisation de Te_restant
	  {
    		Te_restant[i] = p1.proc[i].TE;
  	  }
		
	int np, q, i;
	q = 0;
	addArrivedProcessesToQeue();
	while(Ncomplet != NP) //verifier s'il reste des processus qui n'ont pas encore termine leur execution 
	{
		np = getNextProcess();//recupere l'indexe du processus existant dans la tete de qeue
		if(np == -1)
		{
		
		//s'il n y a pas de processus dans le qeue d'attente , shedular[time]= -1 ce que veuut dire que le cpu est vide(idle)

			scheduler[time] = -1;
			time++;
			addArrivedProcessesToQeue();
		}
		else//s'il y a des processus dans le qeue d'attente
		{
			q = quantum;
	               R.size=R.size+1;
	               R.tab[R.size].pos = np;
	               R.tab[R.size].deb = time;

			if(Te_restant[np] < q)
			{
				q = Te_restant[np];
			}
			
			for(i = q; i>0; i--)
			{
				scheduler[time]=np;
				time++;
				Te_restant[np]--;
				addArrivedProcessesToQeue();
			}
		        R.tab[R.size].fin = time;
			if(Te_restant[np] > 0)// ajout du processus a la fin de la qeue d'attente s'il n'a pas encore termine son temps d'execution
			{
				addToQeue(np);
			}
			else{     // le processus a terminé son temps d'execution =>recuperation de son temps de sortie
				p1.proc[np].TR = time; 
				Ncomplet ++;
			}
		}
		
	}
	
        affichage(p1.proc, p1.sz);	
	gantt_chart_preemptif(p1.proc , p1.sz, R);
}
