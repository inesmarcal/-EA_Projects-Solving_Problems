#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

//Criar um grupo sempre que houvesse um homem e uma mulher e a soma dos cartões das mulheres tem de ser igual ao número do cartão do homem
//Grupos de 3

int main()
{

    int n;
    int num, sum;
    std::vector<int> array;
    int zero;
    int j, k;
    int flag = 0;
    //Le-se o n, número de números que vou ler
    while (std::cin >> n){

        for (int i = 0; i < n; i++){
            
            std::cin >> num;
            array.push_back(num);
        }
        //Separação casos testes
        std::cin >> zero;
        //Ordenar os cartões dos convidados
        std::sort(array.begin(), array.begin() + n);

        //Pesquisa binária para os cartões
        //Somar os números dos 3 ponteiros, se desse zero era o grupo pretendido
        for(int m = 0; m < n - 2; m++){
            
            j = m + 1;
            k = n - 1;

            while( j < k){

                sum = array[m] + array[j] + array[k];

                if (sum == 0){

                    std::cout << "Fair\n";
                    flag = 1;
                    break;

                //Número maior que zero diminuiu o ponteiro mais à frente
                }else if( sum > 0){

                    k = k - 1;
                //Número menor que zero aumenta o ponteiro mais atrás
                }else{

                    j = j + 1;
                }
            }
            //Para sair do for ao se ter encontrado uma solução
            if(flag == 1){
                break;
            }
 
        }
        array = {};

        if(flag == 0){
            std::cout << "Rigged\n";
        
        }else{
            flag = 0; 
        }

    }
}