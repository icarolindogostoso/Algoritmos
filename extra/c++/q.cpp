#include <iostream>

int main(){
    int quantidade = 10;
    int array[quantidade] = {1,1,2,3,3,4,5,5,6,7};

    for (int i = 0; i < quantidade; i++){
        int valor1 = array[i];
        int index = 1;
        for (int j = i+1; j < quantidade; j++){
            int valor2 = array[j];
            if (valor1 == valor2){
                quantidade--;
            } else{
                array[index] = valor2;
                index++;
            }
        }
    }
    for (int i = 0; i < quantidade; i++){
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
    return 0;
}