
void deleteEqualtoElement(string element, string columnName, string filename){
    // Delete all the columns when the values are equal
    // Delete from <table name> where <column name> = <element>
    int offset = 0;
    while(true){
        try{
            TableRecord record = TableRecord(filename,offset);
            if (record.getPasswordLength() >= 15 ){
                break;
            }
            if(!record.isDeleted()){
                if(columnName == "id" && record.getId() != stoi(element)){
                    offset += record.getLength();
                    continue;
                }
                else if(columnName == "username" && record.getUsername() != element){
                    offset += record.getLength();
                    continue;
                }
                else if(columnName == "password" && record.getPassword() != element){
                    offset += record.getLength();
                    continue;
                }
                else if(columnName == "email" && record.getEmail() != element){
                    offset += record.getLength();
                    continue;
                }
                record.setDelete(true);
                record.updateToFile(filename,offset);
            }
            offset += record.getLength();
        }catch(string err){
            break;
        }
    }
    return;
}

void deleteNotEqualtoElement(string element, string columnName, string filename){
    // Delete all the columns where the values are not equal
    // Delete from <table name> where <column name> != <element>
    int offset = 0;
    while(true){
        try{
            TableRecord record = TableRecord(filename,offset);
            if (record.getPasswordLength() >= 15 ){
                break;
            }
            if(!record.isDeleted()){
                if(columnName == "id" && record.getId() == stoi(element)){
                    offset += record.getLength();
                    continue;
                }
                else if(columnName == "username" && record.getUsername() == element){
                    offset += record.getLength();
                    continue;
                }
                else if(columnName == "password" && record.getPassword() == element){
                    offset += record.getLength();
                    continue;
                }
                else if(columnName == "email" && record.getEmail() == element){
                    offset += record.getLength();
                    continue;
                }
                record.setDelete(true);
                record.updateToFile(filename,offset);
            }
            offset += record.getLength();
        }catch(string err){
            break;
        }
    } 
    return;
}

void deleteLessThanElement(string element, string columnName, string filename){
    // Delete all the columns when the values are less than
    // Delete from <table name> where <column name> < <element>
    int offset = 0;
    while(true){
        try{
            TableRecord record = TableRecord(filename,offset);
            if (record.getPasswordLength() >= 15 ){
                break;
            }
            if(!record.isDeleted()){
                if(columnName == "id" && record.getId() >= stoi(element)){
                    offset += record.getLength();
                    continue;
                }
                else if(columnName == "username" && record.getUsername() >= element){
                    offset += record.getLength();
                    continue;
                }
                else if(columnName == "password" && record.getPassword() >= element){
                    offset += record.getLength();
                    continue;
                }
                else if(columnName == "email" && record.getEmail() >= element){
                    offset += record.getLength();
                    continue;
                }
                record.setDelete(true);
                record.updateToFile(filename,offset);
            }
            offset += record.getLength();
        }catch(string err){
            break;
        }
    }
    return;
}

void deleteGreaterThanElement(string element, string columnName, string filename){
    // Delete all the columns when the values are greater than
    // Delete from <table name> where <column name> > <element>
    int offset = 0;
    while(true){
        try{
            TableRecord record = TableRecord(filename,offset);
            if (record.getPasswordLength() >= 15 ){
                break;
            }
            if(!record.isDeleted()){
                if(columnName == "id" && record.getId() <= stoi(element)){
                    offset += record.getLength();
                    continue;
                }
                else if(columnName == "username" && record.getUsername() <= element){
                    offset += record.getLength();
                    continue;
                }
                else if(columnName == "password" && record.getPassword() <= element){
                    offset += record.getLength();
                    continue;
                }
                else if(columnName == "email" && record.getEmail() <= element){
                    offset += record.getLength();
                    continue;
                }
                record.setDelete(true);
                record.updateToFile(filename,offset);
            }
            offset += record.getLength();
        }catch(string err){
            break;
        }
    }
    return;
}

void deleteLessThanOrEqualToElement(string element, string columnName, string filename){
    // delete all the columns when the values are less than or equal
    // Delete from <table name> where <column name> <= <element>
    int offset = 0;
    while(true){
        try{
            TableRecord record = TableRecord(filename,offset);
            if (record.getPasswordLength() >= 15 ){
                break;
            }
            if(!record.isDeleted()){
                if(columnName == "id" && record.getId() > stoi(element)){
                    offset += record.getLength();
                    continue;
                }
                else if(columnName == "username" && record.getUsername() > element){
                    offset += record.getLength();
                    continue;
                }
                else if(columnName == "password" && record.getPassword() > element){
                    offset += record.getLength();
                    continue;
                }
                else if(columnName == "email" && record.getEmail() > element){
                    offset += record.getLength();
                    continue;
                }
                record.setDelete(true);
                record.updateToFile(filename,offset);
            }
            offset += record.getLength();
            offset += record.getLength();
        }catch(string err){
            break;
        }
    }
    return;
}

void deleteGreaterThanOrEqualToElement(string element, string columnName, string filename){
    // delete all the columns when the values are greater than or equal to
    // delete from <table name> where <column name> >= <element>
    int offset = 0;
    while(true){
        try{
            TableRecord record = TableRecord(filename,offset);
            if (record.getPasswordLength() >= 15 ){
                break;
            }
            if(!record.isDeleted()){
                if(columnName == "id" && record.getId() < stoi(element)){
                    offset += record.getLength();
                    continue;
                }
                else if(columnName == "username" && record.getUsername() < element){
                    offset += record.getLength();
                    continue;
                }
                else if(columnName == "password" && record.getPassword() < element){
                    offset += record.getLength();
                    continue;
                }
                else if(columnName == "email" && record.getEmail() < element){
                    offset += record.getLength();
                    continue;
                }
                record.setDelete(true);
                record.updateToFile(filename,offset);
            }
            offset += record.getLength();
        }catch(string err){
            break;
        }
    }
    return;
}

void deleteAllElements(string filename){
    // delete all the rows
    // Delete from <table name>
    int offset = 0;
    while(true){
        try{
            TableRecord record = TableRecord(filename,offset);
            if (record.getPasswordLength() >= 15 ){
                break;
            }
            if(!record.isDeleted()){
                record.setDelete(true);
                record.updateToFile(filename,offset);
            }
            offset += record.getLength();
        }catch(string err){
            break;
        }
    }
    return;
}

void handleDeleteQuery(string query){
    vector<string> queryTokens;
    fstream file;
    query = checkSemiColon(query);
    if(!checkDeleteQuery(query)){
        cout << "Something wrong with your query. Please check the syntax and try again." << endl;
        return;
    }
    queryTokens = tokenizeString(query);
    
    if(queryTokens.size() < 3){
        cout << "Incomplete command. Try again." << endl;
        return;
    }

    string filename = queryTokens[2].append(".db");

    if(access( (&filename)->c_str(), F_OK ) == -1){
        cout << "Error: database hasn't been initialized. Please initialize the database using the import query." << endl;
        return;
    }

    if(queryTokens.size() == 3){
        // delete all the records
        deleteAllElements(filename);
        cout << "Records deleted successfully !!!" << endl;
        return;
    }
    if(queryTokens.size() < 8){
        if (queryTokens[4] == "id"){
            // Where clause on column id
            if (queryTokens[5] == "="){
                // operation : equal to
                deleteEqualtoElement(queryTokens[6],"id",filename);
            }
            else if (queryTokens[5] == "!="){
                // operation : not equal to
                deleteNotEqualtoElement(queryTokens[6],"id",filename);
            }
            else if (queryTokens[5] == "<"){
                // operation : less than
                deleteLessThanElement(queryTokens[6],"id",filename);
            }
            else if (queryTokens[5] == ">"){
                // operation : greater than
                deleteGreaterThanElement(queryTokens[6],"id",filename);
            }
            else if (queryTokens[5] == "<="){
                // operation : less than or equal to
                deleteLessThanOrEqualToElement(queryTokens[6],"id",filename);
            }
            else if (queryTokens[5] == ">="){
                // operation : greater than or equal to
                deleteGreaterThanOrEqualToElement(queryTokens[6],"id",filename);
            }
            else{
                cout << "Error: Invalid operation. Expected operations : =, !=, >, <, >=, <=" << endl;
                return;
            }
        }
        else if (queryTokens[4] == "username"){
            // Where clause on column username
            if (queryTokens[5] == "="){
                // operation : equal to
                deleteEqualtoElement(queryTokens[6],"username",filename);
            }
            else if (queryTokens[5] == "!="){
                // operation : not equal to
                deleteNotEqualtoElement(queryTokens[6],"username",filename);
            }
            else if (queryTokens[5] == "<"){
                // operation : less than
                deleteLessThanElement(queryTokens[6],"username",filename);
            }
            else if (queryTokens[5] == ">"){
                // operation : greater than
                deleteGreaterThanElement(queryTokens[6],"username",filename);
            }
            else if (queryTokens[5] == "<="){
                // operation : less than or equal to
                deleteLessThanOrEqualToElement(queryTokens[6],"username",filename);
            }
            else if (queryTokens[5] == ">="){
                // operation : greater than or equal to
                deleteGreaterThanOrEqualToElement(queryTokens[6],"username",filename);
            }
            else{
                cout << "Error: Invalid operation. Expected operations : =, !=, >, <, >=, <=" << endl;
                return;
            }
        }
        else if (queryTokens[4] == "email"){
            // Where clause on column email
            if (queryTokens[5] == "="){
                // operation : equal to
                deleteEqualtoElement(queryTokens[6],"email",filename);
            }
            else if (queryTokens[5] == "!="){
                // operation : not equal to
                deleteNotEqualtoElement(queryTokens[6],"email",filename);
            }
            else if (queryTokens[5] == "<"){
                // operation : less than
                deleteLessThanElement(queryTokens[6],"email",filename);
            }
            else if (queryTokens[5] == ">"){
                // operation : greater than
                deleteGreaterThanElement(queryTokens[6],"email",filename);
            }
            else if (queryTokens[5] == "<="){
                // operation : less than or equal to
                deleteLessThanOrEqualToElement(queryTokens[6],"email",filename);
            }
            else if (queryTokens[5] == ">="){
                // operation : greater than or equal to
                deleteGreaterThanOrEqualToElement(queryTokens[6],"email",filename);
            }
            else{
                cout << "Error: Invalid operation. Expected operations : =, !=, >, <, >=, <=" << endl;
                return;
            }
        }
        else if (queryTokens[4] == "password"){
            // Where clause on column password
            if (queryTokens[5] == "="){
                // operation : equal to
                deleteEqualtoElement(queryTokens[6],"password",filename);
            }
            else if (queryTokens[5] == "!="){
                // operation : not equal to
                deleteNotEqualtoElement(queryTokens[6],"password",filename);
            }
            else if (queryTokens[5] == "<"){
                // operation : less than
                deleteLessThanElement(queryTokens[6],"password",filename);
            }
            else if (queryTokens[5] == ">"){
                // operation : greater than
                deleteGreaterThanElement(queryTokens[6],"password",filename);
            }
            else if (queryTokens[5] == "<="){
                // operation : less than or equal to
                deleteLessThanOrEqualToElement(queryTokens[6],"password",filename);
            }
            else if (queryTokens[5] == ">="){
                // operation : greater than or equal to
                deleteGreaterThanOrEqualToElement(queryTokens[6],"password",filename);
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
    cout << "Records deleted successfully !!!" << endl;
    return;
}