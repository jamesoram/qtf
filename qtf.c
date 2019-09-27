#include <stdio.h>
#include <string.h>

void quotify(char *s);
void qtf_with_params(int param_count, char **params);
void qtf_no_params(void);

int main(int argc, char **argv) {
  if (argc < 2) {
    qtf_no_params();
  } else {
    qtf_with_params(argc, argv);  
  }
  return 0;
}

void quotify(char *s) {
  size_t length = strlen(s);
  char tmp[length + 2];

  tmp[0] = '\"';
  int i;
  for (i = 0; i < length; i++) {
    tmp[i + 1] = s[i];  
  }
  tmp[length + 1] = '\"';
  tmp[length + 2] = '\0';
  puts(tmp);
}

void qtf_with_params(int param_count, char **params) {
  int i;
  for (i = 1; i < param_count; i++) {
    quotify(params[i]);
  }
}

void qtf_no_params(void) {
  char buffer[BUFSIZ];

  while (fgets(buffer, sizeof(buffer), stdin) != 0) {
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
      buffer[len - 1] = '\0';
    }
    quotify(buffer);
  }
}
