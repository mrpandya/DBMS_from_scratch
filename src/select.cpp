

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
            int i = 0;
            while(i++<20){
                try{
                    // cout << "hello " << endl;
                    // TODO : seg fault debug the code to find the breaking point.
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