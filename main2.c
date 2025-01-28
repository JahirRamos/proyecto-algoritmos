#include <stdio.h>

#define TARIFA_POR_MINUTO 5.0

int mostrarMenu() {
    printf("\nMenu de opciones:\n");
    printf("1. Cargar vehiculo\n");
    printf("2. Salir\n");
    printf("Seleccione una opcion: ");
    return 0;
}

int obtenerTiempoDeCarga() {
    int tiempo;
    do {
        printf("\nIngrese el tiempo de carga en minutos: ");
        scanf("%d", &tiempo);
        if (tiempo < 0) {
            printf("El tiempo de carga no puede ser negativo. Por favor, ingrese un valor valido.\n");
        }
    } while (tiempo < 0);
    return tiempo;
}

float obtenerMontoPagado(float costoTotal) {
    float montoPagado;
    do {
        printf("Ingrese el monto pagado: ");
        scanf("%f", &montoPagado);
        if (montoPagado < 0) {
            printf("El monto pagado no puede ser negativo. Por favor, ingrese un valor valido.\n");
        } else if (montoPagado < costoTotal) {
            printf("Monto insuficiente. Por favor, ingrese un monto mayor o igual al costo total.\n");
        }
    } while (montoPagado < costoTotal);
    return montoPagado;
}

int calcularCambio(int cambio) {
    int monedas[] = {20, 10, 5, 2};
    printf("\nDesglose del cambio:\n");
    for (int i = 0; i < 4; i++) {
        int cantidad = cambio / monedas[i];
        if (cantidad > 0) {
            printf("%d moneda(s) de %d pesos\n", cantidad, monedas[i]);
            cambio %= monedas[i];
        }
    }
    return cambio;
}

int procesarCarga() {
    int tiempo = obtenerTiempoDeCarga();
    float costoTotal = tiempo * TARIFA_POR_MINUTO;
    printf("Costo total: %.2f pesos\n", costoTotal);

    float montoPagado = obtenerMontoPagado(costoTotal);
    int cambio = (int)(montoPagado - costoTotal);

    printf("\nCambio a entregar: %d pesos\n", cambio);
    calcularCambio(cambio);

    printf("\nResumen:\n");
    printf("Tiempo de carga: %d minutos\n", tiempo);
    printf("Costo total: %.2f pesos\n", costoTotal);
    printf("Monto pagado: %.2f pesos\n", montoPagado);
    printf("Cambio entregado: %d pesos\n", cambio);

    return 0;
}

int main() {
    char opcion;
    do {
        mostrarMenu();
        scanf(" %c", &opcion);
        switch (opcion) {
            case '1':
                printf("\nEstacion de carga de vehiculos electricos\n");
                procesarCarga();
                break;
            case '2':
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no valida. Por favor, intente de nuevo.\n");
        }
    } while (opcion != '2');

    return 0;
}
