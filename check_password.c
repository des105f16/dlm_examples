#include <stdbool.h>
#include <string.h>

typedef struct pinfo {
  char name[20];
  char pass[20];
} pinfo;

bool check_password(pinfo *db, int db_size, char *username, char *password) {
  int i = 0;
  bool match = false;

  while (i < db_size) {
    if (!strcmp(db[i].name, username) && !strcmp(db[i].pass, password)) {
      match = true;
    }
    i = i + 1;
  }
  return match;
}
