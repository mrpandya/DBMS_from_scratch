<div align="center">

# DBMS made from SCRATCH
 
 [![](https://img.shields.io/badge/Made_with-C++-blue?style=for-the-badge&logo=c++)](https://cplusplus.com/ "C++")

### This is a **SQL based Database Management System**. This DBMS works IMPORT, SELECT, INSERT, DELETE queries.

The SQL queries can be run on the Command Line Interface.

</div>

## How to use:
- Clone the repo :
```
$ git clone https://github.com/mrpandya/mydb.git
```
- Go to the repo :
```
$ cd mydb
```
- To compile :

> GNU G++ compiler for C++ required
```
$ g++ -o driver driver.cpp
```
- To execute :
> Compiled version for linux version has already been added. You can directly run the executable file without compiling
```
$ ./driver
```


### Syntax

#### IMPORT Query

	Import <file_name>.csv;

#### SELECT Query
	 Select * from <table_name> [Where] [column_name] [operation] [value];
  
	 
  - OPTION
  
		 WHERE => It can be used only on any one column.
		 OPERATION => Valid operations are {=, !=, >, <, <=, >=}

#### INSERT Query
	 Insert into <table_name> values (data...);
  
  
  - DESCRIPTION
  
		 DATA => It is comma separated string of the data to be inserted. DO NOT leave a space in the paranthesis.

#### DELETE Query
	 Delete from <table_name> [Where] [column_name] [operation] [value];
  
  
  - OPTION
 
		 WHERE => It can be used only on any one column.
		 OPERATION => Valid operations are {=, !=, >, <, <=, >=}

#### The following code has been tested and executed on Linux.

 #### This project still has scope of development, so you can also contribute to this Project as follows:
* [Fork](https://github.com/mrpandya/mydb) this Repository.
* Clone your Fork on a different branch:
	* `git clone -b <name-of-branch> https://github.com/mrpandya/mydb.git`
* After adding any feature:
	* Goto your fork and create a pull request.
	* Your modifications will be  tested and the changes will be merged.

---
<h3 align="center"><b>Developed with :heart: by <a href="https://github.com/mrpandya">Manan Pandya</a> .</b></h1>


 
