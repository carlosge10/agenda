//Paulina Castellanos Narváez  No.2
//Edson Alberto González Espinoza No.6
#include <iostream>
#include <string>
#include "types.h"

using namespace std;
Domicilio contactod;
Telefono contactot;
int tam;


Domicilio AD[10];
Personas *p;
/*
AD[0].calle
AD[1].numero
AD[2].interior
AD[3].ciudad
AD[4].codigo_postal
AD[5].colonia
AD[6].estado
*/

bool space_in_agenda() {
    bool space = false;
    for(int i = 0; i < tam; i++) {
        if (!p[i].isInitialized) {
            space = true;
            break;
        }
    }
    return space;
}

void menu(){
    cout << "~~~~~~~~~~~AGENDA DE CONTACTOS~~~~~~~~~~~" << endl;
    cout << "Autores: Paulina Castellanos, Edson González" << endl;
    cout << endl;
    cout << "Instrucciones: " << endl;
    cout << "Presione la tecla correspondiente al comando deseado. " << endl;
    cout << endl;
    cout << "|-A-|: Agregar un contacto " << endl;
    cout << "|-B-|: Buscar un contacto " << endl;
    cout << "|-C-|: Editar contacto " << endl;
    cout << "|-D-|: Informacion de contacto " << endl;
    cout << "|-E-|: Eliminar un contacto " << endl;
    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << endl;
    cout << "|-M-|: Mostrar  lista de contactos " << endl;
    cout << "|-N-|: Mostrar cantidad de contactos " << endl;
    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << endl;
    cout << "|-S-|: Finalizar programa " << endl;
    cout << "|-V-|: Mostrar version del programa " << endl;
    cout << "|-?-|: Ayuda " << endl << endl;
}

int main ()
{
    int ini=0;
    tam=25;
    int numero;
    char op;
    p = new Personas[tam];

    menu();

   do{

        char yn;
        cout<< "$>";
        cin >> op;
        op = toupper(op);
        switch (op)
        {
                case 'A':
                    Persona contacto;
                    cout << "-----Ingrese los datos requeridos para agregar un contacto: ------" << endl;
                    cout << "Nombre(s): ";
                    cin >> contacto.nombre;
                    cout << "Apellido Paterno: ";
                    cin >> contacto.apellido_p;
                    cout << "Apellido Materno: ";
                    cin >> contacto.apellido_m;
                    cout << "Desea agregar el domicilio de " << contacto.nombre << " ahora?(Y/N)" << endl;
                    cin >> yn;
                    yn = toupper(yn);
                    if (yn == 'Y')
                    {
                        cout << "Calle: ";
                        cin >> contactod.calle;
                        cout << "Numero: " << endl;
                        cin >> contactod.numero;
                        cout << "Interior: " << endl;
                        cin >> contactod.interior;
                        cout << "Colonia: " << endl;
                        cin >> contactod.colonia;
                        cout << "Codigo postal: " << endl;
                        cin >> contactod.codigo_postal;
                        cout << "Ciudad: " << endl;
                        cin >> contactod.ciudad;
                        cout << "Estado: " << endl;
                        cin >> contactod.estado;
                    }
                    cout << "Desea capturar el telefono de " << contacto.nombre << " ahora?(Y/N)" << endl;
                    cin >> yn;
                    yn = toupper(yn);
                    if (yn=='Y')
                    {

                        char linea;
                        cout << "Tipo de telefono: (C= Celular| H= Casa| W= Trabajo) " << endl;
                        cin >> linea;
                        linea= toupper(linea);
                        if (linea == 'C' || linea == 'H' || linea == 'W'){
                            cout << "Linea local: " << endl;
                            cin >> contactot.local;
                            cout << "Clave de la ciudad: " <<endl;
                            cin >> contactot.clave_cd;
                            cout << "Dame el numero "<<endl;
                            cin >> numero;
                            cout << "Numero guardado"<<endl;

                        }
                        else
                            cout << "No valido";

                    }
                    if(ini == tam)
                        cout<<"No se puede inserar, ya esta llena la lista"<<endl ;
                    else
                        for(int i = 0; i < ini; i++)
                            if (!p[i].isInitialized)
                                p[i] = contacto;
                    break;
                case 'B':

                    break;

                case 'C':
                    break;

                case 'D':
                /*
                    int opc;

                    cout << "Escribe el número en la lista del contacto que quieres que te de informacion";
                    cin >> opc;
                    opc=opc-1;
                    contacto[opc].isInitialized;
                    cout <<"Calle: " << contactod[opc].calle<<endl;
                    cout <<"Ciudad: " << contactod[opc].ciudad<<endl;
                    cout <<"Colonia: " << contactod[opc].colonia<<endl;
                    cout <<"Estado: " << contactod[opc].estado<<endl;
                    cout <<"Interior: " << contactod[opc].interior<<endl;
                    cout <<"Numero: " << contactod[opc].numero<<endl;
                    contactot[opc].isInitialized;
                    cout<<"Su numero es"<< contactot[opc].line<< contactot[opc].clave_cd<< numero <<endl*/
                break;

                case 'E':
                    int pos;
                    cout<<"Dime la posicion del contacto a eliminar: "<<endl;
                    do{

                        cin>> pos;
                        if(pos>ini)
                            cout<<"Elemento vacio. intente otra vez:";
                        

                    }while(pos>tam || pos<1);

                    break;

                case 'M':
                    break;

                case 'N':
                    cout <<"Hay "<<ini<<" contactos activos y la capacidad de contactos en tu agenda es de: " << tam;
                    break;

                case 'S':
                    cout<<"Gracias por utilizar la agenda de contactos."<< endl;
                    break;

                case '?':
                     cout << "~~~~~~~~~~~AGENDA DE CONTACTOS~~~~~~~~~~~" << endl;
        cout << "Autores: Paulina Castellanos, Edson González" << endl;
        cout << endl;
        cout << "Instrucciones: " << endl;
        cout << "Presione la tecla correspondiente al comando deseado. " << endl;
        cout << endl;
        cout << "|-A-|: Agregar un contacto " << endl;
        cout << "|-B-|: Buscar un contacto " << endl;
        cout << "|-C-|: Editar contacto " << endl;
        cout << "|-D-|: Informacion de contacto " << endl;
        cout << "|-E-|: Eliminar un contacto " << endl;
        cout << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << endl;
        cout << "|-M-|: Mostrar  lista de contactos " << endl;
        cout << "|-N-|: Mostrar cantidad de contactos " << endl;
        cout << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << endl;
        cout << "|-S-|: Finalizar programa " << endl;
        cout << "|-V-|: Mostrar version del programa " << endl;
        cout << "|-?-|: Ayuda " << endl << endl;
                    break;


                case 'V':
                    break;

                default:
                    cout << "Opcion no valida" << endl;
                    break;
        }
  }while (op != 'S');

return 0;
}