#include "IndexList.h"


class Entry{

    private:
        string _key;
        int _value;
        int _hash;

        // previous is the hash of the previous and next is the hash of the next entry in the sorted order.
        int _previous;
        int _next;

    public:
        Entry(){ 
            this->_key = "";
            this->_value = 0;
            this->_hash = 0;
            this->_previous = -1;
            this->_next = -1;
        }

        Entry(string key, int value, int hash){
            this->_key = key;
            this->_value = value;
            this->_hash = hash;
            this->_previous = -1;
            this->_next = -1;
        }

        string get_key(){ return this->_key; }
        int get_value(){ return this->_value; }
        int get_hash(){ return this->_hash; }
        int get_next(){ return this->_next; }
        int get_previous(){ return this->_previous; }
        void set_key(string key) { this->_key = key; }
        void set_value(int value) { this->_value = value; }
        void set_hash(int hash) { this->_hash = hash; }
        void set_next(int next) { this->_next = next; }
        void set_previous(int previous) { this->_previous = previous; }

};

class ChildList{
    
    public:
        // The length of the child list is 100,000
        Entry list[MAX_LENGTH] = { Entry() };

};

// TODO : Implement the read file method in the IndexList class.
class IndexList{

    private:
        vector<ChildList> _parentNode;
        int _index;
        int _start;
        DataTypes _dataType;

    public:

        IndexList(DataTypes dataType){
            this->_index = 0;
            this->_dataType = dataType;
            this->_start = -1;
        }

        int getIndex(){ return this->_index; }

        vector<ChildList> getIndexList(){ return this->_parentNode; }

        static int* hashFunction(int value) {
            // param value : index to get the hash values
            // return : an array where 1st element is the parent hash and the 2nd element is the child hash
            static int hash[2];
            hash[0] = ceil(value/MAX_LENGTH);
            hash[1] = value%MAX_LENGTH;
            return hash;
        }
        
        // TODO : complete the sort method

        void sort(Entry element){
            // param element : the entry to be inserted in the sorted order
            if(this->_start == -1){
                this->_start = element.get_hash();
                return;
            }
            int *hash = hashFunction(this->_start);
            Entry temp_entry = this->_parentNode[hash[0]].list[hash[1]];
            if(temp_entry.get_next() == -1){
                if(temp_entry.get_key() > element.get_key()){
                    temp_entry.set_previous(element.get_hash());
                    element.set_next(temp_entry.get_hash());
                    int *element_hash = hashFunction(element.get_hash());
                    this->_parentNode[element_hash[0]].list[element_hash[1]] = element;
                    this->_start = element.get_hash();
                    cout << this->_parentNode[element_hash[0]].list[element_hash[1]].get_key() << endl;
                    return;
                }
                temp_entry.set_next(element.get_hash());
                element.set_previous(temp_entry.get_hash());
                int *element_hash = hashFunction(element.get_hash());
                cout << "element_hash = " << element_hash[0] << " " << element_hash[1] <<endl;
                this->_parentNode[element_hash[0]].list[element_hash[1]].set_previous(temp_entry.get_hash());
                this->_parentNode[hash[0]].list[hash[1]] = temp_entry;
                cout << this->_parentNode[hash[0]].list[hash[1]].get_next() << " " << this->_parentNode[element_hash[0]].list[element_hash[1]].get_previous() << endl;
                return;
            }
            int next = temp_entry.get_next();
            while(next != -1){
                next = temp_entry.get_next();
                int*next_hash = hashFunction(next);
                if (temp_entry.get_key() > element.get_key()){
                    if(this->_start == temp_entry.get_hash()){
                        this->_start = element.get_hash();
                        continue;
                    }
                    int temp_next = temp_entry.get_next();
                    int *hash = hashFunction(temp_entry.get_hash());
                    Entry next_entry = this->_parentNode[next_hash[0]].list[next_hash[1]];
                    temp_entry.set_next(element.get_hash());
                    next_entry.set_previous(element.get_hash());
                    element.set_previous(temp_entry.get_hash());
                    element.set_next(next_entry.get_hash());
                    this->_parentNode[hash[0]].list[hash[1]] = temp_entry;
                    this->_parentNode[next_hash[0]].list[next_hash[1]] = next_entry;
                    int *element_hash = hashFunction(element.get_hash());
                    this->_parentNode[element_hash[0]].list[element_hash[1]] = element;

                    cout << this->_parentNode[element_hash[0]].list[element_hash[1]].get_next() << endl;
                }
                temp_entry = this->_parentNode[next_hash[0]].list[next_hash[1]];
            }
        }

        void insert(string key, int value) {
            Entry entry =  Entry(key, value, this->_index);
            int *hash = hashFunction(this->_index);
            sort(entry);
            if(hash[0] < this->_parentNode.size()){
                this->_parentNode[hash[0]].list[hash[1]] = entry;
                this->_index++;
                return;
            }
            ChildList child = ChildList();
            child.list[hash[1]] = entry;
            this->_parentNode.push_back(child);
            this->_index++;
            return;
        }

        void print_sorted(){
            // int *hash = hashFunction(this->_start);
            // cout<<hash[0] << " "<<hash[1]<<endl;
            // Entry temp_entry = this->_parentNode[hash[0]].list[hash[1]];
            // while(temp_entry.get_next() != -1){
            //     cout<<temp_entry.get_key() <<endl;
            //     hash = hashFunction(temp_entry.get_next());
            //     temp_entry = this->_parentNode[hash[0]].list[hash[1]];
            // }
            for(int i = 0; i < this->_index; i++){
                int *hash = hashFunction(i);
                cout<<hash[0] << " "<<hash[1]<<endl;
                Entry temp_entry = this->_parentNode[hash[0]].list[hash[1]];
                cout << temp_entry.get_previous() << " "<<temp_entry.get_next() << endl;
            }
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
            return this->_parentNode[parentHash].list[childHash];
        }

        void updateEntryKey(int parentHash, int childHash, string key){
            this->_parentNode[parentHash].list[childHash].set_key(key);
            return;
        }

        void updateEntryValue(int parentHash, int childHash, int value){
            this->_parentNode[parentHash].list[childHash].set_value(value);
            return;
        }

};