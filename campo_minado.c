#include <stdio.h>
#include <string.h>

int main (){
    int qtd_jogos, qtd_matriz, qtd_jogadas;
    //printf("Numero de Jogos: ");
    scanf("%d", &qtd_jogos); // quantidade de jogos linha 1

    for (int i = 0 ; i < qtd_jogos; i++){
    //printf("Matriz: ");
    scanf("%d", &qtd_matriz); // quantidade de linha da matriz
    
    int linha = qtd_matriz, coluna = qtd_matriz;
    char matriz[linha][coluna];
    char aux[linha][coluna];

    // Lê os elementos da matriz
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            scanf(" %c", &matriz[i][j]);

            aux[i][j] = '\0';
            if(matriz[i][j] == 'b') aux[i][j] = 'b';
            
        }
    }

    //quantidade de jogadas
    //printf("Quantidade Jogada: ");
    scanf("%d", &qtd_jogadas);

    for(int i = 0; i < qtd_jogadas; i++){
        int x = 0, y = 0;

        //printf("Jogada %d: ", i + 1);
        scanf("%d %d", &x, &y);

        // se o lugar tem bomba
        if(matriz[x][y] == 'b'){
            marcador = 1;
            printf("PERDEU \n");
            break;
        }else{

                // colocando os x no aux em todos os adjacentes
            aux[x][y] = 'x'; // o propio x
            
            if(aux[x + 1][y] != 'b' && (x + 1) < linha && aux[x + 1][y] != 'x') aux[x + 1][y] = 'x'; // baixo
            if(aux[x - 1][y] != 'b' && (x - 1) >= 0 && aux[x - 1][y] != 'x') aux[x - 1 ][y] = 'x'; // cima
            if(aux[x][y + 1] != 'b' && (y + 1) < coluna && aux[x][y + 1] != 'x') aux[x][y + 1] = 'x'; // direita
            if(aux[x][y - 1] != 'b' && (y - 1)  >= 0 && aux[x][y - 1] != 'x') aux[x][y -1] = 'x'; // esquerda

            if(aux[x - 1][y - 1] != 'b' && (x - 1) >= 0 && (y - 1) >= 0 && aux[x - 1][y - 1] != 'x')aux[x - 1][y - 1] = 'x'; //  diagonal superior esquerda
            if(aux[x - 1][ y + 1 ] != 'b' && (x - 1) >= 0 && (y + 1) < coluna && aux[x - 1][ y + 1 ] != 'x' )aux[x - 1][ y + 1 ] = 'x'; // diagonal superior direita

            if(aux[x + 1][y - 1] != 'b' && (y - 1)  >= 0 && (x + 1) < linha && aux[x + 1][y - 1] != 'x' )aux[x + 1][y - 1] = 'x'; //  diagonal inferior esquerda
            if(aux[x + 1][ y + 1 ] != 'b' && (x + 1) < linha && y + 1 < coluna && aux[x + 1][ y + 1] != 'x' )aux[x + 1][ y + 1 ] = 'x'; // diagonal inferior direita

        

            //verificação
            if(aux[x - 1][y] == 'b'){ // adjacente cima
            if(aux[x - 1][y - 1] != 'b' && aux[x - 1][y - 1] != 'x' )aux[x - 1][y - 1] = '\0'; // diagonal superior esquerda
            if(aux[x - 1][ y + 1 ] != 'b' && aux[x - 1][ y + 1 ] != 'x' )aux[x - 1][ y + 1 ] = '\0'; // diagonal superior direita
            }

            if(aux[x + 1][y] == 'b'){  // adjacente baixo
                if(aux[x + 1][y - 1] != 'b' && aux[x + 1][y - 1] != 'x' )aux[x + 1][y - 1] = '\0'; // diagonal inferior esquerda
                if(aux[x + 1][ y + 1 ] != 'b' && aux[x + 1][ y + 1 ] != 'x' )aux[x + 1][ y + 1 ] = '\0'; //diagonal inferior direita
                
            }
                
            if(aux[x][y + 1] == 'b')  { // adjacente direita
                if(aux[x - 1][ y + 1 ] != 'b' && aux[x - 1][ y + 1 ] != 'x')aux[x - 1][ y + 1 ] = '\0';
                if(aux[x + 1][ y + 1 ] != 'b' && aux[x + 1][ y + 1 ] != 'x')aux[x + 1][ y + 1 ] = '\0';
            }  

            if(aux[x][y - 1] == 'b')  { //  adjacente esquerda
                if(aux[x - 1][ y - 1 ] != 'b' && aux[x - 1][ y - 1 ] != 'x' )aux[x - 1][ y - 1 ] = '\0';
                if(aux[x + 1][ y - 1 ] != 'b' && aux[x + 1][ y - 1 ] != 'x' )aux[x + 1][ y - 1 ] = '\0';
            }
        }
    }

    int marcador = 1;

    for(int i = 0; i < qtd_matriz; i++){
        for (int j = 0; j < qtd_matriz; j++){
            if(aux[i][j] == '\0') marcador = 0;
        }
        
    }
    
    if(!marcador) printf("GANHOU \n");
    if(marcador) printf("FALTOU TERMINAR \n");
    
    //Imprime os elementos da matriz
    /*printf("A matriz é:\n");
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            printf("%c ", aux[i][j]);
        }
        printf("\n");
    }*/
    
        

    }
    return 0;
    }


  
