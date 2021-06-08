#include <iostream>
#include <fstream>
#include "string.h"
#include <vector>

using namespace std;

void encriptacion();
void desencriptacion();

int main(){
    system("cls");
    string llave,opcion = "0";
    do{
        // menu
        cout <<endl<<"MENU"<< endl << "1 - encriptar" <<endl<< "2 - desencriptar" <<endl << "3 - salir" <<endl;
        cout << "Que desea realizar:";
        cin>>opcion;

        //llamado a la funcion
        if (opcion == "1"){
            encriptacion();
            system("pause");
        }
        else if (opcion == "2"){
            desencriptacion();
            system("pause");
        }
        else if (opcion == "3"){
        }
        else{
            system("cls");
            cout<<"Opcion Erronea verifique !!!"<<endl;
            system("pause");
        }

        system("cls");

    }while(opcion!="3");
    return 0;
}

void encriptacion(){
    int centena, decena, unidad, contenidonumero;
    string llave;
    vector <int> listallave;
    
    //obtener llave
    cout <<endl<< "Dame la llave de encriptacion:";
    cin>>llave;

    int size =(int) llave.size();

    //iniciando el enlace con los archivos
    ifstream archivo("textoOriginal.txt",ifstream::binary);
    ofstream archivosalida("textoEncriptado.txt",fstream::out);

    //metemos la llave a un vector
    for(int i=0;i<=size;i++){
        listallave.push_back((int)llave[i]);
    }

    //tamaño del archivo a leer
    archivo.seekg (0, archivo.end);
    int length = archivo.tellg();
    archivo.seekg (0, archivo.beg);

    cout<<"Reading "<<length<<" character..."<<endl;

    //variables para guardar el contenido del archivo a leer
    char * contenido = new char [length];
    char * contenidoencriptado = new char [length];

    //guardamos el texto en la variable
    archivo.read(contenido,length);

    //paso de parametros
    for (int i = 0; i<length;i++){
        contenidoencriptado[i] = contenido[i];
    }
    //encriptacion
    for(int i=0;i<size;i++){

        centena = listallave[i]/100;
        decena = (listallave[i]/10) - (centena*10);
        unidad = listallave[i] - (decena*10) - (centena*100);

        for(int j = 0; j<length;j = centena + j + 1){
            
                contenidonumero =  ((long) contenidoencriptado[j]+unidad - decena + centena );
           
            contenidoencriptado[j] = contenidonumero;
        }

    }
    //imprimir resultado
    cout<<"texto original ----------"<<endl<<endl;
    cout<<contenido<<endl<<endl;
    cout<<"texto encriptado ----------"<<endl<<endl;
    cout<<contenidoencriptado<<endl<<endl;

    //cerrar comunicacion
    archivo.close();

    //pasamos texto al archivo
    archivosalida << contenidoencriptado;
}

void desencriptacion(){
    int centena, decena, unidad, opcion,contenidonumero;
    string llave;
    vector <int> listallave;

    //obtener llave
    cout <<endl<< "Dame la llave de encriptacion:";
    cin>>llave;

    int size =(int) llave.size();

    //iniciando el enlace con los archivos
    ifstream archivor("textoEncriptado.txt",ifstream::binary);
    ofstream archivosalida2("textoDesencriptado.txt",fstream::out);

    //metemos la llave a un vector
    for(int i=0;i<=size;i++){
        listallave.push_back((int)llave[i]);
    }

    //tamaño del archivo a leer
    archivor.seekg (0, archivor.end);
    int lengthr = archivor.tellg();
    archivor.seekg (0, archivor.beg);

    cout<<"Reading "<<lengthr<<" character..."<<endl;

    //variables para guardar el contenido del archivo a leer
    char * contenidoencriptador = new char [lengthr];
    char * contenidodesencriptado = new char [lengthr];

    //guardamos el texto en la variable
    archivor.read(contenidoencriptador,lengthr);

    //paso de parametros
    for (int i = 0; i<lengthr;i++){
        contenidodesencriptado[i] = contenidoencriptador[i];
    }
    //desencriptado
    for(int i=0;i<size;i++){

        centena = listallave[i]/100;
        decena = (listallave[i]/10) - (centena*10);
        unidad = listallave[i] - (decena*10) - (centena*100);

        for(int j = 0; j<lengthr;j = centena + j + 1){
            
                contenidonumero =  ((long) contenidodesencriptado[j]-unidad + decena - centena );
           
            contenidodesencriptado[j] = contenidonumero;
            
        }

    }
    //imprimir el resultado
    cout<<"texto encriptado ----------"<<endl<<endl;
    cout<<contenidoencriptador<<endl<<endl;
    cout<<"texto desencriptado ----------"<<endl<<endl;
    cout<<contenidodesencriptado<<endl<<endl;

    //cerramos la lectura
    archivor.close();

    //pasamos texto al archivo
    archivosalida2 << contenidodesencriptado;

}