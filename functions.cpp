#include<iostream>
#include <fstream>
#include <vector>
#include "functions.h"
using namespace std;
// node

void mergeFiles(){
    int numOfInt1,numOfInt2;
    cout << "Enter the size of first integers array = ";
    cin >> numOfInt1;
    int *arr = new int[numOfInt1];

    for(int i=0;i<numOfInt1;i++){
        cout << "Enter the number at " << i+1 << " = ";
        cin >> arr[i];
    }

    cout << "Enter the size of second integers array = ";
    cin >> numOfInt2;
    int *brr  = new int[numOfInt2];

    for(int i=0;i<numOfInt2;i++){
        cout << "Enter the number at " << i+1 << " = ";
        cin >> brr[i];
    }

    ofstream put("q1-1.txt");
    if(put.fail()){
        cout << "File failed to open ! " << endl;
    }

    int j=0;
    while(j<numOfInt1){
        put << arr[j] << endl;
        j++;
    }

    put.close();

    ofstream put1("q1-2.txt");
    if(put1.fail()){
        cout << "File failed to open ! " << endl;
    }

    int b=0;
    while(b<numOfInt2){
        put1 << brr[b] << endl;
        b++;
    }

    put1.close();

    ifstream getObject("q1-1.txt");
    int lines = 0;

    string line;
    while(getline(getObject,line)){
        lines++;

    }

    getObject.close();

    ifstream getObject1("q1-2.txt");
    int lines1 = 0;

    string line1;
    while(getline(getObject1,line1)){
        lines1++;
    }

    getObject1.close();

    int *arr1 =new int[lines];

    ifstream gain("q1-1.txt");

    int k=0;
    string hazim;
    while(getline(gain,hazim))
    {
        arr1[k] = stoi(hazim);
        k++;

    }
    gain.close();

    int *brr1 =new int[lines1];

    ifstream gain1("q1-2.txt");

    int l=0;
    string hazim1;
    while(getline(gain1,hazim1))
    {
        brr1[l] = stoi(hazim1);
        l++;

    }
    gain1.close();


    int sumOfArrays;
    sumOfArrays = lines + lines1;

    int *mergeArray = new int[sumOfArrays];
    int i,a;
    for(i=0;i<lines;i++){
        mergeArray[i] = arr1[i];
    }
    a = i;
    for(i=0;i<lines1;i++)
    {
        mergeArray[a] = brr1[i];
        a++;
    }



    ofstream mergeFile("q1-3.txt");

    if(mergeFile.fail())
    {
        cout << "File failed to open.....";
    }

    int m=0;
    while(m<sumOfArrays)
    {
        mergeFile << mergeArray[m];
        m++;
    }
    mergeFile.close();

    cout << "Your entered integers in merged form = " << endl;
    ifstream mergeFileGet("q1-3.txt");

    string str;

    while(getline(mergeFileGet,str))
    {
        cout << str << endl;

    }
    mergeFileGet.close();

    delete [] arr;
    delete [] brr;
    delete [] arr1;
    delete [] brr1;

}

struct book{
    string Title;
    string Author;
    float Price;
};

void replaceSpaces(string& str){
    for(char& ch : str){
        if(ch == ' '){
            ch = '-';
        }
    }
}

void replaceDashes(string& str){
    for(char& ch : str){
        if(ch == '-'){
            ch = ' ';
        }
    }
}


void addBooksInStock(){

    const int books = 1000;
    book *arr = new book[books];

    int bookEntry;
    cout << "Enter the number of books you want to enter = ";
    cin >> bookEntry;
    cin.ignore();
    for(int i=0;i<bookEntry;i++){
        cout << "Enter the Name of Book = " << endl;
        getline(cin,arr[i].Title);
        cout << "Enter the Name of Author of " << arr[i].Title << " = ";
        getline(cin,arr[i].Author);
        cout << "Enter the Price of " << arr[i].Title << " = ";
        cin >> arr[i].Price;
        cin.ignore();

        replaceSpaces(arr[i].Title);
        replaceSpaces(arr[i].Author);
    }

    ofstream putBooks("library.txt",ios::app);
    if(putBooks.fail()){
        cout << "File failed to open....." << endl;
    }

    for(int j=0;j<bookEntry;j++){
        putBooks << arr[j].Title << endl;
    }

    putBooks.close();

    ofstream putAuthors("Authors.txt",ios::app);

    if(putAuthors.fail()){
        cout << "File Failed to open......" << endl;
    }

    for(int j=0;j<bookEntry;j++){
        putAuthors << arr[j].Author << endl;
    }

    putAuthors.close();

    ofstream putPrices("prices.txt",ios::app);

    if(putPrices.fail()){
        cout << "File failed to open....." << endl;
    }

    int i=0;
    while(i<bookEntry){
        putPrices << arr[i].Price << endl;
        i++;
    }

    putPrices.close();

    delete [] arr;
}

void getBooks() {
    const int books =1000;
    book arr[books];

    ifstream readLines("library.txt",ios::in);

    if(readLines.fail()){
        cout << "File Failed to open......" << endl;
    }

    int lines = 0;
    string readL;
    while(getline(readLines,readL)){
        arr[lines].Title = readL;
        replaceDashes(arr[lines].Title);
        lines++;
    }

    readLines.close();

    ifstream readAuthors("Authors.txt",ios::in);

    int currentLines = 0;
    while(getline(readAuthors,readL)){
        arr[currentLines].Author = readL;
        replaceDashes(arr[currentLines].Author);
        currentLines++;
    }

    readAuthors.close();

    ifstream readPrices("prices.txt");

    for(int j=0;j<lines;j++){
        readPrices >> arr[j].Price;
    }

    readPrices.close();

    cout << "------------------------------------------------------" << endl;
    cout << "|                      Library                       |" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "**Book**" << "\t\t\t\t\t" << "**Author**" << "\t\t\t\t\t" << "**Prices**" << endl;
    for(int k=0;k<lines;k++){
        cout << k+1 << " . " << arr[k].Title << "\t\t\t\t" << arr[k].Author << "\t\t\t\t" << arr[k].Price << endl;
    }

}

void changePrice(){
    const int books =1000;
    book arr[books];

    ifstream readLines("library.txt",ios::in);

    if(readLines.fail()){
        cout << "File Failed to open......" << endl;
    }

    int lines = 0;
    string readL;
    while(getline(readLines,readL)){
        arr[lines].Title = readL;
        replaceDashes(arr[lines].Title);
        lines++;
    }

    readLines.close();

    ifstream readAuthors("Authors.txt",ios::in);

    int currentLines = 0;
    while(getline(readAuthors,readL)){
        arr[currentLines].Author = readL;
        replaceDashes(arr[currentLines].Author);
        currentLines++;
    }

    readAuthors.close();

    ifstream readPrices("prices.txt");

    for(int j=0;j<lines;j++){
        readPrices >> arr[j].Price;
    }

    readPrices.close();

    cout << "------------------------------------------------------" << endl;
    cout << "|                      Library                       |" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "**Book**" << "\t\t\t\t\t" << "**Author**" << "\t\t\t\t\t" << "**Prices**" << endl;
    for(int k=0;k<lines;k++){
        cout << k+1 << " . " << arr[k].Title << "\t\t\t\t" << arr[k].Author << "\t\t\t\t" << arr[k].Price << endl;
    }

    int price_line;
    string newPrice;

    cout  << endl << "Enter the Book number = " << endl;
    cin >> price_line;

    cin.ignore();
    cout << "Enter the new price for Book number " << price_line << " = " << endl;
    getline(cin,newPrice);

    fstream read_price("prices.txt");

    if(read_price.fail()){
        cout << "Error opening in file." << endl;
    }

    vector<string> prices;
    string price;

    while(getline(read_price,price)){
        prices.push_back(price);
    }

    read_price.close();

    if(price_line > prices.size()) {
        cout << "The Book with " << price_line << " number is not find in file. " << endl;
    }

    ofstream writeNewPrice("prices.txt");

    if(writeNewPrice.fail()){
        cout << "File failed to open." << endl;
    }

    price_line--;

    for(int i=0;i<prices.size() ;i++){
        if(i!= price_line){
            writeNewPrice << prices[i] << endl;
        }
        else{
            writeNewPrice << newPrice << endl;
        }
    }

    writeNewPrice.close();
    cout << "The price of Book number " << price_line+1 << " has been changed to " << newPrice << "." << endl;
}


void deleteBookInInventory(){

    const int books =1000;
    book arr[books];

    ifstream readLines("library.txt",ios::in);

    if(readLines.fail()){
        cout << "File Failed to open......" << endl;
    }

    int lines = 0;
    string readL;
    while(getline(readLines,readL)){
        arr[lines].Title = readL;
        replaceDashes(arr[lines].Title);
        lines++;
    }

    readLines.close();

    ifstream readAuthors("Authors.txt",ios::in);

    int currentLines = 0;
    while(getline(readAuthors,readL)){
        arr[currentLines].Author = readL;
        replaceDashes(arr[currentLines].Author);
        currentLines++;
    }

    readAuthors.close();

    ifstream readPrices("prices.txt");

    for(int j=0;j<lines;j++){
        readPrices >> arr[j].Price;
    }

    readPrices.close();

    cout << "------------------------------------------------------" << endl;
    cout << "|                      Library                       |" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "**Book**" << "\t\t\t\t\t" << "**Author**" << "\t\t\t\t\t" << "**Prices**" << endl;
    for(int k=0;k<lines;k++){
        cout << k+1 << " . " << arr[k].Title << "\t\t\t\t" << arr[k].Author << "\t\t\t\t" << arr[k].Price << endl;
    }


    int book_number;
    cout << "Enter the book number you want to delete = " << endl;
    cin >> book_number;

    fstream deleteBook("library.txt");

    if(deleteBook.fail()){
        cout << "File Failed to open. " << endl;
    }

    vector <string> delete_books;
    string book;

    while(getline(deleteBook,book)){
        delete_books.push_back(book);
    }

    deleteBook.close();

    ofstream writeBook("library.txt");

    if(writeBook.fail()){
        cout << "File Failed to open. " << endl;
    }

    book_number--;
    for(int i=0;i<delete_books.size();i++){
        if(i!= book_number){
            writeBook << delete_books[i] << endl;
        }
    }

    writeBook.close();

    fstream deleteAuthor("Authors.txt");

    if(deleteAuthor.fail()){
        cout << "File Failed to open. " << endl;
    }

    vector <string> delete_authors;
    string author;

    while(getline(deleteAuthor,author)){
        delete_authors.push_back(author);
    }

    deleteAuthor.close();

    ofstream writeAuthors("Authors.txt");

    if(writeAuthors.fail()){
        cout << "File Failed to open. " << endl;
    }


    for(int i=0;i<delete_authors.size();i++){
        if(i!= book_number){
            writeAuthors << delete_authors[i] << endl;
        }
    }

    writeAuthors.close();

    fstream deletePrices("prices.txt");

    if(deletePrices.fail()){
        cout << "File Failed to open. " << endl;
    }

    vector <string> delete_prices;
    string price;

    while(getline(deletePrices,price)){
        delete_prices.push_back(price);
    }

    deletePrices.close();

    ofstream writePrices("prices.txt");

    if(writePrices.fail()){
        cout << "File Failed to open. " << endl;
    }

    for(int i=0;i<delete_prices.size();i++){
        if(i!= book_number){
            writePrices << delete_prices[i] << endl;
        }
    }

    writePrices.close();

    cout << "This Book has been successfully deleted from the inventory. " << endl;

}

void deleteAllInventory(){

    ofstream deleteBooks("library.txt",ios::out | ios::trunc);
    deleteBooks.close();

    ofstream deleteAuthors("Authors.txt",ios::out | ios::trunc);
    deleteAuthors.close();

    ofstream deletePrices("prices.txt",ios::out | ios::trunc);
    deletePrices.close();

    cout << "The Whole Inventory has been deleted." << endl;
}

void matrixSum(int rows,int cols,int rows1,int cols1,int **arr,int **arr2){

    if(rows == rows1 && cols == cols1){
        int **sum = new int*[rows];
        for(int i=0;i<rows;i++){
            sum[i] = new int[cols];
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                sum[i][j] = arr[i][j] + arr2[i][j];
            }
        }
        cout << "First Matrix ......." << endl;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }

        cout << "Second Matrix ......." << endl;
        for(int i=0;i<rows1;i++){
            for(int j=0;j<cols1;j++){
                cout << arr2[i][j] << " ";
            }
            cout << endl;
        }

        cout << "Sum of Both Matrices ........" << endl;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                cout << sum[i][j] << " ";
            }
            cout << endl;
        }

        for(int i=0;i<rows;i++){
            delete[] sum[i];
        }

        delete[] sum;
    }

    else{
        cout << "Sum is not possible. " << endl;
    }

}
void matrixSubtraction(int rows,int cols,int rows1,int cols1,int **arr,int **arr2){

    if(rows == rows1 && cols == cols1){
        int **sub = new int*[rows];
        for(int i=0;i<rows;i++){
            sub[i] = new int[cols];
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                sub[i][j] = arr[i][j] - arr2[i][j];
            }
        }
        cout << "First Matrix ......." << endl;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }


        cout << "Second Matrix ......." << endl;
        for(int i=0;i<rows1;i++){
            for(int j=0;j<cols1;j++){
                cout << arr2[i][j] << " ";
            }
            cout << endl;
        }

        cout << "Subtraction of Both Matrices ........" << endl;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                cout << sub[i][j] << " ";
            }
            cout << endl;
        }

        for(int i=0;i<rows;i++){
            delete[] sub[i];
        }

        delete[] sub;
    }

    else{
        cout << "Subtraction is not possible. " << endl;
    }

}

void matrixMultiplication(int rows,int cols,int rows1,int cols1,int **arr1,int **arr2){
    if(cols == rows1){
        int **mul = new int*[rows];
        for(int i=0;i<rows;i++){
            mul[i] = new int[cols1];
        }

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols1;j++) {
                int sum = 0;
                for (int k = 0; k < cols; k++) {
                    sum = sum + arr1[i][k] * arr2[k][j];
                }
                mul[i][j] = sum;
            }
        }

        cout << "First Matrix ......." << endl;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                cout << arr1[i][j] << " ";
            }
            cout << endl;
        }


        cout << "Second Matrix ......." << endl;
        for(int i=0;i<rows1;i++){
            for(int j=0;j<cols1;j++){
                cout << arr2[i][j] << " ";
            }
            cout << endl;
        }

        cout << endl << "Resultant Matrix ........" << endl;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols1;j++){
                cout << mul[i][j] << " ";
            }
            cout << endl;
        }

        for(int i=0;i<rows;i++){
            delete[] mul[i];
        }
        delete[] mul;
    }

    else{
        cout << "Multiplication of Matrix is not possible." << endl;
    }
}

void fileCompression(){
    int lines = 0;
    string line;
    ifstream getLines("normal.txt");

    while(getline(getLines,line)){
        lines++;
    }

    getLines.close();

    string *com = new string[lines];

    ifstream putFile("normal.txt");

    for(int i=0;i<lines;i++) {
        putFile >> com[i];
    }

    putFile.close();

    cout << "The Array ......." << endl;

    for(int i=0;i<lines;i++){
        cout << com[i] << " ";
    }

    cout << endl << endl << "The Frequency of Array Elements ........." << endl << endl ;

    int visited[lines];

    for(int i=0;i<lines;i++){
        int count = 0;
        if(visited[i] != 1){
            for(int j=0;j<lines;j++){
                if(com[i] == com[j]){
                    count++;
                    visited[j] = 1;
                }
            }
            if(count  > 1 || count == 1) {
                cout << com[i] << " appears " << count << " times. " << endl;
            }
            ofstream putData("compress.txt",ios::app);

            putData << count << " " << com[i] << endl;

            putData.close();

        }
    }


}
