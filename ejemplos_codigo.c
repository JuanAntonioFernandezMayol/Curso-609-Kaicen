#include <stdio.h>
#include <stdlib.h>

void printStrings(char **arr, int size)
{
int i;
for (i = 0; i < size; i++)
printf("%s | ", arr[i]);
printf("\n");
}

int main(int argc, char *argv[]) {
if (argc < 3) {
printf("Usage: ./program string_0 string_1 string_2...\n");
exit(1);
}
printStrings(argv, argc-1);

}