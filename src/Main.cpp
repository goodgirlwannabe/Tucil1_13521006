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
    cout << "Input: ";
    int input, input2, input3;
    cin >> input;
    if (input == 1){
        keyboard_input();
        cout << "Do you want to play again?\n";
        cout << "1. Yes\n";
        cout << "2. No\n";
        cout << "Input: ";
        cin >> input2;
        if (input2 == 1){
            main();
        } else if (input2 == 2){
            cout << "Thank you for using this program\n";
        } else {
            cout << "Invalid input\n";
            cout << "Thank you for using this program\n";
        }
    } else if (input == 2){
        random_input();
        cout << "Do you want to play again?\n";
        cout << "1. Yes\n";
        cout << "2. No\n";
        cout << "Input: ";
        cin >> input2;
        if (input2 == 1){
            main();
        } else if (input2 == 2){
            cout << "Thank you for using this program\n";
        } else {
            cout << "Invalid input\n";
            cout << "Thank you for using this program\n";
        }
    } else {
        cout << "Invalid input\n";
        cout << "Do you want to try again?\n";
        cout << "1. Yes\n";
        cout << "2. No\n";
        cout << "Input: ";
        cin >> input3;
        if (input3 == 1){
            main();
        } else if (input3 == 2){
            cout << "Thank you for using this program\n";
        } else {
            cout << "Invalid input\n";
            cout << "Thank you for using this program\n";
        }
    }

    return 0;
}