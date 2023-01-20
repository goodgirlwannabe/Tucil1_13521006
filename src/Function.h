#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <string>
#include <algorithm>
#include <ctime>
#include <fstream>
using namespace std;

string c1, c2, c3, c4;
char op[4]= {'+', '-', '*', '/'};
vector <int> val;
vector <int> arr;
vector <string> s;
string hsl;

int convert_cards(string c){
    if (c == "A"){
        return 1;
    } else if (c == "J"){
        return 11;
    } else if (c == "Q"){
        return 12;
    } else if (c == "K"){
        return 13;
    } else if(c == "2" || c == "3" || c == "4" || c == "5" || c == "6" || c == " 7" || c == "8" || c == "9" || c == "10"){
        return stoi (c);
    }
    else {
        cout << "Invalid input\n";
        return 0;
    }
}

float convert_op(char op[], float left, float right){
    float ans;
    for (int i = 0; i < 4; i++){
        if (op[i] == '+'){
            ans = left + right;
        } else if (op[i] == '-'){
            ans = left - right;
        } else if (op[i] == '*'){
            ans = left * right;
        } else if (op[i] == '/'){
            ans = left / right;
        }return ans;
    }    
}

void bracket(vector <int> arr, char op[]){
    time_t start, end;
    start = clock();
    float ans1, ans2, ans3, ans4, ans5, ans6, ans7;
    int count = 0;
    vector <float> ans;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            for (int k = 0; k < 4; k++){
                for (int l = 0; l < 4; l++){
                    for (int m = 0; m < 4; m++){
                        for (int n = 0; n < 4; n++){
                            for (int o = 0; o < 4; o++){
                                if (i != j && i != k && i != l && j != k && j != l && k != l){
                                    // ((i op j) op k) op l
                                    ans1 = convert_op(&op[o], convert_op(&op[n], convert_op(&op[m], (float)arr[i], (float)arr[j]), (float)arr[k]), (float)arr[l]);
                                    if(abs(ans1-24) < 0.0001){
                                        hsl = "((" + to_string(arr[i]) + op[m] + to_string(arr[j]) + ")" + op[n] + to_string(arr[k]) + ")" + op[o] + to_string(arr[l]);
                                        s.push_back(hsl);
                                        count += 1;
                                    }
                                    // (i op (j op k)) op l
                                    ans2 = convert_op(&op[o], convert_op(&op[m], (float)arr[i], convert_op(&op[n], (float)arr[j], (float)arr[k])), (float)arr[l]);
                                    if(abs(ans2-24) < 0.0001){
                                        hsl = "(" + to_string(arr[i]) + op[m] + "(" + to_string(arr[j]) + op[n] + to_string(arr[k]) + "))" + op[o] + to_string(arr[l]);
                                        s.push_back(hsl);
                                        count += 1;
                                    }
                                    // i op ((j op k) op l)
                                    ans3 = convert_op(&op[m], (float)arr[i],convert_op(&op[o], convert_op(&op[n], (float)arr[j], (float)arr[k]), (float)arr[l]));
                                    if(abs(ans3-24) < 0.0001){
                                        hsl = to_string(arr[i]) + op[m] + "((" + to_string(arr[j]) + op[n] + to_string(arr[k]) + ")" + op[o] + to_string(arr[l]) + ")";
                                        s.push_back(hsl);
                                        count += 1;
                                    }
                                    // i op (j op (k op l))
                                    ans4 = convert_op(&op[m], (float)arr[i], convert_op(&op[n], (float)arr[j], convert_op(&op[o], (float)arr[k], (float)arr[l])));
                                    if(abs(ans4-24) < 0.0001){
                                        hsl = to_string(arr[i]) + op[m] + "(" + to_string(arr[j]) + op[n] + "(" + to_string(arr[k]) + op[o] + to_string(arr[l]) + "))";
                                        s.push_back(hsl);
                                        count += 1;
                                    }
                                    // (i op j) op (k op l)
                                    ans5 = convert_op(&op[n], convert_op(&op[m], (float)arr[i], (float)arr[j]), convert_op(&op[o], (float)arr[k], (float)arr[l]));
                                    if(abs(ans5-24) < 0.0001){
                                        hsl = "(" + to_string(arr[i]) + op[m] + to_string(arr[j]) + ")" + op[n] + "(" + to_string(arr[k]) + op[o] + to_string(arr[l]) + ")";
                                        s.push_back(hsl);
                                        count += 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } 
    if (count == 0){
        cout << "No solution\n";
    } else {
        cout << "There are " <<  count << " solutions\n";
        cout << "--------------------------------------------\n";
        for (int i = 0; i < s.size(); i++){
            cout << s[i] << endl;
        }
    }
    end = clock();
    cout << "--------------------------------------------\n" << "Time taken: ";
    cout << (end - start) / double(CLOCKS_PER_SEC) << " seconds\n";
}

void save_file(vector <string> s, string file_name){
    ofstream file("./test/" + file_name + ".txt");
    file << "Cards: " << val[0] << " " << val[1] << " " << val[2] << " " << val[3] << endl;
    file << "There are " <<  s.size() << " solutions\n";
    file << "--------------------------------------------\n";
    for (int i = 0; i < s.size(); i++){
        file << s[i] << endl;
    }
    file.close();
}

void keyboard_input(){
    string save;
    string file_name;
    cout << "Cards must be 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K, or A\n";
    cout << "Enter 4 cards: ";
    cin >> c1 >> c2 >> c3 >> c4 ;
    vector <string> cards = {c1, c2, c3, c4};
    bool found = false;
    for (int i = 0; i < 4; i++){
        if (cards[i] == "2" || cards[i] == "3" || cards[i] == "4" || cards[i] == "5" || cards[i] == "6" || cards[i] == "7" || cards[i] == "8" || cards[i] == "9" || cards[i] == "10" || cards[i] == "J" || cards[i] == "Q" || cards[i] == "K" || cards[i] == "A"){
        }
        else {
            cout << "Invalid input\n";
            cout << "Cards must be 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K, or A\n";
            found = true;
        }
    }
    if (found == false){
        val.push_back(convert_cards(c1));
        val.push_back(convert_cards(c2));
        val.push_back(convert_cards(c3));
        val.push_back(convert_cards(c4));
    }
    cout << "Cards: " << val[0] << " " << val[1] << " " << val[2] << " " << val[3] << endl;
    bracket(val, op);
    cout << "--------------------------------------------\n";
    cout << "Do you want to save the result to a file? (y/n): ";
    cin >> save;
    if (save == "y" || save == "Y"){
        cout << "Enter file name: ";
        cin >> file_name;
        save_file(s, file_name);
        cout << "Thank you for using this program\n";
    }
    else if( save == "n" || save == "N"){
        cout << "Thank you for using this program\n";
    }
    else {
        cout << "Invalid input\n";
        cout << "Thank you for using this program\n";
    }
}

void random_input(){
    string save;
    string file_name;
    srand(time(0));
    for (int i = 0; i < 4; i++){
        val.push_back(rand() % 13 + 1);
    }
    cout << "Cards: " << val[0] << " " << val[1] << " " << val[2] << " " << val[3] << endl;
    bracket(val, op);
        cout << "--------------------------------------------\n";
    cout << "Do you want to save the result to a file? (y/n): ";
    cin >> save;
    if (save == "y" || save == "Y"){
        cout << "Enter file name: ";
        cin >> file_name;
        save_file(s, file_name);
        cout << "Thank you for using this program\n";
    }
    else if( save == "n" || save == "N"){
        cout << "Thank you for using this program\n";
    }
    else {
        cout << "Invalid input\n";
        cout << "Thank you for using this program\n";
    }
}