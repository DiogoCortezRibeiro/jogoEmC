#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.c>
#include <time.h>
#include <ctype.h>

int  l,c ,aux = 0 ,totalPontos = 0, totalJogadas = 0, espacoLivre = 0, scoreUsuario = 0;
int  posLinha = 5, posColuna = 5, porcentagemBombas = 0, pontosRecorde = 0;
int  pontPorRodada = 0, pontPorJogo = 0;
char matControler[5][5], resp, respSalvar;
bool gameOver = false;

void verificaJogada();
void apresentarCampo();
void scoresCampo();
void instrucoesJogo();
void sairJogo(); 
void menuTopo();
void selecioneNivel();
void prencherMatriz(int pBombas);
void fimDeJogo();
void salvarPontuacao();
void arquivoPontuacao(int controle);

void setcursor(int y, int x){ 
   CONSOLE_CURSOR_INFO cursor = {1, FALSE};
   SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y});
}

void menuTopo(){
   system("cls");
   textcolor(15); textbackground(1);
   gotoxy(31, 4); printf("\t                                                      ");
   gotoxy(31, 5);  printf("\t******************************************************");
   gotoxy(31, 6);  printf("\t****************                    ******************");
   gotoxy(31, 7);  printf("\t****************   CAMPO  MINADO    ******************");
   gotoxy(31, 8);  printf("\t****************                    ******************"); 
   gotoxy(31, 9); printf("\t******************************************************");
   gotoxy(31, 10); printf("\t                                                      "); 
}

void menuInicial() {
   int  escolha = 0 , x = 13, y = 50;
   bool existe;
   char tecla;
   menuTopo();
   textbackground(1);
   do{      
      do{
        if(x == 13){
     	  textcolor(3); textbackground(15); setcursor(x,y);
        }
	    else{
          textcolor(15); textbackground(1);	
        }
	    setcursor(13,54); printf("JOGAR");
	 
	    if(x == 15){
          textcolor(3); textbackground(15); setcursor(x,y);
        }
        else{
          textcolor(15); textbackground(1);
   	    }
	    setcursor(15,54); printf("SCORES");
		
	    if(x == 17){
           textcolor(3); textbackground(15); setcursor(x,y);
        }
	    else{
          textcolor(15); textbackground(1);
 	    }
        setcursor(17,54); printf("INSTRUCOES");
	
	    if(x == 19){
          textcolor(3); textbackground(15); setcursor(x,y);
        }
 	    else{
          textcolor(15); textbackground(1);
        }
	    setcursor(19,54);
	    printf("SAIR");	
      	textcolor(3); textbackground(15); setcursor(22,44);
		printf("PRESSIONE ENTER PARA CONTINUAR");			
		textbackground(1);
		if (x == 13){
            setcursor(x + 2, 50); printf(" "); 
        } 
		if (x == 15){
            setcursor(x - 2, 50); printf(" "); setcursor(x + 2, 50); printf(" ");
        } 
		if (x == 17){
            setcursor(x - 2, 50); printf(" "); setcursor(x + 2, 50); printf(" ");
        } 
		if (x == 19){
           setcursor(x - 2, 50); printf(" ");
        }

	   tecla = getch();
	   if(tecla == 72 && x != 13){
          x = x - 2;
       }
	   if(tecla == 80 && x != 19){
          x = x + 2;
       }
	   if(tecla == 13){
          escolha = 1;
       }
	 }while(escolha == 0);
	
	 if(x == 13){
       selecioneNivel();
       break; 
     }
    
     if(x == 15){
       scoresCampo();
       break; 
     }
    
     if(x == 17){
       instrucoesJogo();
       break; 
     }
    
     if(x == 19){
       sairJogo();
       break; 
     }            
   }while(x != 13 && x != 19);  
}

void selecioneNivel(){
    system("cls");
    menuTopo();
    int  escolha = 0, x = 13, y = 50;
    bool existe;
    char tecla;
    do{      
       do{
         if(x == 13){
      	   textcolor(3); textbackground(15); setcursor(x,y);
         }
         
	     else{
            textcolor(15); textbackground(1);	
         }
	     setcursor(13,54); printf("FACIL");
	 
	     if(x == 15){
           textcolor(3); textbackground(15); setcursor(x,y);
         }
         
         else{
           textcolor(15); textbackground(1);
   	     }
	     setcursor(15,54); printf("MEDIO");
		
	     if(x == 17){
            textcolor(3); textbackground(15); setcursor(x,y);
         }
         
	     else{
          textcolor(15); textbackground(1);
 	     }
         setcursor(17,54);
         printf("CHUCKNORRIS");		
         setcursor(22,44); textcolor(3); textbackground(15);
	     printf("PRESSIONE ENTER PARA CONTINUAR");			
		 textbackground(1);
		 if (x == 13){
             setcursor(x - 2, 50); printf(" "); setcursor(x + 2, 50); printf(" "); 
         } 
         if (x == 15){
            setcursor(x - 2, 50); printf(" "); setcursor(x + 2, 50); printf(" ");
         } 
         if (x == 17){
            setcursor(x - 2, 50); printf(" "); setcursor(x + 2, 50); printf(" ");
         } 

         tecla = getch();
         if(tecla == 72 && x != 13){
            x = x - 2;
         }
         if(tecla == 80 && x != 17){
            x = x + 2;
         }
	     if(tecla == 13){
            escolha = 1;
         }
	}while(escolha == 0);
	
	if(x == 13){
       porcentagemBombas = 85;
       espacoLivre       = 6;
       pontPorRodada     = 5;
       pontPorJogo       = 50;
       prencherMatriz(porcentagemBombas);
       break; 
    }
    
    if(x == 15){
       porcentagemBombas = 70;
       espacoLivre       = 5;
       pontPorRodada     = 15;
       pontPorJogo       = 150;
       prencherMatriz(porcentagemBombas);
       break; 
    }
    
    if(x == 17){
       porcentagemBombas = 55;
       espacoLivre       = 4;
       pontPorRodada     = 30;
       pontPorJogo       = 300;
       prencherMatriz(porcentagemBombas);
       break; 
    }          
    
 }while(tecla != 13);
 apresentarCampo();  
     
}

void scoresCampo() {
  arquivoPontuacao(2);
}

void instrucoesJogo() {
   system("cls");
   int x = 13,y = 50; 
   menuTopo();
   textcolor(15);
   setcursor(11,32); printf("1- O jogador devera encontrar o total de casas vazias a cada rodada");
   setcursor(13,32); printf("2- A quantidade de casas vazias variam conforme a dificuldade escolhida");
   setcursor(15,32); printf("3- Facil: 6 casas, Medio: 5 casas, ChuckNorris: 4 casas");  
   setcursor(17,32); printf("4- Conforme o nivel de dificuldade mais bombas estaram presentes no jogo"); 
   setcursor(19,32); printf("5- A cada casa vazia encontrada sera somada na pontuacao um valor"); 
   setcursor(21,32); printf("7- Facil: 5 pontos, Medio: 15 pontos, ChuckNorris: 30 pontos"); 
   setcursor(23,32); printf("8- Todo final de rodada sera somado um valor de bonus a sua pontuacao.");  
   setcursor(25,32); printf("9- Facil: 50 pontos, Medio: 150 pontos, ChuckNorris: 300 pontos"); 
   setcursor(27,32); printf("10- Para maiores duvidas helper@help.com.br");
   textcolor(3); textbackground(15);	
   setcursor(30,44); printf("PRESSIONE ENTER PARA VOLTAR");
   textbackground(1);	  
   getch();
   menuInicial();
}

void sairJogo() {
   Sleep(800);  
   exit(1);
}

void apresentarCampo() { 
    system("cls");
    textcolor(15);
    gotoxy(40, 6); printf("Total de pontos: ");
    textcolor(11);
    gotoxy(57, 6); printf("%d ", scoreUsuario);
    textcolor(15);
    gotoxy(40, 9); printf("Colunas ->      0   1   2   3   4");
    gotoxy(40, 10); printf("Linha 0 ->       |   |   |   |   ");
    gotoxy(40, 11); printf("              ---+---+---+---+---");
    gotoxy(40, 12); printf("Linha 1 ->       |   |   |   |   ");
    gotoxy(40, 13); printf("              ---+---+---+---+---");
    gotoxy(40, 14); printf("Linha 2 ->       |   |   |   |   ");
    gotoxy(40, 15); printf("              ---+---+---+---+---");
    gotoxy(40, 16); printf("Linha 3 ->       |   |   |   |   ");
    gotoxy(40, 17); printf("              ---+---+---+---+---");
    gotoxy(40, 18); printf("Linha 4 ->       |   |   |   |   ");
}

void verificaJogada(int pLinha, int pColuna) {
   int posIni = 0;
   
   for(l = 0;l < 5; l++){ 
     if(matControler[pLinha][pColuna] == 1){
        fimDeJogo();
     }
     else{
        matControler[pLinha][pColuna] = 'X';
     }               
     posIni = 55;                        
     for(c = 0;c < 5; c++){         
        if(matControler[l][c] != 1){
          gotoxy(posIni,l * 2 + 10); printf("%c",matControler[l][c]);
        }
        posIni += 4; 
    }
  }        
}

void prencherMatriz(int pBombas) {
   srand(time(NULL)); 
   totalPontos = 0;
   for(l = 0; l < 5; l++) {
      for(c = 0; c < 5; c++) {
         aux = rand()% 100;   
         if(aux > pBombas) {   
            matControler[l][c] = 1;   
         }else {
            matControler[l][c] = 0;          
         }   
      }   
   }
}

void limpaCampo() {
    apresentarCampo(); 
    verificaJogada(posLinha, posColuna);
}

void fimDeJogo() { 
    respSalvar = 'Z';  
    if(totalPontos < espacoLivre) {
       textbackground(15);textcolor(12);            
       Sleep(800);
       gotoxy(40,21); printf("BUUUUUUUUUUUUUUUUMMMM, GAME OVER "); 
       do{
          textbackground(1);
          textcolor(15);            
          gotoxy(40,23); printf("Deseja jogar novamente [S,N]: ");
          scanf("%s", &resp);
          resp = toupper(resp);
       }while(resp != 'S' && resp != 'N');
       if(resp == 'S') {
          pontosRecorde = totalPontos;
          totalPontos  = 0;  
          scoreUsuario = 0;
          prencherMatriz(porcentagemBombas);  
          menuInicial();     
       }else {
          do{
             gotoxy(40,23); printf("Deseja salvar sua pontuacao [S,N]: ");
             scanf("%s", &respSalvar);
             respSalvar = toupper(respSalvar);                  
           }while(respSalvar != 'S' && respSalvar != 'N');
           if(respSalvar == 'S') {
              arquivoPontuacao(1);           
           }else{
              gotoxy(40,24); printf("FINALIZANDO....: ");
              Sleep(1500);
              exit(1);   
           }       
       }
    }else{
       Sleep(800);  
       textbackground(15); textcolor(1);   
       gotoxy(40,21); printf("PAAARAAABEEENS VOCEE VEENCEEUU!!!");
       do{
          textbackground(1);
          textcolor(15);            
          gotoxy(40,23); printf("Deseja continuar [S,N]: ");
          scanf("%s", &resp);
          resp = toupper(resp);
       }while(resp != 'S' && resp != 'N');
       if(resp == 'S') {
          scoreUsuario += pontPorJogo;
          totalPontos = 0;
          prencherMatriz(porcentagemBombas);     
          selecioneNivel();     
       }else {
           do{
              gotoxy(40,23); printf("Deseja salvar sua pontuacao [S,N]: ");
              scanf("%s", &respSalvar);
              respSalvar = toupper(respSalvar);                  
           }while(respSalvar != 'S' && respSalvar != 'N');
           if(respSalvar == 'S') {
              arquivoPontuacao(1);           
           }else{
              gotoxy(40,24); printf("FINALIZANDO....: ");
              Sleep(1500);
              exit(1);   
           }            
       }               
    }
}

void arquivoPontuacao(int controle) {
     char nome[45], frase[300], m[5] = "";
     int i = 0;
     menuTopo();
     textcolor(3);
     gotoxy(34,12); printf("|-------------------------------------------------|\n");
     gotoxy(34,13); printf("|                                                 |\n");
     gotoxy(34,14); printf("|                                                 |\n");
     gotoxy(34,15); printf("|                                                 |\n");
     gotoxy(34,16); printf("|                                                 |\n");
     gotoxy(34,17); printf("|                                                 |\n");
     gotoxy(34,18); printf("|                                                 |\n");
     gotoxy(34,19); printf("|                                                 |\n");
     gotoxy(34,20); printf("|                                                 |\n");
     gotoxy(34,21); printf("|                                                 |\n");
     gotoxy(34,22); printf("|                                                 |\n");
     gotoxy(34,23); printf("|                                                 |\n");
     gotoxy(34,24); printf("|-------------------------------------------------|\n");
     textcolor(15);
     FILE *file;
     file = fopen("novoTeste.txt", "r");

     if(controle == 1) {     
        gotoxy(36,16); printf("Informe Seu Nome:\n");
        gotoxy(54,16); scanf("%s", &nome);
        file = fopen("novoTeste.txt", "a");     
        fprintf(file, "Nome: %8s     Pontuacao: %2d Pontos\n", nome, scoreUsuario);
        gotoxy(43,19); printf("Pontuacao Salva Com Sucesso!!!");
        textbackground(15);textcolor(3);
        gotoxy(45, 22); printf("PRESSIONE ENTER PARA FECHAR");
        getch();
        textbackground(1);textcolor(15);
        fclose(file); 
        Sleep(1000); 
        exit(1);
     }else {
        while(fgets(frase, 200, file) != NULL && i < 3) {   
            gotoxy(39,17+i);printf("%s\n", frase); 
            i++;
        } 
        textbackground(15);textcolor(3); 
        gotoxy(45, 22); printf("PRESSIONE ENTER PARA VOLTAR");
        getch();
        textbackground(1);textcolor(15);
        fclose(file);  
        menuInicial();
     }  
}

int main() { 
    textbackground(1); textcolor(15);
    menuInicial(); 
    while(totalPontos <= espacoLivre) {
       do{  
         gotoxy(40,20); printf("Informe da linha jogada: ");
         gotoxy(65,20); scanf("%d",&posLinha);
         gotoxy(40,21); printf("Informe da coluna jogada: ");
         gotoxy(66,21); scanf("%d",&posColuna);
         if(posLinha >= 5 || posColuna >= 5) {
             limpaCampo();        
         }
       }while((posLinha < 0 || posLinha > 4) || (posColuna < 0 || posColuna > 4));
       if(matControler[posLinha][posColuna] != 'X' && matControler[posLinha][posColuna] != 1) {
          scoreUsuario += pontPorRodada;
          totalPontos++;                              
       }
       apresentarCampo();
       verificaJogada(posLinha, posColuna);
       if(totalPontos > espacoLivre){
          fimDeJogo();
       }
    }  
    system("PAUSE"); 
    return 0; 
}
