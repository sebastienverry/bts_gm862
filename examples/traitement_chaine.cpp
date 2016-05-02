#include <iostream>
#include <string>
#include <sstream>

using namespace std;


int main(void) {

  string s;
  string delimiter = ":";
  string line = "FIX! Id:GH3000 Imei:354333000000 Time:2016.04.23 10:47:30 Fix:48.12313213,2.77777 Sat:3 Op:20899 Cell:0AAA Sig_Lvl:99 Bat_Lvl:8;";
  string arr[11];
  string sql;
  int i = 0;
  stringstream ssin(line);


  while (ssin.good() && i < 11){
    ssin >> arr[i];
    ++i;
  }

  for(i=1; i < 11; i++) {
    s = arr[i];
    arr[i] = s.substr(s.find(delimiter) + 1,s.length());

  }

  /* Display SQL */
  sql = "INSERT INTO VALUES(";
  for(i = 0; i < 10; i++){
    sql += "'"  + arr[i] + "',";
  }
  sql += "'" + arr[10] + "');";

  cout << sql << endl;
}
