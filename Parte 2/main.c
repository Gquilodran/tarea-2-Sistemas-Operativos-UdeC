#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "sim.h"
#include "funcion.h"


int main(int argc, char* argv[]){
	if (argc < 4){
        printf("Uso: %s Nmarcos tamanho_marco [--verbose] traza.txt\n", argv[0]);
        return 1;
    }

    int arg_index = 1;
    int Nmarcos = atoi(argv[arg_index++]);
    int tamanho_marco = atoi(argv[arg_index++]);

    bool verbose = false;

    if (strcmp(argv[arg_index], "--verbose") == 0){
        verbose = true;
        arg_index++;
    }

    char* archivo_traza = argv[arg_index];
    FILE* f = fopen(archivo_traza, "r");
    if (!f){
        perror("Error al abrir el archivo");
        return 1;
    }

    Sim sim;
    inicializa_sim(&sim, Nmarcos, tamanho_marco);

    char linea[128];
    long int dv;
    int npv, offset;
    int referencias = 0;

    while (fgets(linea, sizeof(linea), f)){
        linea[strcspn(linea, "\n")] = 0;
        dv = lee_direccionV(linea, tamanho_marco, &npv, &offset);
        sim_procesar_dv(&sim, dv, npv, offset, verbose);
        referencias++;
    }

    fclose(f);

    printf("\nTotales:\n");
    printf("Referencias: %d\n", referencias);
    printf("Fallos de pagina: %d\n", sim.fallos_de_pagina);
    printf("Tasa de fallos: %.2f%%\n", 100.0*sim.fallos_de_pagina / referencias);

    sim_destruir(&sim);

    return 0;

}