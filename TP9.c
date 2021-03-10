#include<stdio.h>
#include<stdlib.h>

typedef struct Maillon{
						int valeur;
						struct Maillon * suivant;
						} maillon;

typedef struct Maillon* liste;




liste InitListe()
{
		liste tete;
		tete=NULL;
		return tete;
} 
int ajouter (liste *tete, int V)
{
	      	maillon* m;
	        m=(maillon *)malloc(sizeof(maillon));
			if(m!=NULL)
			{
					m->valeur = V;
					m->suivant = NULL;
			}
			
			if(m!=NULL)
			{
					m->suivant = *tete;
					*tete =m;
			           return 1;
			}
		return 0;
}
void afficherListe(liste tete)
			{
			maillon* m;
			m=tete;
			while(m!=NULL)
		  {
				printf("%d",m->valeur);
			    m=m->suivant;	
          }
}  
int longListe(liste tete)
{
		maillon* m;
		int nb=0;
		m=tete;
		while(m!=NULL)
		{
			nb++ ;
			m=m->suivant;
		}
		return nb;
} 

maillon* Recherche(liste tete , int V)
{
		maillon* ptr;
		ptr=tete;
		while(ptr!=NULL)
		{
			if(ptr->valeur==V)
			return ptr;
			ptr=ptr->suivant;
		}
		return NULL;
} 
int nbr_d_occurences(liste tete , int V)
{
int c=0;

	maillon* ptr;
		ptr=tete;
		while(ptr!=NULL)
		{
			if(ptr->valeur==V)
			
			c++;
			ptr=ptr->suivant;
		}
		return c;

}
int max_liste(liste tete )
{int mx;
		maillon* ptr;
		
		ptr=tete;
		
		
		mx=ptr->valeur;
		
		while(ptr!=NULL)
		{
			if(mx<ptr->valeur)
			 {mx=ptr->valeur;}
			
			ptr=ptr->suivant;
		}
		return mx;
	

}
int modifier(liste*tete , int v,int c)
{
		maillon* ptr;
		ptr=*tete;
		while(ptr!=NULL)
		{
			if(ptr->valeur==v)
			{
			ptr->valeur=c;
			break;
	     	}
			ptr=ptr->suivant;
			
		}
		return 0;
	
	
	
}
int renvoyer(liste tete , int v)
{
	int i=0,c;
	maillon* ptr;
	ptr=tete;
	
		while(ptr!=NULL)
		{
			c=ptr->valeur;
			if (i==v)
			{printf(" elet %d=|%d",i,c);}
			i++;
			ptr=ptr->suivant;
			
		}
		return 0;
	
	
	
}

main()
{
	int i,n,v,r,m,mx,k,o,p;
	liste l;
	l=InitListe();
	printf("veuillez saisir le nmbr que vous voullez ajouter  =|");
	scanf("%d",&n);
	printf("\n\n  ");
	for(i=0;i<n;i++)
	{
			  printf("elet %d = ",i+1);
	          scanf("%d",&v);
	          printf("\n\n  ");
	          ajouter (&l, v);
	          printf("\n\n  ");
	}
	afficherListe(l);
	printf("\n\n  ");
	mx=max_liste(l );
	printf("la valeur maximale de votre liste =|%d",mx);
	printf("\n\n  ");
	printf("veuillez saisir le nmbr que vous voullez rechercher  =|");
	scanf("%d",&m);
	printf("\n\n  ");
	r=nbr_d_occurences(l , m);
	
	printf("la valeur %d repeter %d fois dans la liste   ",m ,r);
	printf("\n\n  ");
	mx=max_liste(l );
	printf("\n\n  ");
	printf("veuillez saisir le i =|");
	scanf("%d",&p);
	renvoyer(l, p);
	printf("\n\n  "); 
    printf("veuillez saisir elet que vous voullez modifier   =|");
	scanf("%d",&k);
	printf("\n\n  ");
	printf("veuillez saisir un  nmbr que =|");
	scanf("%d",&o);
	modifier(&l ,k,o);
	afficherListe(l);	
	printf("\n\n  "); 
	
}



















