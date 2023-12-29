#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct bus
{
    int capacite;
    char matricule[50];
    char nomcom[50];
}bus;
typedef struct listchbus {
    bus data;
    struct listchbus *next;
} listchbus;
typedef struct sponsor{
    char message[125];
}sponsor;
typedef struct listsponsor {
    sponsor data;
    struct listsponsor *next;
} listsponsor;
void ajoutsponsor(listsponsor *l){
    sponsor s;
    listsponsor *tmp=NULL;
    printf("donner le message:\n");
    scanf("%s",s.message);
    tmp=malloc(sizeof(s)*2);
    tmp->data=s;
    tmp->next=l;
    l=tmp;
    free(tmp);
}
void affsponsor(listsponsor *l){
    listsponsor *tmp=l;
    while (tmp!=NULL)
    {
        printf("%s",tmp->data.message);
    }
}
int rechercherbusint(char matricule[50] ,listchbus *l){
    int i=0;
    listchbus *tmp=l;
    while (tmp!=NULL) {
        i++;
        if(strcmp(tmp->data.matricule,matricule)==0){
            return i;
        }
        tmp=tmp->next;
    }
    return 0;
}
typedef struct reservation
{
    int numreserv;
    int placeassise;
    char matricule[50];
}reservation;
typedef struct listeservation
{
    reservation data;
    struct listeservation *next;
}listeservation;
int rechercheresvnum(int numresv,listeservation *l){
    int i=0;
    listeservation *tmp=l;
    while (tmp!=NULL) {
        i++;
        if(tmp->data.numreserv==numresv){
            return i;
        }
        tmp=tmp->next;
    }
    return 0;
}
void suppresv(int pos,listeservation *l){
    listeservation *tmp=l;
    if(pos==1){
        l=l->next;
    }
    for (int i = 1; i < pos; i++)
    {
        tmp=tmp->next;
    }
    tmp->next=tmp->next->next;
}
typedef struct agencedevoyage{
    char nom[50];
    char motdepasse[50];
}agencedevoyage;
typedef struct listchagence {
    agencedevoyage data;
    struct listchagence *next;
} listchagence;
typedef struct client
{
    int idclient;
    char nom[50];
    char prenom[50];
    char adresse[256];
    char email[50];
    char telephone[13];
    char motdepasse[256];
}client;
typedef struct pass{
    int idclient;
    int numresv;
}pass;
typedef struct listpass{
    pass data;
    struct listpass *next;
}listpass;
int recherchepassnum(int numresv,listpass *l){
    int i=0;
    listpass *tmp=l;
    while (tmp!=NULL) {
        i++;
        if(tmp->data.numresv==numresv){
            return i;
        }
        tmp=tmp->next;
    }
    return 0;
}
void supppass(int pos,listpass *l){
    listpass *tmp=l;
    if(pos==1){
        l=l->next;
    }
    else{
        for (int i = 1; i < pos; i++)
        {
            tmp=tmp->next;
        }
        tmp->next=tmp->next->next;
    }
}
typedef struct listclient
{
    client data;
    struct listclient *next;
}listclient;
client retourclient(int pos,listclient *l){
    listclient *tmp=l;
    for (int i = 0; i < pos; i++)
    {
        tmp=tmp->next;
    }
    return tmp->data;
}
agencedevoyage retouragence(int pos,listchagence *l){
    listchagence *tmp=l;
    for (int i = 0; i < pos; i++)
    {
        tmp=tmp->next;
    }
    return tmp->data;
}
bus retourbus(int pos,listchbus *l){
    listchbus *tmp=l;
    for (int i = 0; i < pos; i++)
    {
        tmp=tmp->next;
    }
    return tmp->data;
}
reservation retourreservation(int pos,listeservation *l){
    listeservation *tmp=l;
    for (int i = 0; i < pos; i++)
    {
        tmp=tmp->next;
    }
    return tmp->data;
}
listchbus* ajoutbus(listchbus *l,bus b){
    listchbus *tmp=l;
    listchbus *tmp1;
    tmp1=malloc(sizeof(b)*2);
    tmp1->data=b;
    tmp1->next=tmp;
    tmp=tmp1;
    free(tmp1);
    return tmp;
}
listpass* ajoutpass(listpass *l,pass p){
    listpass *tmp=l;
    listpass *tmp1;
    tmp1=malloc(sizeof(p)*2);
    tmp1->data=p;
    tmp1->next=tmp;
    tmp=tmp1;
    free(tmp1);
    return tmp;
}
listpass *retourlistpassc(int idc,listpass *l){
    listpass *tmp=l;
    listpass *l1=NULL;
    pass p;
    while (tmp != NULL){
        if (tmp->data.idclient==idc)
        {
            p.idclient=idc;
            p.numresv=tmp->data.numresv;
            l1=ajoutpass(l1,p);
        }
        
    }
    return l1;
}
listchbus* ajout_bus(listchbus *l,agencedevoyage ag){
    bus b;
    printf("donner la matricule");
    scanf("%s",b.matricule);
    printf("quel est la capacité:\n");
    scanf("%d",&b.capacite);
    strcpy(b.nomcom,ag.nom);
    l=ajoutbus(l,b);
    return l;
}
listchagence* ajoutagence(listchagence *l,agencedevoyage agence){
    listchagence *tmp=l;
    listchagence *tmp1;
    tmp1=malloc(sizeof(agence)*2);
    tmp1->data=agence;
    tmp1->next=tmp;
    tmp=tmp1;
    free(tmp1);
    return tmp;
}
listeservation* ajoutreservation(listeservation *l,reservation resv){
    listeservation *tmp=l;
    listeservation *tmp1;
    tmp1=malloc(sizeof(resv)*2);
    tmp1->data=resv;
    tmp1->next=tmp;
    tmp=tmp1;
    free(tmp1);
    return tmp;
}
listeservation* ajout_reseservation(listeservation *l,bus b){
    reservation resv;
    strcpy(resv.matricule,b.matricule);
    printf("donner le nombre de la reservation:\n");
    scanf("%d",&resv.numreserv);
    resv.placeassise=0;
    l=ajoutreservation(l,resv);
    return l;
}
listclient* ajoutclient(listclient *l,client c){
    listclient *tmp=l;
    listclient *tmp1;
    tmp1=malloc(sizeof(c)*2);
    tmp1->data=c;
    tmp1->next=tmp;
    tmp=tmp1;
    free(tmp1);
    return tmp;
}
int loginclient(listclient *l){
    char email[50];
    char pass[50];
    printf("donner email:\n");
    scanf("%s",email);
    printf("donner mot de passe:\n");
    scanf("%s",pass);
    listclient *tmp=l;
    int i=0;
    while(tmp!=NULL){
        if((strcmp(tmp->data.email,email)==0)&&(strcmp(tmp->data.motdepasse,pass)==0)){
            return i;
        }
    }
    return 0;
}
int loginagence(listchagence *l){
    char email[50];
    char pass[50];
    printf("donner nom:\n");
    scanf("%s",email);
    printf("donner mot de passe:\n");
    scanf("%s",pass);
    listchagence *tmp=l;
    int i=0;
    while(tmp!=NULL){
        if((strcmp(tmp->data.nom,email)==0)&&(strcmp(tmp->data.motdepasse,pass)==0)){
            return i;
        }
    }
    return 0;
}
listchbus *retourlistbusag(listchbus *l1,agencedevoyage ag){
    listchbus *tmp=l1;
    listchbus *l=NULL;
    while (tmp!=NULL)
    {
        if (strcmp(tmp->data.nomcom,ag.nom)==1)
        {
            ajoutbus(l,tmp->data);
        }
        tmp=tmp->next;
    }
    return l;
}
listeservation *retourlistresvbus(listeservation* l,bus b){
    listeservation *tmp = l ;
    listeservation *l1=NULL;
    while (tmp!=NULL)
    {
        if (strcmp(tmp->data.matricule,b.matricule)==0){
            ajoutreservation(l1,tmp->data);
        }
        tmp=tmp->next;
    }
    return l1;
}
listeservation *sumlistresv(listeservation *l,listeservation *l1){
    listeservation *tmp=l1;
    while(tmp!=NULL){
        ajoutreservation(l,tmp->data);
        tmp=tmp->next;
    }
    return l;
}
listeservation *retourlistresvag(listeservation *l,agencedevoyage ag,listchbus *l1){
    listeservation *tmp=NULL;
    listeservation *tmp1=NULL;
    listchbus *l2=retourlistbusag(l1,ag);
    while(l2!=NULL){
        tmp1=retourlistresvbus(l,l2->data);
        tmp=sumlistresv(tmp,tmp1);
    }
    return tmp;
}
void affresv(listeservation *l,listchbus *l1,agencedevoyage ag){
    listeservation *tmp=retourlistresvag(l,ag,l1);
    printf("Réservation de %s\n",ag.nom);
    while (tmp!=NULL)
    {
        printf("%d\n",tmp->data.numreserv);
    }
}
bus choixbus(listchbus *l1,agencedevoyage ag){
    listchbus *l=retourlistbusag(l1,ag);
    listchbus *tmp=l;
    int choix;
    int i;
    i=0;
    while (tmp!=NULL)
    {
        i++;
        printf("%d",i);
        printf(".%s",tmp->data.matricule);
    }
    scanf("%d",&choix);
    bus b=retourbus(choix,l);
    return b;
}
void modifresv(listeservation *l1,agencedevoyage ag,listchbus *l2){
    listchbus *l=retourlistbusag(l2,ag);
    listeservation *tmp=retourlistresvag(l1,ag,l);
    listeservation *tmp1=tmp;
    int choix;
    int i;
    i=0;
    while (tmp!=NULL)
    {
        i++;
        printf("%d",i);
        printf(".%d",tmp->data.numreserv);
    }
    scanf("%d",&choix);
    tmp=tmp1;
    for (int i = 1; i < choix; i++)
    {
        tmp=tmp->next;
    }
    printf("donner la nouvelle matricule:\n");
    scanf("%s",tmp->data.matricule);
}
void supprimerresv(listeservation *l1,agencedevoyage ag,listchbus *l2,listpass *l3){
    listchbus *l=retourlistbusag(l2,ag);
    listeservation *tmp=retourlistresvag(l1,ag,l);
    listeservation *tmp1=tmp;
    int choix;
    int i;
    i=0;
    while (tmp!=NULL)
    {
        i++;
        printf("%d",i);
        printf(".%d",tmp->data.numreserv);
    }
    scanf("%d",&choix);
    tmp=tmp1;
    for (int i = 1; i < choix; i++)
    {
        tmp=tmp->next;
    }
    int num=tmp->data.numreserv;
    i=rechercheresvnum(num,l1);
    suppresv(i,l1);
    do{
        i=recherchepassnum(num,l3);
        supppass(i,l3);
    }while(i!=0);
}
void suppbus(listeservation *l1,agencedevoyage ag,listchbus *l2,listpass *l3){
    bus b=choixbus(l2,ag);
    listeservation *tmp=l1;
    int i=0,j;
    while(tmp!=NULL){
        i++;
        if (strcmp(tmp->data.matricule,b.matricule)==0)
        {
            suppresv(i,l1);
            do{
                j=recherchepassnum(tmp->data.numreserv,l3);
                supppass(i,l3);
            }while(j!=0);
        }
        
    }
}
void ajoutresvag(listchbus *l,listeservation *l1,agencedevoyage ag){
    bus b=choixbus(l,ag);
    ajout_reseservation(l1,b);
    printf("ajout reussie\n");
}
void profilagence(int i,listchagence *l,listchbus *l1,listeservation *l2,listpass *l3,listsponsor *l4){
    agencedevoyage ag=retouragence(i,l);
    int choix;
    do{
        affsponsor(l4);
        printf("1.ajouter une reservation:\n");
        printf("2.ajouter un bus:\n");
        printf("3.modifier une reservation:\n");
        printf("4.supprimer une reservation:\n");
        printf("5.supprimer un bus:\n");
        printf("6.afficher les reservations:\n");
        scanf("%d",&choix);
        switch (choix)
        {
        case 1:
            ajoutresvag(l1,l2,ag);
            break;
        
        case 2:
            ajout_bus(l1,ag);
            break;
        case 3:
            modifresv(l2,ag,l1);
            break;
        case 4:
            supprimerresv(l2,ag,l1,l3);
            break;
        case 5:
            suppbus(l2,ag,l1,l3);
        case 6:
            affresv(l2,l1,ag);
            break;
        }
    }while(choix<0);
}
void choixclientresv(client c,listeservation *l1,listpass *l2){
    listeservation *tmp=l1;
    int i=0;
    while (tmp!=NULL)
    {
        i++;
        printf("%d.",i);
        printf("%d ",tmp->data.numreserv);
    }
    int choix;
    scanf("%d",&choix);
    reservation resv=retourreservation(choix,l1);
    pass p;
    p.idclient=c.idclient;
    p.numresv=resv.numreserv;
    resv.placeassise+=1;
    l2=ajoutpass(l2,p);
}
void suppresvc(int idc,listpass *l){
    listpass *tmp=retourlistpassc(idc,l);
    while (tmp!=NULL)
    {
        printf("%d\n",tmp->data.numresv);
        tmp=tmp->next;
    }
    printf("Numero de la reservation a supprimer?\n");
    int choix;
    scanf("%d",&choix);
    int i=0;
    while (tmp!=NULL)
    {
        i++;
        if ((tmp->data.idclient==idc)&&(tmp->data.numresv==choix))
        {
            supppass(i,l);
        }
        tmp=tmp->next;
    }
    
}
void profilclient(int i,listclient *l,listeservation *l1,listpass *l2,listsponsor *l3){
    client c=retourclient(i,l);
    int choix;
    do{
        affsponsor(l3);
        printf("1.faire une reservation:\n");
        printf("2.supprimer sa reservation:\n");
        scanf("%d",&choix);
        switch (choix)
        {
        case 1:
            choixclientresv(c,l1,l2);
            break;
        
        case 2:
            suppresvc(c.idclient,l2);
            break;
        }
    }while(choix<0);
}
void login(listchagence *l1,listclient *l,listchbus *l2,listeservation *l3,listpass *l4,listsponsor *l5){
    int choix,i;
    do{
    affsponsor(l5);
    printf("1.voyageur\n");
    printf("2.agence\n");
    scanf("%d",&choix);
    switch (choix)
    {
    case 1:
        i=loginclient(l);
        profilclient(i,l,l3,l4,l5);
        break;
    
    case 2:
        i=loginagence(l1);
        profilagence(i,l1,l2,l3,l4,l5);
        break;
    }
    }while (choix>0);
}
void createclient(listclient *l){
    client nouv;
    printf("doner votre cin :\n");
    scanf("%d",&nouv.idclient);
    printf("donner votre nom:\n");
    scanf("%s",nouv.nom);
    printf("donner votre prenom:\n");
    scanf("%s",nouv.prenom);
    printf("donner votre telephone:\n");
    scanf("%s",nouv.telephone);
    printf("donner l'e-mail:\n");
    scanf("%s",nouv.email);
    printf("donner le mot de pass:\n");
    scanf("%s",nouv.motdepasse);
    printf("donner votre address:\n");
    scanf("%s",nouv.adresse);
    l=ajoutclient(l,nouv);
    FILE *f;
    f=fopen("clients.txt","a+");
    fprintf(f,"%d ",nouv.idclient);
    fprintf(f,"%s %s \n",nouv.nom,nouv.prenom);
    fprintf(f,"%s %s %s %s\n",nouv.telephone,nouv.email,nouv.motdepasse,nouv.adresse);
    fclose(f);
}
void createagence(listchagence *l){
    agencedevoyage nouv;
    printf("donner le nom de l'agence:\n");
    scanf("%s",nouv.nom);
    printf("donner le mot de passe:\n");
    scanf("%s",nouv.motdepasse);
    ajoutagence(l,nouv);
}
void create(listchagence *l,listclient *l1,listsponsor *l3){
    int choix;
        do{
        printf("1.voyageur\n");
        printf("2.agence\n");
        printf("3.sponsor:\n");
        scanf("%d",&choix);
        switch (choix)
        {
        case 1:
            createclient(l1);
            break;
        case 2:
            createagence(l);
            break;
        case 3:
            ajoutsponsor(l3);
            break;
        }
    }while (choix>0);
}
int main(){
    listclient *l=NULL;
    listchagence *l1=NULL;
    listchbus *l2=NULL;
    listeservation *l3=NULL;
    listpass *l4=NULL;
    listsponsor *l5=NULL;
    int choix;
    do{
        printf("1.create:\n");
        printf("2.login:\n");
        scanf("%d",&choix);
        switch (choix)
        {
        case 1:
            create(l1,l,l5);
            break;
        case 2:
            login(l1,l,l2,l3,l4,l5);
            break;
        }
    } while (choix>0);
}