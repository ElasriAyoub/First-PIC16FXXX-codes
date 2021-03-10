#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Maillon{
				    	char valeur;
				    	struct Maillon * suivant;
					} maillon;

typedef maillon* pile;
pile creer_pile()
{
	pile p=NULL;
	
	return p;
}
int estVide(pile  p)
{
			if(p==NULL)
			     return 1;
			return 0;
} 
int sommet(pile P, char *x)
{
					if (estVide(P)==0) {
											*x =P->valeur;
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

int bien_parenthese(char c[])
{
	pile p;
	
	int dp=1,i=0;
	p=creer_pile();
	while((i<strlen(c)) && (dp=1))
	{
		if(c[i]=='(')
		{
			empiler(&p,c[i]);dp=1;
			
		}
		if(c[i]==')')
		{  if(!estVide(p)){
		
		                 depiler(&p);dp=1;
			
		                }
		   else
		   {
		        dp=0;
		   }             
	
		
	   }i++;
    }
    if((!estVide(p)))
    {dp=0;
	}
    
 return dp;
}
int bien_saisie(char c[])
{
	
	pile p;
	
	int dp=1,i=0;
	char x;
	p=creer_pile();
	while((i<strlen(c)) && (dp=1))
	{
		if(c[i]=='('||c[i]=='[')
		{
			empiler(&p,c[i]);dp=1;
			
		}
		else{
	
		if(c[i]==')')
		sommet(p,&x);
		{  if((estVide(p)==0)&&(x=='(')){
		
		                 depiler(&p);dp=1;
			
		                }
		  if((estVide(p)==1)||(x!='('))
		   {
		        dp=0;
		   }             
	
		
	   }
	   if(c[i]==']')
	   {	sommet(p,&x);
	   	if((estVide(p)==0)&&(x=='[')){
		
		                 depiler(&p);dp=1;
			
		                }
		   if((estVide(p)==1)||(x!='['))
		   {
		        dp=0;
		   }             
	
		
	   	
	   	
	   }
	   
	   
	   	}i++;
    }
    if((estVide(p)==0))
    {
	   dp=0;
	}
    
 return dp;
	
	
	
}		
		




main()
{   int v,l;
	char c[]="()()()";
	char ch[]="()";
	v=bien_parenthese(c);
	if(v==0)
	{
		printf("la ch n'est pas bien parenthese");
		
	}
	if(v==1)
	{
		printf("la ch est  bien parenthese");
		
	}
	printf("--------------------------------------------------\n");
	l= bien_saisie(c);
	if(l==0)
	{
		printf("la ch n'est pas bien saisie");
		
	}
	if(l==1)
	{
		printf("la ch est  bien saisie");
		
	}
	
	
	
	
	
	
}





















