#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "pile.h"

Pile pile_vide()
{
  Pile pile;
  pile.top = -1;

  return pile;
}

bool est_vide(Pile *pile)
{
  return pile->top == -1;
}

bool est_pleine(Pile *pile)
{
  return pile->top == PILE_MAX_SIZE - 1;
}

void empiler(Pile *pile, Element item)
{
  if (est_pleine(pile))
  {
    printf("Erreur : la pile est pleine\n");
    exit(EXIT_FAILURE);
  }

  pile->items[++pile->top] = item;
}

Element dépiler(Pile *pile)
{
  if (est_vide(pile))
  {
    printf("Erreur : la pile est vide\n");
    exit(EXIT_FAILURE);
  }

  return pile->items[pile->top--];
}

void afficher_pile(Pile pile)
{
  printf("Taille de la pile : %d\nContenu de la pile : ", pile.top + 1);

  for (int i = 0; i <= pile.top; i++)
  {
    printf("%c ", pile.items[i]);
  }

  printf("\n");
}