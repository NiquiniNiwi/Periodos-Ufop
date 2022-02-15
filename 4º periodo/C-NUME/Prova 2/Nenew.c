#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char *palavra;
    int contador[26];
    int maiorValor;
    int posicaoMaiorValor;
    fgets(palavra);

    for(int i = 0; i <= strlen(palavra); i++){
        if(palavra[i] == 'a' || palavra[i] = 'A'){
            contador[0] = contador[0] + 1;
        }
        else if(palavra[i] == 'b' || palavra[i] = 'B'){
            contador[1] = contador[1] + 1;
        }
        else if(palavra[i] == 'c' || palavra[i] = 'C'){
            contador[2] = contador[2] + 1;
        }
        else if(palavra[i] == 'd' || palavra[i] = 'D'){
            contador[3] = contador[3] + 1;
        }
        else if(palavra[i] == 'e' || palavra[i] = 'E'){
            contador[4] = contador[4] + 1;
        }
        else if(palavra[i] == 'f' || palavra[i] = 'F'){
            contador[5] = contador[5] + 1;
        }
        else if(palavra[i] == 'g' || palavra[i] = 'G'){
            contador[6] = contador[6] + 1;
        }
        else if(palavra[i] == 'h' || palavra[i] = 'H'){
            contador[7] = contador[7] + 1;
        }
        else if(palavra[i] == 'i' || palavra[i] = 'I'){
            contador[8] = contador[8] + 1;
        }
        else if(palavra[i] == 'j' || palavra[i] = 'J'){
            contador[9] = contador[9] + 1;
        }
        else if(palavra[i] == 'k' || palavra[i] = 'K'){
            contador[10] = contador[10] + 1;
        }
        else if(palavra[i] == 'l' || palavra[i] = 'L'){
            contador[11] = contador[11] + 1;
        }
        else if(palavra[i] == 'm' || palavra[i] = 'M'){
            contador[12] = contador[12] + 1;
        }
        else if(palavra[i] == 'n' || palavra[i] = 'N'){
            contador[13] = contador[13] + 1;
        }
        else if(palavra[i] == 'o' || palavra[i] = 'O'){
            contador[14] = contador[14] + 1;
        }
        else if(palavra[i] == 'p' || palavra[i] = 'P'){
            contador[15] = contador[15] + 1;
        }
        else if(palavra[i] == 'q' || palavra[i] = 'Q'){
            contador[16] = contador[16] + 1;
        }
        else if(palavra[i] == 'r' || palavra[i] = 'R'){
            contador[17] = contador[17] + 1;
        }
        else if(palavra[i] == 's' || palavra[i] = 'S'){
            contador[18] = contador[18] + 1;
        }
        else if(palavra[i] == 't' || palavra[i] = 'T'){
            contador[19] = contador[19] + 1;    
        }
        else if(palavra[i] == 'u' || palavra[i] = 'U'){
            contador[20] = contador[20] + 1;
        }
        else if(palavra[i] == 'v' || palavra[i] = 'V'){
            contador[21] = contador[21] + 1;
        }
        else if(palavra[i] == 'w' || palavra[i] = 'W'){
            contador[22] = contador[22] + 1;
        }
        else if(palavra[i] == 'x' || palavra[i] = 'X'){
            contador[23] = contador[23] + 1;
        }
        else if(palavra[i] == 'y' || palavra[i] = 'Y'){
            contador[24] = contador[24] + 1;
        }
        else if(palavra[i] == 'z' || palavra[i] = 'Z'){
            contador[25] = contador[25] + 1;
        }
    }

    maiorValor = contador[0];
    posicaoMaiorValor = 0;

    for(int i = 1; i < 26; i++){
        if(maiorValor <= contador[i]){
            maiorValor = contador[i];
            posicaoMaiorValor = i;
        }
    }

    printf("Frequencia mais alta do carctere: '%c' ", posicaoMaiorValor+65);
    printf("Aparece numero de vezes: %d", maiorValor);

    return 0;
}