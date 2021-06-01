#include "IndexList.h"
#include "../constants/DataTypes.h"
#include "../constants/checkSemiColon.h"

class Entry{

    private:
        string key;
        int value;
        int hash;

    public:
        Entry(){ 
            this->key = "";
            this->value = 0;
            this->hash = 0;
        }

        Entry(string key, int value, int hash){
            this->key = key;
            this->value = value;
            this->hash = hash;
        }

        string get_key(){ return this->key; }
        int get_value(){ return this->value; }
        int get_hash(){ return this->hash; }
        void set_key(string key) { this->key = key; }
        void set_value(int value) { this->value = value; }
        void set_hash(int hash) { this->hash = hash; }

};

class ChildList{
    
    public:
        // The length of the child list is 100,000
        Entry list[MAX_LENGTH] = { Entry() };

};

// TODO : Implement the read file method in the IndexList class.
class IndexList{

    private:
        vector<ChildList> ParentNode;
        int index;
        DataTypes dataType;

    public:

        IndexList(DataTypes dataType){
            this->index = 0;
            this->dataType = dataType;
        }

        int getIndex(){ return this->index; }

        vector<ChildList> getIndexList(){ return this->ParentNode; }

        static int* hashFunction(int value) {
            // param value : index to get the hash values
            // return : an array where 1st element is the parent hash and the 2nd element is the child hash
            static int hash[2];
            hash[0] = ceil(value/MAX_LENGTH);
            hash[1] = value%MAX_LENGTH;
            return hash;
        }

        void insert(string key, int value) {
            Entry entry =  Entry(key, value, this->index);
            int* hash = hashFunction(this->index++);
            if(hash[0]<this->ParentNode.size()){
                this->ParentNode[hash[0]].list[hash[1]] = entry;
                return;
            }
            ChildList child = ChildList();
            child.list[hash[1]] = entry;
            this->ParentNode.push_back(child);
            return;
        }

        void writeToFile(string filepath){
            // param filepath : string : path to the ndx file
            fstream file;
            file.open(filepath, ios::binary | ios::out);
            for(int i=0;i<this->index;i++){
                int* tempHash = hashFunction(i);
                file << getEntry(tempHash[0],tempHash[1]).get_key().length() << getEntry(tempHash[0],tempHash[1]).get_key();
                file << this->index;
                int temp = i;
                while(file && temp++ != this->index-1 ){
                    tempHash = hashFunction(temp);
                    file << getEntry(tempHash[0],tempHash[1]).get_value();
                }
            }
            file.close();
        }

        Entry getEntry(int parentHash, int childHash){
            return this->ParentNode[parentHash].list[childHash];
        }

        void updateEntryKey(int parentHash, int childHash, string key){
            this->ParentNode[parentHash].list[childHash].set_key(key);
            return;
        }

        void updateEntryValue(int parentHash, int childHash, int value){
            this->ParentNode[parentHash].list[childHash].set_value(value);
            return;
        }

};