#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "ru");
    if (argc != 2) {
        printf("Вы забыли ввести свое имя.\n");
        exit(1);
    }
    printf("Привет %s", argv[1]);

    return 0;
}
