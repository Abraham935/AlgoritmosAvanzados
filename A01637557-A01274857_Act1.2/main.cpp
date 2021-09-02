#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Algoritmo greedy
void greedyCoinPicker(int coins[], int producto, int billete, int size){
    //Funcion recibe arreglo de denominacion de monedas, precio del producto, billete ingresado y tamaño del arreglo de monedas.
    //La misma función imprime a la salida estandar el total de monedas usadas y sus denominaciones. 
    //Validamos entradas
    if(producto>=0 && billete>=0){  
        cout<<"//Resolucion con algoritmo Greedy//"<<endl;
        int cambio = billete-producto;
        sort(coins, coins+size);
        vector<int> nCoins;
        for (int i = size-1; i >= 0; i--)
        {
            while (cambio >= coins[i])
            {
                cambio = cambio - coins[i];
                nCoins.push_back(coins[i]);
            }
        } //Complejidad del algoritmo es O(C) donde C es el tamaño del array que contiene las denominaciones de monedas que se usaran.

        cout << "El numero de monedas que recibiras de cambio es de " << nCoins.size() << " y son las siguientes:" <<endl;

        for (int i = 0; i < nCoins.size(); i++)
        {
            cout << nCoins[i] <<endl;
        }
        if(cambio!=0){
            cout << "La maquina no cuenta con la denominacion de monedas necesaria para dar todo el cambio. Se le debe: "<<cambio;
        }
    }else{
        cout <<"Valor ingresado de producto o billete invalido."<<endl;
    }
}


//Algoritmo con programacion dinamica
int dynamicCoinPicker(int cambio, int coins[], int size, int C[], int dI[]){
    C[0] = 0;
    for(int j = 1; j <= cambio; j++) { //j cantidad de monedas
	C[j] = INT_MAX;
	for(int i = 0; i < size; i++) { //i denominacion de monedas
	    if(j >= coins[i] && 1 + C[j-coins[i]] < C[j] ) {
		C[j] = 1 + C[j-coins[i]];

		dI[j] = i;  // Denominacion de moneda i por la respectiva cantidad de j
	    }
	}
    }
    return C[cambio];
}

void printDynamic(int cambio,int coins[],int minCoinsDin,int s[]){
    cout<<"//Resolucion con algoritmo Dinamico//"<<endl;
   cout << "El numero de monedas que recibiras de cambio es de " << minCoinsDin << " y son las siguientes:" <<endl;
	
    int k = cambio;
    while(k) {
	cout << coins[s[k]] << endl;
	k = k - coins[s[k]];
    }

}

int main() {
    int size=0;
    int producto;
    int billete;
    
    cout<<"Ingresa la cantidad de monedas que se usaran: "<<endl;
    cin>>size;
    cout<<"Ingresa la denominacion de las monedas que se usaran: "<<endl;
    int coins[size];

    for(int i=0;i<size;i++){
        int denom;
        cin>>denom;
        coins[i]=denom;
    }

    cout<<"Ingresa el precio del producto a pagar: "<<endl;
    cin>>producto;
    cout<<"Ingresa el valor del billete con el que vas a pagar: "<<endl;
    cin>>billete;
    int cambio = billete-producto;

    int *C = new int[cambio+1];
    int *denomIndex = new int[cambio+1];

    //LLamado a funciones
   int minCoinsDin=dynamicCoinPicker(cambio, coins, size, C, denomIndex);
   printDynamic(cambio,coins,minCoinsDin,denomIndex);
    delete[] C;
    delete[] denomIndex;
    greedyCoinPicker(coins,producto,billete,size);
    return 0;
}

