#pragma once
#include <iostream>
#include <string>


//https://www.tutorialspoint.com/How-to-execute-a-command-and-get-the-output-of-command-within-Cplusplus-using-POSIX
std::string exec(std::string command) {
    char buffer[128];
    std::string result = "";

    // Open pipe to file
    FILE* pipe = _popen(command.c_str(), "r");
    if (!pipe) {
        return "popen failed!";
    }

    // read till end of process:
    while (!feof(pipe)) {

        // use buffer to read and add to result
        if (fgets(buffer, 128, pipe) != NULL)
            result += buffer;
    }

    _pclose(pipe);
    return result;
}


int GetPid(std::string target)
{
    std::string command = "tasklist /svc /FI \"IMAGENAME eq " + target + "\"";
    std::string taskList = exec(command);
    std::remove_if(taskList.begin(), taskList.end(), isspace);


    size_t pos = taskList.find(target);
    if (pos != std::string::npos)
    {
        std::string pid;
        for (size_t i = 0; i < 10; i++)
        {
            if (taskList[pos + target.length() + i] != 'N')
                pid += taskList[pos + target.length() + i];
            else
                return std::stoi(pid);
        }
        return 0;
    }
    else
    {
        return 0;
    }
}

