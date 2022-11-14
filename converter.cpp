#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string join(const vector<string>& StringedNumber){
    string result;
    for(const auto& str : StringedNumber) {
        result+=str;
    }
    return result;
}



int main(){
    long double inputNumber,fractional;
    int basis,number;
    string log;

    cout << "Enter number" << endl;
    cin >> inputNumber;
    string str1 = to_string(inputNumber);
    cout << "Enter new basis(0-36)"<< endl;
    cin >> basis;
    

    if(str1.find('.') != string::npos){
        number = stoi(str1.substr(0,str1.find('.')));
        fractional = stod(str1.substr(str1.find('.'),str1.size()-1));
    } else {
        return 0;
    }

    vector<string> charVector;
    vector<string> fractionalVector;
    vector<string> letters = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};

    while(number / basis > 0){
        string n12 = to_string(number % basis);
        if(number % basis > 9){
            n12 = letters[number % basis - 10];
        }
        charVector.push_back(n12);
        number= number / basis;
    }

    int stop = 0;
    while(fractional != 0 && stop != 20){
        stop++;
        str1 = to_string(fractional*basis);
        string wholePart = str1.substr(0,str1.find('.'));
        if(stoi(wholePart) > 9){
            wholePart = letters[stoi(wholePart)-10];
        }
        fractional = stod(str1.substr(str1.find('.'),str1.size()-1));
        fractionalVector.push_back(wholePart);
    }

    if((number % basis) > 9){
        int a = (number % basis) - 10;
        charVector.push_back(letters[a]);
    }else{
        charVector.push_back(to_string(number % basis));
    }
    reverse(charVector.begin(), charVector.end());

    cout << join(charVector)<<"."<<join(fractionalVector) << endl;
    return 0;
}