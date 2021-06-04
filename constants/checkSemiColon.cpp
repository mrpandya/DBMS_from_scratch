using namespace std;

string checkSemiColon(string query){
    // returns a substr if a ; is present else will return the query
    if(query[query.length()-1]!=';'){
        cout<<"Trailing ; is missing. I will add it for you this time, but you better add one next time!!!"<<endl;
        return query;
    }
    else return query.substr(0,query.length()-1);
}