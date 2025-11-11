#ifndef STRUCTS_H
#define STRUCTS_H
typedef struct {
    long long id;
    char nombre[50];
    char correo[50];
    char programa[50];
} Autor;

typedef struct {
    int id;
    char titulo[100];
    int tipo;
    int year;
    char premio[50];
    char abstract[1000];
    int puntosBase;
    int puntosExtra;
} Publicacion;

#endif
