#include "database.h"

database::database() {
}

database::~database() {
}

void database::connect() {
/* Create a connection */
		driver = get_driver_instance();
		con = driver->connect("databases.aii.avans.nl", "mnkruith", "Ab12345");
		/* Connect to the MySQL test database */
		con->setSchema("mnkruith_db");
}

void database::disconnect() {
	delete con;	//Delete database connection
}

void database::insert(double temperature, int humidity) {
	 /* '?' is the supported placeholder syntax */
	pstmt = con->prepareStatement("INSERT INTO tblsensorvalue(Temperature, Humidity) VALUES (?, ?)");
	pstmt->setDouble(1, temperature);	//Insert values to database using the query above
	pstmt->setInt(2, humidity);
	pstmt->executeUpdate();
	if(pstmt) delete pstmt;	//Delete query
}