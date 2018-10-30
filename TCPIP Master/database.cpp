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
	delete con;
}

void database::select() {
	stmt = con->createStatement();
	res = stmt->executeQuery("SELECT * FROM tblSensorValue");
	while (res->next()) {
		std::cout << res->getDouble(4) << "|" << res->getInt(5) << "|" << res->getDouble(6) << "|" << res->getString(7).c_str() << std::endl;
	}
	delete stmt;
	delete res;
}

void database::insert(int id, double temperature, int humidity, double windSpeed) {
	 /* '?' is the supported placeholder syntax */

	int measurementID;

	pstmt = con->prepareStatement("INSERT INTO `tblmeasurementrecord`(`Weatherstations Contributed`) VALUES (?)");
	pstmt->setInt(1, id);
	pstmt->executeUpdate();

	stmt = con->createStatement();
	res = stmt->executeQuery("SELECT ID FROM tblmeasurementrecord ORDER BY ID DESC");
	if(res->next()) {
		measurementID = res->getInt(1);
	}

	pstmt = con->prepareStatement("INSERT INTO `tblsensorvalue`(`IDMeasurement`, `IDWeatherStation`, `Temperature`, `Humidity`, `Wind_Speed`, `Wind_Direction`) VALUES (?,?,?,?,?,'N')");
	pstmt->setInt(1, measurementID);
	pstmt->setInt(2, id);
	pstmt->setDouble(3, temperature);
	pstmt->setInt(4, humidity);
	pstmt->setDouble(5, windSpeed);
	pstmt->executeUpdate();
	if(pstmt) delete pstmt;
	if(stmt)  delete stmt;
	if(res)   delete res;
}