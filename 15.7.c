#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAXLINE 1024

int main(void) {
  char line[MAXLINE];
  FILE *fpin;

  if ((fpin = popen("./15.6", "r")) == NULL) {
    printf("popen error\n");
    exit(-1);
  }

  for (;;) {
    fputs("prompt> ", stdout);
    fflush(stdout);

    if (fgets(line, MAXLINE, fpin) == NULL) {
      break;
    }

    if (fputs(line, stdout) == EOF) {
      printf("fputs error to pipe");
      exit(-1);
    }
  }

  if (pclose(fpin) == -1) {
    printf("pclose error\n");
    exit(-1);
  }

  putchar("\n");
  return 0;
}
