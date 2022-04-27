#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    FILE *ficheroPreguntas;
    char nombreFicheroPreguntas[] = "preguntas.csv";
    char buffer[BUFFER_SIZE];
    char *identificador;
    enum categoria {ciencias, historia, artes, deportes, ocio, geografia} *categoria;
    char *pregunta, *opcion1, *opcion2, *opcion3, *opcion4, *opcionCorrecta;

    ficheroPreguntas = fopen(nombreFicheroPreguntas, "r"); // Abre el fichero en modo lectura

    if(ficheroPreguntas == NULL) { // Si no lo puede abrir muestra el mensaje de error y se termina la ejecucion
        printf("\nNo se pudo abrir el fichero");
        return 1;
    }

    const char delimitador[] = ";";


    while(fgets(buffer, BUFFER_SIZE, ficheroPreguntas)) {

        identificador = strtok(buffer, delimitador);
        categoria = (enum categoria *) strtok(NULL, delimitador);
        pregunta = strtok(NULL, delimitador);
        opcion1 = strtok(NULL, delimitador);
        opcion2 = strtok(NULL, delimitador);
        opcion3 = strtok(NULL, delimitador);
        opcion4 = strtok(NULL, delimitador);
        opcionCorrecta = strtok(NULL, delimitador);

        printf("\nIdentificador: %s"
               "\nCategoria: %s"
               "\nPregunta: %s"
               "\nopcion1: %s"
               "\nopcion2: %s"
               "\nopcion3: %s"
               "\nopcion4: %s"
               "\nopcionCorrecta: %s", identificador, (char*) categoria, pregunta, opcion1, opcion2, opcion3, opcion4, opcionCorrecta);
    }

    return 0;
}
