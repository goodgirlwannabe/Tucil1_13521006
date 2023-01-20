#include <iostream>
using namespace std;
#include "Function.h"

int main() {
    cout << "                     __                  ______   __            ___    __ __      " << endl;
    cout << "   /'\\_/`\\          /\\ \\                /\\__  _\\ /\\ \\__       /'___`\\ /\\ \\  \\     " << endl;
    cout << "  /\\      \\     __  \\ \\ \\/'\\    __      \\/_/\\ \\/ \\ \\ ,_\\     /\\_\\ /\\ \\\\ \\ \\  \\   " << endl;
    cout << "  \\ \\ \\__\\ \\  /'__`\\ \\ \\ , <  /'__`\\       \\ \\ \\  \\ \\ \\/     \\/_/// /__\\ \\ \\  \\_  " << endl;
    cout << "   \\ \\ \\_/\\ \\/\\ \\L\\.\\_\\ \\ \\`\\/\\  __/        \\_\\ \\__\\ \\ \\_       // /_\\ \\\\ \\__ ,__\\ " << endl;
    cout << "    \\ \\_ \\ \\_\\ \\__/. \\_\\ \\_\\ \\_\\ \\____\\     /\\_____\\\\ \\__\\     /\\______/ \\/_/\\_\\_/" << endl;
    cout << "     \\/_/ \\/_/\\/__/\\/_/ \\/_/\\/_/\\/____/     \\/_____/ \\/__/     \\/_____/     \\/_/  " << endl;
                                                                                
    cout << "                                                                            " << endl;

    
    cout << "Choose your input:\n";
    cout << "1. Keyboard\n";
    cout << "2. Random\n";

    int input;
    cin >> input;
    if (input == 1){
        keyboard_input();
    } else if (input == 2){
        random_input();
    } else {
        cout << "Invalid input\n";
    }

    return 0;
}