void handleInsertQuery(string query, TableList *table){
    vector<string> queryTokens, row;
    fstream file;
    query = checkSemiColon(query);
    // if(!checkInsertQuery(query)){
    //     cout << "Something wrong with your query. Please check the syntax and try again." << endl;
    //     return;
    // }
    queryTokens = tokenizeString(query);
    if(queryTokens.size() < 5){
        cout << "Incomplete command. Try again." << endl;
        return;
    }
    string filename = queryTokens[2].append(".db");

    if(access( (&filename)->c_str(), F_OK ) == -1){
        cout << "Error: database hasn't been initialized. Please initialize the database using the import query." << endl;
        return;
    }
    if (queryTokens.size() > 5){
        cout << "Error: check the correct syntax for the INSERT Query." << endl;
        return;
    }
    row = tokenizeString(stripParanthesis(queryTokens[4]),",");
    if (row.size() != 4){
        cout << "Error: Incorrect data entry. Check the data format in the Query." << endl;
        return;
    }
    TableRecord record = TableRecord(stoi(row[0]), row[1], row[2], row[3]);
    record.writeToFile(filename);
    (*table).insertRecord(&record);
    cout << "Record inserted successfully !!!" << endl;
    return;
}