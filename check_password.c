#include <stdbool.h>
#include <string.h>

typedef struct user_info {
  char username[20];
  char password[20];
} user_info;

user_info* get_users();
void send_response(bool is_match);

bool check_password(char *username, char *password) {
  int user_count = 100;
  user_info *users = get_users();
  int i = 0;
  bool match = false;

  while (i < user_count) {
    if (!strcmp(users[i].username, username) && !strcmp(users[i].password, password)) {
      match = true;
    }
    i = i + 1;
  }

  return match;
}

int main(int argc, char **argv) {
  bool is_match = check_password(argv[1], argv[2]);
  send_response(is_match);
}
