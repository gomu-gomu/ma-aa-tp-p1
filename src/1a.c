#include <stdio.h>

#include "1a.h"
#include "pile.h"

void question_1a()
{
  printf("1. A - Affichage de contenu et taile d'une pile.\n");

  Pile pile = pile_vide();

  empiler(&pile, 'A');
  empiler(&pile, 'B');
  empiler(&pile, 'C');
  afficher_pile(pile);

  printf("\n");
}