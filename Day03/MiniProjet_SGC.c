#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_RESET "\x1b[0m"

void modfier();
void afficher();
void ajouter();
void rechercher();
void supprimer();

typedef struct
{

  char nom[50];
  char tele[14];
  char email[20];

} contact;

contact info[200];

int size = sizeof(info) / sizeof(info[0]);

int nombre;

int compteurcontact = 0;

int main()
{
here:
  printf(ANSI_COLOR_MAGENTA "\n>\tGestionnaire de Contacts\t<\n" ANSI_COLOR_RESET);

  printf("\n1.Ajouter un contact\n");
  printf("2.Modifier un Contact\n");
  printf("3.Supprimer un Contact\n");
  printf("4.Afficher tous les contacts\n");
  printf("5.Rechercher un contact\n");

  printf("\n\tChoisir un nombre: ");
  scanf("%d", &nombre);

  switch (nombre)
  {
  case 1:
    ajouter();
    goto here;
    break;
  case 2:
    modfier();
    goto here;
    break;
  case 3:
    supprimer();
    goto here;
    break;
  case 4:
    afficher();
    goto here;
    break;
  case 5:
    rechercher();
    goto here;
    break;
  default:
    printf("Choix Invalide\n");
    break;
  }
}

void ajouter()
{
  printf(ANSI_COLOR_MAGENTA "\n>\tAjouter un contact\t<\n" ANSI_COLOR_RESET);
  if (compteurcontact < size)
  {
    printf("\nEntrer le nom: ");
    scanf(" %[^\n]s", &info[compteurcontact].nom);
    printf("Entrer le nemero de telephone: ");
    scanf(" %[^\n]s", &info[compteurcontact].tele);
    printf("Entrer l'adresse email: ");
    scanf(" %[^\n]s", &info[compteurcontact].email);
    compteurcontact++;
  }
  else
  {
    printf("liste est pleine");
  }
}

void afficher()
{
  if (compteurcontact == 0)
  {
    printf("Aucun contact.\n");
    return;
  }

  printf(ANSI_COLOR_MAGENTA "\n>\tContacts\t<\n" ANSI_COLOR_RESET);

  for (int i = 0; i < compteurcontact; i++)
  {
    printf("\nLe nom: %s\n", info[i].nom);
    printf("Numero de telephone: %s\n", info[i].tele);
    printf("Email: %s\n", info[i].email);
  }
}

void rechercher()
{
  int trouve=0;
  printf(ANSI_COLOR_MAGENTA "\n>\tRechercher un contact\t<\n" ANSI_COLOR_RESET);
  char searchedname[50];

  printf("Entrez le nom que vous recherchez: ");
  scanf(" %[^\n]s", searchedname);

  printf(ANSI_COLOR_MAGENTA "\n>\tContact\t<\n" ANSI_COLOR_RESET);

  for (int i = 0; i < compteurcontact; i++)
  {
    if (strcmp(searchedname, info[i].nom) == 0)
    {
      printf("Le nom: %s\n", info[i].nom);
      printf("Le nemero de Telephone: %s\n", info[i].tele);
      printf("Email: %s\n", info[i].email);
      trouve = 1;
    }
  }
  if (trouve != 1)
  {
    printf("Contact non trouve");
  }
}

void modfier()
{
  int trouve=0;
  char searchedname[50];
  printf(ANSI_COLOR_MAGENTA "\n>\tModifier un contact\t<\n" ANSI_COLOR_RESET);

  printf("Entrez le nom que vous Modifer: ");
  scanf(" %[^\n]s", searchedname);

  for (int i = 0; i < compteurcontact; i++)
  {
    if (strcmp(searchedname, info[i].nom) == 0)
    {
      printf("Le numero  ancien: %s", info[i].tele);
      printf("\nLe numero nouveau: ");
      scanf(" %[^\n]s", &info[i].tele);

      printf("\nEmail ancien: %s", info[i].email);
      printf("\nEmail nouveau: ");
      scanf(" %[^\n]s", &info[i].email);
      trouve = 1;
      break;
    }
  }

  if (trouve != 1)
  {
    printf("Contact non trouve");
  }
}

void supprimer()
{
  int trouve=0;
  char searchedname[50];
  printf("Entrez le nom que vous recherchez: ");
  scanf(" %[^\n]s", &searchedname);

  for (int i = 0; i < compteurcontact; i++)
  {
    if (strcmp(searchedname, info[i].nom) == 0)
    {
      for (int j = i; j < compteurcontact - 1; j++)
      {
        info[j] = info[j + 1];
      }
      compteurcontact--;
      printf("Contact supprime avec succes\n");
      trouve = 1;
      break;
    }
    }
    if (trouve!=1){ 
      printf("Contact non trouve\n");
    }
}
