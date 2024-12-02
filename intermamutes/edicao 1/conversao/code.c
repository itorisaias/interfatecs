#include <stdio.h>

void converter_bytes(unsigned long long n)
{
  // Definições das unidades em bytes
  unsigned long long TB = 1024ULL * 1024 * 1024 * 1024;
  unsigned long long GB = 1024ULL * 1024 * 1024;
  unsigned long long MB = 1024ULL * 1024;
  unsigned long long KB = 1024ULL;

  // Cálculo das unidades
  unsigned long long terabytes = n / TB;
  n %= TB;
  unsigned long long gigabytes = n / GB;
  n %= GB;
  unsigned long long megabytes = n / MB;
  n %= MB;
  unsigned long long kilobytes = n / KB;
  unsigned long long bytes_remaining = n % KB;

  // Exibição do resultado no formato TB:GB:MB:KB:B
  printf("%llu:%llu:%llu:%llu:%llu\n", terabytes, gigabytes, megabytes, kilobytes, bytes_remaining);
}

int main()
{
  unsigned long long N;

  while (scanf("%llu", &N) != EOF)
  {
    converter_bytes(N);
  }

  return 0;
}
