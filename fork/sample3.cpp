#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

int main() {
    pid_t pid = fork();
    if(pid == 0) {
	cout << "Child: Hello, I am the child process with pid = " << pid  << endl;
	cout << "Child: I am about to start some long task." << endl;
	sleep(10);
	cout << "Child: I am done executing the long task" << endl;
    }
    else {
	cout << "Parent: Hello, I am the parent. My child is pid = " << pid << endl;
	cout << "Parent: I am going to wait for my child to finish execution" << endl;
	int status;
	pid_t child_pid = waitpid(pid, &status, 0);
	cout << "Parent: Child " << child_pid << " finished execution hence I am done." << endl;
    }
}
