#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

// Funciones auxiliares
void generarContrasena(char *contrasena, int longitud, int mayusculas, int minusculas, int numeros, int simbolos);
void mostrarMenu();

int main() {
    int longitud, mayusculas, minusculas, numeros, simbolos;
    char contrasena[256]; 

    srand(time(NULL));

    while (1) {
        mostrarMenu();
        int opcion;
        printf("Elige una opción: ");
        scanf("%d", &opcion);

        if (opcion == 0) {
            printf("Saliendo del programa...\n");
            break;
        }

        switch (opcion) {
            case 1:
                printf("Ingrese la longitud de la contraseña: ");
                scanf("%d", &longitud);

                printf("Incluir mayúsculas? (1: Sí, 0: No): ");
                scanf("%d", &mayusculas);

                printf("Incluir minúsculas? (1: Sí, 0: No): ");
                scanf("%d", &minusculas);

                printf("Incluir números? (1: Sí, 0: No): ");
                scanf("%d", &numeros);

                printf("Incluir símbolos? (1: Sí, 0: No): ");
                scanf("%d", &simbolos);

                if (!mayusculas && !minusculas && !numeros && !simbolos) {
                    printf("Debe incluir al menos un tipo de carácter.\n");
                    break;
                }

                generarContrasena(contrasena, longitud, mayusculas, minusculas, numeros, simbolos);
                printf("Contraseña generada: %s\n", contrasena);
                break;

            default:
                printf("Opción no válida. Inténtalo de nuevo.\n");
        }
    }

    return 0;
}

void mostrarMenu() {
    printf("\n=== Generador de Contraseñas ===\n");
    printf("1. Generar una nueva contraseña\n");
    printf("0. Salir\n");
}

void generarContrasena(char *contrasena, int longitud, int mayusculas, int minusculas, int numeros, int simbolos) {
    const char mayus[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char minus[] = "abcdefghijklmnopqrstuvwxyz";
    const char nums[] = "0123456789";
    const char symbs[] = "!@#$%^&*()-_=+[]{}|;:,.<>?";

    char caracteres[256];
    int num_caracteres = 0;

    if (mayusculas) {
        for (int i = 0; mayus[i] != '\0'; i++) {
            caracteres[num_caracteres++] = mayus[i];
        }
    }
    if (minusculas) {
        for (int i = 0; minus[i] != '\0'; i++) {
            caracteres[num_caracteres++] = minus[i];
        }
    }
    if (numeros) {
        for (int i = 0; nums[i] != '\0'; i++) {
            caracteres[num_caracteres++] = nums[i];
        }
    }
    if (simbolos) {
        for (int i = 0; symbs[i] != '\0'; i++) {
            caracteres[num_caracteres++] = symbs[i];
        }
    }

    for (int i = 0; i < longitud; i++) {
        contrasena[i] = caracteres[rand() % num_caracteres];
    }
    contrasena[longitud] = '\0';
}
