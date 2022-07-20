#include <stdio.h>
#include <string.h>

void forca(int state){
  if(state == 0){
    printf("\n------------");
    printf("\n|          |");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n-");
  } 
  else if(state == 1){
    printf("\n------------");
    printf("\n|          |");
    printf("\n|          0");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n-");
  } 
  else if(state == 2){
    printf("\n------------");
    printf("\n|          |");
    printf("\n|          0");
    printf("\n|          |");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n-");
  } 
  else if(state == 3){
    printf("\n------------");
    printf("\n|          |");
    printf("\n|          0");
    printf("\n|         -|");
    printf("\n|           ");
    printf("\n|");
    printf("\n|");
    printf("\n-");
  } 
  else if(state == 4){
    printf("\n------------");
    printf("\n|          |");
    printf("\n|          0");
    printf("\n|         -|-");
    printf("\n|           ");
    printf("\n|");
    printf("\n|");
    printf("\n-");
  }
   else if(state == 5){
    printf("\n------------");
    printf("\n|          |");
    printf("\n|          0");
    printf("\n|         -|-");
    printf("\n|         /  ");
    printf("\n|");
    printf("\n|");
    printf("\n-");
  }
   else if(state == 6){
    printf("\n------------");
    printf("\n|          |");
    printf("\n|          0");
    printf("\n|         -|-");
    printf("\n|         / \\ ");
    printf("\n|");
    printf("\n|    Nao foi dessa vez!");
    printf("\n-");
  }
}

int main(void) {
  char  palavra_da_forca[100];//palavra secreta
  printf("\nJogador 1: Digite uma palavra para ser adivinhada -> ");
  fgets(palavra_da_forca, 100, stdin);
  printf("A palavra tem %lu letras", strlen( palavra_da_forca)-1);
  
  //retira o ultimo caracter de p_sec que esta a mais devido a captura ser com fgets()
   palavra_da_forca[strlen( palavra_da_forca)-1]='\0';
  char palavra_na_tela[100];//palavra para tela
  strcpy(palavra_na_tela,  palavra_da_forca);//copia de p_sec 
  //substitui letras por '_'
  for(int i=0;i<strlen(palavra_na_tela);i++){
    palavra_na_tela[i]='_';
  }
  
  int num_erros = 0;
  while(1){
    //imprimir a forca
    limpa_tela();
    forca(num_erros);
    //imprimir os underline/underscores '_' para cada letra da palavra secreta, ou seja, imprimir p_tela
    printf("\nAdivinhe a palara: ");
    for(int i = 0; i<strlen(palavra_na_tela); i++){
      printf("%c ", palavra_na_tela[i]);
    }
    //recebe a letra
    printf("\nLetra: ");
    char letra;
    scanf(" %c", &letra);//o espaço antes do % é por conta do repl.it usado via web...
    //se letra correta atualiza palavra na tela 
    //verifica se a letra esta correta
    int erro_ou_acerto=1;//1=sim 0=nao
    for(int i = 0; i<strlen(palavra_na_tela); i++){
      if(letra == palavra_da_forca[i]){//certo
        palavra_na_tela[i]=letra;
        erro_ou_acerto = 0;
      } 
    }
    //senao, incrementa erros
    if(erro_ou_acerto == 1){
      num_erros++;
    }
    //verifica se o jogo acabou
    //verifica se ganhou
    //verifica se p_sec é igual a p_tela
    if(strcmp(palavra_na_tela, palavra_da_forca) == 0){
      //ENTAO ganhou
      printf("\nAcertou: ");
      for(int i = 0; i<strlen(palavra_na_tela); i++){
        printf("%c ", palavra_na_tela[i]);
      }
      printf("\nVenceu! Parabéns!!!");
      printf("\nYou win!");
      break;
    }
    //verifica se perdeu
    if(num_erros == 6){
      //perdeu
      forca(num_erros);
      break;
    }
  }

  return 0;
}
