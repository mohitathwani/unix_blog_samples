#include <iostream>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main() {
    pid_t pid = fork();
    if(pid == 0) {
	cout << "Hello, I am the child process with pid = " << pid  << endl;    	
    }
    else {
	cout << "Hello, I am the parent. My child is pid = " << pid << endl;
    }
    while(true);
}
