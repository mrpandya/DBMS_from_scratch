#include "IndexList.h"


class Entry{

    private:
        string _key;
        int _value;
        int _hash;

    public:
        Entry(){ 
            this->_key = "";
            this->_value = 0;
            this->_hash = 0;
        }

        Entry(string key, int value, int hash){
            this->_key = key;
            this->_value = value;
            this->_hash = hash;
        }

        string get_key(){ return this->_key; }
        int get_value(){ return this->_value; }
        int get_hash(){ return this->_hash; }
        void set_key(string key) { this->_key = key; }
        void set_value(int value) { this->_value = value; }
        void set_hash(int hash) { this->_hash = hash; }

};

class ChildList{
    
    public:
        // The length of the child list is 100,000
        Entry list[MAX_LENGTH] = { Entry() };

};

// TODO : Implement the read file method in the IndexList class.
class IndexList{

    private:
        vector<ChildList> _ParentNode;
        int _index;
        DataTypes _dataType;

    public:

        IndexList(DataTypes dataType){
            this->_index = 0;
            this->_dataType = dataType;
        }

        int getIndex(){ return this->_index; }

        vector<ChildList> getIndexList(){ return this->_ParentNode; }

        static int* hashFunction(int value) {
            // param value : index to get the hash values
            // return : an array where 1st element is the parent hash and the 2nd element is the child hash
            static int hash[2];
            hash[0] = ceil(value/MAX_LENGTH);
            hash[1] = value%MAX_LENGTH;
            return hash;
        }

        void insert(string key, int value) {
            Entry entry =  Entry(key, value, this->_index);
            int *hash = hashFunction(this->_index++);
            if(hash[0] < this->_ParentNode.size()){
                this->_ParentNode[hash[0]].list[hash[1]] = entry;
                return;
            }
            ChildList child = ChildList();
            child.list[hash[1]] = entry;
            this->_ParentNode.push_back(child);
            return;
        }

        void writeToFile(string filepath){
            // param filepath : string : path to the ndx file
            ofstream file (filepath, ios::binary);
            for(int i = 0; i < this->_index; i++){
                int *tempHash = hashFunction(i);
                int tempLen = getEntry(tempHash[0],tempHash[1]).get_key().length();
                file.write(
                    reinterpret_cast<char*>(&tempLen), 
                    sizeof(int)
                );
                file.write(
                    &(getEntry(tempHash[0],tempHash[1]).get_key())[0], 
                    sizeof(getEntry(tempHash[0],tempHash[1]).get_key())
                );
                file.write(
                    reinterpret_cast<char*>(&this->_index), 
                    sizeof(int)
                );
                int temp = i;
                while(file && temp++ != this->_index-1 ){
                    tempHash = hashFunction(temp);
                    int tempVal = getEntry(tempHash[0],tempHash[1]).get_value();
                    file.write(
                        reinterpret_cast<char*>(&tempVal), 
                        sizeof(tempVal)
                    );
                }
            }
            file.close();
        }

        Entry getEntry(int parentHash, int childHash){
            return this->_ParentNode[parentHash].list[childHash];
        }

        void updateEntryKey(int parentHash, int childHash, string key){
            this->_ParentNode[parentHash].list[childHash].set_key(key);
            return;
        }

        void updateEntryValue(int parentHash, int childHash, int value){
            this->_ParentNode[parentHash].list[childHash].set_value(value);
            return;
        }

};