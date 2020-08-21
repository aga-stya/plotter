#include <iostream>
#include <fstream>

std::ofstream outfile;

void rampFunction(int amp) {
    int j = 0;
    bool reverse = false;
    for (auto i = 0; i < 50; i++) {
        if (!reverse) 
            j++;
        else
            j--;
        
        if (j > 25)
            reverse = true;
        std::cout << j * amp << "\n";
        outfile << j * amp << "\n";
    }
}

int main() {
    outfile.open("rampData.txt");
    for (auto i = 1; i <= 50; i++) {
        rampFunction(i);
    }
    outfile.close();
}