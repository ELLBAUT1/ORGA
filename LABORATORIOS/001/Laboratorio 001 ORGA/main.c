#include <stdio.h>
#include <stdlib.h>

//Funcion calcular consumo
float calcularConsumo(float potencia, int horas){
    return (potencia*horas)/1000;
}

int main(){
    //Input del usuario
    int codigo = 1;
    int horas = 0;
    float potencia = 0;

    //Valores almacenados para calcular resultados
    float consumo = 0;
    int cantidadrigs = 0;
    int totalhoras = 0;
    float totalconsumo = 0;
    float consumomenor = 0;
    int codigomenor = 0;
    float consumomayor = 0;
    int codigomayor = 0;

    while(codigo != 0){
        printf("Ingrese el codigo del rig: \n");
        scanf("%i", &codigo);
        if(codigo == 0){
            printf("Se ha ingresado el codigo de salida.\n");
            break;
        }
        printf("Ingrese la potencia del rig: \n");
        scanf("%f", &potencia);

        printf("Ingrese la cantidad de horas de funcinamiento del rig: \n");
        scanf("%i", &horas);

        consumo = calcularConsumo(potencia, horas);

         if(cantidadrigs == 0){
            //Inicializacion de las variables de control, en caso de ser la primera entrada
            codigomenor = codigo;
            consumomenor = consumo;

            codigomayor = codigo;
            consumomayor = consumo;
         }

        //Suma a las variables de control globales de totales
        totalhoras += horas;
        totalconsumo += consumo;
        cantidadrigs += 1;

        //Actualizacion de menor y mayor
        if(consumomenor > consumo){
            consumomenor = consumo;
            codigomenor = codigo;
        }

        if(consumomayor < consumo){
            consumomayor = consumo;
            codigomayor = codigo;
        }
    }

    //Sabemos que cantidadrigs > 0
    float consumopromedio = totalconsumo/cantidadrigs;

    float porcentajemayor = (consumomayor * 100)/totalconsumo;

    //Devolvemos los resultados
    printf("El consumo total de todos los equipos es de %f kWh.\n", totalconsumo);

    printf("La cantidad total de horas de funcionamiento de los rigs mineros es %i horas.\n", totalhoras);

    printf("El consumo energético promedio de los equipos de minería es de %f kWh\n", consumopromedio);

    printf("El codigo del rig que presentó mayor consumo energético es: %i\n", codigomayor);

    printf("El código del rig que presentó menor consumo energético es: %i\n", codigomenor);

    printf("El porcentaje que representa el consumo del equipo de mayor consumo respecto del consumo energético total es equivalente al %f porciento\n", porcentajemayor);

    //Finaliza la ejecucion
    return 0;
}
