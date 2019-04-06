#include <iostream>
#include <sys/types.h>
#include <unistd.h>

int main() {
    fork();
    while(true);
}
