#ifndef FUNCION_H
#define FUNCION_H

long int traduce_Hexa(char* arg);
int traduce_Bi(char* arg);
int create_Mask(int page_size);

long int lee_direccionV(char* arg, int page_size, int* npv_out, int* offset_out);

#endif