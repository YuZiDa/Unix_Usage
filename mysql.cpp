/*
    This code show how to use C++ MySQL
    /usr/local/mysql/bin/mysql -u root -p psw
    g++ -I /usr/local/mysql/include -L /usr/local/mysql/lib -l mysqlclient mysql.cpp -o mysql.out
*/

#include <iostream>
#include <string>
#include <mysql.h>

using namespace std;

int main()
{
    MYSQL mysql;
    MYSQL_RES *mysql_ret = NULL;
    MYSQL_ROW mysql_row = 0;
    string query;

    mysql_init(&mysql);
    if (mysql_real_connect(&mysql, "localhost", "root", "pwd", "Distributed_Database", 3306, NULL, 0))
    {
        query = "SELECT m_value FROM Key_Value_Table;";
        mysql_query(&mysql, query.c_str());
        mysql_ret = mysql_store_result(&mysql);
        if(mysql_ret != NULL)
        {
            int row_count = mysql_num_rows(mysql_ret);
            int field_count = mysql_num_fields(mysql_ret);
            cout << field_count << endl;
            
            if (row_count != 0)
            {
                while ((mysql_row = mysql_fetch_row(mysql_ret)))
                {
                    cout << mysql_row[0] << endl;
                }
            }
        }
    }
    else
    {
        cout << "MySQL Connection Error!" << endl;
    }

    mysql_close(&mysql);
}