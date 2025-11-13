#include <iostream>
#include <climits>
#include <iomanip>
#include "MyString.h"
#include "structs.h"
using namespace std;
long long cntAutor = 0;  // aurtores[cntAutor++]=newAuthor;
Autor autores[100];
Publicacion publicaciones[100];

/*
Tipos de premiacion
 Publicación en revista internacional indexada.
 Publicación en revista nacional.
 Ponencia en congreso internacional.
 Ponencia en congreso nacional.
 Artículo en boletín o revista estudiantil.
*/

bool existePublicacion(long long idnum) {
    for (int i = 0; i < cntAutor; i++)
        for (int j = 0; j < autores[i].cntPubs; j++)
            if (autores[i].pubs[j].id == idnum) return true;
    return false;
}
bool existeAutor(long long idnum) {
    for (int i = 0; i < cntAutor; i++)
        if (autores[i].id == idnum) return true;
    return false;
}
Autor* searchAutor(long long idnum) {
    for (int i = 0; i < cntAutor; i++) {
        if (autores[i].id == idnum)
            return &autores[i];
    }
    return nullptr;
}

Autor* searchAutorByPub(long long idnum) {
    for (int i = 0; i < cntAutor; i++)
        for (int j = 0; j < autores[i].cntPubs; j++)
            if (autores[i].pubs[j].id == idnum)
                return &autores[i];
    return nullptr;
}

Publicacion* searchPub(long long idnum) {
    for (int i = 0; i < cntAutor; i++)
        for (int j = 0; j < autores[i].cntPubs; j++)
            if (autores[i].pubs[j].id == idnum)
                return &autores[i].pubs[j];
    return nullptr;
}

int puntosPorTipo(int t) {
    switch (t) {
        case 1:
            return 50;
        case 2:
            return 35;
        case 3:
            return 30;
        case 4:
            return 20;
        default:
            return 10;
    }
}
int puntosPorPremio(const char* p) {
    return strcmp(p, "Ninguno") == 0 ? 0 : 10;
}

void mostrarDatosAutor(const Autor* author) {
    cout << "\nID: " << author->id << endl;
    cout << "Nombre: " << author->nombre << endl;
    cout << "Correo: " << author->correo << endl;
    cout << "Programa: " << author->programa << endl;
    for (int i = 0; i < author->cntPubs; i++) {
        cout << "\nPublicacion #" << i + 1 << endl;
        cout << "  ID: " << author->pubs[i].id << endl;
        cout << "  Titulo: " << author->pubs[i].titulo << endl;
        cout << "  Tipo: " << author->pubs[i].tipo << endl;
        cout << "  Año: " << author->pubs[i].year << endl;
        cout << "  Premio: " << author->pubs[i].premio << endl;
        cout << "  Abstract: " << author->pubs[i].abstract << endl;
        cout << "  Puntos base: " << author->pubs[i].puntosBase << endl;
        cout << "  Puntos extra: " << author->pubs[i].puntosAdic << endl;
        cout << "  Total: " << (author->pubs[i].puntosBase + author->pubs[i].puntosAdic) << endl;
    }
}

void mostrarDatosPub(const Publicacion& pp) {
    Autor* user = searchAutorByPub(pp.id);
    cout << "\nTitulo: " << pp.titulo << endl;
    cout << "Tipo: " << pp.tipo << endl;
    cout << "Year: " << pp.year << endl;
    cout << "Premio: " << pp.premio << endl;
    cout << "Abstract: " << pp.abstract << endl;
    cout << "Puntos base: " << pp.puntosBase << endl;
    cout << "Puntos extra: " << pp.puntosAdic << endl;
    cout << "Total puntaje: " << (pp.puntosBase + pp.puntosAdic) << endl;

    if (user) {
        cout << "\nAutor de la publicacion:\n";
        cout << "ID autor: " << user->id << endl;
        cout << "Nombre: " << user->nombre << endl;
        cout << "Correo: " << user->correo << endl;
        cout << "Programa: " << user->programa << endl;
    } else {
        cout << "\nAutor no encontrado.\n";
    }
}

void modifyPub(Publicacion* pp) {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Titulo (" << pp->titulo << "): ";
    cin.getline(pp->titulo, 80);
    cout << "Tipo (" << pp->tipo << "): ";
    cin >> pp->tipo;
    cout << "Año (" << pp->year << "): ";
    cin >> pp->year;
    cin.ignore();
    cout << "Premio (" << pp->premio << "): ";
    cin.getline(pp->premio, 80);
    pp->puntosBase = puntosPorTipo(pp->tipo);
    pp->puntosAdic = puntosPorPremio(pp->premio);
    cout << "New PuntosBase: " << pp->puntosBase << endl;
    cout << "New PuntosAdic: " << pp->puntosAdic << endl;
    cout << "Total: " << (pp->puntosBase + pp->puntosAdic) << endl;
    cout << "Recalculado.\n";
}

void modifyAuthor(Autor* author) {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Nombre (" << author->nombre << "): ";
    cin.getline(author->nombre, 60);
    cout << "Correo (" << author->correo << "): ";
    cin.getline(author->correo, 60);
    cout << "Programa (" << author->programa << "): ";
    cin.getline(author->programa, 60);
    cout << "Actualizado.\n";
}

void actualizar() {
    system("cls");
    int type;
    cout << "1. Autor.\n2.Publicacion.\n3.Salir.\n";
    safeReadInt(type, 1, 3, "Ingrese su eleccion: ", "Opcion invalida");
    if (type == 3) return;
    long long idnum;
    while (true) {
        cout << ((type == 1) ? "ID autor: " : "ID publicacion: ");
        cin >> idnum;

        bool existe = (type == 1) ? existeAutor(idnum) : existePublicacion(idnum);

        if (!existe) {
            cout << ((type == 1) ? "Autor no encontrado.\n" : "Publicacion no encontrada.\n");
            system("pause");
            continue;
        } else
            break;
    }
    if (type == 1) {
        Autor *user = searchAutor(idnum);
        mostrarDatosAutor(user);
        cout << "¿Deseas modificar algo? (S/N): ";
        char option;
        cin >> option;
        if (tolower(option) == 's'){
            modifyAuthor(user);
            system("pause");
        }
        else{
            cout << "Okey\n";
            system("pause");
        }
    } else {
        Publicacion* pub = searchPub(idnum);
        mostrarDatosPub(*pub);
        cout << "¿Deseas modificar algo? (S/N): ";
        char option;
        cin >> option;
        if (tolower(option) == 's'){
            modifyPub(pub);
            system("pause");
        }
        else{
            cout << "Okey\n";
            system("pause");
        }
    }
    system("pause");
}
void reportes(){
    system("cls");
	int type;
    cout << "1. Consultar un Autor.\n2. Consultar una Publicacion.\n3. Listar Autores y publicaciones.\n4. Salir\n";
    safeReadInt(type, 1, 4, "Ingrese su eleccion: ", "Opcion invalida");
    if (type == 4) return;
    long long idnum;
    while (true) {
    	if(type==1){
	        cout << "ID autor: "; cin >> idnum;
	        bool existe = existeAutor(idnum);
	        if (!existe) {
	            cout <<"Autor no encontrado.\n";
	            system("pause");
	            continue;
	        } 
	        Autor *user = searchAutor(idnum);
            mostrarDatosAutor(user);
            system("pause");
            break;
		}
		else if(type==2){
	        cout << "ID publicacion: "; cin >> idnum;
	        bool existe = existePublicacion(idnum);
	        if (!existe) {
	            cout <<"Pub no encontrada.\n";
	            system("pause");
	            continue;
	        } 
	        Publicacion* pub = searchPub(idnum);
            mostrarDatosPub(*pub);
            system("pause");
            break;
		}
		else {
		    for(int i =0; i<cntAutor; i++){
		       mostrarDatosAutor(&autores[i]);
		    }
		    cout << "Programa finalizado.\n";
		    system("pause");
		    break;
		}
	}
}
int cntAutorConTipoPremiacion(int pre){
    int cntp=0;
    for (int i = 0; i < cntAutor; i++)
        for (int j = 0; j < autores[i].cntPubs; j++)
            if (autores[i].pubs[j].tipo == pre) {
                cntp++;
                break;
            }
    return cntp;
}
void autorMayorYMenorPuntaje() {
    system("cls");
    if (cntAutor == 0) {
        cout << "No hay autores registrados.\n";
        return;
    }
    int idxMax = 0, idxMin = 0, maxPuntos = 0, minPuntos = INT_MAX;
    for (int i = 0; i < cntAutor; i++) {
        int total = 0;
        for (int j = 0; j < autores[i].cntPubs; j++)
            total += autores[i].pubs[j].puntosBase + autores[i].pubs[j].puntosAdic;
        if (total > maxPuntos) {
            maxPuntos = total;
            idxMax = i;
        }
        if (total < minPuntos) {
            minPuntos = total;
            idxMin = i;
        }
    }

    cout << "\nAutor con MAYOR puntaje total:\n";
    cout << "Nombre: " << autores[idxMax].nombre << endl;
    cout << "Puntaje total: " << maxPuntos << endl;

    cout << "\nAutor con MENOR puntaje total:\n";
    cout << "Nombre: " << autores[idxMin].nombre << endl;
    cout << "Puntaje total: " << minPuntos << endl;
    cout << "Programa finalizado." << endl;
    system("pause");
}
void tipoPublicacionMasRegistros() {
    system("cls");
    if (cntAutor == 0) {
        cout << "No hay publicaciones registradas.\n";
        system("pause");
        return;
    }
    const int MAX_TIPO = 5;
    int conteo[MAX_TIPO] = {0};
    int puntosTotales[MAX_TIPO] = {0};
    int totalPubs = 0;
    for (int i = 0; i < cntAutor; i++) {
        for (int j = 0; j < autores[i].cntPubs; j++) {
            int tipo = autores[i].pubs[j].tipo;
            if (tipo >= 1 && tipo < MAX_TIPO) {
                conteo[tipo]++;
                puntosTotales[tipo] += autores[i].pubs[j].puntosBase + autores[i].pubs[j].puntosAdic;
                totalPubs++;
            }
        }
    }
    if (totalPubs == 0) {
        cout << "No hay publicaciones registradas.\n";
        system("pause");
        return;
    }
    int tipoMax = 1;
    for (int t = 2; t < MAX_TIPO; t++)
        if (conteo[t] > conteo[tipoMax])
            tipoMax = t;

    double porcentaje = (static_cast<double>(conteo[tipoMax]) / totalPubs) * 100.0;
    double promedio = (conteo[tipoMax] > 0)
        ? static_cast<double>(puntosTotales[tipoMax]) / conteo[tipoMax]
        : 0.0;

    cout << "\nTipo de publicacion con mas registros:\n";
    cout << "Tipo: " << tipoMax << endl;
    cout << "Cantidad: " << conteo[tipoMax] << " de " << totalPubs << " (" 
         << fixed << setprecision(2) << porcentaje << "%)\n";
    cout << "Puntaje promedio: " << fixed << setprecision(2) << promedio << endl;
    system("pause");
}

void estadisticas(){
    system("cls");
	int type;
    cout << "1. Listado Autores.\n2. Porcentajes de docentes por tipo de premiacion.\n3. Max/min puntaje\n4. Tipo de publicacion con mas registros\n5. Salir\n";
    safeReadInt(type, 1, 5, "Ingrese su eleccion: ", "Opcion invalida");
    if (type == 5) return;
    long long idnum;
    while (true) {
    	if(type==1){
	        for(int i =0; i<cntAutor; i++){
	           cout << "Nombre: " <<autores[i].nombre<<endl;
		       cout << "# de pubs: " <<autores[i].cntPubs<<endl;
		    }
		    cout << "Programa finalizado.\n";
		    system("pause");
		    break;
		}
		else if (type == 2) {
            int pre;
            safeReadInt(pre, 1, 5, "Tipo de premiacion (1-5)?\n", "Opcion invalida");
            int cntt = cntAutorConTipoPremiacion(pre);
            cout << "Hay en total " << cntt << " docentes con ese tipo de premiacion.\n";
            if (cntAutor > 0){
                cout << "El porcentaje es: " 
                     << fixed << setprecision(2) 
                     << (static_cast<double>(cntt) / cntAutor * 100) 
                     << "%\n";
                     system("pause");
            }
            else{
                cout << "No hay autores registrados.\n";
                system("pause");
            }
            break;
}
		else if(type==3){
		    autorMayorYMenorPuntaje();
		    break;
		}
		else if(type==4){
		    tipoPublicacionMasRegistros();
		    break;
		}
	}
}

int main() {
    Autor a1 = {1, "Carlos", "c@uni.edu", "Ingenieria"};
    Publicacion p1 = {101, "IA y Etica", 1, 2023, "Ninguno", "Sobre IA y moral", 50, 0};
    a1.pubs[a1.cntPubs++] = p1;
    autores[cntAutor++] = a1;

    int op;
    while (true) {
        system("cls");
        cout << "1. Agregar autor\n2. Agregar publicacion\n3. Actualizar\n4. Reportes y Consultas\n5.estadisticas\n6. Salir\n> ";
        safeReadInt(op, 1, 6, "Ingrese su eleccion: ", "Opcion invalida");
        switch (op) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                actualizar();
                break;
            case 4:
                reportes();
                break;
            case 5:
                estadisticas();
                break;
            case 6:
                return 0;
        }
    }
}
