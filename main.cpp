# include <iostream>
# include <string>
# include "analizadorSemantico.hpp"

using namespace std;


enum MENU{
    MENU_DO = 1,
    MENU_EX
};


int main(){
    string myStr;
    do{
        cout << "[Analizador lexico]" << endl
             << "1.- Introducir una cadena a analizar" << endl
             << "2.- finalizar el programa" << endl
             << "Ingrese una opccion: ";
        getline(cin, myStr);
        switch(atoi(myStr.c_str())){
            case MENU_DO:
            //funcion de evaluacion;
            {
                string data;
                getline(cin, data);
                if (semantico(data)){
                    cout << "Cadena semanticamente correcta" << endl;
                }
                else {
                    cout << "Cadena semanticamente incorrecta" << endl;
                }
                

            }
            break;
            case MENU_EX:
            break;
            default:
                cout << "Ingreso una opccion invalida, vuelva a intentarlo" << endl;
        }
    }while(atoi(myStr.c_str()) != MENU_EX);
    return 0;
}