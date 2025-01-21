#include <stdio.h>

int main() {
    float tarifaPorMinuto = 5.0; // Tarifa por minuto
    int tiempo;
    float costoTotal;
    float montoPagado;
    char continuar;
    char opcion;

    do {
        printf("\nMenu de opciones:\n");
        printf("1. Cargar vehiculo\n");
        printf("2. Salir\n");
        printf("Seleccione una opcion: ");
        scanf(" %c", &opcion);

        if (opcion == '1') {
            printf("\nEstacion de carga de vehiculos electricos\n");

            do {
                printf("\nIngrese el tiempo de carga en minutos: ");
                scanf("%d", &tiempo);
                if (tiempo < 0) {
                    printf("El tiempo de carga no puede ser negativo. Por favor, ingrese un valor válido.\n");
                }
            } while (tiempo < 0);

            costoTotal = tiempo * tarifaPorMinuto;
            printf("Costo total: %.2f pesos\n", costoTotal);

            do {
                printf("Ingrese el monto pagado: ");
                scanf("%f", &montoPagado);
                if (montoPagado < 0) {
                    printf("El monto pagado no puede ser negativo. Por favor, ingrese un valor válido.\n");
                } else if (montoPagado < costoTotal) {
                    printf("Monto insuficiente. Por favor, ingrese un monto mayor o igual al costo total.\n");
                }
            } while (montoPagado < costoTotal);

            int cambio = (int)(montoPagado - costoTotal);
            printf("\nCambio a entregar: %d pesos\n", cambio);

            int monedas[] = {20, 10, 5, 2};
            printf("\nDesglose del cambio:\n");
            for (int i = 0; i < 4; i++) {
                int cantidad = cambio / monedas[i];
                if (cantidad > 0) {
                    printf("%d moneda(s) de %d pesos\n", cantidad, monedas[i]);
                    cambio %= monedas[i];
                }
            }

            
            printf("\nResumen:\n");
            printf("Tiempo de carga: %d minutos\n", tiempo);
            printf("Costo total: %.2f pesos\n", costoTotal);
            printf("Monto pagado: %.2f pesos\n", montoPagado);
            printf("Cambio entregado: %d pesos\n", (int)(montoPagado - costoTotal));

        } else if (opcion == '2') {
            printf("Saliendo del programa...\n");
        } else {
            printf("Opción no válida. Por favor, intente de nuevo.\n");
        }
    } while (opcion != '2');

    return 0;
}
