#pragma once

#include "MySQLIncludes.h

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
	virtual void		insert(double temperature, int humidity);

};