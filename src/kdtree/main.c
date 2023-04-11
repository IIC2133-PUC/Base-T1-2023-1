#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


/* Retorna true si ambos strings son iguales */
bool string_equals(char *string1, char *string2)
{
  return !strcmp(string1, string2);
}

/* Revisa que los parametros del programa sean válidos */
bool check_arguments(int argc, char **argv)
{
  if (argc != 3)
  {
    printf("Modo de uso: %s INPUT OUTPUT\n", argv[0]);
    printf("Donde:\n");
    printf("\tINPUT es la ruta del archivo de input\n");
    printf("\tOUTPUT es la ruta del archivo de output\n");
    exit(1);
  }

  return true;
}
int main(int argc, char** argv) {
    check_arguments(argc, argv);

    FILE* input_file = fopen(argv[1], "r");
    FILE* output_file = fopen(argv[2], "w");

    int criteria;
    int node_count;
    int query_count;
    /* leemos el criterio para armar el arbol */
    fscanf(input_file, "%d", &criteria);

    fscanf(input_file, "%d", &node_count);

    /* leemos Cada nodo */
    int index, conductivness, hardness, inatorness;
    for(int i=0; i<node_count; i++){
        fscanf(input_file, "%d %d %d %d", &index, &conductivness, &hardness, &inatorness);
        printf("%d %d %d %d\n", index, conductivness, hardness, inatorness);
    }


    fscanf(input_file, "%d", &query_count);
    /* leemos las consultas */
    char command[32];
    int value;
    for(int i=0; i<query_count; i++){
        fscanf(input_file, "%s %d", command, &value);
        printf("%s %d\n", command, value);
        /* completar la revision de comando y ejecucion de los mismos */
    }

    fclose(input_file);
    fclose(output_file);
    return 0;
}

