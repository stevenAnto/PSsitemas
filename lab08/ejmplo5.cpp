#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
  // Fork retorna el id del proceso
  // en el proceso padre
  pid_t child_pid = fork();
  // Proceso padre
  if (child_pid > 0)
    sleep(50);
  // Proceso hijo
  else
    exit(0);
  return 0;
}
