#include<stdio.h>
#include<string.h>

typedef struct  //structure du processus 
{
    char NOM[50];
    int DA,TE,P,TR;
}processus;

typedef struct
{
    	processus proc[100];
    	int sz;
}pr;
  
  
  //fonction pour l'extraction des donnees a partir du fichier de configuration  
pr extract(char c[15]){
   pr p;
   p.sz=0;
  
  FILE *fp=fopen(c,"r");
    if(fp==NULL) {
        fputs("erreur d'ouverture\n",stderr);
    } else {
        
        
        char buffer[250];
        char x[50];
        int n,n1,n2;

        while(fgets(buffer,sizeof buffer,fp)) {

            if(sscanf(buffer,"%s %d %d %d",x,&n,&n1,&n2)==4) {
            if(x[0]!='/'&&x[1]!='/')  //controle sur les commentaires
            {
            	strcpy(p.proc[p.sz].NOM,x); 
            	p.proc[p.sz].DA=n;
            	p.proc[p.sz].TE=n1;
            	p.proc[p.sz].P=n2;
            	p.sz++;
             }							
             }
}

        fclose(fp),fp=NULL;
        }
        return p;
        }

 
 

//Tri croissant des processus selon leur date d'arrivée  
void tri_croissant_DA(processus *p,int sz)
{     
processus p1; 
for(int i=0;i<sz;i++)
{
for(int j=i+1;j<sz;j++)
{
if(p[i].DA>p[j].DA)
{
p1=p[i];
p[i]=p[j];
p[j]=p1;
}
}     
 }}       
 


//Tri croissant des processus selon leur date de sortie
void tri_croissant_TR(processus *p,int sz)
{     
processus p1; 
 for(int i=0;i<sz;i++) 
	{
	for(int j=i+1;j<sz;j++)
	{
		if(p[i].TR>p[j].TR)
		{
		p1 = p[i];
		p[i] = p[j];
		p[j] = p1;
		}
	}
	}
}

 
 void affichage(processus *p, int sz){
	printf("\n\n\n");
	printf("\t+-----+----------------+-------------------+------------+----------------+\n");
	printf("\t| Nom | Date d'arrivée | Temps d'execution |  Priorité  | Date de sortie |\n");
	printf("\t+-----+----------------+-------------------+------------+----------------+\n");
	for (int i = 0; i < sz; i++) {
	printf("\t| %3s |      %3d       |        %3d        |    %3d     |      %3d       |\n", p[i].NOM ,p[i].DA,p[i].TE, p[i].P, p[i].TR);
	printf("\t+-----+----------------+-------------------+------------+----------------+\n");
					}
}


 
 //procedure pour l affichage du diagramme de gantt des algorithmes non preemptif
        void gantt_chart_non_preemptif(processus *p, int len)
{
	int i, j;

	printf("\n\n\t DIAGRAMME DE GANTT\n\n");	
	printf("\t ");

	for (i = 0; i < len; i++)
	{
		for (j = 0; j < p[i].TE; j++)
			printf("--");

		printf(" ");
	}

	printf("\n\t|");

	for (i = 0; i < len; i++)
	{
		for (j = 0; j < p[i].TE - 1; j++)
			printf(" ");

		printf("%s", p[i].NOM);

		for (j = 0; j < p[i].TE - 1; j++)
			printf(" ");

		printf("|");
	}
	printf("\n\t ");

	
	for (i = 0; i < len; i++)
	{
		for (j = 0; j < p[i].TE; j++)
			printf("--");

		printf(" ");
	}

	printf("\n\t");

	printf("%d",p[0].DA);

	for (i = 0; i < len; i++)
	{
		for (j = 0; j < p[i].TE; j++)
			printf("  ");
        if (p[i].TR > 9)
			printf("\b");

		printf("%d", p[i].TR);
	}
	printf("\n\n\n");
}


        
    //structure utilise pour la manipulation des donnees dans les algorithmes preemptif    
typedef struct
{
    int pos;
    int deb,fin;
    }tableau;

typedef struct
{
    tableau tab[50];
    int size;
    int date_debut;
    }rr; 



 //procedure pour l affichage du diagramme de gantt des algorithmes preemptif
void gantt_chart_preemptif(processus *p, int len, rr r)
{
	int i, j;
        int s=r.size;

	printf("\n\n\t DIAGRAMME DE GANTT\n\n");
	printf("\t ");

        for (i = 0; i <= s; i++)
	{
		for (j = r.tab[i].deb ; j < r.tab[i].fin ; j++)

			printf("--");

		printf(" ");
	}

	printf("\n\t|");

	for (i = 0; i <= s; i++)
	{
		for (j = r.tab[i].deb ; j < r.tab[i].fin - 1; j++)
			printf(" ");

		printf("%s", p[r.tab[i].pos].NOM);

		for (j = r.tab[i].deb; j < r.tab[i].fin - 1; j++)
			printf(" ");

		printf("|");
	}
	printf("\n\t ");

        for (i = 0; i <= s; i++)
	{
		for (j = r.tab[i].deb ; j < r.tab[i].fin ; j++)
			printf("--");

		printf(" ");
	}

	printf("\n\t");

	printf("%d",r.date_debut);

        for (i = 0; i <= s; i++)
	{
		for (j = r.tab[i].deb ; j < r.tab[i].fin ; j++)
			printf("  ");
        if (r.tab[i].fin > 9)
			printf("\b");

		printf("%d", r.tab[i].fin);		

	}

	printf("\n\n\n");
}
