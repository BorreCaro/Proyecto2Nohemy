#include "MyString.h"
#include<bits/stdc++.h>
using namespace std;
 struct Publicacion {
    long long id;
    char titulo[100];
    int tipo;
    int year;
    char premio[50];
    char abstract[1000];
    int puntosBase;
    int puntosAdic;
};
 struct Autor {
    long long id;
    char nombre[50];
    char correo[50];
    char programa[50];
    Publicacion pubs[100]; 
    int cntPubs=0;
};
long long cntAutor=0; //aurtores[cntAutor++]=newAuthor;
Autor autores[100];
Publicacion publicaciones[100];

bool existePublicacion(long long idnum){
    for (int i = 0; i < cntAutor; i++)
        for (int j = 0; j < autores[i].cntPubs; j++)
            if (autores[i].pubs[j].id == idnum) return true;
    return false;
}
bool existeAutor(long long idnum){
    for (int i = 0; i < cntAutor; i++)
        if (autores[i].id == idnum) return true;
    return false;
}
Autor searchAutor(long long idnum){
    for(int i =0; i<cntAutor; i++){
        if(autores[i].id == idnum) 
            return autores[i];
    }
    Autor empty={};
    return empty;
}

Autor searchAutorByPub(long long idnum) {
    for (int i = 0; i < cntAutor; i++)
        for (int j = 0; j < autores[i].cntPubs; j++)
            if (autores[i].pubs[j].id == idnum)
                return autores[i];
    Autor empty = {};
    return empty;
}

Publicacion searchPub(long long idnum){
    for (int i = 0; i < cntAutor; i++)
        for (int j = 0; j < autores[i].cntPubs; j++)
            if (autores[i].pubs[j].id == idnum)
                return autores[i].pubs[j];
    Publicacion empty = {};
    return empty;
}

int puntosPorTipo(int t){
    switch(t){
        case 1: return 50;
        case 2: return 35;
        case 3: return 30;
        case 4: return 20;
        default: return 10;
    }
}
int puntosPorPremio(const char* p){
    return strcmp(p, "Ninguno")==0 ? 0 : 10;
}

void mostrarDatosAutor(const Autor &author) {
    cout << "\nID: " << author.id << endl;
    cout << "Nombre: " << author.nombre << endl;
    cout << "Correo: " << author.correo << endl;
    cout << "Programa: " << author.programa << endl;
    for (int i = 0; i < author.cntPubs; i++) {
        cout << "\nPublicacion #" << i + 1 << endl;
        cout << "  ID: " << author.pubs[i].id << endl;
        cout << "  Titulo: " << author.pubs[i].titulo << endl;
        cout << "  Tipo: " << author.pubs[i].tipo << endl;
        cout << "  Año: " << author.pubs[i].year << endl;
        cout << "  Premio: " << author.pubs[i].premio << endl;
        cout << "  Abstract: " << author.pubs[i].abstract << endl;
        cout << "  Puntos base: " << author.pubs[i].puntosBase << endl;
        cout << "  Puntos extra: " << author.pubs[i].puntosAdic << endl;
    }
}
void mostrarDatosPub(const Publicacion &pp) {
    Autor user = searchAutorByPub(pp.id);
    cout << "\nTitulo: " << pp.titulo << endl;
    cout << "Tipo: " << pp.tipo << endl;
    cout << "Year: " << pp.year << endl;
    cout << "Premio: " << pp.premio << endl;
    cout << "Abstract: " << pp.abstract << endl;
    cout << "Puntos base: " << pp.puntosBase << endl;
    cout << "Puntos extra: " << pp.puntosAdic << endl;
    cout << "Total puntaje: " << (pp.puntosBase + pp.puntosAdic) << endl;
    cout << "\nAutor de la publicacion:\n";
    cout << "ID autor: " << user.id << endl;
    cout << "Nombre: " << user.nombre << endl;
    cout << "Correo: " << user.correo << endl;
    cout << "Programa: " << user.programa << endl;
}
void modifyPub(Publicacion &pp) {
    cin.ignore();
    cout << "Titulo (" << pp.titulo << "): "; cin.getline(pp.titulo, 80);
    cout << "Tipo (" << pp.tipo << "): "; cin >> pp.tipo;
    cout << "Año (" << pp.year << "): "; cin >> pp.year;
    cin.ignore();
    cout << "Premio (" << pp.premio << "): "; cin.getline(pp.premio, 80);
    pp.puntosBase = puntosPorTipo(pp.tipo);
    pp.puntosAdic = puntosPorPremio(pp.premio);
    cout << "New PuntosBase: " << pp.puntosBase << endl;
    cout << "New PuntosAdic: " << pp.puntosAdic << endl;
    cout << "Total: " << (pp.puntosBase + pp.puntosAdic) << endl;
    cout << "Recalculado.\n";
}

void modifyAuthor(Autor &author) {
    cin.ignore();
    cout << "Nombre (" << author.nombre << "): "; cin.getline(author.nombre, 60);
    cout << "Correo (" << author.correo << "): "; cin.getline(author.correo, 60);
    cout << "Programa (" << author.programa << "): "; cin.getline(author.programa, 60);
    cout << "Actualizado.\n";
}
void actualizar(){
    int type;
    cout<<"1. Autor.\n2.Publicacion.\n3.Salir.\n";
    bool re=true;
    do{
        cin>>type;
        if(type==1){
            re = false;
            long long idnum; 
            cout<<"ID autor: ";
            do{
                cin>>idnum;
                if(existeAutor(idnum)){
                    Autor user=searchAutor(idnum);
                    mostrarDatosAutor(user);
                    char option;
                    cout<<"Deseas modificar algo? (S/N)"<<endl; 
                    bool modify=false;
                    do{
                        cin>>option;
                        if(tolower(option)=='n'){
                            cout<<"Oka"<<endl;
                            return;
                        } else if(tolower(option)=='s'){
                            cout<<"Que deseas modificar?"<<endl;
                            modifyAuthor(user);
                            modify=true;
                            break;
                        } else {
                            cout<<"try again."<<endl;
                            break;
                        }
                    } while(modify);
                }
            } while(!existeAutor(idnum));
        }
        else if(type==2){
            long long idnum; 
            re = false;
            do{
                cin>>idnum;
                if(existePublicacion(idnum)){
                    Publicacion pub=searchPub(idnum);
                    mostrarDatosPub(pub);
                    char option;
                    cout<<"Deseas modificar algo? (S/N)"<<endl; 
                    bool modify=false;
                    do{
                        cin>>option;
                        if(tolower(option)=='n'){
                            cout<<"Oka"<<endl;
                            return;
                        } else if(tolower(option)=='s'){
                            cout<<"Que deseas modificar?"<<endl;
                            modifyPub(pub);
                            modify=true;
                            break;
                        } else {
                            cout<<"try again."<<endl;
                            break;
                        }
                    } while(modify);
                }
            } while(!existePublicacion(idnum));
        } 
        else{
            cout<<"try again."<<endl;
        }
    } while(re);
}

int main(){
    Autor a1 = {1, "Carlos", "c@uni.edu", "Ingenieria"};
    Publicacion p1 = {101, "IA y Etica", 1, 2023, "Ninguno", "Sobre IA y moral", 50, 0};
    a1.pubs[a1.cntPubs++] = p1;
    autores[cntAutor++] = a1;

    int op;
    do {
        cout << "\n1. Agregar autor\n2. Agregar publicacion\n3. Actualizar\n4. Mostrar\n6. Salir\n> ";
        cin >> op;
        if (op == 3) actualizar();
        else if (op == 4) {
            long long id;
            cout << "ID de autor: ";
            cin >> id;
            if (existeAutor(id)) mostrarDatosAutor(searchAutor(id));
            else cout << "No existe.\n";
        }
    } while (op != 6);

}
