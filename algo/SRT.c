include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#include"../library.h"

   

int main(int argc, char *argv[])
{
        pr p1 = extract(argv[1]);
        int n = p1.sz;
	rr R;
        R.size=-1;
	int Te_restant[n];
	R.date_debut=p1.proc[0].DA;

	for (int i = 0; i < n; i++)
		{
		Te_restant[i] = p1.proc[i].TE;	// initialisation de Te_restant
		if(p1.proc[i].DA<R.date_debut)
			{
			R.date_debut= p1.proc[i].DA;  //Recuperation de la date de debut
			} 
		}
						
	int complete = 0, time = 0, minm = INT_MAX;
	int shortest = 0, finish_time;
	bool check = false;

	
	while (complete != n) // bouclé jusqu'a tous les processus complete leur temps d'execution
	{

	// trouvé le processus avec le minimum temps d'execution restnat parmi les processus qui sont arrivee jusqu'à ce moment <=time`
		for (int j = 0; j < n; j++) {
			if ((p1.proc[j].DA <= time) && (Te_restant[j] < minm) && Te_restant[j] > 0) {
				minm = Te_restant[j];
				shortest = j; 
				check = true;
			}
		}
		if (check == false) {
			time++;
			continue;
		}
		else{
			// Reduire temps d'execution restant (-1)
		        Te_restant[shortest]--;
                        R.size=R.size+1;
                        R.tab[R.size].pos = shortest;
	                R.tab[R.size].deb = time ;
	                R.tab[R.size].fin = time + 1;
		        // Update minimum
	       	minm = Te_restant[shortest];
		       if (minm == 0)
			       minm = INT_MAX;

		       // Si un processus a terminé son temps d'execution
		       if (Te_restant[shortest] == 0) {

			        complete++;  	  // Incrementé complete
			        check = false;

              			finish_time = time + 1;  // touvé le finish time du processus current 

                               p1.proc[shortest].TR = finish_time;
		                                      } 		
		time++;   // Incrementé le temps
         	}
	}

        affichage(p1.proc, n);
	gantt_chart_preemptif(p1.proc, n, R);
	return 0;
}

