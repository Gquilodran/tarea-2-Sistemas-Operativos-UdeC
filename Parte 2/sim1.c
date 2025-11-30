#include "sim.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>


static int calcular_b(int n){
    if(n <= 0) return 0;
    return (int)round(log2((double)n));
}

static int buscar_npv(Sim* sim, int npv){
    for(int i = 0; i < sim->Nmarcos; i++){
        if(sim->tabla_marcos[i].npv == npv && sim->tabla_marcos[i].valido){
            return i;
        }
    }
    return -1;
}

void inicializa_sim(Sim* sim, int Nmarcos, int tamano_marcos){
    sim->Nmarcos = Nmarcos;
    sim->page_size = tamano_marcos;
    sim->reloj_puntero = 0;
    sim->marcos_libres = Nmarcos;
    sim->fallos_de_pagina = 0;

    sim->tabla_marcos = (Pte*)calloc(Nmarcos, sizeof(Pte));
    if(sim->tabla_marcos == NULL){
        perror("Error al asignar memoria para la tabla de marcos");
        exit(EXIT_FAILURE);
    }
}

static int clock_reemplazo(Sim* sim){
    int marco_victima = 0;
    bool encontrado = false;

    while(!encontrado){
        if(sim->tabla_marcos[sim->reloj_puntero]->referencia==true){
            sim->tabla_marcos[sim->reloj_puntero]->referencia = false;
        }else{
            marco_victima = sim->reloj_puntero;
            encontrado = true;
            sim->tabla_marcos[marco_victima]->valido = false;
        }
        sim->reloj_puntero = (sim->reloj_puntero + 1) % sim->Nmarcos;
    }
    return marco_victima;
}

long int sim_procesar_dv(Sim* sim, long int dv, int npv, int offset, bool verbose){
    int marco_encontrado=buscar_npv(sim, npv);
    int marco_usado;
    char* resultado;

    if(marco_encontrado >= 0){
        marco_usado= marco_encontrado;
        resultado = "HIT";
        sim->tabla_marcos[marco_usado]->referencia = true;
    }else{
        sim->fallos_de_pagina++;
        resultado = "FALLO";
        if(sim->marcos_libres>0){
            marco_usado = sim->Nmarcos - sim->marcos_libres;
            sim->marcos_libres--;
        }else{
            marco_usado = clock_reemplazo(sim);
        }

        sim->tabla_marcos[marco_usado]->npv = npv;
        sim->tabla_marcos[marco_usado]->valido = true;
        sim->tabla_marcos[marco_usado]->referencia = true;

    }

    int b=calcular_b(sim->page_size);
    long int df =((long int)marco_usado<<b)|(offset);

    if(verbose){
        printf("Dv:0x%lX (npv:%d, offset:%d) | Resultado:%s | Marco usado:%d | Df: 0x%lX\n",
               dv, npv, offset, resultado, marco_usado, df);
    }

    return df;
}

void sim_destruir(Sim* sim){
    if(sim->tabla_marcos){
        free(sim->tabla_marcos);
        sim->tabla_marcos = NULL;
    }
}