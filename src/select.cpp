

void handleSelectQuery(string query){
    vector<string> queryTokens;
    string data;
    fstream file;
    query = checkSemiColon(query);
    if (!checkSelectQuery(query)){
        cout << "Something wrong with your query. Please check the syntax and try again." << endl;
        return;
    }
    queryTokens = tokenizeString(query);

    if(queryTokens.size() < 4){
        cout << "Incomplete command. Try again." << endl;
        return;
    }
    string filename = queryTokens[3].append(".db");

    if(access( (&filename)->c_str(), F_OK ) == -1){
        cout << "Error: database hasn't been initialized. Please initialize the database using the import query." << endl;
        return;
    }
    // Where keyword is not present
    if(queryTokens.size() == 4){
        // printing all the records
        if (queryTokens[1] == "*"){
            int offset = 0;
            cout << "+----+---------------+-------------------------------+---------------+";
            cout << endl; 
            cout << "|";
            cout << setw(6/2) << setfill(' ') << "id" << setw(6/3) << "|";
            cout << setw(20/2) << setfill(' ') << "username" << setw(20/3) << "|";
            cout << setw((40/2)-1) << setfill(' ') << "email" << setw((40/3)) << "|";
            cout << setw(20/2) << setfill(' ') << "password" << setw(20/3) << "|";
            cout << endl;
            cout << "+----+---------------+-------------------------------+---------------+";
            cout << endl; 
            while(true){
                try{
                    TableRecord record = TableRecord(filename,offset);
                    if (record.getPasswordLength() >= 15 ){
                        break;
                    }
                    if(!record.isDeleted()){
                        record.testRecord();
                    }
                    offset += record.getLength();
                }catch(string err){
                    break;
                }
            }
            cout << "+----+---------------+-------------------------------+---------------+";
            cout << endl; 
            
        }
    }
    // WHERE keyword is present
    else{
        if (queryTokens[1] == "*"){
            // WHERE clause used on only one column
            if(queryTokens.size() < 9){
                // if ()
            }
            int offset = 0;
            while(true){
                try{
                    TableRecord record = TableRecord(filename,offset);
                    if (record.getPasswordLength() >= 15 ){
                        break;
                    }
                    if(!record.isDeleted()){
                        record.testRecord();
                    }
                    offset += record.getLength();
                }catch(string err){
                    break;
                }
            }
            
        }
    }


}