#include <iostream>
using namespace std;

int main () {
    int val; 
    int M; 
    int N;

    cout<<"Insert the number of rows: ";
    cin>> M;
    cout<<"Insert the number of columns: ";
    cin>> N;

    int arr[M][N];

    for(int i = 0; i < M; i++){
        int j=0;
        while(j<N){
            cin >> val;
            arr[i][j] = val;
            j+=1;
            if(cin.peek()=='\n')
            break;
        }
    }

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cout<< arr[i][j];
        }
        cout<<endl;
    }

}

