#pragma once

#include "C:\Program Files\MySQL\Connector C++ 8.0\include\jdbc\mysql_connection.h"
#include <C:\Program Files\MySQL\Connector C++ 8.0\include\jdbc\cppconn\driver.h>
#include <C:\Program Files\MySQL\Connector C++ 8.0\include\jdbc\cppconn\exception.h>
#include <C:\Program Files\MySQL\Connector C++ 8.0\include\jdbc\cppconn\resultset.h>
#include <C:\Program Files\MySQL\Connector C++ 8.0\include\jdbc\cppconn\statement.h>
#include <C:\Program Files\MySQL\Connector C++ 8.0\include\jdbc\cppconn\prepared_statement.h>

class database {

private:
	sql::Driver *driver;
	sql::Connection *con;
	sql::Statement *stmt;
	sql::ResultSet *res;
	sql::PreparedStatement *pstmt;


public:
						database();
	virtual			   ~database();

	virtual void		connect();
	virtual void		disconnect();
	virtual void		select();
	virtual void		insert(int id, double temperature, int humidity, double windSpeed);

};