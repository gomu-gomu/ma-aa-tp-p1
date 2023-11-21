#include <stdio.h>
#include <stdbool.h>

#include "1b.h"
#include "pile.h"

bool vérification(char expression[])
{
  Pile pile = pile_vide();

  for (int i = 0; expression[i] != '\0'; i++)
  {
    char currentChar = expression[i];
    if (currentChar == '(' || currentChar == '[' || currentChar == '{')
    {
      empiler(&pile, currentChar);
    }
    else if (currentChar == ')' || currentChar == ']' || currentChar == '}')
    {
      if (est_vide(&pile))
      {
        return false;
      }

      char poppedChar = dépiler(&pile);
      if ((currentChar == ')' && poppedChar != '(') ||
          (currentChar == ']' && poppedChar != '[') ||
          (currentChar == '}' && poppedChar != '{'))
      {
        return false;
      }
    }
  }

  return est_vide(&pile);
}

void question_1b()
{
  printf("1. B - Vérification d'équilibre des parenthèses.\n");

  char *expression1 = "2 * [(a + b) - c] + {5 * d}";
  char *expression2 = "[a + (b - c}] * 5";

  printf("\"E1 = %s\" est %s\n", expression1, vérification(expression1) ? "Parenthèses correctes" : "Parenthèses incorrectes");
  printf("\"E2 = %s\" est %s\n", expression2, vérification(expression2) ? "Parenthèses correctes" : "Parenthèses incorrectes");

  printf("\n");
}