#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>




struct liste{
	int val ;
	liste*suiv;
};

int compte(liste*tete){
	int c=0;
	while(tete!=NULL){
		c++;
		tete=tete->suiv;
	}
	return c;
}
int max(liste*tete){
	int ma=tete->val;
	tete=tete->suiv;
	while(tete!=NULL){
		if(tete->val>ma){
			ma=tete->val;
		}
		tete=tete->suiv;
		
	}
	return ma;
}

liste*add_head(liste*tete,int a){
	liste*nouv=(liste*)malloc(sizeof(liste));
	nouv->val=a;
	nouv->suiv=tete;
	tete= nouv;
	return tete;
}


liste*paire(liste*tete){
	liste*tmp;
	tmp=tete;
	for(tmp=tete;tmp->suiv!=NULL;tmp=tmp->suiv){
	
		if((tmp->val) % 2 ==0){
			printf(" %d est paire \n ",tmp->val);

		}

		

		}
		return tete;
	}
		
				
liste*impaire(liste * tete){
		liste*p;
		p=tete;
		for(p=tete;p!=NULL;p=p->suiv){
			if((p->val) % 2 != 0){
				printf("%d est impaire \n ",p->val);
			}
		}
		return tete;
	}
	
	
			
		
void afficher(liste*tete){
	
	liste*tmp=tete;
	if(tete==NULL){
		printf("la liste est  vide");
	}
	else{
	
	while(tmp!=NULL){
		printf(" %d ->",tmp->val);
		tmp=tmp->suiv;	
		
	}
	}
	printf("NULL\n ");
}
	
int somme(liste * tete) {
    int s = 0;
    while (tete!=NULL) {
        s += tete->val;
        tete = tete->suiv;
    }
    return s;
    }  
liste* existe(liste * tete,int x) {
	liste*tmp;
	tmp=tete;
    while (tmp->suiv!=NULL && tmp->val!=x){
	
     tmp = tmp->suiv;
 }
 
    if (tmp!=NULL){
    	printf("%d est  la ",tmp->val);
	}
	else{
		printf("%d nest pas la ", tmp->val);
}
    return tete;
}
    
int min(liste * tete) {
    int m = tete->val;
    tete=tete->suiv;
    while (tete!=NULL) {
        if (tete->val<m) {
        m=tete->val;
}
    tete = tete->suiv;
}
return m;
}
liste*triee(liste*tete){
	int pr;
	liste*tmp,*p;
	for(tmp=tete;tmp->suiv!=NULL;tmp=tmp->suiv){
		for(p=tmp->suiv;p!=NULL;p=p->suiv){
			if(p->val<tmp->val){
				pr=p->val;
				p->val=tmp->val;
				tmp->val=pr;
			}
		}
	}
	return tete;
}
void linked(liste*li1,liste*li2){
	
	while(li1->suiv!=NULL)
	
		li1=li1->suiv;

		li1->suiv=li2;
	
}
liste*ajouteraufin(liste*tete,int a){
	liste*tmp,*nouv;
	tmp=tete;
	nouv=(liste*)malloc(sizeof(liste));
	nouv->suiv=NULL;
	nouv->val=a;
	if(tete==NULL){
		tete=nouv;
	}
	else{
		while(tmp->suiv!=NULL){
			tmp=tmp->suiv;
		}
		tmp->suiv=nouv;
		tmp=nouv;
	}
	return tete;
}


int main(){
   
	liste*li1=NULL;
	liste*li2=NULL;
	
	int n,i,nb,v,x,option=1,chx;
	printf("donnez le nombre des element :");
	scanf("%d",&nb);
	for(i=0;i<nb;i++){
		scanf("%d",&n);
		li1=ajouteraufin(li1,n);
	
	}
	printf("donnez lees elemnt de la 2 liste : \n");
	for(i=0;i<nb;i++){
		scanf("%d",&n);
		li2=add_head(li2,n);
	
	}
	while(option){
		printf("Menu principale");
		printf("\n1.afficher n2.reliée les deux liste\n3.la somme\n4.Minumum \n5.compte \n6.maximum\n7.triee la liste \n8.afficher les nombre paire\n9.les nobre impaire\n10.recherche un nombre");
		printf("\n\5 donnez votre choix ");
		scanf("%d",&chx);
		
	switch (chx) {
        case 1:
            afficher(li1);
            printf("\n");
            afficher(li2);
           break;
      case 2:
         printf("les deux liste reliee : \n ");
         linked(li1,li2);
         afficher(li1);
         break;
        case 3:
          printf("\n la somme de la premier  liste = %d",somme(li1));
          printf("\nla somme de la 2 liste = %d ",somme(li2));
          break;
        case 4:
            printf("\n le minimum nombre de la premier liste = %d ",min(li1));
            printf("\n le minimum nombre de la 2 liste = %d ",min(li2));

        	break;
        case 5:
            printf("\n  le nombre de element de la premiere liste = %d ",compte(li1));
            printf("\n  le nombre de element de la 2 liste = %d ",compte(li2));

            break;
            
		case 6:
			printf(" \n  le max nombre de la premiere liste = %d",max(li1));
			printf(" \n  le max nombre de la 2 liste = %d",max(li2));

			break;
        case 7:
            printf("\n avant le triee : \n\n\t\t");
            afficher(li1);
            printf(" \n\n apres le triee de la premiere liste  : \n\n\t\t",triee(li1));
            printf(" \n\n apres le triee de la 2 liste  : \n\n\t\t",triee(li2));
            afficher(li2);
            break;
        case 8:
        	printf(" \nles nombre paire de la premiere liste : \n ");
            paire(li1);
            printf(" \nles nombre paire de la 2 liste : \n ");
            paire(li2);

            break;
        case 9:
           printf(" \nles  nombre impaire de la premiere liste : \n");
           impaire(li1);
           printf(" \nles  nombre impaire de la 2 liste : \n");
           impaire(li2);
           break;
        case 10:
		    printf(" \n donnez le nombre que va chercher dans la premier liste :  ");
            scanf("%d",&x);
            li1=existe(li1,x);	
            break;
        	
      }
      printf("\n tapez 1 si vous avez continue et 0 pour quitez  : ");
      scanf("%d",&option);
  }
  		getch();

	}

