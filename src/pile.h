#ifndef PILE_H
#define PILE_H

#include <stdbool.h>

#define PILE_MAX_SIZE 50

typedef char Element;

typedef struct Pile
{
  char items[PILE_MAX_SIZE];
  int top;
} Pile;

Pile pile_vide();

bool est_vide(Pile *pile);

bool est_pleine(Pile *pile);

void empiler(Pile *pile, Element item);

Element dépiler(Pile *pile);

void afficher_pile(Pile pile);

#endif