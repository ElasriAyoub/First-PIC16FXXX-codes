#include<stdio.h>
#include<stdlib.h>
typedef struct Maillon{
	float valeur;
	struct Maillon *suivant;
}maillon;
typedef struct {
	maillon * queue;
	maillon * tete;	
}file;
file creerfile(){
	file f;
	f.tete=NULL;
	f.queue=NULL;
	return f;
}
int filevide(file f){
	if((f.tete==NULL))
		return 1;
	return 0;
}
int tete(file f,float *x){
	while(!filevide(f)){
		*x=f.tete->valeur;
		return 1;
	}
	return 0;
}
int queue(file f, float *x){
	while(!filevide(f)){
		*x=f.queue->valeur;
		return 1;
	}
	return 0;
}
int enfiler(file *f, float x){
	maillon *m;
	m=(maillon*)malloc(sizeof(maillon));
	if(m!=NULL){
		m->valeur=x;
		m->suivant=NULL;
		if(!filevide(*f)){
			f->queue->suivant=m;
			f->queue=m;
		}
		else{
			f->tete=f->queue=m;
		}
		return 1;
	}

	return 0;
}

int defiler(file *f){
	maillon *m;
	if( !filevide(*f)){
		m=f->tete;
		f->tete=f->tete->suivant;
		free(m);
		return 1;
	}
	return 0;
}
void nbr_elt(file f)
{int c=0;
	while(!filevide(f))
	{
	
	   c++;
	  defiler(&f);
	
	
	
	
	}
	
	//return c;
	printf("longeur du fil :%d",c);
}
void afficher(file* f){
	float ch;
	while(!filevide(*f)){
		tete(*f,&ch);
		printf("%f", ch);
		defiler(&(*f));
	}
}
int enfiler_tab(file *f, float t[100],int n)
{
	int i ;
	for(i=0;i<n;i++)
	{
		enfiler(&f,t[i]);
		
	}
	
	afficher(&f);
	
}



main(){
	file f;
	int ch,l,i,n;
	float t[10];
	printf("veuillez saisir la taille du tab>|");
	scanf("%d",&n);
	printf("\n");
		for(i=0;i<n;i++)
	{
	printf("T[%d]>|",i);
	scanf("%d",&t[i]);
	printf("\n");
		
	}
	f=creerfile();
	enfiler_tab( &f, t, n);
/*	//afficher(f);
nbr_elt(f);
//	printf("longeur du fil :%d",l);
enfiler_tab(fille f, float t[],int n)	 
	*/
	
}
