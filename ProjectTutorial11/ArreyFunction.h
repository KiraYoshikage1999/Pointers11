//
void AddbookFunc( int amountOfBooks , char** str) {
    char** tempArr = new char* [amountOfBooks];
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

    cin.getline(str[amountOfBooks - 1], 12);

    for (int i = 0; i < amountOfBooks; i++)
    {
        cout << str[i] << endl;
    }

}
//
//void RenameBookFunc(char** str, int size, int numBook) {
//	for (int i = 0; i < size; i++)
//	{
//		if (i == numBook) {
//			cout << "Enter new name of Book: \n";
//			cin >> str[i];
//
//		}
//		cout << str[i] << endl;
//	}
//}
//
//
//
//
//
void PrintDynamicBooks(char** str, int amountOfBooks) {
	for (int i = 0; i < amountOfBooks; i++)
	{
		cout << str[i] << endl;
	}
}