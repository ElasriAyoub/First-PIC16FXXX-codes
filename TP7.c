#include<stdio.h>
#include<stdlib.h>
#include<conio.h>



/* type maillon */
typedef struct {
				char valeur;
				struct maillon *suivant;
				} maillon;
		
typedef struct {
					maillon *tete;
					maillon *queue;
				} ayoun;
				
				

ayoun creeFile()
				{  ayoun F;
					F.tete=NULL;
					F.queue=NULL;
					return F;
				} 
int estVide(ayoun F)
{
		if(F.tete==NULL && F.queue==NULL )
			return 1;
		return 0;
} 				

int  tete(ayoun F, char *x)
{
			if (!estVide(F)) {
				       *x = F.tete->valeur;
				        return 1;
			                  }
			return 0;
} 


int Queue(ayoun F, char *x)
{
			if (!estVide(F)) {
							*x = F.queue->valeur;
							return 1;
			                  }
                          return 0;
} 
int enfiler(ayoun *F, char V) {
			maillon* m;
			m=(maillon*)malloc(sizeof(maillon));
			if(m!=NULL){
					m->valeur = V;
					m->suivant = NULL;
					if(!estVide(*F)) {
							        F.queue->suivant =m->suivant;
									F->queue = m ;
			                         }
					else 
					{
					       F->tete =F->queue=m;
					}

			  return 1;
		           	}
			                    return 0;} 	
								
int defiler(ayoun *F){
					maillon* m;
					if (!estVide(*F)){
										m=F->tete;
										F->tete=F->tete->suivant;
										free(m);
										return 1;
					                  }
					return 0;
}					
								
								
									                        

int file_copie(ayoun* F)
{int c ,v,i=0;
char t[100];
 char ch;
    ayoun dp=creeFile();
	while(!estVide(*F))
	{
	   	 tete(*F, &ch);
		// enfiler(&dp,ch);
		 //t[i]=ch;
		 printf("%c",ch);
		defiler(&F);
		 //i++;	
	}	//t[i]='\0';
//	printf("--------------\n");
////	getch();

/*	for(i=0;t[i]!='\0';i++)
	printf(" %c",t[i]);*/

//puts(t);	
	
}








main(){ 
ayoun F;
char C;
F=creeFile();
enfiler(&F,'A'); enfiler(&F,'B');
enfiler(&F,'C'); tete(F,&C); defiler(&F);
enfiler(&F,'a'); enfiler(&F,C);
printf("----------------");
getch();
file_copie(&F);
getch();
}










