
void printEqualtoElement(string element, string columnName, string filename){
    // Print all the columns when the values are equal
    // Select * from <table name> where <column name> = <element>
    int offset = 0;
    while(true){
        try{
            TableRecord record = TableRecord(filename,offset);
            if (record.getPasswordLength() >= 15 ){
                break;
            }
            offset += record.getLength();
            if(!record.isDeleted()){
                if(columnName == "id" && record.getId() != stoi(element)){
                    continue;
                }
                else if(columnName == "username" && record.getUsername() != element){
                    continue;
                }
                else if(columnName == "password" && record.getPassword() != element){
                    continue;
                }
                else if(columnName == "email" && record.getEmail() != element){
                    continue;
                }
                record.testRecord();
            }
        }catch(string err){
            break;
        }
    }
    cout << "+----+---------------+-------------------------------+---------------+";
    cout << endl; 
    return;
}

void printNotEqualtoElement(string element, string columnName, string filename){
    // Print all the columns where the values are not equal
    // Select * from <table name> where <column name> != <element>
    int offset = 0;
    while(true){
        try{
            TableRecord record = TableRecord(filename,offset);
            if (record.getPasswordLength() >= 15 ){
                break;
            }
            offset += record.getLength();
            if(!record.isDeleted()){
                if(columnName == "id" && record.getId() == stoi(element)){
                    continue;
                }
                else if(columnName == "username" && record.getUsername() == element){
                    continue;
                }
                else if(columnName == "password" && record.getPassword() == element){
                    continue;
                }
                else if(columnName == "email" && record.getEmail() == element){
                    continue;
                }
                record.testRecord();
            }
        }catch(string err){
            break;
        }
    }
    cout << "+----+---------------+-------------------------------+---------------+";
    cout << endl; 
    return;
}

void printLessThanElement(string element, string columnName, string filename){
    // Print all the columns when the values are less than
    // Select * from <table name> where <column name> < <element>
    int offset = 0;
    while(true){
        try{
            TableRecord record = TableRecord(filename,offset);
            if (record.getPasswordLength() >= 15 ){
                break;
            }
            offset += record.getLength();
            if(!record.isDeleted()){
                if(columnName == "id" && record.getId() >= stoi(element)){
                    continue;
                }
                else if(columnName == "username" && record.getUsername() >= element){
                    continue;
                }
                else if(columnName == "password" && record.getPassword() >= element){
                    continue;
                }
                else if(columnName == "email" && record.getEmail() >= element){
                    continue;
                }
                record.testRecord();
            }
        }catch(string err){
            break;
        }
    }
    cout << "+----+---------------+-------------------------------+---------------+";
    cout << endl; 
    return;
}

void printGreaterThanElement(string element, string columnName, string filename){
    // Print all the columns when the values are greater than
    // Select * from <table name> where <column name> > <element>
    int offset = 0;
    while(true){
        try{
            TableRecord record = TableRecord(filename,offset);
            if (record.getPasswordLength() >= 15 ){
                break;
            }
            offset += record.getLength();
            if(!record.isDeleted()){
                if(columnName == "id" && record.getId() <= stoi(element)){
                    continue;
                }
                else if(columnName == "username" && record.getUsername() <= element){
                    continue;
                }
                else if(columnName == "password" && record.getPassword() <= element){
                    continue;
                }
                else if(columnName == "email" && record.getEmail() <= element){
                    continue;
                }
                record.testRecord();
            }
        }catch(string err){
            break;
        }
    }
    cout << "+----+---------------+-------------------------------+---------------+";
    cout << endl; 
    return;
}

void printLessThanOrEqualToElement(string element, string columnName, string filename){
    // Print all the columns when the values are less than or equal
    // Select * from <table name> where <column name> <= <element>
    int offset = 0;
    while(true){
        try{
            TableRecord record = TableRecord(filename,offset);
            if (record.getPasswordLength() >= 15 ){
                break;
            }
            offset += record.getLength();
            if(!record.isDeleted()){
                if(columnName == "id" && record.getId() > stoi(element)){
                    continue;
                }
                else if(columnName == "username" && record.getUsername() > element){
                    continue;
                }
                else if(columnName == "password" && record.getPassword() > element){
                    continue;
                }
                else if(columnName == "email" && record.getEmail() > element){
                    continue;
                }
                record.testRecord();
            }
        }catch(string err){
            break;
        }
    }
    cout << "+----+---------------+-------------------------------+---------------+";
    cout << endl; 
    return;
}

void printGreaterThanOrEqualToElement(string element, string columnName, string filename){
    // Print all the columns when the values are greater than or equal to
    // Select * from <table name> where <column name> >= <element>
    int offset = 0;
    while(true){
        try{
            TableRecord record = TableRecord(filename,offset);
            if (record.getPasswordLength() >= 15 ){
                break;
            }
            offset += record.getLength();
            if(!record.isDeleted()){
                if(columnName == "id" && record.getId() < stoi(element)){
                    continue;
                }
                else if(columnName == "username" && record.getUsername() < element){
                    continue;
                }
                else if(columnName == "password" && record.getPassword() < element){
                    continue;
                }
                else if(columnName == "email" && record.getEmail() < element){
                    continue;
                }
                record.testRecord();
            }
        }catch(string err){
            break;
        }
    }
    cout << "+----+---------------+-------------------------------+---------------+";
    cout << endl; 
    return;
}

void printAllElements(string filename){
    // Print all the rows
    // Select * from <table name>
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
    cout << "+----+---------------+-------------------------------+---------------+";
    cout << endl; 
    return;
}

void printAllColumnsHeader(){
    // Print all the column names in a tabluar form
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
    return;
}


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
            printAllColumnsHeader();
            printAllElements(filename);
        }
    }
    // WHERE keyword is present
    else{
        if (queryTokens[1] == "*"){
            // WHERE clause used on only one column
            if(queryTokens.size() < 9){
                if (queryTokens[5] == "id"){
                    // Where clause on column id
                    if (queryTokens[6] == "="){
                        // operation : equal to
                        printAllColumnsHeader();
                        printEqualtoElement(queryTokens[7],"id",filename);
                    }
                    else if (queryTokens[6] == "!="){
                        // operation : not equal to
                        printAllColumnsHeader();
                        printNotEqualtoElement(queryTokens[7],"id",filename);
                    }
                    else if (queryTokens[6] == "<"){
                        // operation : less than
                        printAllColumnsHeader();
                        printLessThanElement(queryTokens[7],"id",filename);
                    }
                    else if (queryTokens[6] == ">"){
                        // operation : greater than
                        printAllColumnsHeader();
                        printGreaterThanElement(queryTokens[7],"id",filename);
                    }
                    else if (queryTokens[6] == "<="){
                        // operation : less than or equal to
                        printAllColumnsHeader();
                        printLessThanOrEqualToElement(queryTokens[7],"id",filename);
                    }
                    else if (queryTokens[6] == ">="){
                        // operation : greater than or equal to
                        printAllColumnsHeader();
                        printGreaterThanOrEqualToElement(queryTokens[7],"id",filename);
                    }
                    else{
                        cout << "Error: Invalid operation. Expected operations : =, !=, >, <, >=, <=" << endl;
                        return;
                    }
                }
                else if (queryTokens[5] == "username"){
                    // Where clause on column username
                    if (queryTokens[6] == "="){
                        // operation : equal to
                        printAllColumnsHeader();
                        printEqualtoElement(queryTokens[7],"username",filename);
                    }
                    else if (queryTokens[6] == "!="){
                        // operation : not equal to
                        printAllColumnsHeader();
                        printNotEqualtoElement(queryTokens[7],"username",filename);
                    }
                    else if (queryTokens[6] == "<"){
                        // operation : less than
                        printAllColumnsHeader();
                        printLessThanElement(queryTokens[7],"username",filename);
                    }
                    else if (queryTokens[6] == ">"){
                        // operation : greater than
                        printAllColumnsHeader();
                        printGreaterThanElement(queryTokens[7],"username",filename);
                    }
                    else if (queryTokens[6] == "<="){
                        // operation : less than or equal to
                        printAllColumnsHeader();
                        printLessThanOrEqualToElement(queryTokens[7],"username",filename);
                    }
                    else if (queryTokens[6] == ">="){
                        // operation : greater than or equal to
                        printAllColumnsHeader();
                        printGreaterThanOrEqualToElement(queryTokens[7],"username",filename);
                    }
                    else{
                        cout << "Error: Invalid operation. Expected operations : =, !=, >, <, >=, <=" << endl;
                        return;
                    }
                }
                else if (queryTokens[5] == "email"){
                    // Where clause on column email
                    if (queryTokens[6] == "="){
                        // operation : equal to
                        printAllColumnsHeader();
                        printEqualtoElement(queryTokens[7],"email",filename);
                    }
                    else if (queryTokens[6] == "!="){
                        // operation : not equal to
                        printAllColumnsHeader();
                        printNotEqualtoElement(queryTokens[7],"email",filename);
                    }
                    else if (queryTokens[6] == "<"){
                        // operation : less than
                        printAllColumnsHeader();
                        printLessThanElement(queryTokens[7],"email",filename);
                    }
                    else if (queryTokens[6] == ">"){
                        // operation : greater than
                        printAllColumnsHeader();
                        printGreaterThanElement(queryTokens[7],"email",filename);
                    }
                    else if (queryTokens[6] == "<="){
                        // operation : less than or equal to
                        printAllColumnsHeader();
                        printLessThanOrEqualToElement(queryTokens[7],"email",filename);
                    }
                    else if (queryTokens[6] == ">="){
                        // operation : greater than or equal to
                        printAllColumnsHeader();
                        printGreaterThanOrEqualToElement(queryTokens[7],"email",filename);
                    }
                    else{
                        cout << "Error: Invalid operation. Expected operations : =, !=, >, <, >=, <=" << endl;
                        return;
                    }
                }
                else if (queryTokens[5] == "password"){
                    // Where clause on column password
                    if (queryTokens[6] == "="){
                        // operation : equal to
                        printAllColumnsHeader();
                        printEqualtoElement(queryTokens[7],"password",filename);
                    }
                    else if (queryTokens[6] == "!="){
                        // operation : not equal to
                        printAllColumnsHeader();
                        printNotEqualtoElement(queryTokens[7],"password",filename);
                    }
                    else if (queryTokens[6] == "<"){
                        // operation : less than
                        printAllColumnsHeader();
                        printLessThanElement(queryTokens[7],"password",filename);
                    }
                    else if (queryTokens[6] == ">"){
                        // operation : greater than
                        printAllColumnsHeader();
                        printGreaterThanElement(queryTokens[7],"password",filename);
                    }
                    else if (queryTokens[6] == "<="){
                        // operation : less than or equal to
                        printAllColumnsHeader();
                        printLessThanOrEqualToElement(queryTokens[7],"password",filename);
                    }
                    else if (queryTokens[6] == ">="){
                        // operation : greater than or equal to
                        printAllColumnsHeader();
                        printGreaterThanOrEqualToElement(queryTokens[7],"password",filename);
                    }
                    else{
                        cout << "Error: Invalid operation. Expected operations : =, !=, >, <, >=, <=" << endl;
                        return;
                    }
                }
                else{
                    cout << "Error : Column not found. Please try again." << endl;
                    return;
                }

            }
        }
    }


}