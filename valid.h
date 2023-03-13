#include <iostream>
using namespace std;

// validates for integer input
int getInteger(string prompt = "Enter integer: ") {
    int num = 0;
    cout << prompt;
    cin >> num;
    while (!cin || cin.peek()!= '\n') {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid integer." << endl;
        cout << prompt;
        cin >> num;
    }
    cin.get();
    return num;
}

// validates for float input
float getFloat(string prompt = "Enter float: ") {
    float num = 0;
    cout << prompt;
    cin >> num;
    while (!cin || cin.peek()!= '\n') {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid float." << endl;
        cout << prompt;
        cin >> num;
    }
    cin.get();
    return num;
}

//validates for string input
string getPhrase(string prompt = "Enter phrase: "){
  string phrase = "";
  cout << prompt;
  cin >> phrase;
  while (!cin || cin.peek()!= '\n'){
    cin.clear();
    cin.ignore(100, '\n');
    cout << "Invalid phrase." << endl;
    cout << prompt;
    cin >> phrase;
  }
  getline(cin, phrase);
  return phrase;
}


//validates for character intput
char getCharacter(string prompt = "Enter character: "){
  char character = '\0';
  cout << prompt;
  cin >> character;
  while (!cin || cin.peek()!= '\n'){
    cin.clear();
    cin.ignore(100, '\n');
    cout << "Invalid letter." << endl;
    cout << prompt;
    cin >> character;
  }
  return character;
}

//validates for double input
double getDouble(string prompt = "Enter double: ") {
    double num = 0;
    cout << prompt;
    cin >> num;
    while (!cin || cin.peek()!= '\n') {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid double." << endl;
        cout << prompt;
        cin >> num;
    }
    cin.get();
    return num;
}
