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
    char query[500];
    while(true){
        cout << "___.db> ";
        cin.getline(query, 500);
        string str_query = (string)query;
        if(str_query == "\\q"){
            break;
        }
        else if(str_query == "\\h"){
            // TODO: add a menu for syntax
        }
        else if(checkImportQuery(str_query)){
            handleImportQuery(str_query,&table);
        }
        else if(checkSelectQuery(str_query)){
            handleSelectQuery(str_query);
        }
        else if(checkInsertQuery(str_query)){
            handleInsertQuery(str_query,&table);
        }
        else if(checkDeleteQuery(str_query)){
            handleDeleteQuery(str_query);
        }
        else{
            cout << "Error: Something wrong with your query. Please check the syntax." << endl;
        }
    }
    cout << "********************************" <<endl;
    cout << "*          THANK YOU :)        *" << endl;
    cout << "********************************" <<endl;
    return 0;
}