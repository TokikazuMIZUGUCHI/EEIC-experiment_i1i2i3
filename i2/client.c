# include <stdlib.h>
# include <netinet/in.h>
# include <netinet/ip.h>
# include <netinet/tcp.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "usage: %s <IP address> <port>\n", argv[0]);
    exit(1);
  }
  int s = socket(PF_INET, SOCK_STREAM, 0);

  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  int flag = inet_aton(argv[1], &addr.sin_addr);
  if (flag == 0) {
    fprintf(stderr, "IP address ERROR\n");
    exit(1);
  }
  addr.sin_port = htons(atoi(argv[2]));
  int ret = connect(s, (struct sockaddr *)&addr, sizeof(addr));
  if (ret == -1) {
    fprintf(stderr, "CONNECT ERROR\n");
    exit(1);
  }
  
  const size_t bufsize = 500;
  char buf[bufsize];
  while (fgets(buf, bufsize, stdin) != NULL) {
    // if (!feof(stdin)) {
    //   break;
    // }
    size_t len = strlen(buf);
    if (send(s, buf, len, 0) == -1) {
      fprintf(stderr, "SEND ERROR\n");
      exit(1);
    }
  }
  // unsigned char buffer[1];
  // while (scanf("%s", buffer) != EOF) {
  //   if (send(s, buffer, 1, 0) == -1) {
  //     fprintf(stderr, "SEND ERROR\n");
  //     exit(1);
  //   }
  // }

  shutdown(s, SHUT_WR);

  unsigned char data[1];
  while (recv(s, data, 1, 0) != 0) {
      printf("%s", data);
  }

  close(s);
  return 0;
}