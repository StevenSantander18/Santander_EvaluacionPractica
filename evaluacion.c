#include <stdio.h>

// Definición de constantes
#define NUM_ALUMNOS 23
#define NUM_PROGRESOS 3

// Declaración de funciones
void obtenerCalificaciones(float calificaciones[][NUM_PROGRESOS], int numAlumnos, int numProgresos);
float calcularPromedioAlumno(float calificaciones[], int numProgresos);
float calcularPromedioGrupo(float calificaciones[][NUM_PROGRESOS], int numAlumnos, int numProgresos);
int encontrarMejorAlumno(float calificaciones[][NUM_PROGRESOS], int numAlumnos, int numProgresos);
void imprimirCalificaciones(float calificaciones[][NUM_PROGRESOS], int numAlumnos, int numProgresos);

int main() {
    // Declaración e inicialización de la matriz de calificaciones
    float calificaciones[NUM_ALUMNOS][NUM_PROGRESOS];

    // Menú principal
    int opcion;
    do {
        printf("\nMenu:\n");
        printf("1. Ingresar calificaciones\n");
        printf("2. Calcular promedio de cada alumno\n");
        printf("3. Calcular nota promedio del grupo para cada progreso\n");
        printf("4. Encontrar al alumno con el mejor promedio\n");
        printf("5. Imprimir calificaciones\n");
        printf("0. Salir\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                // 1. Obtener el promedio de calificaciones de cada alumno durante el semestre.
                obtenerCalificaciones(calificaciones, NUM_ALUMNOS, NUM_PROGRESOS);
                break;

            case 2:
                // 2. Calcular la nota promedio del grupo para cada progreso.
                printf("Promedio de cada alumno:\n");
                for (int i = 0; i < NUM_ALUMNOS; i++) {
                    printf("Alumno %d: %.2f\n", i + 1, calcularPromedioAlumno(calificaciones[i], NUM_PROGRESOS));
                }
                break;

            case 3:
                // 3. Encontrar al alumno que obtuvo el mayor promedio de calificación durante el semestre.
                printf("Nota promedio del grupo para cada progreso:\n");
                for (int i = 0; i < NUM_PROGRESOS; i++) {
                    printf("Progreso %d: %.2f\n", i + 1, calcularPromedioGrupo(calificaciones, NUM_ALUMNOS, NUM_PROGRESOS));
                }
                break;

            case 4:
                // 4. Encontrar al alumno que obtuvo el mayor promedio de calificación durante el semestre.
                printf("El alumno con el mejor promedio es el número %d.\n", encontrarMejorAlumno(calificaciones, NUM_ALUMNOS, NUM_PROGRESOS) + 1);
                break;

            case 5:
                // 5. Imprimir calificaciones (opcional, solo para revisión)
                imprimirCalificaciones(calificaciones, NUM_ALUMNOS, NUM_PROGRESOS);
                break;

            case 0:
                // Salir del programa
                printf("Saliendo del programa. ¡Hasta luego!\n");
                break;

            default:
                // Opción inválida
                printf("Opción no válida. Por favor, ingrese una opción válida.\n");
        }
    } while (opcion != 0);

    return 0;
}

// Implementación de funciones

void obtenerCalificaciones(float calificaciones[][NUM_PROGRESOS], int numAlumnos, int numProgresos) {
    printf("Ingrese las calificaciones de los estudiantes:\n");
    for (int i = 0; i < numAlumnos; i++) {
        printf("Alumno %d:\n", i + 1);
        for (int j = 0; j < numProgresos; j++) {
            printf("Progreso %d: ", j + 1);
            scanf("%f", &calificaciones[i][j]);
        }
    }
}

float calcularPromedioAlumno(float calificaciones[], int numProgresos) {
    float suma = 0.0;
    for (int i = 0; i < numProgresos; i++) {
        suma += calificaciones[i];
    }
    return suma / numProgresos;
}

float calcularPromedioGrupo(float calificaciones[][NUM_PROGRESOS], int numAlumnos, int numProgresos) {
    float suma = 0.0;
    for (int i = 0; i < numAlumnos; i++) {
        for (int j = 0; j < numProgresos; j++) {
            suma += calificaciones[i][j];
        }
    }
    return suma / (numAlumnos * numProgresos);
}

int encontrarMejorAlumno(float calificaciones[][NUM_PROGRESOS], int numAlumnos, int numProgresos) {
    float mejorPromedio = 0.0;
    int mejorAlumno = 0;

    for (int i = 0; i < numAlumnos; i++) {
        float promedioAlumno = calcularPromedioAlumno(calificaciones[i], numProgresos);
        if (promedioAlumno > mejorPromedio) {
            mejorPromedio = promedioAlumno;
            mejorAlumno = i;
        }
    }
    return mejorAlumno;
}

void imprimirCalificaciones(float calificaciones[][NUM_PROGRESOS], int numAlumnos, int numProgresos) {
    printf("Calificaciones de cada alumno:\n");
    for (int i = 0; i < numAlumnos; i++) {
        printf("Alumno %d: ", i + 1);
        for (int j = 0; j < numProgresos; j++) {
            printf("%.2f ", calificaciones[i][j]);
        }
        printf("\n");
    }
}
