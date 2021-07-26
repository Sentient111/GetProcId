#include "ProcessId.h"

std::string targetName = "notepad.exe";


int main()
{

    int pid = 0;
    while (pid == 0)
    {
        pid = GetPid(targetName);
    }
    std::cout << "target pid = " << pid << std::endl;
}
