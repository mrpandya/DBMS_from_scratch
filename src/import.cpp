#include "../utils/IndexList.cpp"
#include "../constants/checkQuery.cpp"
#include "../constants/tokenizeQuery.cpp"

void handleImportQuery(string query){
    vector<string> queryTokens;
    string data;
    fstream file;
    query = checkSemiColon(query);
    if (!checkImportQuery(query)){
        cout << "Something wrong with your query. Please check the syntax and try again." << endl;
        return;
    }
    queryTokens = tokenizeString(query);
    for(int i = 0; i < queryTokens.size(); i++){
        cout << queryTokens[i] << endl;
    }
    // TODO : make tablerecord
    if(queryTokens.size()==1){
        cout << "Incomplete command. Try again." << endl;
        return;
    }
    if(queryTokens[1].find(".csv", 0) == string::npos){
        cout << "Please enter a .csv file." << endl;
        return;
    }
    file.open(queryTokens[1], ios::in);
    if(!file){
        cout << "File not found. Try again." << endl;
        return;
    }
    // extra call for the column names in the csv file
    getline(file, data);
    IndexList id = IndexList(INT);
    IndexList username = IndexList(STRING);
    IndexList email = IndexList(STRING);
    IndexList password = IndexList(STRING);

    if(file.eof()){
        cout << "File is empty. Please import a file with data." << endl;
        return;
    }
    while(!file.eof()){
        getline(file, data);
        vector<string> row = tokenizeString(data,",");
        id.insert(row[0],4);
        username.insert(row[1],4);
        email.insert(row[2],4);
        password.insert(row[3],4);
        cout<<row[0]<<" "<<row[1]<<" "<<row[2]<<" "<<row[3]<<" "<<row[4]<<endl;
    }
    id.writeToFile("../temp/id.ndx");
    username.writeToFile("../temp/username.ndx");
    email.writeToFile("../temp/email.ndx");
    password.writeToFile("../temp/password.ndx");
    file.close();
}