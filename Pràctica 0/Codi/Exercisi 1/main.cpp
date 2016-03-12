/* 
 * File:   main.cpp
 * Author: Rubén Ballester Bautista
 * Oriol Rabasseda Alcaide
 *
 * Created on 25 / febrer / 2016, 12:17
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * Method: main
 * Acces: public
 * Returns: int
 * Parameter: int argc
 * Parameter: char** argv
 */

int main(int argc, char** argv) {
    string nom;
    float nota;
    
    cout << "Hi, what's your name?" << endl;
    cin >> nom;
    cout << "Hi, " + nom + " what mark do you expect to achieve in Data Structure?" << endl;
    cin >> nota;
    //cin.good() Comprova que la entrada introduida per l'usuari és del tipus desitjat
    if(cin.good()) {
        if (nota >= 9 && nota <= 10) {
            cout << "Wow, a " << nota << " isn't bad... I wish you luck";
        }
        else if (nota >= 7 && nota < 9) {
            cout << "A " << nota << " is quite good, but I think you could do more.";
        }
        else if (nota >= 6 && nota < 7) {
            cout << "Mmm, a " << nota << ". You can pass with this mark but be careful.";
        }
        else if (nota >= 5 && nota < 6) {
            cout << "Ufff, a " << nota << " is a low mark to be expected. Come on, you can expect a better mark";
        }
        else if (nota >= 0 && nota < 5) {
            cout << "What? A " << nota << " is a failure. You should try to pass this subject.";
        }
        else {
            cout << "A " << nota << "? This is not possible, you are lying.";
        }
        return 0;
    }
    else {
        cout << "The input that you've introduced isn't a number, please try again.";
    }
}

