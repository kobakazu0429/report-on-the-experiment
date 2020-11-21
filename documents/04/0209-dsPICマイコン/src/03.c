void put_str(char *str) {
  char i;
  for (i = 0; str[i] != '\0'; i++) {
    put_char(str[i]);
  }
}
