#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/// la déclaration de structure de Gestion voiture///
typedef struct
{
    int idvoiture;
	char marque[15];
	char nomvoiture[15];
	char couleur[7];
	int nbplaces;
	int prixJour;
	char enLocation[3];

} voiture;


typedef struct date
{
	int jj;
	int mm;
	int aa;
} date;

/// la déclaration de structure de Gestion location///
typedef struct contrat 
{
	float numcontrat;
	int nbrJ;
	int idvoiture;
	int idclient;
	date debut;
	date fin;
	int cout;
} contrat;

/// la déclaration de structure de Gestion Client///
typedef struct {
	int idclient;
	char nom[20];
	char prnom[20];
	char CIN[10];
	int rue;
	char quartier[15];
	char ville[15];
	int num;
	int cpostal;
	int phone;
}client;



//************************************************************
//**	Fonction  : EnTete					                **
//**	Parametre : pas de parametre					    **
//**	Traitement: elle dessine l'entete de notre interface**
//************************************************************



void EnTete()
{
	system("cls");



   
	
	printf("\t\xc9");
	printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
	printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
	printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
	printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
	printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
	printf("\xbb");
	
	printf("\n                  \t\t  Location voiture                      \n");	

	printf("\t\xc8");
	printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
	printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
	printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
	printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
	printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
	printf("\xbc");

	printf("\n\n");

}

//// PARTIE VOITURE ////




//********************************************************
//**	Fonction  : Saisir une voiture              	**
//**	Parametre : une fichier pour sauvgarder les     ** 
//**   informations saisie par l'utilisateur            **
//**	Traitement: Saisie des champs d'un ou           ** 
//**                plusieurs voiture                   **
//********************************************************




void Saisirvoiture(FILE *listeclient)
{
	voiture *clt,*CLT;	//***pointeut sur structure voiture a saisir***
    int n;
    
	EnTete();
	printf("combien de voiture :");
	scanf("%d",&n);
	
	
	clt=(voiture*)malloc(n*sizeof (voiture));


	for(CLT=clt;CLT<(clt+n);CLT++){
	
	printf("\nSaisie voiture........");
	
	printf("\n\t\tle id voiture:");
	scanf("%d",&CLT->idvoiture);
	
	printf("\n\t\tla marque                : ");
	scanf("%s",&CLT->marque);
	
	printf("\n\t\tle nom de voiture        : ");
	scanf("%s",&CLT->nomvoiture);
	
    printf("\n\t\tla couleur                :");
    scanf("%s",CLT->couleur);
	
	printf("\n\t\tle nombre de place           :");
	scanf("%d",&CLT->nbplaces);

	printf("\n\t\tle prix de jour            : ");
	scanf("%d",&CLT->prixJour);
	
	printf("\n\t\ten location                 : ");
	scanf("%s",&CLT->enLocation);
	
	
}

   listeclient=fopen("voiture.txt","a+");
   
	
   for(CLT=clt;CLT<clt+n;CLT++){
    fprintf(listeclient,"\n \t %d",CLT->idvoiture);
    fprintf(listeclient,"\t \t %s",CLT->marque);
    fprintf(listeclient,"\t \t %s",CLT->nomvoiture);
    fprintf(listeclient,"\t \t %s",CLT->couleur);
    fprintf(listeclient,"\t \t %d",CLT->nbplaces);
    fprintf(listeclient,"\t \t %d",CLT->prixJour);
    fprintf(listeclient,"\t \t %s",CLT->enLocation);
		
		}

	fclose(listeclient);
	free(clt);
	
	
	
}

      

//************************************************************
//**    Fonction : Affichage de liste des voitures          **
//**    Parametre : le fichier liste voiture                **
//**    Traitement: c'est une Fonction  qui affiche         **  
//**                les voitures                            ** 
//************************************************************


void listevoiture(FILE *listevoiture){
	char c;
	EnTete();
	printf("\n                               \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                               \xb3 List du Voiture:\xb3");
	printf("\n                               \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9\n");
	
	listevoiture=fopen("voiture.txt","r");
	printf("   Id voiture  |    Marque    |   Nom de Voiture    |    Couleur    |   Nombre de Places   |   Prix    |    En location    \n");
	c=fgetc(listevoiture);
	while(c != EOF){
		printf("%c",c);
		c=fgetc(listevoiture);
	}
	fclose(listevoiture);
}




//************************************************************
//**    Fonction : nombre de lignes                         **
//**    Parametre : le fichier de liste  voiture            **
//**    Traitement: c'est une Fonction qui calculer le      **  
//**                nombre de ligne dans le fichie          ** 
//************************************************************

int nbreligne(FILE *p){
	char c;
	int lign=1;
	p=fopen("voiture.txt","r");
	c= getc(p);
	while(c!=EOF){
		if(c=='\n'){
			  lign++;
		}
		c=getc(p);
	}
	return lign;
}




//********************************************************
//**    Fonction  : Modifier un voiture                 **
//**    Parametre : fichier de liste voiture            **
//**    Traitement: Modifie un ou plusieurs voiture     **
//**                  s'il existe                       **
//**    Utilise   : la fonction listevoiture            **
//**                  La fonction nombre de ligne       **
//********************************************************




void modifierVOITURE(FILE *liste){

	voiture *tab,*pt;
	int tmp,nbM,idmo;
	EnTete();
	listevoiture(liste);
	printf("\n\t donnez le nombre de voiture que vous voulez modifier s'il vous plait: ");
	scanf("%d",&nbM);
	tmp=nbreligne(liste);
	tab=(voiture*)malloc(tmp*sizeof(voiture));
	
	liste=fopen("voiture.txt","r");
	for(pt=tab;pt<tab+tmp;pt++){
		fscanf(liste,"%d %s %s %s %d %d %s",&pt->idvoiture,&pt->marque,&pt->nomvoiture,&pt->couleur,&pt->nbplaces,&pt->prixJour,&pt->enLocation);
	}
	fclose(liste);
	
	liste=fopen("voiture.txt","r+");
	for(pt=tab;pt<tab+nbM;pt++){
		
		printf("\n saisir le id de voiture num %d: ",pt-tab+1);
		scanf("%d",&idmo);
		for(pt=tab;pt<tab+tmp;pt++){
		if(idmo==pt->idvoiture){
			    printf("Veuillez entrer le nouvelle id       : ");
				scanf("%d",&pt->idvoiture);
				
				printf("Veuillez entrer la nouvelle marque      : ");
				scanf("%s",&pt->marque);
				
				printf("Veuillez entrer le nouvelle nom de voiture   : ");
				scanf("%s",&pt->nomvoiture);
				
				printf("Veuillez entrer la nouvelle couleur      : ");
				scanf("%s",&pt->couleur);
			
				printf("Veuillez entrer le nouvelle nombre de place  : ");
	            scanf("%d",&pt->nbplaces);
	
             	printf("Veuillez entrer le nouvelle prix de jour  :     ");       
            	scanf("%d",&pt->prixJour);
			
				printf("en location    : ");
				scanf("%s",&pt->enLocation);
				}
	
		fprintf(liste,"\n \t %d",pt->idvoiture);
        fprintf(liste,"\t  %s",pt->marque);
        fprintf(liste,"\t  %s",pt->nomvoiture);
        fprintf(liste,"\t  %s",pt->couleur);
        fprintf(liste,"\t  %d",pt->nbplaces);
        fprintf(liste,"\t  %d",pt->prixJour);
        fprintf(liste,"\t  %s",pt->enLocation);
			}
	   	printf("la voiture a ete modifier ");
	}
	fclose(liste);
	free(tab);
	
		}




//************************************************************
//**    Fonction  : Supprimer un ou plusieurs voiture	    **
//**    Parametre : fichier de Liste de voiture				**
//**    Traitement: elle supprime un voiture à partir de    **
//**                sa position								**
//**	Utilise   : la fonction liste voiture		    	**
//**                La fonction nombre de ligne             **
//************************************************************



void suppvoiture(FILE *liste){
	
	
	voiture *tab,*pt;
	int tmp,nbs,idsupp;
	
	listevoiture(liste);
	printf(" \n\tcombien de voiture vous voulez supprimer:");
	scanf("%d",&nbs);
	tmp=nbreligne(liste);
	
	tab=(voiture*)malloc(tmp*sizeof(voiture));
	
	liste=fopen("voiture.txt","r");
	for(pt=tab;pt<tab+tmp;pt++){
		fscanf(liste,"%d %s %s %s %d %d %s",&pt->idvoiture,&pt->marque,&pt->nomvoiture,&pt->couleur,&pt->nbplaces,&pt->prixJour,&pt->enLocation);
	}
	fclose(liste);
	
	liste=fopen("voiture.txt","r+");
	for(pt=tab;pt<tab+nbs;pt++){
		
		printf("\n\tdonner le id de voiture num %d:",pt-tab+1);
		scanf("%d",&idsupp);
		for(pt=tab;pt<tab+tmp;pt++){
		if(idsupp==pt->idvoiture){
		}
		
		else
    fprintf(liste,"\t %d   %s   %s   %s   %d   %d    %s \n",pt->idvoiture,pt->marque,pt->nomvoiture,pt->couleur,pt->nbplaces,pt->prixJour,pt->enLocation);
    
  }
		printf("\n voiture supprimer.");
	}
	fclose(liste);
	free(tab);
	
	}



///FINI DE PARTIE VOITURE ///




/// PARTIE CLIENT ////	



//********************************************************
//**	Fonction  : Saisie d'un ou plusieurs client		**
//**	Parametre : fichier liste client				**
//**	Traitement: Saisie des champs du clients		**
//********************************************************

void SaisieClient(FILE *listeclient)
{
	client *clt,*CLT;	//***pointeut sur structure client a saisir***
   
    int n;
    
	EnTete();
	printf("combien de clients :");
	scanf("%d",&n);
	
	
	clt=(client*)malloc(n*sizeof (client));


	for(CLT=clt;CLT<(clt+n);CLT++){
	
	printf("\nSaisie personne........");
	
	printf("\n\t\tle id client:");
	scanf("%d",&CLT->idclient);
	
	printf("\n\t\tNom           : ");
	scanf("%s",&CLT->nom);
	
	printf("\n\t\tPrenom        : ");
	scanf("%s",&CLT->prnom);
	
    printf("\n\t\tle code d'identitee nationale:");
    scanf("%s",CLT->CIN);
	
	printf("\n\tAdresse...");
	
	printf("\n\t\tNumero        : ");
	scanf("%d",&CLT->num);
	
	printf("\n\t\tRue           : ");
	scanf("%d",&CLT->rue);
	
	printf("\n\t\tQuartier         : ");
	scanf("%s",&CLT->quartier);
	
	printf("\n\t\tVille         : ");
	scanf("%s",&CLT->ville);
	
	printf("\n\t\tCode postal   : ");
	scanf("%d",&CLT->cpostal);

	printf("\n\t\tN° telephone  : ");
	scanf("%d",&CLT->phone);
	
	
}

   listeclient=fopen("client.txt","a+");
   
	
   for(CLT=clt;CLT<clt+n;CLT++){
    		fprintf(listeclient,"\n\t %d",CLT->idclient);
    		fprintf(listeclient,"\t %s",CLT->nom);
		    fprintf(listeclient,"\t %s",CLT->prnom) ;
            fprintf(listeclient,"\t %s",CLT->CIN);
            fprintf(listeclient,"\t %d  %d  %s  %s  %d",CLT->num,CLT->rue,CLT->quartier,CLT->ville,CLT->cpostal);
            fprintf(listeclient,"\t %d",CLT->phone);
					
		
		}

	fclose(listeclient);
	free(clt);
	
	
	
}

      



//************************************************************
//**    Fonction  : Afichage la liste des clients           **
//**    Parametre : le fichier de liste clients             **
//**    Traitement: c'est une fonction qui affiche la       **  
//**               liste des clients                        ** 
//************************************************************



void listeclient(FILE *listeclient){
		EnTete();
   
    char c;
    printf("\n                               \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                               \xb3 List du Clients:\xb3");
	printf("\n                               \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9\n");
	
    
    printf("Id client|    Nom     |   Prénom     |    CIN    |            Adresse               |   Numéro de Téléphone    \n");
    listeclient=fopen("client.txt","r");
    c=getc(listeclient);
    while(c!=EOF){
    	printf("%c",c);
		c=fgetc(listeclient);
		
	}
	fclose(listeclient);

   
}



//************************************************************
//**    Fonction : nombre de lignes                         **
//**    Parametre : le fichier de liste  client             **
//**    Traitement: c'est une Fonction qui calculer le      **  
//**                nombre de ligne dans le fichie          ** 
//************************************************************



 int nbrligne(FILE *p){
	char c;
	int lign=0;
	p=fopen("client.txt","r");
	c= getc(p);
	while(c!=EOF){
		if(c=='\n'){
			  lign++;
		}
		c=getc(p);
	}
	return lign;
}





//********************************************************
//**    Fonction  : Modifier un client ou plusieurs     **
//**                    client                          **
//**    Parametre : fichier de liste clients            **
//**    Traitement: Modifie un ou plusieurs clients     **
//**                  s'il existe                       **
//**    Utilise   : la fonction listeclients            **
//**                  La fonction nombre de ligne       **
//********************************************************



void modifierclient(FILE *liste){
	char nom[20];
	client *tab,*pt;
	int tmp,nbM,idm;
	
	EnTete();
	listeclient(liste);
	printf("\n\t donnez le nombre de client que vous voulez modifier s'il vous plait: ");
	scanf("%d",&nbM);
	tmp=nbrligne(liste);
	tab=(client*)malloc(tmp*sizeof(client));
	
	liste=fopen("client.txt","r");
	for(pt=tab;pt<tab+tmp;pt++){
		fscanf(liste,"%d %s %s %s %d %d %s %s %d %d",&pt->idclient,&pt->nom,&pt->prnom,&pt->CIN,&pt->num,&pt->rue,&pt->quartier,&pt->ville,&pt->cpostal,&pt->phone);
	}
	fclose(liste);
	
	liste=fopen("client.txt","r+");
	for(pt=tab;pt<tab+nbM;pt++){
		
		printf("\n saisir le ID de client num %d:",pt-tab+1);
		scanf("%d",&idm);
	
		for(pt=tab;pt<tab+tmp;pt++){
		if(idm==pt->idclient){
			printf("Veuillez entrer la nouvelle id       : ");
				scanf("%d",&pt->idclient);
				
				printf("Veuillez entrer la nouvelle nom      : ");
				scanf("%s",&pt->nom);
				
				printf("Veuillez entrer la nouvelle prenom   : ");
				scanf("%s",&pt->prnom);
				
				printf("Veuillez entrer la nouvelle CIN      : ");
				scanf("%s",&pt->CIN);
			
				printf("Veuillez entrer la nouvelle Adresse  : ");
					
	printf("\n\t\tNumero        : ");
	scanf("%d",&pt->num);
	
	printf("\n\t\tRue           : ");
	scanf("%d",&pt->rue);
	
	printf("\n\t\tQuartier         : ");
	scanf("%s",&pt->quartier);
	
	printf("\n\t\tVille         : ");
	scanf("%s",&pt->ville);
	
	printf("\n\t\tCode postal   : ");
	scanf("%d",&pt->cpostal);
			
				printf("Veuillez entrer la nouvelle tele     : ");
				scanf("%d",&pt->phone);
				
			}
			
	    printf("le client a ete modifier ");
	    
	    	fprintf(liste,"\n\t %d",pt->idclient);
    		fprintf(liste,"\t %s",pt->nom);
		    fprintf(liste,"\t %s",pt->prnom) ;
            fprintf(liste,"\t %s",pt->CIN);
            fprintf(liste,"\t %d  %d  %s  %s  %d",pt->num,pt->rue,pt->quartier,pt->ville,pt->cpostal);
            fprintf(liste,"\t %d",pt->phone);
	}
}
	fclose(liste);
	free(tab);
	
		}
	
	

//************************************************************
//**    Fonction  : Supprimer un ou plusieurs clients 	    **
//**    Parametre : fichier de Liste de clients				**
//**    Traitement: elle supprime un client  à partir de    **
//**                son nom 								**
//**	Utilise   : la fonction liste clients		    	**
//**                La fonction nombre de ligne             **
//************************************************************
	





void suppclient(FILE *liste){
	
	char nom[20];
	client *tab,*pt;
	int tmp,nbs;
	EnTete();
	listeclient(liste);
	printf(" \n\tcombien de client vous voulez supprimer:");
	scanf("%d",&nbs);
	tmp=nbrligne(liste);
	
	tab=(client*)malloc(tmp*sizeof(client));
	
	liste=fopen("client.txt","r");
	for(pt=tab;pt<tab+tmp;pt++){
			fscanf(liste,"%d %s %s %s %d %d %s %s %d %d",&pt->idclient,&pt->nom,&pt->prnom,&pt->CIN,&pt->num,&pt->rue,&pt->quartier,&pt->ville,&pt->cpostal,&pt->phone);
	}
	fclose(liste);
	
	liste=fopen("client.txt","w");
	for(pt=tab;pt<tab+nbs;pt++){
		
		printf("\n\tdonner le nom de client num %d:",pt-tab+1);
		scanf("%s",&nom);
		
		if(strcmp(nom,pt->nom)==0){
		}
		
		else
			fprintf(liste,"\t %d   %s   %s   %s   %d   %d   %s   %s   %d   %d\n ",pt->idclient,pt->nom,pt->prnom,pt->CIN,pt->num,pt->rue,pt->quartier,pt->ville,pt->cpostal,pt->phone);
	}
		printf("\n client supprimer.");
	
	fclose(liste);
	free(tab);
	
	}
	


/// FINIE DE PARTIE CLIENT ///	


/// PARTIE CONTRAT ///




//************************************************************
//**    Fonction : nombre de lignes                         **
//**    Parametre : le fichier de liste  contrat            **
//**    Traitement: c'est une Fonction qui calculer le      **  
//**                nombre de ligne dans le fichie          ** 
//************************************************************



int nbreLigne(FILE *p){
	char c;
	int lign=1;
	p=fopen("Contrat.txt","r");
	c= getc(p);
	while(c!=EOF){
		if(c=='\n'){
			  lign++;
			  c=getc(p);
		}
		
	}
   fclose(p);
	return lign;
}




//********************************************************
//**	Fonction  : Louer une voiture    				**
//**	Parametre : fichier des contrats                **
//**	Traitement: Saisie des champs du contrat        **
//**	Utilise   : La fonction nombre de ligne         **
//********************************************************





void Louervoiture(FILE *liste){
	
	char nom[20], rep[3];
	int tmp1,tmp2,nbrJ,AIDE=0,aide=0,aide1=0,nbl;
	client *tab1,*pt1;
	voiture *tab2,*pt2;
	contrat CONT;
	EnTete();
	tmp1=nbreligne(liste);
	tmp2=nbrligne(liste);
	
	tab1=(client*)malloc(tmp2*sizeof(client));
	tab2=(voiture*)malloc(tmp1*sizeof(voiture));
	
	liste=fopen("client.txt","r");
	for(pt1=tab1;pt1<tab1+tmp2;pt1++){
			fscanf(liste,"%d %s %s %s %d %d %s %s %d %d",&pt1->idclient,&pt1->nom,&pt1->prnom,&pt1->CIN,&pt1->num,&pt1->rue,&pt1->quartier,&pt1->ville,&pt1->cpostal,&pt1->phone);
	}
	fclose(liste);
	
	
	liste=fopen("client.txt","r+");
	printf("saisir votre nom s'il vous plait:");
	scanf("%s",&nom);
	for(pt1=tab1;pt1<tab1+tmp2;pt1++){
		
		if(strcmp(nom,pt1->nom)!=0)
		            AIDE=AIDE+1;
		            
	}
		        
		        if(AIDE==tmp2)  printf("\n client non trouve. \n\t s'il vous plait saisir votre information dans le menu de Gestion des Client.");
		        else if(AIDE==tmp2-1){
		        	
		        liste=fopen("voiture.txt","r");
		        for(pt2=tab2;pt2<tab2+tmp1;pt2++){
			     	fscanf(liste,"%d %s %s %s %d %d %s",&pt2->idvoiture,&pt2->marque,&pt2->nomvoiture,&pt2->couleur,&pt2->nbplaces,&pt2->prixJour,&pt2->enLocation);
         	}
	            fclose(liste);
	            liste=fopen("voiture.txt","r+");
	            printf("saisir le id de voiture que vous voulez louer:");
		        scanf("%d",&CONT.idvoiture);
		        	for(pt2=tab2;pt2<tab2+tmp1;pt2++){
		        		if(CONT.idvoiture!=pt2->idvoiture){
		        			aide=aide+1;
						}
					}
		            if(aide==tmp1)  printf("\n voiture non trouve.");
		            else if(aide==tmp1-1 ){
		            	for(pt2=tab2;pt2<tab2+tmp1;pt2++){
		        		   if(strcmp(pt2->enLocation,"oui")==0||strcmp(pt2->enLocation,"OUI")==0){
		        			    printf("\n Désolé,cette voiture est louée.");
						}
						    else if((strcmp(pt2->enLocation,"non")==0||strcmp(pt2->enLocation,"NON")==0)&& CONT.idvoiture==pt2->idvoiture){
						    	
						         	printf("\nsaisir votre id client :");
						         	scanf("%d",&CONT.idclient);
						         	printf("saisir le nombre de jour que la voiture etre en location:");
						         	scanf("%d",&nbrJ);
									 printf("saisir la date de debut que vous voulez louer la voiture svp:");
						         	scanf("%d %d %d",&CONT.debut.jj,&CONT.debut.mm,&CONT.debut.aa);
						         	printf("saisir la date de fin que vous voulez retourner la voiture svp:");
						         	scanf("%d %d %d",&CONT.fin.jj,&CONT.fin.mm,&CONT.fin.aa);
						         	CONT.cout=pt2->prixJour*nbrJ;
						    	    printf("le prix total est :%d",CONT.cout);
						    	    printf("\n vous voulez louer cette voiture :");
						    	    scanf("%s",&rep);
						    	    do{
		        			    	printf("changer la location de voiture :");
		        			    	scanf("%s",&pt2->enLocation);
		        			       }while(strcmp(pt2->enLocation,"non")==0 || strcmp(pt2->enLocation,"NON")==0);
						    	    
						    	    printf("\nmerci .");
						    	    liste=fopen("Contrat.txt","a+");
	                                CONT.numcontrat=CONT.idclient;
	                                fprintf(liste,"\n Contrat N° %f:",CONT.numcontrat);
	                                fprintf(liste,"   %d     %d       %d/%d/%d       %d/%d/%d        %d",CONT.idclient,nbrJ,CONT.debut.jj,CONT.debut.mm,CONT.debut.aa,CONT.fin.jj,CONT.fin.mm,CONT.fin.aa,CONT.cout);
	
	
                                 	fclose(liste);
	
						    fprintf(liste,"\t %d   %s   %s   %s   %d   %d    %s \n",pt2->idvoiture,pt2->marque,pt2->nomvoiture,pt2->couleur,pt2->nbplaces,pt2->prixJour,pt2->enLocation);	    
							}
							
					}
					}
				}
				
				/*for(pt2=tab2;pt2<tab2+tmp1;pt2++)
				 fprintf(liste,"\t %d   %s   %s   %s   %d   %d    %s \n",pt2->idvoiture,pt2->marque,pt2->nomvoiture,pt2->couleur,pt2->nbplaces,pt2->prixJour,pt2->enLocation);*/
	            fclose(liste);
	            free(tab2);
	
	for(pt1=tab1;pt1<tab1+tmp2;pt1++)
	fprintf(liste,"\n %d   %s   %s   %s   %d   %d   %s   %s   %d   %d ",pt1->idclient,pt1->nom,pt1->prnom,pt1->CIN,pt1->num,pt1->rue,pt1->quartier,pt1->ville,pt1->cpostal,pt1->phone);
	fclose(liste);
	free(tab1);
	
	
}




//********************************************************
//**	Fonction  : retourner une voiture    			**
//**	Parametre : fichier des contrats                **
//**	Traitement: changer la location d'une voiture   **
//**	Utilise   : La fonction nombre de ligne         **
//********************************************************



void retournevoiture(FILE *liste){
	
	
	char nom[20],rep[3];
	int tmp1,tmp2,nbrJ,AIDE=0,aide=0,aide1=0,nbl;
	client *tab1,*pt1;
	voiture *tab2,*pt2;
	contrat CONT;
	
	EnTete();
	tmp2=nbreligne(liste);
	tmp1=nbrligne(liste);
	
	tab1=(client*)malloc(tmp1*sizeof(client));
	tab2=(voiture*)malloc(tmp2*sizeof(voiture));
	
	liste=fopen("client.txt","r");
	for(pt1=tab1;pt1<tab1+tmp2;pt1++){
			fscanf(liste,"%d %s %s %s %d %d %s %s %d %d",&pt1->idclient,&pt1->nom,&pt1->prnom,&pt1->CIN,&pt1->num,&pt1->rue,&pt1->quartier,&pt1->ville,&pt1->cpostal,&pt1->phone);
	}
	fclose(liste);
	liste=fopen("client.txt","r+");
	printf("saisir votre nom s'il vous plait:");
	scanf("%s",&nom);
	for(pt1=tab1;pt1<tab1+tmp1;pt1++){
		
		if(strcmp(nom,pt1->nom)!=0)
		            AIDE=AIDE+1;
		            
	}
		        
		        if(AIDE==tmp1)  printf("\n client non trouve.");
		        else if(AIDE==tmp1-1){
		        	
		        liste=fopen("voiture.txt","r");
		        for(pt2=tab2;pt2<tab2+tmp2;pt2++){
			     	fscanf(liste,"%d %s %s %s %d %d %s",&pt2->idvoiture,&pt2->marque,&pt2->nomvoiture,&pt2->couleur,&pt2->nbplaces,&pt2->prixJour,&pt2->enLocation);
         	}
	            fclose(liste);
	            liste=fopen("voiture.txt","r+");
	            printf("saisir le id de voiture que vous voulez retourner:");
		        scanf("%d",&CONT.idvoiture);
		        	for(pt2=tab2;pt2<tab2+tmp2;pt2++){
		        		if(CONT.idvoiture!=pt2->idvoiture){
		        			aide=aide+1;
						}
					}
		            if(aide==tmp2)  printf("\n voiture non trouve.");
		            else if(aide==tmp2-1 ){
		            	for(pt2=tab2;pt2<tab2+tmp2;pt2++){
		        		   if((strcmp(pt2->enLocation,"oui")==0||strcmp(pt2->enLocation,"OUI")==0) && pt2->idvoiture==CONT.idvoiture){
		        			    printf("\n vous etes sûre de récupérer la voiture ?");
		        			    scanf("%s",&rep);
		        			    if(strcmp(rep,"oui")==0||strcmp(rep,"OUI")==0){
		        			    	do{
		        			    	printf("changer la location de voiture :");
		        			    	scanf("%s",&pt2->enLocation);
		        			       }while(strcmp(pt2->enLocation,"oui")==0 || strcmp(pt2->enLocation,"OUI")==0);
								}
						   }
                        }
                }
            }
    
                for(pt2=tab2;pt2<tab2+tmp2;pt2++)
				fprintf(liste,"\t %d   %s   %s   %s   %d   %d    %s \n",pt2->idvoiture,pt2->marque,pt2->nomvoiture,pt2->couleur,pt2->nbplaces,pt2->prixJour,pt2->enLocation);
	            fclose(liste);
	            free(tab2);
	            
	for(pt1=tab1;pt1<tab1+tmp1;pt1++)
	fprintf(liste,"\n %d   %s   %s   %s   %d   %d   %s   %s   %d   %d ",pt1->idclient,pt1->nom,pt1->prnom,pt1->CIN,pt1->num,pt1->rue,pt1->quartier,pt1->ville,pt1->cpostal,pt1->phone);
	fclose(liste);
	free(tab1);

}




//************************************************************
//**    Fonction  : Affichage d'un contrat                  **
//**    Parametre : le fichier des contrat                  **
//**    Traitement: c'est une fonction  qui affiche         **  
//**                les contrat                             ** 
//************************************************************



void listeCONTRAT(FILE *liste){
	EnTete();
   
    char c;
    printf("\n                               \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                               \xb3 List du Contrat:\xb3");
	printf("\n                               \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9\n");
    
    printf("Id client|  nombre de jour     |    date debut    |    date fin   |   le prix    \n");
    liste=fopen("Contrat.txt","r");
    c=getc(liste);
    while(c!=EOF){
    	printf("%c",c);
		c=fgetc(liste);
		
	}
	fclose(liste);
	}
	
	
	

//********************************************************
//**    Fonction  : Modifier un contrat                 **
//**    Parametre : le fichers de liste des contrats    **
//**    Traitement: Modifie un contrat s'il existe      **      
//**    Utilise   : la fonction Liste de contrat        **
//**                La fonction nombre de ligne         **
//********************************************************


void modifierCONTRAT(FILE *liste){
	int idmod,nbl,nbL;
	voiture *pt1,*tab1;
	listeCONTRAT(liste);
	
	nbl=nbreLigne(liste);
	nbL=nbreligne(liste);
	contrat *tab,*pt;
	
	tab = (contrat*)malloc(nbl*sizeof(contrat));


	
	liste=fopen("Contrat.txt","r");
	for(pt=tab;pt<tab+nbl;pt++){
		fscanf(liste,"%d %d %d %d %d %d %d %d %d %d",&pt->numcontrat,&pt->idclient,&pt->nbrJ,&pt->debut.jj,&pt->debut.mm,&pt->debut.aa,&pt->fin.jj,&pt->fin.mm,&pt->fin.aa,&pt->cout);
	}
	fclose(liste);
	liste=fopen("Contrat.txt","r+");
	printf("\n Veuillez entrer le numéro de contrat a modifier : ");
	scanf("%d",&idmod);   
		for(pt=tab;pt<tab+nbl;pt++){
			if(idmod==pt->numcontrat){
				printf("Veuillez entrer la nouvelle id       : ");
				scanf("%d",&pt->idclient);
				
				printf("Veuillez entrer le nouvelle nombre de jour       : ");
				scanf("%d",&pt->nbrJ);
				
				printf("Veuillez entrer la nouvelle date de debut     : ");
				scanf("%d %d %d",&pt->debut.jj,&pt->debut.mm,&pt->debut.aa);
				
				printf("Veuillez entrer la nouvelle date de fin   : ");
				scanf("%d %d %d",&pt->fin.jj,&pt->fin.mm,&pt->fin.aa);
				
				
				printf(" Veuillez entrer le nouvelle prix   :");
				scanf("%d",&pt->cout);	
			}
			fprintf(liste,"\n ContratN°%d:   %d    %d   %d/%d/%d    %d/%d/%d   %d",pt->numcontrat,pt->idclient,pt->nbrJ,pt->debut.jj,pt->debut.mm,pt->debut.aa,pt->fin.jj,pt->fin.mm,pt->fin.aa,pt->cout);
	}
		

	fclose(liste);
	free(tab);
	printf("le contrat a ete modifier ");
}





//************************************************************
//**    Fonction  : Supprimer un Contrat					**
//**    Parametre : le fichers de liste des contrats    	**
//**    Traitement: elle supprime un contrat            	**
//**	Utilise   : La fonction nombre de ligne 			**
//************************************************************

void suppCONTRAT(FILE *ptc){
	int idsup,nbl;
	listeCONTRAT(ptc);
	nbl=nbreLigne(ptc);
	printf("\n Veuillez entrer le num du contrat a supprimer : ");
	scanf("%d",&idsup);
	contrat *tab,*pt;
	tab = (contrat*)malloc(nbl*sizeof(contrat));
	ptc=fopen("Contrat.txt","r");
	for(pt=tab;pt<tab+nbl;pt++){
			fscanf(ptc,"%f %d %d %d %d %d %d %d %d %d",&pt->numcontrat,&pt->idclient,&pt->nbrJ,&pt->debut.jj,&pt->debut.mm,&pt->debut.aa,&pt->fin.jj,&pt->fin.mm,&pt->fin.aa,&pt->cout);
	}
	fclose(ptc);
	ptc=fopen("Contrat.txt","r+");

		for(pt=tab;pt<tab+nbl;pt++){
			if(idsup!=pt->numcontrat){
			fprintf(ptc,"\n ContratN° %f:",pt->numcontrat);
			fprintf(ptc,"   %d    %d   %d/%d/%d    %d/%d/%d   %d",pt->nbrJ,pt->debut.jj,pt->debut.mm,pt->debut.aa,pt->fin.jj,pt->fin.mm,pt->fin.aa,pt->cout);
             }  
	   }
	fclose(ptc);
	free(tab);
	printf("\nle contrat est supprimer .");
}

/// FINI DE PARTIE CONTRAT ///



///Les fonctions Menu ///


//********************************************************
//**	Fonction  : MenuLocation     					**
//**	Parametre : pas de parametre					**
//**	Traitement: creation du menu location   		**
//********************************************************

int MenuLocation()
{
	int choix;
	FILE *contrat;

	EnTete();

	printf("\n                               \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                               \xb3 Location voiture\xb3");
	printf("\n                               \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
	
	printf("\n\n");
	
	printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
	printf("\n               \xba                                              \xba");
	printf("\n               \xba    Visualiser contrat....................1   \xba");
	printf("\n               \xba    Louer  voiture........................2   \xba");
	printf("\n               \xba    Retourner voiture.....................3   \xba");
	printf("\n               \xba    Modifier contrat......................4   \xba");
	printf("\n               \xba    Supprimer contrat.....................5   \xba");
	printf("\n               \xba    Retour................................6   \xba");
	printf("\n               \xba                                              \xba");
	printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
	printf("\n\n                                Votre choix  :  ");
	
	
	scanf("%d",&choix);
	if(choix==2)   Louervoiture(contrat);
	if(choix==1)   listeCONTRAT(contrat);
	if(choix==3)   {
	retournevoiture(contrat);}
	if(choix==4)   modifierCONTRAT(contrat);
	if(choix==5)   suppCONTRAT(contrat);
	



}



//********************************************************
//**	Fonction  : MenuGestionVoiture 					**
//**	Parametre : pas de parametre					**
//**	Traitement: creation du menu GestionVoiture		**
//********************************************************


int MenuGestionVoiture()
{
	int choix;
	FILE *voiture;
    int choix1;
	EnTete();

	printf("\n                               \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                               \xb3 Gestion voiture \xb3");
	printf("\n                               \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
	
	printf("\n\n");
	
	printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
	printf("\n               \xba                                              \xba");
	printf("\n               \xba    Liste des voiture.....................1   \xba");
	printf("\n               \xba    Ajouter voiture.......................2   \xba");
	printf("\n               \xba    Modifier voiture......................3   \xba");
	printf("\n               \xba    Supprimer voiture.....................4   \xba");
	printf("\n               \xba    Retour................................5   \xba");
	printf("\n               \xba                                              \xba");
	printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
	printf("\n\n                                Votre choix  :  ");
	
	

    scanf("%d",&choix);
    
    
    
	if(choix==1){
		listevoiture(voiture);
		
	}
	 if(choix==2){
	Saisirvoiture(voiture);
	
	printf("\n               \xba    La liste...............................1  \xba");
	printf("\n               \xba    Retour ................................2  \xba");
	printf("\n\n                                Votre choix  :  ");
	scanf("%d",&choix1);
		if(choix1==1){
			listevoiture(voiture);
		}
		if(choix1==2){
			MenuGestionVoiture();
		}
	}
	 if(choix==3){
	 	modifierVOITURE(voiture);
    }
	else if(choix==4){
	suppvoiture(voiture);
	}
	
}



//********************************************************
//**	Fonction  : MenuGestionClient 					**
//**	Parametre : pas de parametre					**
//**	Traitement: creation du menu GestionClient		**
//********************************************************

int MenuGestionClient()
{   
    FILE *client;
	
	int choix,choix1;

	EnTete();

	printf("\n                               \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                               \xb3 Gestion client  \xb3");
	printf("\n                               \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
	
	printf("\n\n");
	
	printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
	printf("\n               \xba                                              \xba");
	printf("\n               \xba    Saisie client.........................1   \xba");
	printf("\n               \xba    Liste des client......................2   \xba");
	printf("\n               \xba    Modifier client.......................3   \xba");
	printf("\n               \xba    Supprimer client......................4   \xba");
	printf("\n               \xba    Retour................................5   \xba");
	printf("\n               \xba                                              \xba");
	printf("\n               \xba                                              \xba");
	printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
	printf("\n\n                                Votre choix  :  ");
	
	scanf("%d",&choix);
	
	
	if(choix==1){
	SaisieClient(client);
	printf("\n               \xba    afficher..........................1   \xba");
	printf("\n               \xba    Retour  ..........................2   \xba");
	printf("\n\n                                Votre choix  :  ");	
	scanf("%d",&choix1);
	if(choix1==1){
		listeclient(client);
	}
	else{
		MenuGestionClient();
	}
	}
	if(choix==2){
		listeclient(client);
		
	}
    else if(choix==3){
         modifierclient(client);
	}
	if(choix==4){
	     
	suppclient(client);
	}
    if(choix==5){
    	 
	}
	
}



//********************************************************
//**	Fonction  : MenuPrincipale   					**
//**	Parametre : pas de parametre					**
//**	Traitement: creation du menu principale  		**
//********************************************************


int MenuPrincipal()
{
	int choix;

	EnTete();
    while(
	
	printf("\n                               \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf"),
	printf("\n                               \xb3 Menu Principale \xb3"),
	printf("\n                               \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9"),
	
	printf("\n\n"),
	
	printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb"),
	printf("\n               \xba                                              \xba"),
	printf("\n               \xba    Location..............................1   \xba"),
	printf("\n               \xba    Gestion voitures......................2   \xba"),
	printf("\n               \xba    Gestion clients.......................3   \xba"),
	printf("\n               \xba    Quitter...............................4   \xba"),
	printf("\n               \xba                                              \xba"),
	printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc"),
	printf("\n\n                                Votre choix  :  "),

	scanf("%d",&choix),(choix==1||choix==2||choix==3)){
	
	
	if (choix==1)   {
	MenuLocation();
	}
	else if(choix==2) {
	  MenuGestionVoiture();
	  }
	else if(choix==3)    {
	MenuGestionClient();
	}
    }
}


int main(){
	 MenuPrincipal();
}
