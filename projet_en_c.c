/*Ca c'est le projet demandé,voila ma version de code*/
/*Mehdi Belhiba*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
/* declarer la structure */
typedef struct{
    char ID[10];
    char NAME[10];
    char PRENAME[10];
    float BALANCE;
}InfoClients;


int indextabl = -1;
InfoClients info[1000];
int i = 0;

/* functions */
void Mainenu();
void    AddAccount();
void    AddMultipleAccount();
void    Operations();
int     SearchByID();
void    Retrait();
void    Deposit();
void    show();
void    ShowAllAccounts();
void    InAscendingOrder();



/*function to add accounts */
void    AddAccount(){
    system("cls");
    printf("\n\t___Introduire un compte bancaire___\n\n");
    printf("\t__veuille saisir les informations__\n\n");
    printf("\tentrer le CIN: ");
    scanf("%s",info[i].ID);
    printf("\tentrer le Nom: ");
    scanf("%s",info[i].NAME);
    printf("\tentrer le Prenom: ");
    scanf("%s",info[i].PRENAME);
    printf("\tentrer le Montant: ");
    scanf("%f",&info[i].BALANCE);
    printf("\n%s %s %s %f\n",info[i].CIN,info[i].Nom,info[i].Prenom,info[i].Montant);
    printf("\n---Ajouter est Succee---\n");
    indextabl++;

}
/* function for adding multiple accounts*/
void    AddMultipleAccount(){
    system("cls");
    int NbrClients,i;
    printf("\n___Introduire plusieurs compte bancaire___\n\n");
    printf("saisir le nombre des comptes que vou avez ajouter: \n");
    scanf("%d",&NbrClients);
    for (i = 0; i < NbrClients; i++)
    {
        printf("\nveuille saisir les informations numero %d: \n\n",i+1);
        printf("\tentrer le CIN: ");
        scanf("%s",info[i].ID);
        printf("\tentrer le Nom: ");
        scanf("%s",info[i].NAME);
        printf("\tentrer le Prenom: ");
        scanf("%s",info[i].PRENAME);
        printf("\tentrer le Montant: ");
        scanf("%f",&info[i].BALANCE);
        indextabl++;
    }
    
    for (i = 0; i < NbrClients; i++){
        printf("\n\tles informations de client numero %d\n\n",i+1);
        printf("\t%s ",info[i].ID);
        printf("\t%s ",info[i].NAME);
        printf("\t%s ",info[i].PreNAME); 
        printf("\t%f ",info[i].BALANCE);
        printf("\n");
    }
    printf("\n---l'ajout a été fait---\n");
}

/*function for searching an account by id*/
int    SearchByID(){
    char ID[10];
    int i;
    printf("\tdonner votre CIN:");
    scanf("%s",ID);
    for(i = 0;i<indextabl;i++)
    {
        if(strcmp(cin,info[i].ID) == 0)
        {
            printf("compte est existe ;");
            return i;
        }
    }
    if(strcmp(cin,info[i].ID) == 1){
        return -1;
    }
}
/*function for money withdrawal*/
void    Retrait(){

    float Montant;
    int i = SearchByID();
    if(i >= 0){
        printf("\n%s %s %s %f\n",info[i].CIN,info[i].Nom,info[i].Prenom,info[i].Montant);
        printf("\n\tdonner le Montant pour retrait: ");
        scanf("%f",&BALANCE);

        if(Montant > info[i].BALANCE){
            printf("impossible Pour retrait!!!");
        }
        else{
            info[i].BALANCE = info[i].BALANCE - BALANCE;
            printf("\n%s %s %s %f\n",info[i].ID,info[i].NAME,info[i].PRENAME,info[i].BALANCE);
        }
    }
    else{
        printf("ce compte n\'existe pas");
    }
}

/* functon for money deposit*/
void    Deposit(){
    float BALANCE;
    int i = SearchByID();
    if(i >= 0){
        printf("\n%s %s %s %f\n",info[i].ID,info[i].NAME,info[i].PRENAME,info[i].BALANCE);
        printf("\n\tdonner le Montant pour depot: ");
        scanf("%f",&Montant);
        info[i].BALANCE = info[i].BALANCE + BALANCE;
        printf("\n%s %s %s %f\n",info[i].ID,info[i].NAME,info[i].PRENAME,info[i].BALANCE);
    }
    else{
        printf("ce compte n\'existe pas");
    }
}
/*function for In account changes*/

void    Operations(){
    system("cls");
    int choix;
    printf("\n\n\t---------Les opertaion-----------\n\n");
    printf("\t___[1]__Retrait__________:\n\n");
    printf("\t___[2]__Depot____________:\n\n");
    printf("\t___[3]____Menu Principal____________:\n\n");
    printf("\tEntrer votre choix:");
    scanf("%d",&choix);
    switch(choix){
        case 1:
            Retrait();
        break;
        case 2:
            Depot();
        break;
        case 3:
            Mainenu();
        break;
        default:
            printf("__erreur de saisi__");
        break;
    }
}

/* function for ordering the tab */
void    TriTab(){
    int i,j;
    InfoClients temp;
    for (i = 0; i <indextabl; i++){
        for(j = 0; j <indextabl; j++){
            if(info[j].BALANCE > info[j +1].BALANCE){
                temp= info[j];
                info[j] = info[j +1];
                info[j + 1] = temp;
            }
        }
    }
}

/* function for showing thed tab in ascending order*/
void    InAscendingOrder(){
    TriTab();
    int i;
    for(i = 0;i<=indextabl;i++)
    {
        printf("\t%s ",info[i].ID);
        printf("\t%s ",info[i].NAME);
        printf("\t%s ",info[i].PRENAME);
        printf("\t%f ",info[i].BALANCE);
        printf("\n\n");
    }
}

/* function for showing thed tab in descendant order*/
void    ParOrdreDescendant(){
    TriTab();
    int i;
    printf("\n");
    for(i = indextabl;i>=0;i--)
    {
        printf("\t%s ",info[i].ID);
        printf("\t%s ",info[i].NAME);
        printf("\t%s ",info[i].PRENAME);
        printf("\t%f ",info[i].BALANCE);
        printf("\n\n");
    }
}





/*fonction for showing menus*/
void    Affichage(){
    int choix;
    system("cls");
    printf("\t-----------------L\'affichage-----------------\n\n");
    printf("\t___[1]__ Par Ordre Ascendant__________:\n\n");
    printf("\t___[2]__ Par Ordre Descendant____________:\n\n");
    printf("\t___[3]__Recherche par CIN____________:\n\n");
    printf("\t___[4]____Menu Principal____________:\n\n");
    printf("\tEntrer votre choix:");
    scanf("%d",&choix);
    switch(choix){
        case 1:
            InAscendingOrder();
        break;
        case 2:
            ParOrdreDescendant();
        break;
        case 3:
            i = SearchByID();
            if(i >= 0)
                printf("\n%s %s %s %f\n",info[i].ID,info[i].NAME,info[i].PRENAME,info[i].BALANCE);
            else
                printf("ce compte n\'existe pas:");
        break;
        case 4:
            Mainenu();
        break;
        default:
            printf("__erreur de saisi__");
        break;
    }
}

/* fuction for showing the main menu */
void    Mainenu(){
    system("cls");
    int choix;
    printf("\n\t------------------BIENVENU---------------------\n\n");
    do
    {
        
        printf("\n\t__[1]_Introduire un compte bancaire_________\n\n");
        printf("\t__[2]_Introduire plusieurs comptes bancaires\n\n");
        printf("\t__[3]_Operations____________________________\n\n");
        printf("\t__[4]_Affichage_____________________________\n\n");  
        printf("\t__[5]_Quitter l\'application_________________\n\n");
        printf("\t_____________donner votre choix ____________\n\n");
        scanf("\t%d",&choix);

        switch (choix)
        {
        case 1:
            AddAccount();
            break;
        case 2:
            AddMultipleAccount();
            break;
        case 3:
            Operations();
            break;
        case 4:
            show();
            break;
       
        case 5:
            printf("\n\nvous avez quitte le programme:");
            break;
        default:
            printf("erreur de saisir  :\n");
            break;
        }
    } while (choix != 5);
    
}

int main(){
    system("COLOR 0A");
    Mainenu();
    return 0;
}