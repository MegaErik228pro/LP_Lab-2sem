#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "ru");
    if (argc != 2) {
        printf("�� ������ ������ ���� ���.\n");
        exit(1);
    }
    printf("������ %s", argv[1]);

    return 0;
}
