#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct servidor{
    int codigo;
    char nombre[50];
    char tipo;
    float promedioCPU;
    float promedioMEM;
    float porcentajeDISCO;
} servidor;

// Declaración de prototipos para que el main los reconozca
void cargarinfo(servidor servidores[], int* cantservidores);
void informarcodigoynombremayorporCPU(servidor servidores[], int cantservidores);
void informarcodigoynombremayorporMEM(servidor servidores[], int cantservidores);
void informarpromedioutilizacionCPU(servidor servidores[], int cantservidores);
void informarporcentajetasaelevada80(servidor servidores[], int cantservidores);
void tipodeservidorconmayorpromedio(servidor servidores[], int cantservidores);
void informarservidorescriticos(servidor servidores[], int cantservidores);

void cargarinfo(servidor servidores[], int* cantservidores){
    // Validación: cantidad entre 1 y 30
    do {
        printf("Ingrese la cantidad de servidores a almacenar (Maximo 30): \n");

        scanf("%d", cantservidores);
    } while (*cantservidores < 1 || *cantservidores > 30);


    for(int i = 0; i < *cantservidores; i++){
        int cod;
        char nom[50];
        char tip;
        float promCPU;
        float promMEM;
        float porcDISCO;
        servidor server;

        printf("\n--- Servidor %d ---\n", i + 1);

        int codigoRepetido;
        do {
            codigoRepetido = 0;
            printf("Ingrese el codigo del servidor (entero positivo unico): ");
            scanf("%d", &cod);

            if (cod <= 0) {
                codigoRepetido = 1;
            } else {
                for (int j = 0; j < i; j++) {
                    if (servidores[j].codigo == cod) {
                        codigoRepetido = 1;
                        printf("Error: Ese codigo ya existe.\n");
                        break;
                    }
                }
            }
        } while (codigoRepetido == 1);
        server.codigo = cod;

        printf("Ingrese el nombre del servidor: ");
        scanf("%49s", nom);
        strcpy(server.nombre, nom);

        do {
            printf("Ingrese el tipo del servidor (W, B, A): ");
            scanf(" %c", &tip);
            tip = toupper(tip);
        } while (tip != 'W' && tip != 'B' && tip != 'A');
        server.tipo = tip;

        do {
            printf("Ingrese el porcentaje promedio de utilizacion de CPU del servidor (0-100): ");
            scanf("%f", &promCPU);
        } while (promCPU < 0 || promCPU > 100);
        server.promedioCPU = promCPU;

        do {
            printf("Ingrese el porcentaje promedio de utilizacion de memoria del servidor (0-100): ");
            scanf("%f", &promMEM);
        } while (promMEM < 0 || promMEM > 100);
        server.promedioMEM = promMEM;

        do {
            printf("Ingrese el porcentaje de espacio utilizado de disco del servidor (0-100): ");
            scanf("%f", &porcDISCO);
        } while (porcDISCO < 0 || porcDISCO > 100);
        server.porcentajeDISCO = porcDISCO;

        servidores[i] = server;
    }
}

void informarcodigoynombremayorporCPU(servidor servidores[], int cantservidores){
    int codigomayorporcentajeCPU = servidores[0].codigo;
    char nombremayorporcentajeCPU[50];
    strcpy(nombremayorporcentajeCPU, servidores[0].nombre); // Inicializar usando strcpy
    float promediomaxCPU = servidores[0].promedioCPU;

    for(int i = 1; i < cantservidores; i++){
        // Al usar ">" estricto, cumplimos la regla de reportar el primero encontrado en caso de empate
        if(servidores[i].promedioCPU > promediomaxCPU){
            codigomayorporcentajeCPU = servidores[i].codigo;
            strcpy(nombremayorporcentajeCPU, servidores[i].nombre);
            promediomaxCPU = servidores[i].promedioCPU;
        }
    }
    printf("\na) El codigo del servidor con mayor promedio de uso de CPU es: %d, y su nombre es: %s\n", codigomayorporcentajeCPU, nombremayorporcentajeCPU);
}

void informarcodigoynombremayorporMEM(servidor servidores[], int cantservidores){
    int codigomayorporcentajeMEM = servidores[0].codigo;
    char nombremayorporcentajeMEM[50];
    strcpy(nombremayorporcentajeMEM, servidores[0].nombre);
    float promediomaxMEM = servidores[0].promedioMEM;

    for(int i = 1; i < cantservidores; i++){
        if(servidores[i].promedioMEM > promediomaxMEM){
            codigomayorporcentajeMEM = servidores[i].codigo;
            strcpy(nombremayorporcentajeMEM, servidores[i].nombre);
            promediomaxMEM = servidores[i].promedioMEM;
        }
    }
    printf("b) El codigo del servidor con mayor promedio de uso de memoria es: %d, y su nombre es: %s\n", codigomayorporcentajeMEM, nombremayorporcentajeMEM);
}

void informarpromedioutilizacionCPU(servidor servidores[], int cantservidores){
    float sumapromedios = 0;
    float promedio;
    for(int i = 0; i < cantservidores; i++){
        sumapromedios += servidores[i].promedioCPU;
    }
    promedio = sumapromedios / cantservidores;
    printf("c) El uso promedio de CPU de todos los servidores es: %.2f%%\n", promedio);
}

void informarporcentajetasaelevada80(servidor servidores[], int cantservidores){
    int cantidad = 0;
    float porcentaje;
    for(int i = 0; i < cantservidores; i++){
        if(servidores[i].promedioCPU > 80.0){
            cantidad += 1;
        }
    }

    porcentaje = ((float)cantidad * 100.0) / cantservidores;
    printf("d) El porcentaje de servidores con tasa de utilizacion de CPU elevada es: %.2f%%\n", porcentaje);
}

void tipodeservidorconmayorpromedio(servidor servidores[], int cantservidores){
    float sumaW = 0, sumaB = 0, sumaA = 0;
    int contW = 0, contB = 0, contA = 0;

    for(int i = 0; i < cantservidores; i++){
        if(servidores[i].tipo == 'W') { sumaW += servidores[i].promedioCPU; contW++; }
        else if(servidores[i].tipo == 'B') { sumaB += servidores[i].promedioCPU; contB++; }
        else if(servidores[i].tipo == 'A') { sumaA += servidores[i].promedioCPU; contA++; }
    }

    float promW = (contW > 0) ? (sumaW / contW) : -1;
    float promB = (contB > 0) ? (sumaB / contB) : -1;
    float promA = (contA > 0) ? (sumaA / contA) : -1;

    char tipoGanador = 'W';
    float mayorProm = promW;

    if (promB > mayorProm) { mayorProm = promB; tipoGanador = 'B'; }
    if (promA > mayorProm) { mayorProm = promA; tipoGanador = 'A'; }

    printf("e) El tipo de servidor que presenta el mayor promedio de utilizacion de CPU es: %c\n", tipoGanador);
}


void informarservidorescriticos(servidor servidores[], int cantservidores){
    printf("f) Servidores con utilizacion de CPU y memoria simultaneamente superior al 70%%:\n");
    int hallados = 0;
    for(int i = 0; i < cantservidores; i++){
        if(servidores[i].promedioCPU > 70.0 && servidores[i].promedioMEM > 70.0){
            printf("   - Codigo: %d | Nombre: %s\n", servidores[i].codigo, servidores[i].nombre);
            hallados = 1;
        }
    }
    if(hallados == 0){
        printf("   - Ningun servidor cumple con esta condicion.\n");
    }
}

int main(){
    // Inicialización de variables locales
    int cantservidores = 0;
    servidor servidores[30];

    // Carga de la información pasándole la dirección de memoria de cantservidores
    cargarinfo(servidores, &cantservidores);

    // Si la carga fue exitosa y hay servidores, invocamos las funciones requeridas
    if (cantservidores > 0) {
        informarcodigoynombremayorporCPU(servidores, cantservidores);
        informarcodigoynombremayorporMEM(servidores, cantservidores);
        informarpromedioutilizacionCPU(servidores, cantservidores);
        informarporcentajetasaelevada80(servidores, cantservidores);
        tipodeservidorconmayorpromedio(servidores, cantservidores);
        informarservidorescriticos(servidores, cantservidores);
    }

    return 0;
}
