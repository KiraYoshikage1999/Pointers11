#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <ctime>
#include <string.h>

using namespace std;

#include "ArreyFunction.h"



void main() {
    int amountOfBooks = 4;
    char** str = new char* [amountOfBooks];

    for (int i = 0; i < amountOfBooks; i++) {
        str[i] = new char[12];
        cout << "Enter a name of book: ";
        cin.getline(str[i], 12);
    }

    while (true) {
        cout << "1 - Add a book\n2 - Rename book\n3 - Delete book\n4 - Exit application\n5 - Show all books" << endl    ;
        int result;
        cin >> result;
        cin.ignore();

        if (result == 1) {
            AddbookFunc(amountOfBooks , str);
            /*char** tempArr = new char* [amountOfBooks];
            for (int i = 0; i < amountOfBooks; i++) {
                tempArr[i] = new char[strlen(str[i]) + 1];
                for (int j = 0; j < strlen(str[i]) + 1; j++) {
                    tempArr[i][j] = (char)str[i][j];
                }

                delete[] str[i];
                str[i] = nullptr;
            }

            delete[] str;
            str = nullptr;

            amountOfBooks++;

            str = new char* [amountOfBooks];

            for (int i = 0; i < amountOfBooks - 1; i++) {
                str[i] = new char[strlen(tempArr[i]) + 1];

                for (int j = 0; j < strlen(tempArr[i]) + 1; j++) {
                    str[i][j] = (char)tempArr[i][j];

                }
                delete[] tempArr[i];
                tempArr[i] = nullptr;
            }

            delete[] tempArr;
            tempArr = nullptr;

            str[amountOfBooks - 1] = new char[12];

            cout << "Add new book\n";

            cin.getline(str[amountOfBooks - 1], 12);*/

        }
        else if (result == 3) {
            if (amountOfBooks - 1 < 0) {
                cout << "Size of array can't be less than zero\n";
                continue;
            }
            cout << "Enter an index of book: ";
            int tempIndex;
            cin >> tempIndex;
            cin.ignore();

            while (tempIndex < 0 || tempIndex > amountOfBooks - 1) {
                cout << "Enter an index of book: ";
                cin >> tempIndex;
                cin.ignore();
            }

            char** tempArr = new char* [amountOfBooks - 1];
            int currentTemporaryIndex = 0;
            for (int i = 0; i < amountOfBooks; i++) {
                if (i == tempIndex) {
                    delete[] str[i];
                    str[i] = nullptr;
                    continue;
                }

                tempArr[currentTemporaryIndex] = new char[12];

                for (int j = 0; j < strlen(str[i]) + 1; j++) {
                    tempArr[currentTemporaryIndex][j] = (char)str[i][j];
                }
                currentTemporaryIndex++;
                delete[] str[i];
                str[i] = nullptr;
            }
            delete[] str;
            str = nullptr;

            amountOfBooks--;
            str = new char* [amountOfBooks];

            for (int i = 0; i < amountOfBooks; i++) {
                str[i] = new char[strlen(tempArr[i]) + 1];
                for (int j = 0; j < strlen(tempArr[i]) + 1; j++) {
                    str[i][j] = (char)tempArr[i][j];
                }

                delete[] tempArr[i];
                tempArr[i] = nullptr;
            }

            delete[] tempArr;
            tempArr = nullptr;
        }
        else if (result == 3) {
            if (amountOfBooks - 1 < 0) {
                cout << "Size of array can't be less than zero\n";
                continue;
            }
            cout << "Enter index of book: " << endl;
            int tempIndex;
            cin >> tempIndex;
            cin.ignore();

            while (tempIndex < 0 || tempIndex > amountOfBooks - 1) {
                cout << "Enter index of book: " << endl;
                cin >> tempIndex;
                cin.ignore();
            }

            char** tempArr = new char* [amountOfBooks - 1];
            int currentTemporaryIndex = 0;

            for (int i = 0; i < amountOfBooks; i++) {
				if (i == tempIndex) {
					delete[] str[i];
					str[i] = nullptr;
					continue;
				}

                tempArr[currentTemporaryIndex] = new char[12];

                for (int j = 0; j < strlen(str[i]) + 1; j++) {
                    tempArr[currentTemporaryIndex][j] = (char)str[i][j];
                }

                
                currentTemporaryIndex++;
                delete[] str[i];
                str[i] = nullptr;

            }
            amountOfBooks--;

            str = new char* [amountOfBooks];

            for (int i = 0; i < amountOfBooks; i++) {
                str[i] = new char[strlen(tempArr[i]) + 1];
                for (int j = 0; j < strlen(tempArr[i]) + 1; j++) {
                    str[i][j] = (char)tempArr[i][j];
                }

                delete[] tempArr[i];
                tempArr[i] = nullptr;
            }

            delete[] tempArr;
            tempArr = nullptr;
        }
        else if (result == 4) { 
            exit(0);
        }
        else if (result == 5) {
            PrintDynamicBooks(str, amountOfBooks);
        }
        else {
            cout << "Incorrect value\n";
        }

    }
}