#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
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
void sommet(pile P, int *x)
{
					if (!estVide(P)) {
											*x = P->valeur;
										//	return 1;
										}
					//return 0;
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
								m=*p;
								*p=(*p)->suivant;
								free(m);
								return 1;
				                 }
return 0;
		} 

		
		
		
void affiche(pile p){
	int t[100];
	int i=0,x,r,o;
	pile dp=creer_pile();
	
	while(!estVide(p))
	{
		sommet(p,&x);
		t[i]=x;
		empiler(&dp,x);
		r=depiler(&p);
		i++;
		
	}
	
	
	
	t[i]=122222222;
	for(i=0;t[i]!=122222222;i++)
	{  
		printf("elet-pile =|: %d\n",t[i]);
	}
			while(!estVide(dp))
	{      sommet(dp,&o);
			empiler(&p,o);
		    depiler( &dp);
			
	}	
	
	
}
pile depilerkelt(pile p,int k)
{int i=0,r,c;
for ( i=0;i<k;i++)
			{
			   r=depiler(&p);
			   
			   if(estVide(p)==1)
			   {
			    
				 printf("la pile est depiler totalement \n ");
				 
			   
			   }
			   
				
          }	
	
return p;
	
	
}
	
pile  depilet_jusq_x(pile p ,int x)
{int O,r, c;
	sommet(p,&O);
	while(O!=x && estVide(p)==0)
	{
	r=depiler(&p);
	sommet(p,&O);
		
	}
	
//affiche(p)	;

return p;
	
	
	
	
}

    
    

	
main()
{
	int k;
	pile p;
	int x,a,i ;
	
	
	p=creer_pile();
	printf("pile-taille =");
			scanf("%d",&a );
	for(i=0;i<a;i++)
	{       
	        printf("pile-%d =",i);
			scanf("%d",&x );
			printf("\n\n");
			empiler(&p,x);
	}printf("-----------------------\n");
	affiche(p );
    printf("-----------------------\n\n\n");	
	
	
	
	
	printf("pile:condition d'arrete  =: ");
	scanf("%d",&x );
	p=depilet_jusq_x(p,x);
	affiche(p)	;
	printf("----------------------\n\n\n");
    printf("NOMBRE DE DEPELAGE =");
	scanf("%d",&k );
	p=depilerkelt(p, k);
    affiche(p );
	
	
			}			
