#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

// g++ -std=c++11 main.cpp -o main
// ./main

struct ProcessInfo {
    int gpu;
    int pid;
    std::string type;
    std::string name;
    std::string memUsage;
};

std::string formatString(const std::string& str, size_t width) {
    if (str.length() >= width) return str.substr(0, width);
    return str + std::string(width - str.length(), ' ');
}

void printDateTime() {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    char buffer[80];
    strftime(buffer, sizeof(buffer), "%a %b %d %H:%M:%S %Y", ltm);
    std::cout << buffer << std::endl;
}

int main() {
    printDateTime();
    std::cout << "+----------------------------------------------------------------------------------------+\n";
    std::cout << "| NVIDIA-SMI 551.86                  Driver Version: 551.86       CUDA Version: 12.4     |\n";
    std::cout << "|------------------------------------------+----------------------+----------------------|\n";
    std::cout << "| GPU  Name                        TCC/WDDM| Bus-Id        Disp.A | Volatile Uncorr. ECC |\n";
    std::cout << "| Fan  Temp  Perf             Pwr:Usage/Cap|         Memory-Usage | GPU-Util  Compute M. |\n";
    std::cout << "|==========================================+======================+======================|\n";
    std::cout << "|   0  NVIDIA GeForce GTX 1080     WDDM    | 00000000:00:00.0  On |                  N/A |\n";
    std::cout << "|  28%   37C    P8               11W / 180W|    512MiB / 8192MiB  |      0%      Default |\n";
    std::cout << "|                                          |                      |                  N/A |\n";
    std::cout << "+------------------------------------------+----------------------+----------------------+\n";

    std::vector<ProcessInfo> processes;
    processes.push_back((ProcessInfo){0, 1214, "C+G", "thisisthelongestprocessnameevertoexist.exe", "120MiB"});
    processes.push_back((ProcessInfo){0, 2546, "C+G", "dumdum2.exe", "80MiB"});
    processes.push_back((ProcessInfo){0, 3987, "C+G", "dumdum3.exe", "64MiB"});
    processes.push_back((ProcessInfo){0, 4102, "C+G", "dumdum4.exe", "32MiB"});
    processes.push_back((ProcessInfo){0, 5748, "C+G", "dumdum5.exe", "256MiB"});

    std::cout << "| Processes:                                                                             |\n";
    std::cout << "|  GPU    PID    Type  Process name                                      GPU Memory Usage|\n";
    std::cout << "|========================================================================================|\n";

    for (size_t i = 0; i < processes.size(); ++i) {
        ProcessInfo p = processes[i];
        std::cout << "|  "
                  << std::setw(3) << p.gpu << "  "
                  << std::setw(5) << p.pid << "   "
                  << std::setw(4) << p.type << "   "
                  << formatString(p.name, 35)
                  << "                  " << std::setw(6) << p.memUsage << "       |\n";
    }

    std::cout << "+----------------------------------------------------------------------------------------+\n";

    return 0;
}
