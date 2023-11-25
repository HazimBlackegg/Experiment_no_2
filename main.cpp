#include<iostream>
#include "functions.h"
using namespace std;
int main()
{
    int choice;
    cout << "****Welcome to Assignment-13****" << endl;
    cout << "Enter numbers from 1 to 4 to run the respective question : " << endl;
    cin >> choice;

    if(choice == 1)
    {
        mergeFiles();
    }

    else if(choice == 2)
    {
        int choice1;
        while(true){
            cout << endl << endl;
            cout << "****Welcome to Book-Inventory****" << endl;
            cout << "1.-> Enter Books in Inventory." << endl;
            cout << "2.-> View the whole Inventory." << endl;
            cout << "3.-> Change the price of any book." << endl;
            cout << "4.-> Delete any book from inventory." << endl;
            cout << "5.-> Delete Whole Inventory." << endl;
            cout << "0.-> Press 0 to exit the programme." << endl;
            cin >> choice1;
            if(choice1 == 1){
                addBooksInStock();
            }
            else if(choice1 == 2){
                getBooks();
            }
            else if(choice1 == 3){
                changePrice();
            }
            else if(choice1 == 4){
                deleteBookInInventory();
            }
            else if(choice1 == 5){
                deleteAllInventory();
            }
            else if(choice1 == 0){
                break;
            }
        }

    }
    else if(choice == 3) {
        cout << endl;
            int rows, cols;
            cout << "Enter the number of rows for matrix-1 = ";
            cin >> rows;
            cout << "Enter the number of columns for matrix-1 = ";
            cin >> cols;
            int **arr1 = new int *[rows];
            for (int i = 0; i < rows; i++) {
                arr1[i] = new int[cols];
            }

            int rows1, cols1;
            cout << "Enter the number of rows for matrix-2 = ";
            cin >> rows1;
            cout << "Enter the number of columns for matrix-2 = ";
            cin >> cols1;
            int **arr2 = new int *[rows1];
            for (int i = 0; i < rows1; i++) {
                arr2[i] = new int[cols1];
            }

            cout << endl << "Enter the numbers for Matrix-1 ......." << endl << endl;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    cout << "Enter the number at [" << i + 1 << "," << j + 1 << "] = " << endl;
                    cin >> arr1[i][j];
                }
            }

            cout << endl << "Enter the numbers for Matrix-2 ......." << endl << endl;
            for (int i = 0; i < rows1; i++) {
                for (int j = 0; j < cols1; j++) {
                    cout << "Enter the number at [" << i + 1 << "," << j + 1 << "] = " << endl;
                    cin >> arr2[i][j];
                }
            }
            char ch;
            cout << "Enter the following for Matrix Operations = " << endl;
            cout << "+ .-> For Summation." << endl;
            cout << "- .-> For Subtraction." << endl;
            cout << "x .-> For Multiplication." << endl;
            cin >> ch;
            if (ch == '+') {
                matrixSum(rows, cols, rows1, cols1, arr1, arr2);
            }
            else if (ch == '-') {
                matrixSubtraction(rows, cols, rows1, cols1, arr1, arr2);
            }
            else if (ch == 'x') {
                matrixMultiplication(rows, cols, rows1, cols1, arr1, arr2);
            }

            for (int i = 0; i < rows; i++) {
                delete[] arr1[i];
            }
            delete[] arr1;

            for (int i = 0; i < rows1; i++) {
                delete[] arr2[i];
            }
            delete[] arr2;

    }
    else if(choice == 4){
        fileCompression();
    }

    return 0;
}
