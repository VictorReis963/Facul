# include <stdio.h>
 # include <unistd.h>
 # include <sys/wait.h>
 # include <string.h>
 # include <stdlib.h>

 int main () {
 int pipefd [2]; // pipefd [0] = leitura , pipefd [1] = escrita
 char buffer [100];

 if (pipe(pipefd ) == -1) {
 perror ("pipe");
 exit( EXIT_FAILURE );
 }

 pid_t pid = fork ();
 if (pid < 0) {
 perror ("fork");
 exit( EXIT_FAILURE );
 }

 if (pid == 0) { // Processo Filho: escreve no pipe
 close(pipefd [0]); // Filho nao le , fecha a ponta de leitura
 const char* msg = "Ola do filho!";
 printf ("Filho: enviando mensagem ...\n");
 ssize_t bytes_written = write(pipefd [1], msg , strlen (msg) + 1);
 if ( bytes_written == -1) {
 perror ("write");
 exit( EXIT_FAILURE );
 }

 close(pipefd [1]); // Fecha a ponta de escrita apos o uso
 exit( EXIT_SUCCESS );
 } else { // Processo Pai: le do pipe
 close(pipefd [1]); // Pai nao escreve , fecha a ponta de escrita
 printf ("Pai: esperando mensagem ...\n");
 ssize_t bytes_read = read(pipefd [0], buffer , sizeof (buffer ));
 if ( bytes_read == -1) {
 perror ("read");
 exit( EXIT_FAILURE );
 }

 printf ("Pai: recebeu a mensagem : '%s' (%zd bytes)\n", buffer , bytes_read );
 close(pipefd [0]); // Fecha a ponta de leitura apos o uso
 wait(NULL); // Limpa o processo filho zumbi
 }
 return 0;
}