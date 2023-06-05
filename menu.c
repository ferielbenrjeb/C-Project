#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    char NOM[50];    
    }ch; 
    
int main(int argc, char *argv[]) 
{
    
char chaine[20];
bool trouve=false;
ch cc[100];
int n=0;

    printf("                 --------------------------------------------------------\n");
    printf("                |                    ~~ Mini Projet ~~                   |\n");
    printf("                |           PROGRAMME DE GESTION DES PROCESSUS           |\n");
    printf("                 --------------------------------------------------------\n");

system("ls algo/ | sed -n 's/\\.c$//p' >liste.txt");

FILE *f1=fopen("liste.txt","r");
    if(f1==NULL) {
    	fputs("erreur d'ouverture\n",stderr);
        return 0;
    } else {
                
        char buffer[250];
        char x[50];

        while(fgets(buffer,sizeof buffer,f1)) {
        
            if(sscanf(buffer,"%s",x)==1) {
            if(x[0]!='/'&&x[1]!='/')  //controle sur les commentaires
            {
            strcpy(cc[n].NOM,x); 
            n++;
             }							
             }
}

        fclose(f1),f1=NULL;

        printf("\n\n");
	printf("\t\t\t+-------------------------------------+\n");
	printf("\t\t\t**********        MENU       **********\n");
        printf("\t\t\t+-------------------------------------+\n");
	for (int i = 0; i < n; i++) {
        printf("\t\t                         %s                   \n",cc[i].NOM);
        printf("\t\t\t+-------------------------------------+\n");
        }

	}
	puts("\n\n");
printf("\t\t      BONJOUR, VEUILLEZ SAISIR L'ALGORITHME CHOISI! \n");

        printf("\t\t\t\t\tVotre Choix : ");
scanf("%s",chaine);

for(int k=0;k<n;k++){
            if(strcmp(cc[k].NOM,chaine) == 0)  
            {
            trouve=true; 
            break;
            }}

       if(trouve==true)
        {	printf("\n\n\n");
        	char c[100]="./executable/";
        	strcat(c,chaine);	
        	strcat(c," ");
        	char f[50];
        	strcpy(f,argv[1]);
        	strcat(c,f);   
        	system(c);}
        else{
        	char e[50]="./executable/FIFO ";
        	char f[50];
        	strcpy(f,argv[1]);
        	strcat(e,f);
        	system(e);
        }
       

                printf("\n\n\t\tMerci pour avoir utilisé ce programme (^_^) à trés bientot !!\n\n");
return 0;
}
