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
int sommet(pile P, char *x)
{
					if (!estVide(P)) {
											*x = P->valeur;
											return 1;
										}
					return 0;
} 
int empiler(pile *p, char V)
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
void pilecopy(pile p )
{char ch[10],x,c;
int i=0;
	while(!estVide(p))
	{      sommet(p,&c);
	     	ch[i]=c;
		    depiler( &p);
			i++;
	}
	ch[i]='\0';
//	for(i=0;ch[i]!='\0';i++)
//	printf(" %c",ch[i]);
puts(ch);	
	
	
}


main()
{
	
	
	
	
	
	
	
	pile p;
	char c;
	p=creer_pile();
	empiler(&p,'A'); depiler(&p);
    empiler(&p,'B'); sommet(p,&c);
    empiler(&p,'a'); empiler(&p,c);
    pilecopy( p );
	
	
	
	
}

