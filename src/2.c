#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "pile.h"

bool est_operateur(char c)
{
  return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int importance(char operator)
{
  switch (operator)
  {
  case '^':
    return 4;
  case '*':
  case '/':
    return 3;
  case '+':
  case '-':
    return 2;
  case '(':
  case ')':
    return 1;
  default:
    return 0;
  }
}

char *convertToPostfix(char *expression)
{
  Pile operateurs = pile_vide();

  char *postfix = malloc(strlen(expression) + 1);
  int postfixIndex = 0;

  for (int i = 0; expression[i] != '\0'; i++)
  {
    char c = expression[i];

    if (isdigit(c))
    {
      postfix[postfixIndex++] = c;
    }
    else if (est_operateur(c))
    {
      while (!est_vide(&operateurs) && importance(c) <= importance(operateurs.items[operateurs.top]))
      {
        char operator= dépiler(&operateurs);
        postfix[postfixIndex++] = operator;
      }

      empiler(&operateurs, c);
    }
    else if (c == '(')
    {
      empiler(&operateurs, c);
    }
    else if (c == ')')
    {
      while (operateurs.items[operateurs.top] != '(')
      {
        char operator= dépiler(&operateurs);
        postfix[postfixIndex++] = operator;
      }

      dépiler(&operateurs);
    }
  }

  while (!est_vide(&operateurs))
  {
    char operator= dépiler(&operateurs);
    postfix[postfixIndex++] = operator;
  }

  postfix[postfixIndex] = '\0';

  return postfix;
}

int evaluation(char *expression)
{
  Pile pile = pile_vide();
  char *postfix = convertToPostfix(expression);

  for (int i = 0; postfix[i] != '\0'; i++)
  {
    char c = postfix[i];

    if (isdigit(c))
    {
      int operand = c - '0';
      empiler(&pile, operand);
    }
    else if (est_operateur(c))
    {
      int operand1 = dépiler(&pile);
      int operand2 = dépiler(&pile);

      switch (c)
      {
      case '+':
        empiler(&pile, operand2 + operand1);
        break;
      case '-':
        empiler(&pile, operand2 - operand1);
        break;
      case '*':
        empiler(&pile, operand2 * operand1);
        break;
      case '/':
        empiler(&pile, operand2 / operand1);
        break;
      }
    }
  }

  return dépiler(&pile);
}

void question_2()
{
  printf("2. Evaluation d'une expression.\n");

  char *expression = "2 * (4 + 2) - 8 / 2";
  int result = evaluation(expression);

  printf("Expression : %s\n", expression);
  printf("Résultat : %d\n", result);

  printf("\n");
}