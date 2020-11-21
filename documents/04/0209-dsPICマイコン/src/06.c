void put_num3(int n) {
  int a = n / 100;
  int b = n / 10 % 10;
  int c = n % 10;
  put_num1(a);
  put_num1(b);
  put_num1(c);
}
