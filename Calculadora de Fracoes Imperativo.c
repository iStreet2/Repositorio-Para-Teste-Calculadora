#include <stdio.h>

typedef struct {
  int num;
  int den;
} Fracao;

Fracao Soma(Fracao f1, Fracao f2) {
  Fracao f3;
  f3.num = (f1.num * f2.den) + (f2.num * f1.den);
  f3.den = (f1.den * f2.den);
  if(f3.num == 0) f3.den = 0;
  return f3;
}

Fracao Subtracao(Fracao f1, Fracao f2) {
  Fracao f3;
  f3.num = (f1.num * f2.den) - (f2.num * f1.den);
  f3.den = f1.den * f2.den;
  if(f3.num == 0) f3.den = 0;
  return f3;
}

Fracao Multiplicacao(Fracao f1, Fracao f2) {
  Fracao f3;
  f3.num = f1.num * f2.num;
  f3.den = f1.den * f2.den;
  if(f3.num == 0) f3.den = 0;
  return f3;
}

Fracao Divisao(Fracao f1, Fracao f2) {
  Fracao f3;
  f3.num = f1.num * f2.den;
  f3.den = f1.den * f2.num;
  if(f3.num == 0) f3.den = 0;
  return f3;
}

Fracao Simplificacao(Fracao f1) {
  int a = 1;
  if(f1.num == 0) {
    f1.den = 0;
    return f1;
    }
  if (f1.num == f1.den) {
    f1.num = 1;
    f1.den = 1;
    return f1;
  }
  while (a == 1 && f1.num != 1 && f1.den != 1) {
    if (f1.num % 2 == 0 && f1.den % 2 == 0) {
      f1.num = f1.num / 2;
      f1.den = f1.den / 2;
    } else if (f1.num % 3 == 0 && f1.den % 3 == 0) {
      f1.num = f1.num / 3;
      f1.den = f1.den / 3;
    } else if (f1.num % 5 == 0 && f1.den % 5 == 0) {
      f1.num = f1.num / 5;
      f1.den = f1.den / 5;
    } else if (f1.num % 7 == 0 && f1.den % 7 == 0) {
      f1.num = f1.num / 7;
      f1.den = f1.den / 7;
    } else if (f1.num % 9 == 0 && f1.den % 9 == 0) {
      f1.num = f1.num / 9;
      f1.den = f1.den / 9;
    } else if (f1.num % 11 == 0 && f1.den % 11 == 0) {
      f1.num = f1.num / 11;
      f1.den = f1.den / 11;
    } else
      a = 0;
  }
  return f1;
}

void Comparacao(Fracao f1, Fracao f2) {
  if ((f1.num / f1.den) < (f2.num / f2.den))
    printf("\nA fração %d/%d é maior.\n", f1.num, f1.den);
  else if ((f1.num / f1.den) == (f2.num / f2.den))
    printf("\nAs frações são iguais.\n");
  else
    printf("\nA fração %d/%d é maior.\n", f2.num, f2.den);
}

int main(void) {
  Fracao f1, f2, f3;
  int op;
  int on = 1;
  printf("------------Calculadora de Fração------------\n");
  while (on == 1) {
    printf("\nQual Operação Deseja Realizar?\n");
    printf("\n1.Soma\n2.Subtração\n3.Multiplicação\n4.Divisão\n5."
           "Simplificação\n6.Comparação\n7.Sair\n");
    printf("\nOpção: ");
    scanf("%d", &op);
    switch (op) {
    case 1:
      printf("\nDigite o numerador da sua primeira fração: ");
      scanf("%d", &f1.num);
      printf("\nDigite o denominador da sua primeira fração: ");
      scanf("%d", &f1.den);
      printf("\nAgora o numerador da sua segunda fração: ");
      scanf("%d", &f2.num);
      printf("\nE o denominador da sua segunda fração: ");
      scanf("%d", &f2.den);
      if(f2.den == 0 || f1.den == 0){
        printf("\nIMPOSSIVEL DIVIDIR POR 0!\n");
        break;
      }
      f3 = Soma(f1, f2);
      printf("\nO resultado da soma é: %d/%d", f3.num, f3.den);
      printf("\nSimplificado fica: %d/%d", Simplificacao(f3).num,
             Simplificacao(f3).den);
      printf("\n");
      break;
    case 2:
      printf("\nDigite o numerador da sua primeira fração: ");
      scanf("%d", &f1.num);
      printf("\nDigite o denominador da sua primeira fração: ");
      scanf("%d", &f1.den);
      printf("\nAgora o numerador da sua segunda fração: ");
      scanf("%d", &f2.num);
      printf("\nE o denominador da sua segunda fração: ");
      scanf("%d", &f2.den);
      if(f2.den == 0 || f1.den == 0){
        printf("\nIMPOSSIVEL DIVIDIR POR 0!\n");
        break;
      }
      f3 = Subtracao(f1, f2);
      printf("\nO resultado da subtração é: %d/%d", f3.num, f3.den);
      printf("\nE Simplificado fica: %d/%d", Simplificacao(f3).num,
             Simplificacao(f3).den);
      printf("\n");
      break;
    case 3:
      printf("\nDigite o numerador da sua primeira fração: ");
      scanf("%d", &f1.num);
      printf("\nDigite o denominador da sua primeira fração: ");
      scanf("%d", &f1.den);
      printf("\nAgora o numerador da sua segunda fração: ");
      scanf("%d", &f2.num);
      printf("\nE o denominador da sua segunda fração: ");
      scanf("%d", &f2.den);
      if(f2.den == 0 || f1.den == 0){
        printf("\nIMPOSSIVEL DIVIDIR POR 0!\n");
        break;
      }
      f3 = Multiplicacao(f1, f2);
      printf("\nO resultado da multipliacação é: %d/%d", f3.num, f3.den);
      printf("\nE Simplificado fica: %d/%d", Simplificacao(f3).num,
             Simplificacao(f3).den);
      printf("\n");
      break;
    case 4:
      printf("\nDigite o numerador da sua primeira fração: ");
      scanf("%d", &f1.num);
      printf("\nDigite o denominador da sua primeira fração: ");
      scanf("%d", &f1.den);
      printf("\nAgora o numerador da sua segunda fração: ");
      scanf("%d", &f2.num);
      printf("\nE o denominador da sua segunda fração: ");
      scanf("%d", &f2.den);
      if(f2.den == 0 || f1.den == 0){
        printf("\nIMPOSSIVEL DIVIDIR POR 0!\n");
        break;
      }
      f3 = Divisao(f1, f2);
      printf("\nO resultado da divisão é: %d/%d", f3.num, f3.den);
      printf("\nE Simplificado fica: %d/%d", Simplificacao(f3).num,
             Simplificacao(f3).den);
      printf("\n");
      break;
    case 5:
      printf("\nDigite o numerador da sua fração: ");
      scanf("%d", &f1.num);
      printf("\nDigite o denominador da sua fração: ");
      scanf("%d", &f1.den);
      if(f1.den == 0){
        printf("\nIMPOSSIVEL DIVIDIR POR 0!\n");
        break;
      }
      f3 = Simplificacao(f1);
      printf("\nO resultado da simplificação é: %d/%d", f3.num, f3.den);
      printf("\n");
      break;
    case 6:
      printf("\nDigite o numerador da sua primeira fração: ");
      scanf("%d", &f1.num);
      printf("\nDigite o denominador da sua primeira fração: ");
      scanf("%d", &f1.den);
      printf("\nAgora o numerador da sua segunda fração: ");
      scanf("%d", &f2.num);
      printf("\nE o denominador da sua segunda fração: ");
      scanf("%d", &f2.den);
      if(f2.den == 0 || f1.den == 0){
        printf("\nIMPOSSIVEL DIVIDIR POR 0!\n");
        break;
      }
      Comparacao(f1, f2);
      printf("\n");
      break;
    case 7:
      on = 0;
      break;
    }
  }
  return 0;
}