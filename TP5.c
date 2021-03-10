#include<stdio.h>
#include<stdlib.h>
#define CAP 10
typedef struct Maillon{
				    	int valeur;
				    	struct Maillon * suivant;
					} maillon;
/* type PILE */
typedef maillon* pile;
pile creer_pile()
{
	pile p=NULL;
	
	return p;
}
int estVide(pile  p)
{
			if(p== NULL)
			     return 1;
			return 0;
} 
int sommet(pile P, int *x)
{
					if (!estVide(P)) {
											*x = P->valeur;
											return 1;
										}
					return 0;
} 
int empiler(pile *p, int V)
{
	maillon* m;
	m=(maillon*)malloc(sizeof(maillon));
	if(m!=NULL){
					m->valeur = V;
					m->suivant = *p;
					*p=m;
					return 1;
         	}
	       return 0;
} 
int depiler(pile *p){
		maillon* m;
		if (!estVide(*p)){
								m= *p;
								*p= (*p)->suivant;
								free(m);
								return 1;
		                 }
		return 0;
		} 
void afficher(pile p )
{int ch[10],x,c;
int i=0;
	while(!estVide(p))
	{      sommet(p,&c);
	       
		
			ch[i]=c;
		    depiler( &p);
			i++;
	}
ch[i]=1000;
	for(i=0;ch[i]!=1000;i++)
	printf(" %d",ch[i]);	
}
int depiler_k(pile *p,int k)
{
	int i ,c;
		for(i=0;i<k;i++)
		{
		c=depiler(p);
			
		}
		return c;
}

void depiler_jusqu_a(pile *p,int k)
{
		while(!estVide(&p))
		{
		if((*p)->valeur!=k)
		depiler(p);
		else
		 break;
			
		}
	
}
main(){
	
	pile p;
	int k,x,a ;
	
	
	p=creer_pile();
	empiler(&p,0);

	empiler(&p,1);
	
	empiler(&p,2);
	empiler(&p,3);
	
	

	
	
	
	do
	{
    printf("\n -------------------------------\n ") ;
	printf(" 1: Affichage de la pile \n ") ;
	printf(" 2: Depiler K fois \n ") ;
	printf(" 3: Depiler jusqu'a \n ") ;
	printf(" 0: sinon \n ");
	printf("entrez votre choix : ") ;scanf("%d",&a);
	
	switch(a) {
	case 1 :printf("  RESULTATS: ") ; afficher(p) ; break ;
	case 2 : printf(" Entrer la valeur de k : "); scanf("%d",&k);  printf("\n"); depiler_k(&p,k) ; printf("  RESULTATS: ") ;afficher(p) ;break ;
	case 3 : printf(" Entrer la valeur de x : "); scanf("%d",&x);  printf("\n"); depiler_jusqu_a(&p,x); printf("  RESULTATS: ") ;afficher(p) ;break ;
	default : printf(" erreur essayez une autre fois   "); 
		
	}
	getch();
	}while(a!=0);
	
	
	
}
	
	


