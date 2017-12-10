//Paulina Castellanos Narváez  No.2
//Edson Alberto González Espinoza No.6
#include <iostream>
#include <string>
#include "types.h"
#include <conio.h>
#include <math.h>
#include <fstream>
#include <sstream>


using namespace std;
int tam;


Domicilio AD[10];
Persona *p;
/*
AD[0].calle
AD[1].numero
AD[2].interior
AD[3].ciudad
AD[4].codigo_postal
AD[5].colonia
AD[6].estado
*/

int stoi(string s){
    int slen = s.length();
    int r =0;
    for (int i = 0; i < slen; ++i)
    {
        r = r + ((s[i]-'0') * pow(10, i));
    }
    return r;
}




void sortApellido(Persona *p, int tam){
//    cout<<tam<<endl;
    for (int i = 0; i < tam - 1; ++i)
    {
            for (int j = 0; j < tam - i - 1; ++j)
            {
                if(p[j].apellido_p.compare(p[j+1].apellido_p) > 0){
                    Persona p3;
                    p3=p[j];
                    p[j] = p[j+1];
                    p[j+1] = p3;
                }
            }
    }
}

void sortNombre(Persona *p, int tam){
//    cout<<tam<<endl;
    for (int i = 0; i < tam; ++i)
    {
            for (int j = 0; j < tam - i - 1; ++j)
            {
//                cout<<p[j].nombre<<"*"<<p[j+1].nombre<<"*"<<p[j].nombre.compare(p[j+1].nombre)<<endl;
                if(p[j].nombre.compare(p[j+1].nombre) > 0){
                    Persona p3;
                    p3=p[j];
                    p[j] = p[j+1];
                    p[j+1] = p3;
                }
            }
    }
}

bool match(std::string word, std::string pattern) {
    for(int i = 0; i < word.length(); i++) {
        if (toupper(word[i]) == toupper(pattern[i]) && i + 1 == pattern.length())
            return true;
    }
    return false;
}

int tamAgenda(){
    int q=0;
    for(int i = 0; i < tam; i++) {
        if (p[i].isInitialized) {
            q++;
        }
    }
    return q;

}

bool space_in_agenda(int *q) {
    bool space = false;
    for(int i = 0; i < tam; i++) {
        if (!p[i].isInitialized) {
            (*q)++;
            space = true;
            break;
        }
    }
    return space;
}

void print_persona(Persona p, int i) {
    cout<<"Posicion: "<<(i+1)<<endl;
    cout<<p.nombre<<" "<<p.apellido_p<<" "<<p.apellido_m[0]<<endl;
}

void menu() {
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
    cout << "|-G-|: Guardar lista a disco " << endl;
    cout << "|-I-|: Anadir espacio en la agenda " << endl;
    cout << "|-K-|: Kargar list de contactos " << endl;
    cout << "|-O-|: Ordenar contactos " << endl;
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

void guardarContactos(Persona* p){
  ofstream AGENDA;
  AGENDA.open ("AGENDA.TDAT", ios::trunc);

  string s = "CEDI TXT DATA FORMAT v0.1";
  int slen = s.length();
  for (int i = 0; i < 32; ++i)
  {
    if(i<slen){
        AGENDA<<s[i];
    }
    else{
        AGENDA<<" ";
    }
  }
  AGENDA<<endl;

  for (int i = 0; i < tam; ++i)
  {
    AGENDA<<"PERSONA:\t"<<p[i].nombre<<"\t"<<p[i].apellido_p<<endl;
    AGENDA<<"DOMICILIO:\t"<<p[i].dom.calle<<"\t"<<p[i].dom.numero<<"\t"<<p[i].dom.colonia<<"\t"<<p[i].dom.codigo_postal<<"\t"<<p[i].dom.ciudad<<" "<<p[i].dom.estado<<endl;
    AGENDA<<"TELEFONO:\t"<<p[i].tel.line<<"\t"<<p[i].tel.clave_cd<<"\t"<<p[i].tel.local<<endl;
  }
  AGENDA.close();

}

void kargarContactos(Persona* p){

    ifstream agenda;
    agenda.open("AGENDA.TDAT");

    string s;
    string t;
    //lee titulo
    agenda>>s;
    int i=0;
    //lee persona
    while(getline(agenda, s)){

        s = s.substring(s.find("\t"), s.length() - s.find("\t"));
        p[i].nombre = s.substring(s.find("\t") + 1, s.length() - s.find("\t") -1 );
        s = s.substring(s.find("\t") + 1, s.length() - s.find("\t") -1 );
        p[i].apellido_p = s.substring(s.find("\t") + 1, s.length() - s.find("\t") -1 );
        s = s.substring(s.find("\t") + 1, s.length() - s.find("\t") -1 );
        p[i].apellido_m = s.substring(s.find("\t") + 1, s.length() - s.find("\t") -1 );
        //lee domicilio
        getline(agenda, s)
        s = s.substring(s.find("\t"), s.length() - s.find("\t"));
        p[i].dom.calle=s.substring(s.find("\t") + 1, s.length() - s.find("\t") -1 );
        s = s.substring(s.find("\t") + 1, s.length() - s.find("\t") -1 );
        p[i].dom.numero=s.substring(s.find("\t") + 1, s.length() - s.find("\t") -1 );
        s = s.substring(s.find("\t") + 1, s.length() - s.find("\t") -1 );
        p[i].dom.colonia=s.substring(s.find("\t") + 1, s.length() - s.find("\t") -1 );
        s = s.substring(s.find("\t") + 1, s.length() - s.find("\t") -1 );
        p[i].dom.codigo_postal=s.substring(s.find("\t") + 1, s.length() - s.find("\t") -1 );
        s = s.substring(s.find("\t") + 1, s.length() - s.find("\t") -1 );
        p[i].dom.ciudad=s.substring(s.find("\t") + 1, s.length() - s.find("\t") -1 );
        s = s.substring(s.find("\t") + 1, s.length() - s.find("\t") -1 );
        p[i].dom.estado=s.substring(s.find("\t") + 1, s.length() - s.find("\t") -1 );

        getline(agenda, s)
        p[i].tel.line=s.substring(s.find("\t") + 1, s.length() - s.find("\t") -1 );
        p[i].tel.clave_cd=s.substring(s.find("\t") + 1, s.length() - s.find("\t") -1 );
        p[i].tel.local=s.substring(s.find("\t") + 1, s.length() - s.find("\t") -1 );

        i++;
    }
    agenda.close();

}

int main ()
{
    int max_size=0;
    tam=10;
    int numero;
    char op;
    p = new Persona[25];
    bool toggle = true;

    menu();

   do{

        char yn;
        cout<< "$>";
        cin >> op;
        op = toupper(op);
        switch (op)
        {
                case 'A':{
                    int tam_agenda;
                    if (!space_in_agenda(&tam_agenda)) {
                        cout << "No hay espacio para agregar otra persona" << endl;
                        break;
                    }
                    // Hay espacio para agregar persona
                    Persona contacto;
                    cout << "-----Ingrese los datos requeridos para agregar un contacto: ------" << endl;
                    getline(cin,contacto.nombre);
                    cout << "Nombre(s): ";
                    getline(cin,contacto.nombre);
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
                        cin >> contacto.dom.calle;
                        cout << "Numero: " << endl;
                        cin >> contacto.dom.numero;
                        cout << "Interior: " << endl;
                        cin >> contacto.dom.interior;
                        cout << "Colonia: " << endl;
                        cin >> contacto.dom.colonia;
                        cout << "Codigo postal: " << endl;
                        cin >> contacto.dom.codigo_postal;
                        cout << "Ciudad: " << endl;
                        cin >> contacto.dom.ciudad;
                        cout << "Estado: " << endl;
                        cin >> contacto.dom.estado;
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
                            cout << "Clave de la ciudad: " <<endl;
                            cin >> contacto.tel.clave_cd;
                            cout << "Numero: " << endl;
                            cin >> contacto.tel.local;
                            cout << "Numero guardado"<<endl;
                        }
                        else
                            cout << "No valido";
                    }
                    contacto.isInitialized = true;
                    for(int i = 0; i < tam; i++)
                        if (!p[i].isInitialized) {
                            p[i] = contacto;
                            break;
                        }
                    break;}
                case 'B': {
                    cout<<"Que quieres buscar";
                    std::string busqueda;
                    cin>>busqueda;
                    for (int i = 0; i < tam; ++i)
                    {
                        if (p[i].isInitialized) {
                            if (match(p[i].nombre, busqueda) || match(p[i].apellido_p, busqueda) || match(p[i].apellido_m, busqueda))
                                print_persona(p[i], i);
                        }
                    }
                    break;
                }
                case 'C': {
                    int cambio;
                    cout<<"Que numero de contacto quieres cambiar?";
                    cin>>cambio;
                    cambio--;
                    print_persona(p[cambio], cambio);
                    string ndato;
                    getline(cin, ndato);
                    cout<<"Nuevo nombre:";
                    getline(cin, ndato);
                    if(ndato.compare("")!=0){
                        p[cambio].nombre = ndato;
                    }
                    //repetir para todos los datos
                    cout<<"Nuevo Apellido Paterno:";
                    getline(cin, ndato);
                    if(ndato.compare("")!=0){
                        p[cambio].apellido_p = ndato;
                    }
                    cout<<"Nuevo Apellido Materno:";
                    getline(cin, ndato);
                    if(ndato.compare("")!=0){
                        p[cambio].apellido_m = ndato;
                    }
                    cout<<"Nueva calle:";
                    getline(cin, ndato);
                    if(ndato.compare("")!=0){
                        p[cambio].dom.calle = ndato;
                    }
                    cout<<"Nuevo interior:";
                    getline(cin, ndato);
                    if(ndato.compare("")!=0){
                        p[cambio].dom.interior = ndato;
                    }
                    cout<<"Nuevo colonia:";
                    getline(cin, ndato);
                    if(ndato.compare("")!=0){
                        p[cambio].dom.colonia = ndato;
                    }
                    cout<<"Nuevo numero:";
                    getline(cin, ndato);
                    if(ndato.compare("")!=0){
                        p[cambio].dom.numero = stoi(ndato);
                    }
                    cout<<"Nueva ciudad:";
                    getline(cin, ndato);
                    if(ndato.compare("")!=0){
                        p[cambio].dom.ciudad = ndato;
                    }
                    break;
                }

                case 'D': {

                    int opc;
                    cout << "Escribe el número en la lista del contacto que quieres que te de informacion";
                    do{
                        cin >> opc;
                        opc=opc-1;
                        if(p[opc].isInitialized){
                            cout <<"Calle   : " << p[opc].dom.calle<<endl;
                            cout <<"Ciudad  : " << p[opc].dom.ciudad<<endl;
                            cout <<"Colonia : " << p[opc].dom.colonia<<endl;
                            cout <<"Estado  : " << p[opc].dom.estado<<endl;
                            cout <<"Interior: " << p[opc].dom.interior<<endl;
                            cout <<"Numero: " << p[opc].dom.numero<<endl;
                            cout <<"Tipo de linea  : " << p[opc].tel.line<<endl;
                            cout <<"Linea local: " << p[opc].tel.local<<endl;
                            cout <<"Clave de la ciudad: " << p[opc].tel.clave_cd<<endl;
                        }
                        else{
                            cout<<"Persona no inicializada. Intenta otra vez:"<<endl;
                        }
                    }while(!p[opc].isInitialized);
                break;
                }
                case 'E':
                    int pos;
                    cout<<"Dime la posicion del contacto a eliminar: "<<endl;
                    do{
                        cin>> pos;
                        if(!p[pos-1].isInitialized)
                            cout<<"Elemento vacio. intente otra vez:";
                        else if(pos<1||pos>tam)
                            cout<<"Elemento fuera de rango. Intente otra vez:";
                        Persona persona;
                        p[pos-1] = persona;
                    }while(pos>tam || pos<1);
                    break;
                case 'I':
                    cout << "Cual sera el nuevo tamano de la agenda: ";
                    int tamano;
                    cin>>tamano;
                    if (tamano < tam)
                        cout << "Ya esta asignado este tamano.";
                    else if (tamano < 26) {
                        cout << "La agenda crecio a " << tamano << "." << endl;
                        tam = tamano;
                    }
                    else
                        cout << "El tamano maximo es de 25";
                    break;

                case 'G':{
                    guardarContactos(p);
                    break;
                }

                case 'K':{
                    kargarContactos(p);
                    break;
                }
                case 'M':
                    for (int i = 0; i < tam; ++i)
                    {
                        if(p[i].isInitialized){
                            print_persona(p[i], i);
                        }
                    }
                    break;
                case 'N':
                    int tamano_agenda;
                    space_in_agenda(&tamano_agenda);
                    cout <<"Hay "<<tamano_agenda<<" contactos activos y la capacidad de contactos en tu agenda es de: " << tam;
                    break;
                case 'O':
                {
                    toggle = !toggle;
                    int ta = tamAgenda();
                    if(toggle)
                        sortApellido(p, ta);
                    else
                        sortNombre(p, ta);
                    cout<<"Ordenados por " <<((toggle) ? " Apellido paterno" : "Nombre")<<endl;
                    cout <<"Presiona 'M' para ver el orden";
                    break;
                }
                case 'S':
                    cout<<"Gracias por utilizar la agenda de contactos."<< endl;
                    break;

                case '?':
                    menu();
                    break;


                case 'V':
                    cout << "Version 1.0" << endl;
                    break;
                default:
                    cout << "Opcion no valida" << endl;
                    break;
        }
  }while (op != 'S');

return 0;
}
