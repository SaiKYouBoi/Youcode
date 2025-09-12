#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum MENU
{
    AJOUTER = 1,
    AFFICHER,
    MODIFIER,
    SUPPRIMER,
    RECHERCHER,
    STATS,
    Quit
};


typedef struct
{
    char id[50];
    char nom[50];
    char prenom[50];
    char poste[50];
    int numeroMaillot;
    int age;
    int buts;

} joueur;

char postes[][20] = {"Gardien", "Defenseur", "Milieu", "Attaquant"};

joueur info[200] = {
    {"JOU_1", "Ahmed", "haamidi", "Attaquant", 9, 25, 10},
    {"JOU_2", "Ilias", "elgarch", "Milieu", 8, 27, 5},
    {"JOU_3", "Amine", "vombra", "Defenseur", 4, 30, 2},
    {"JOU_4", "Badr", "Kadir", "Gardien", 1, 28, 0},
    {"JOU_5", "Yassine", "adourkane", "Attaquant", 10, 22, 12},
    {"JOU_6", "Hamidi", "Khalid", "Milieu", 6, 26, 4},
    {"JOU_7", "Kamal", "Amir", "Defenseur", 3, 29, 1},
    {"JOU_8", "Youssef", "Hamri", "Attaquant", 11, 24, 15},
    {"JOU_9", "Morad", "Hakim", "Milieu", 7, 31, 3},
    {"JOU_10", "Jamal", "Yossofi", "Defenseur", 5, 28, 10}};
int cmptjrs = 10;

unsigned int generateID()
{
    static unsigned int currentID = 10;
    return ++currentID;
}

void clear_buffer()
{
    while (getchar() != '\n');
}

void effac_newline(char str[])
{
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }
    else
    {
        clear_buffer();
    }
}

void Sortbyname(joueur info[])
{
    joueur temp;

    for (int i = 0; i < cmptjrs - 1; i++)
    {
        for (int j = 0; j < cmptjrs - i - 1; j++)
        {

            if (strcmp(info[j].nom, info[j + 1].nom) > 0)
            {
                temp = info[j];
                info[j] = info[j + 1];
                info[j + 1] = temp;
            }
        }
    }
}

void Sortbyage(joueur info[])
{
    int choix;
    printf("1.Age (croissant):\n");
    printf("2.Age (decroissant):\n");

    scanf("%d", &choix);
    clear_buffer();

    joueur temp;
    for (int i = 0; i < cmptjrs - 1; i++)
    {
        for (int j = 0; j < cmptjrs - i - 1; j++)
        {
            if (choix == 1)
            {
                if (info[j].age > info[j + 1].age)
                {
                    temp = info[j];
                    info[j] = info[j + 1];
                    info[j + 1] = temp;
                }
            }
            if (choix == 2)
            {
                if (info[j].age < info[j + 1].age)
                {
                    temp = info[j];
                    info[j] = info[j + 1];
                    info[j + 1] = temp;
                }
            }
        }
    }
}

joueur Saisijoueurs()
{
    joueur j;
    int found;
    sprintf(j.id, "JOU_%d", generateID());

    printf("\nLe nom du joueur: ");
    fgets(j.nom, sizeof(j.nom), stdin);
    effac_newline(j.nom);

    printf("Le prenom du joueur: ");
    fgets(j.prenom, sizeof(j.prenom), stdin);
    effac_newline(j.prenom);

    printf("Entrer le numero de maillot: ");
    scanf("%d", &j.numeroMaillot);
    clear_buffer();
    
    printf("Entrer l'age': ");
    scanf("%d", &j.age);
    clear_buffer();

    printf("Entrer le poste (Gardien, Defenseur, Milieu, Attaquant): ");
    fgets(j.poste, sizeof(j.poste), stdin);
    effac_newline(j.poste);

    printf("Entrer le nombre des buts: ");
    scanf("%d", &j.buts);
    clear_buffer();

    return j;
}

void Ajouterjoueurs()
{
    int n;
    int choix;
    int found=0;
    printf("\n1.Ajouter un joueur. \n");
    printf("2.Ajouter plusieurs joueurs.\n");
    printf("\nChoix:");

    scanf("%d", &choix);
    clear_buffer();

    if (choix == 2)
    {
        printf("Nombre des joueurs: ");
        scanf("%d", &n);
        clear_buffer();

        if (n + cmptjrs > 200){
            printf("Liste est pleine");
            return;}
        for (int i = 0; i < n; i++)
        {
            info[cmptjrs] = Saisijoueurs();
            cmptjrs++;
            found=1;
        }
    }
    if (choix == 1)
    {
        if (1 + cmptjrs > 200)
            printf("Liste est pleine");
        for (int i = 0; i < 1; i++)
        {
            info[cmptjrs] = Saisijoueurs();
            cmptjrs++;
            found=1;
        }
    }

if(found){
    printf("-------------------------\n");
    printf("joueur ajoute avec succes\n");
    printf("-------------------------\n");

}
}

void AfficherJoueur(joueur j)
{

    printf("---------- Joueur: %s --------\n", j.id);
    printf("Nom : %s\n", j.nom);
    printf("Prenom : %s\n", j.prenom);
    printf("Numero maillot: %d\n", j.numeroMaillot);
    printf("Poste  : %s\n", j.poste);
    printf("Age  : %d\n", j.age);
    printf("Buts : %d\n", j.buts);
    printf("---------------------------------\n");
}

void AfficherJoueurs()
{
    int choix;
    printf("---------------------------------------\n");
    printf("1.Liste des joueurs\n");
    printf("2.Trie des joueurs ordre alphabetique\n");
    printf("3.Trie des joueurs par age\n");
    printf("4.Les joueurs par poste\n");

    scanf("%d", &choix);
    clear_buffer();

    if (cmptjrs == 0)
    {
        printf("--------------\n");
        printf("Liste est vide\n");
        printf("--------------\n");
    }
    if (choix == 1)
    {
        for (int i = 0; i < cmptjrs; i++)
        {
            AfficherJoueur(info[i]);
        }
    }

    if (choix == 2)
    {
        Sortbyname(info);
        for (int i = 0; i < cmptjrs; i++)
        {
            AfficherJoueur(info[i]);
        }
    }

    if (choix == 3)
    {
        Sortbyage(info);
        for (int i = 0; i < cmptjrs; i++)
        {
            AfficherJoueur(info[i]);
        }
    }

    if (choix == 4)
    {
        for (int i = 0; i < 4; i++)
        {
            printf("---------------------------------------\n");
            printf("\tPoste: %s\n", postes[i]);
            printf("---------------------------------------\n");
            for (int j = 0; j < cmptjrs; j++)
            {
                if (strcmp(info[j].poste, postes[i]) == 0)
                {
                    AfficherJoueur(info[j]);
                }
            }
            printf("\n");
        }
    }
}

void RechJouid(char id[])
{
    int found = -1;
    for (int i = 0; i < cmptjrs; i++)
    {
        if (strcmp(id, info[i].id) == 0)
        {
            AfficherJoueur(info[i]);
            found = 1;
            break;
        }
    }
    if (found == -1)
    {
        printf("-------------\n");
        printf("Non trouve\n");
        printf("-------------\n");
    }
}

void RechJounom(char nom[])
{
    int found = -1;
    for (int i = 0; i < cmptjrs; i++)
    {
        if (strcmp(nom, info[i].nom) == 0)
        {
            AfficherJoueur(info[i]);
            found = 1;
            break;
        }
    }
    if (found == -1)
    {
        printf("--------------\n");
        printf("Non Trouve\n");
        printf("--------------\n");
    }
}

void Recherche()
{
    int choix;
    char ID[50];
    char name[50];
    printf("---------------------------------------\n");
    printf("1.Rechercher un joueur par ID:\n");
    printf("2.Rechercher un joueur par nom:\n");

    printf("Entrer le choix:\n");
    scanf("%d", &choix);
    clear_buffer();

    switch (choix)
    {
    case 1:
        printf("Entrer ID du joueur:");
        fgets(ID, sizeof(ID), stdin);
        effac_newline(ID);
        RechJouid(ID);
        break;
    case 2:
        printf("Entrer Le nom du joueur:");
        fgets(name, sizeof(name), stdin);
        effac_newline(name);
        RechJounom(name);
        break;
    default:
        break;
    }
}

void SuppJoueur()
{
    char ID[50];
    int found = 0;
    int confirm = 0;

    printf("Entrez l'identifiant du joueur que vous souhaitez supprimer :");
    fgets(ID, sizeof(ID), stdin);
    effac_newline(ID);

    printf("Veuillez confirmer que vous souhaitez supprimer ce joueur:\n");
    printf("1.[Oui]\t2.[Non]\n");
    scanf("%d", &confirm);
    clear_buffer();

    if (confirm == 2)
    {
        printf("----------------------\n");
        printf("Suppression annulee.\n");
        printf("----------------------\n");
        return;
    }

    for (int i = 0; i < cmptjrs; i++)
    {
        if (strcmp(ID, info[i].id) == 0)
        {
            for (int j = i; j < cmptjrs - 1; j++)
            {
                info[j] = info[j + 1];
            }
            cmptjrs--;
            printf("-------------------------------------\n");
            printf("Joueur %s supprime avec succes.\n", ID);
            printf("-------------------------------------\n");
            found = 1;
            break;
        }
    }

    if (found != 1)
    {
        printf("Joueur avec ID %s non trouve.\n", ID);
    }
}

void ModifierJoueur()
{
    char ID[50];
    int found = -1;
    printf("---------------------------------------\n");
    printf("Entrer l'ID du joueur a modifier : ");
    fgets(ID, sizeof(ID), stdin);
    effac_newline(ID);

    for (int i = 0; i < cmptjrs; i++)
    {
        if (strcmp(ID, info[i].id) == 0)
        {
            found = i;
            break;
        }
    }

    if (found == -1)
    {
        printf("Joueur avec ID %s non trouve.\n", ID);
        return;
    }

    printf("Joueur trouve :\n");
    AfficherJoueur(info[found]);

    printf("Nouveau poste : ");
    fgets(info[found].poste, sizeof(info[found].poste), stdin);
    effac_newline(info[found].poste);

    printf("Nouvel age : ");
    scanf("%d", &info[found].age);
    clear_buffer();

    printf("Nouveau nombre de buts : ");
    scanf("%d", &info[found].buts);
    clear_buffer();

    printf("--------------------------------------------\n");
    printf("Joueur avec ID %s modifier par succes.\n", ID);
    printf("--------------------------------------------\n");
}

void Stats()
{
    int choix;
    int AgeTotal = 0;
    int but;
    int found = 0;
    int max = -1;
    int indexmb = -1;

    printf("-------------------Statistiques--------------------\n");
    printf("1.Le nombre total de joueurs dans l'equipe.\n");
    printf("2.L'age moyen des joueurs\n");
    printf("3.Afficher les joueurs ayant marque\n");
    printf("4.Afficher le meilleur buteur\n");
    printf("5.Afficher le joueur le plus jeune et le plus age\n");
    scanf("%d", &choix);
    clear_buffer();

    switch (choix)
    {
    case 1:
        printf("----------------------------\n");
        printf("\tNombre total de joueur: %d\n", cmptjrs);
        printf("----------------------------\n");
        break;
    case 2:
        for (int i = 0; i < cmptjrs; i++)
        {
            AgeTotal += info[i].age;
        }
        float Moyen = (float)AgeTotal/cmptjrs;
        printf("----------------------------\n");
        printf("Age moyen des joueurs: %f\n", Moyen);
        printf("----------------------------\n");
        break;
    case 3:
        printf("Entrez le nombre de buts: ");
        scanf("%d", &but);
        clear_buffer();
        for (int i = 0; i < cmptjrs; i++)
        {
            if (info[i].buts > but)
            {
                found = 1;
                AfficherJoueur(info[i]);
            }
        }
        if (!found)
        {
            printf("Aucun joueur n'a exactement %d buts.\n", but);
        }
        break;
    case 4:
        printf("Le meilleur buteur:\n");
        for (int i = 0; i < cmptjrs; i++)
        {
            if (info[i].buts > max)
            {
                max = info[i].buts;
                indexmb = i;
            }
        }

        AfficherJoueur(info[indexmb]);
        break;
    case 5:{
        int pjoune = 0;
        int page = 0;

        for (int i = 1; i < cmptjrs; i++)
        {
            if (info[i].age < info[pjoune].age)
            {
                pjoune = i;
            }
            if (info[i].age > info[page].age)
            {
                page = i;
            }
        }
        printf("---------------------------------------\n");
        printf("Joueur le plus jeune: %s, Age : %d \n", info[pjoune].nom, info[pjoune].age);
        printf("---------------------------------------\n");

        printf("---------------------------------------\n");
        printf("Joueur le plus age: %s, Age : %d \n", info[page].nom, info[page].age);
        printf("---------------------------------------\n");

        break;
    }
}
}
int main()
{
    while (1)
    {   
        printf("-------------Menu Principale------------\n");
        printf("1. Ajouter joueur.\n");
        printf("2. Afficher joueurs.\n");
        printf("3. Modifier un joueur.\n");
        printf("4. Supprimer un joueur.\n");
        printf("5. Rechercher un joueur.\n");
        printf("6. Les Statistiques.\n");
        printf("Entrer 7 pour quitter.\n");
        printf("Choix: ");
        int choix;

        scanf("%d", &choix);
        clear_buffer();

        switch (choix)
        {
        case AJOUTER:
            Ajouterjoueurs();
            break;
        case AFFICHER:
            AfficherJoueurs();
            break;
        case MODIFIER:
            ModifierJoueur();
            break;
        case SUPPRIMER:
            SuppJoueur();
            break;
        case RECHERCHER:
            Recherche();
            break;
        case STATS:
            Stats();
            break;
        case Quit:
            exit(0);
        default:
            printf("----------------\n");
            printf("Choix invalide\n");
            printf("----------------\n");
            break;
        }
    }
}