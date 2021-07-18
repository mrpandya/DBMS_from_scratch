#include "./utils/IndexList.h"
#include "./utils/IndexList.cpp"
#include "./constants/checkQuery.cpp"
#include "./constants/tokenizeQuery.cpp"
#include "./utils/TableRecord.cpp"
#include "./utils/TableList.cpp"
#include "./src/import.cpp"
#include "./src/select.cpp"
#include "./src/insert.cpp"
#include "./src/delete.cpp"

int main(){
    cout << "Welcome to ____db" << endl;
    cout << "_____db v1.0.0" << endl;
    cout << "Enter \\h for help and \\q to quit." << endl;
    TableList table = TableList();
    handleImportQuery("Import manan.csv;",&table);
    handleInsertQuery("Insert into manan values (11,_manan,mrpan2017@gmail.com,pa);", &table);
    // handleDeleteQuery("Delete from manan where id > 5;");
    handleSelectQuery("Select * from manan where username = Test#2;");
    // handleDeleteQuery("Delete from manan where username = Test%4;");
    // handleSelectQuery("Select * from manan;");
    handleInsertQuery("Insert into manan values (12,test,test2021@gmail.com,lmao);", &table);
    // handleDeleteQuery("Delete from manan where email = haha420@gmail.com;");
    // handleSelectQuery("Select * from manan;");
    handleDeleteQuery("Delete from manan;");
    handleSelectQuery("Select * from manan;");
    return 0;
}