#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct p_info {
  char name[20];
  char password[20];
} p_info_struct;

bool check_password(int p_info_size, p_info_struct p_infos[], char user[], char password[]);

int main (int argc, char **argv) {
  if (argc < 3) {
    printf("You need to enter more than %i argument(s)...\n", argc-1);
    return 1;
  }

  p_info_struct test_infos[] = {
    {"test", "test"},
    {"mikael", "secret"},
    {"mikkel", "123456"}
  };

  printf("%s\n", check_password(3, test_infos, argv[1], argv[2]) ? "true" : "false");

  return 0;
}

bool check_password(int p_info_size, p_info_struct p_infos[], char username[], char password[]) {
  int i = 0;
  bool match = false;

  while (i < p_info_size) {
    if (!strcmp(p_infos[i].name, username) && !strcmp(p_infos[i].password, password)) {
      match = true;
    }
    i = i + 1;
  }
  return match;
}
