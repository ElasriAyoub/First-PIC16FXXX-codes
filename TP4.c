#include<stdio.h>
#include<stdlib.h>

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
pile binaire(pile p,int k)
{		
	
	int r;
	
	while(k!=0)
	{
		r=k%2;
		empiler(&p,r);
		k=k/2;
		
		
	}

	return p;
}

main()
{
		
	pile p;
	
	
	p=creer_pile();
	int k ;
	
	
	printf("entrez un entier de votre choix : ") ;scanf("%d",&k);
    p=binaire(p,k);
   afficher(p);







	
	
	
}





























