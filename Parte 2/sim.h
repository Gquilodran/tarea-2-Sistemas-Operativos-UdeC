#ifndef SIM_H
#define SIM_H
#include <stdbool.h>


typedef struct{
    int npv;
    bool valido;
    bool referencia;
} Pte;


typedef struct{
    int Nmarcos;
    int page_size;

    int reloj_puntero;
    int marcos_libres;
    int fallos_de_pagina;

    Pte** tabla_marcos;
} Sim;

void inicializa_sim(Sim* sim, int Nmarcos, int tamano_marcos);

long int sim_procesar_dv(Sim* sim, long int dv, int npv, int offset, bool verbose);

void sim_destruir(Sim* sim);

#endif