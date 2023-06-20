#include <iostream>
#include <mysql.h>
#include <sstream>
#include<fstream>

using namespace std;

int qstate;
MYSQL* conn;
MYSQL_ROW row;
MYSQL_RES* res;

void MainPage();
void StaffRegistration();
void SalaryCalculation();
void Record();
void Paysalary();
void UpdateStaffDetail();
void DeleteStaffDetail();
void ViewStaffDetail();
void ViewSalaryDetail();
void SalaryPayment();

int main()
{
	system("title Connect C++ to MySQL");

	class db_response
	{
	public:
		static void ConnectionFunction()
		{
			conn = mysql_init(0);
			if (conn)
			{
				//cout << "Database Connected" << endl;
				system("cls");


			}
			else
				cout << "Failed to connect" << mysql_errno(conn) << endl;
			conn = mysql_real_connect(conn, "localhost", "root", "", "db_kindergarten", 3306, NULL, 0);
			if (conn)
			{
				//cout << "Database connect to mysql" << conn << endl;
				//system("pause");

			}
			else
				cout << "Failed to connect" << mysql_errno(conn) << endl;
		}
	};

	db_response::ConnectionFunction();

	char choice;
	string username, password;

	cout << "\n\t\t\t\t********************************************************************************* ";
	cout << "\n\t\t\t\t|                                                                               | ";
	cout << "\n\t\t\t\t|                       WELCOME TO KINDERGARTEN SYSTEM                          | ";
	cout << "\n\t\t\t\t|                                                                               | ";
	cout << "\n\t\t\t\t********************************************************************************* ";
	cout << "\n\t\t\t\t|                                                                               | ";
	cout << "\n\t\t\t\t|                                LOGIN PAGE                                     |";
	cout << "\n\t\t\t\t|                                                                               | ";
	cout << "\n\t\t\t\t********************************************************************************* ";
	cout << "\n\n\n\n\t\t\t\t\t\tEnter Your Username: ";
	cin >> username;
	cout << "\n\n\t\t\t\t\t\tEnter Your Password: ";
	cin >> password;

	qstate = mysql_query(conn, "SELECT * FROM adminlogin");

	if (!qstate)
	{
		res = mysql_store_result(conn);
		while ((row = mysql_fetch_row(res)))
		{
			if (username == row[0] && password == row[1])
			{
				cout << "\n\n\n\n\n\t\t\t\t********************************************************************************* ";
				cout << "\n\t\t\t\t|                    SUCCESFULLY LOGIN INTO THE SYSTEM !!                       |";
				cout << "\n\t\t\t\t*********************************************************************************";
				cout << endl;

				cout << "\n\n\t\t\t\tPress N to proceed to the Main Page or press any other key to Exit : ";
				cin >> choice;
				if (choice == 'N' || choice == 'n')
				{
					MainPage();
				}
				else
				{
					exit(0);
				}
			}
			else
			{
				cout << endl;
				cout << "\n\n\n\n\n\t\t\t\t********************************************************************************* ";
				cout << "\n\t\t\t\t|                    FAIL TO LOGIN INTO THE SYSTEM !!                           |";
				cout << "\n\t\t\t\t|                                                                               | ";
				cout << "\n\t\t\t\t|                 ATTENTION : WRONG USERNAME OR PASSWORD...                     | ";
				cout << "\n\t\t\t\t|                          PLEASE TRY AGAIN.                                    | ";
				cout << "\n\t\t\t\t|                                                                               | ";
				cout << "\n\t\t\t\t*********************************************************************************";
				cout << endl;

				cout << "\n\n\t\t\t\tPress Y to go Login Menu again or press N to Exit : ";
				cout << "\n\t\t\t\tDo You Wish to Try Again to Login ? [ Y | N ] : ";
				cin >> choice;
				if (choice == 'Y' || choice == 'y')
				{
					main();
				}
				else if (choice == 'N' || choice == 'n')
				{
					exit(0);
				}
				else
				{
					cout << "\n\n\t\tWrong Choice is Selected..." << endl;
				}
			}
		}
	}
	return 0;

}

void MainPage() {

	system("cls");

	int choose2;

	cout << "\n\t\t\t\t********************************************************************************* ";
	cout << "\n\t\t\t\t|                             Welcome Admin Portal                              | ";
	cout << "\n\t\t\t\t|  CHOOSE ANY ONE:                                                              | ";
	cout << "\n\t\t\t\t********************************************************************************* ";
	cout << "\n\t\t\t\t|          1.Staff Registration                                                 | ";
	cout << "\n\t\t\t\t|          2.Salary Calculation                                                 |";
	cout << "\n\t\t\t\t|          3.Update Staff Detail                                                |";
	cout << "\n\t\t\t\t|          4.Delete Staff Detail                                                |";
	cout << "\n\t\t\t\t|          5.View Staff Detail                                                  |";
	cout << "\n\t\t\t\t|          6.View Staff Salary Record                                           |";
	cout << "\n\t\t\t\t|          7.Salary Payment                                                     |";
	cout << "\n\t\t\t\t|          8.Exit															   |";
	cout << "\n\t\t\t\t*********************************************************************************";
	cout << "\n\n\n\n\t\t\t\t\t\tSelect Option >>";
	cin >> choose2;


	switch (choose2)
	{
	case 1: StaffRegistration();
		break;

	case 2: SalaryCalculation();
		break;

	case 3: UpdateStaffDetail();
		break;

	case 4: DeleteStaffDetail();
		break;

	case 5: ViewStaffDetail();
		break;

	case 6: ViewSalaryDetail();
		break;

	case 7:
		SalaryPayment();
		break;

	case 8:
		exit(0);
			break;
	}
}

void StaffRegistration() {

	system("cls");

	string Id;
	string icno;
	string username;
	string address;
	string phone;
	string dob;
	string ecn;
	string relation;
	string relationname;

	cin.ignore(1000, '\n');
	cout << "\n\t\t\tEnter Satff ID: ";
	getline(cin, Id);
	cout << "\n\t\t\tEnter Username: ";
	getline(cin, username);
	cout << "\n\t\t\tEnter Identitical Number: ";
	getline(cin, icno);
	cout << "\n\t\t\tEnter Address: ";
	getline(cin,address);
	cout << "\n\t\t\tEnter Personal Number: ";
	getline(cin, phone);
	cout << "\n\t\t\tEnter Emergency Contact Number: ";
	getline(cin, ecn);
	cout << "\n\t\t\tEnter Relation: ";
	getline(cin, relation);
	cout << "\n\t\t\tEnter Name(Above Realtion): ";
	getline(cin, relationname);




	string insert_query1 = "INSERT INTO staffregistration(StaffId,name,icno,address,phone,ecn,relation,relationname) VALUES('" + Id + "','" + username + "','" + icno + "','"+ address +"','" + phone + "','" + ecn + "','" + relation + "','" + relationname + "') ";
	const char* q = insert_query1.c_str();
	qstate = mysql_query(conn, q);

	if (!qstate)
	{

		cout << endl << "Data Added Sucessfully" << endl;
		MainPage();

	}
	else {

		cout << "Query execution problem!" << mysql_errno(conn) << endl;

	}


}

void SalaryCalculation() {

	system("cls");

	string Id;
	string staffid = "";
	bool HaveException = false;
	bool NotInDatabase = false;
	//string workingday;
	//string totalpayment;
	string month;
	string paid = "UnPaid";
	string paid1 = "paid";
	string name;
	string items[5000];
	int indexForId = 0;
	int hours;
	int days;
	int aa;
	int bb;
	int salary;
	int a;
	
	cout << "\n\t\t\tSalary Calculation";

	try
	{
		cout << endl;
		cout << "\n\t\t\tEnter Staff ID: ";
		cin >> staffid;
		cout << endl;
	}
	catch (exception e)
	{
		cout << "\n\t\t\tPlease enter the valid value" << endl;
		HaveException = true;
		//goto Exit;
	}

	cout << "\n\t\t\tEnter Month: ";
	cin >> month;

	cout << "\n\t\t\tEnter Total Working hours Per day: ";
	cin >> hours;

	cout<< "\n\t\t\tEnter Total Working Days: ";
	cin >> days;

	aa = hours * days;
	bb = 7 * aa;

	std::string workingday = std::to_string(aa);
	std::string totalpayment = std::to_string(bb);

	//std::cout << "The converted string is: " << strNumber << std::endl;


	cout << "\n\t\t\tEnter Total Working Day: "<< workingday <<endl;
	
	cout << "\n\t\t\tEnter Total Payment: " << totalpayment << endl;

	if (HaveException == false) {

		stringstream streamid;
		string strID;
		streamid << staffid;
		streamid >> strID;

		for (int i = 0; i < indexForId; i++) {

			if (strID != items[i]) {

				NotInDatabase = false;

			}
			else {

				NotInDatabase = false;


			}
		}

		if (NotInDatabase == false) {

			string findbyid_query = "SELECT * FROM staffregistration WHERE Staffid='" + strID + "'";
			const char* qi = findbyid_query.c_str();
			qstate = mysql_query(conn, qi);


			if (!qstate)
			{
				res = mysql_store_result(conn);
				cout << endl;
				while ((row = mysql_fetch_row(res)))
				{

					cout << "\n\t\t\tName:" << row[1] << endl;
					name = row[1];
					cout << "\n\t\t\tEnter 1: Record" << endl;
					cout << "\n\t\t\tEnter 2: Pay Salary" << endl;
					cout << "\n\t\t\tEnter 3: Exit" << endl;
					cin >> a;

				}

				if (a == 1) {
					string insert_query1 = "INSERT INTO salarycalculation(StaffId,name,workingday,totalpayment,month,paid) VALUES('" + strID + "','" + name + "','" + workingday + "','" + totalpayment + "','" + month + "','" + paid + "') ";
					const char* q = insert_query1.c_str();
					qstate = mysql_query(conn, q);

					if (!qstate)
					{

						cout << endl << "Data Added Sucessfully" << endl;
						MainPage();

					}
					else {

						cout << "Query execution problem!" << mysql_errno(conn) << endl;

					}

				}
				else if (a == 2) {
					string insert_query1 = "INSERT INTO salarycalculation(StaffId,name,workingday,totalpayment,month,paid) VALUES('" + strID + "','" + name + "','" + workingday + "','" + totalpayment + "','" + month + "','" + paid1 + "') ";
					const char* q = insert_query1.c_str();
					qstate = mysql_query(conn, q);

					if (!qstate)
					{

						cout << endl << "Data Added Sucessfully" << endl;
						MainPage();

					}
					else {

						cout << "Query execution problem!" << mysql_errno(conn) << endl;

					}

				}

				else {

					MainPage();

				}

			}

			else {

				cout << "Query Execution Problem" << mysql_errno(conn) << endl;

			}






		}
	}
	else {

		cout << "Not FOUND in database";
	}
	


	
	/*
	
	string findbyid_query = "SELECT name FROM staffregistration WHERE Staffid='" + Id + "'";
	const char* qi = findbyid_query.c_str();
	qstate = mysql_query(conn, qi);

	if (!qstate)
	{
		//cout << "\n\t\t\tName:" << row[0] << endl;

		res = mysql_store_result(conn);
		cout << endl;
		while ((row = mysql_fetch_row(res)))
		{

			cout << "Name:" << row[1] << endl;

			name = row[1];

			cout << "\n\t\t\tEnter 1: Record" << endl;
			cout << "\n\t\t\tEnter 2: Pay Salary" << endl;
			cout << "\n\t\t\tEnter 3: Exit" << endl;
			cin >> a;

		}
		
	}
	else {

		cout << "Query execution problem!" << mysql_errno(conn) << endl;

	}



	if (a == 1) {
		string insert_query1 = "INSERT INTO salarycalculation(StaffId,name,workingday,totalpayment,month,paid) VALUES('" + Id + "','" + name + "','" + workingday + "','" + totalpayment + "','" + month + "','" + paid + "') ";
		const char* q = insert_query1.c_str();
		qstate = mysql_query(conn, q);

		if (!qstate)
		{

			cout << endl << "Data Added Sucessfully" << endl;
			MainPage();

		}
		else {

			cout << "Query execution problem!" << mysql_errno(conn) << endl;

		}

	}
	else if (a == 2) {
		string insert_query1 = "INSERT INTO salarycalculation(StaffId,name,workingday,totalpayment,month,paid) VALUES('" + Id + "','" + name + "','" + workingday + "','" + totalpayment + "','" + month + "','" + paid1 + "') ";
		const char* q = insert_query1.c_str();
		qstate = mysql_query(conn, q);

		if (!qstate)
		{

			cout << endl << "Data Added Sucessfully" << endl;
			MainPage();

		}
		else {

			cout << "Query execution problem!" << mysql_errno(conn) << endl;

		}

	}

	else {

		MainPage();

	}
	
	
	*/
}

void UpdateStaffDetail() {

	system("cls");
	string staffid = "";
	string name = "";
	string icno = "";
	string address = "";
	string phone = "";
	string ecn = "";
	string relation = "";
	string relationname = "";
	string items[5000];
	int indexForId = 0;
	bool HaveException = false;
	bool NotInDatabase = false;

	//store nvariable
	string storeid;
	string storename;
	string storeic;
	string storeaddress;
	string storephone;
	string storeecn;
	string storerelation;
	string storerelationname;

	cout << "Update Student \n";

	qstate = mysql_query(conn, "SELECT * FROM staffregistration");
	if (!qstate)
	{

		res = mysql_store_result(conn);

		printf("---------------------------------------------------------------------------------------------------------------------------- \n");
		printf("|                                               LIST ALL STAFF                                                              | \n");
		printf("---------------------------------------------------------------------------------------------------------------------------- \n");
		printf("| %-25s | %-25s | %-15s |  %-10s  | %-10s | %-10s |%-10s | \n", "Name", "IC", "Address", "Phone", "ecn", "relation", "relation name");
		printf("---------------------------------------------------------------------------------------------------------------------------- \n");
		while ((row = mysql_fetch_row(res)))
		{
			printf("| %-25s | %-25s | %-15s |  %-10s  | %-10s | %-10s |%-10s | \n", row[1], row[2], row[3], row[4], row[5], row[6], row[7]);
			items[indexForId] = row[0];
			indexForId++;
		}
		printf("---------------------------------------------------------------------------------------------------------------------------- \n");

	}
	else {

		cout << "Query Execute Problem" << mysql_errno(conn) << endl;

	}

	try
	{
		cout << endl;
		cout << "Enter Staff ID: \n";
		cin >> staffid;
		cout << endl;
	}
	catch (exception e)
	{
		cout << "Please enter the valid value" << endl;
		HaveException = true;
		//goto Exit;
	}
	if (HaveException == false) {

		stringstream streamid;
		string strID;
		streamid << staffid;
		streamid >> strID;

		for (int i = 0; i < indexForId; i++) {

			if (strID != items[i]) {

				NotInDatabase = false;

			}
			else {

				NotInDatabase = false;


			}
		}

		if (NotInDatabase == false) {

			string findbyid_query = "SELECT * FROM staffregistration WHERE Staffid='" + strID + "'";
			const char* qi = findbyid_query.c_str();
			qstate = mysql_query(conn, qi);


			if (!qstate)
			{
				res = mysql_store_result(conn);
				cout << endl;
				while ((row = mysql_fetch_row(res)))
				{

					cout << "Name:" << row[1] << "\nIC:" << row[2] << "\nAddress:" << row[3] << "\nPhone:" << row[4] << "\nEcn:" << row[5] << "\nRelation:" << row[6] << "\nRelation Name:" << row[7] << endl << endl;
					//storeid = row[0];
					storename = row[1];
					storeic = row[2];
					storeaddress = row[3];
					storephone = row[4];
					storeecn = row[5];
					storerelation = row[6];
					storerelationname = row[7];

				}
			}

			else {

				cout << "Query Execution Problem" << mysql_errno(conn) << endl;

			}

			cin.ignore(1, '\n');

			cout << "Enter Staff Name(0 to not change): ";
			getline(cin, name);
			if (name == "0") {

				name = storename;

			}
			cout << "Enter Ic(0 to not change): ";
			getline(cin, icno);
			if (icno == "0") {

				icno = storeic;

			}
			cout << "Enter Address(0 to not change): ";
			getline(cin, address);
			if (address == "0") {

				address = storeaddress;

			}
			cout << "Enter Phone Number(0 to not change): ";
			getline(cin, phone);
			if (phone == "0") {

				phone = storephone;

			}
			cout << "Enter Ecn(0 to not change): ";
			getline(cin, ecn);
			if (ecn == "0") {

				ecn = storeecn;

			}

			cout << "Enter Relation(0 to not change): ";
			getline(cin, relation);
			if (relation == "0") {

				relation = storerelation;

			}
			cout << "Enter Relation Name(0 to not change): ";
			getline(cin, relationname);
			if (relationname == "0") {

				relationname = storerelationname;

			}

		}

		string update_query = "UPDATE staffregistration SET name = '" + name + "', icno = '" + icno + "', address = '" + address + "', phone = '" + phone + "', ecn = '" + ecn + "', relation = '" + relation + "', relationname='"+ relationname +"' WHERE Staffid ='" + strID + "'";
		//string update_query = "UPDATE studentrecord SET MATRIC =  '" + matricno + "', NAME = '"+ name +"', Reason = '" + reason +  "'WHERE STUD_ID = '" + strID + "' ";
		const char* qu = update_query.c_str();
		qstate = mysql_query(conn, qu);

		if (!qstate)
		{
			cout << endl << "Successfully saved in database" << endl;
			system("pause");
			MainPage();

		}
		else {

			cout << "Failed to update" << mysql_errno(conn) << endl;

		}

	}
	else {

		cout << "Not FOUND in database";
	}
}

void ViewStaffDetail() {


	system("cls");

	string items[5000];
	int indexForId = 0;
	string staffid;
	char choice;
	bool HaveException = false;
	bool NotInDatabase = false;

	cout << "\n\t\t\t\t********************************************************************************* ";
	cout << "\n\t\t\t\t|                             Staff Record                                      | ";
	cout << "\n\t\t\t\t********************************************************************************* ";
	cout << "\n\t\t\t\tEnter Staff Id:";
	cin >> staffid;


	if (HaveException == false) {

		stringstream streamid;
		string strID;
		streamid << staffid;
		streamid >> strID;

		for (int i = 0; i < indexForId; i++) {

			if (strID != items[i]) {

				NotInDatabase = false;
			}
			else {

				NotInDatabase = false;
			}
		}

		if (NotInDatabase == false) {

			string findbyid_query = "SELECT * FROM staffregistration WHERE Staffid='" + strID + "'";
			const char* qi = findbyid_query.c_str();
			qstate = mysql_query(conn, qi);


			if (!qstate)
			{
				res = mysql_store_result(conn);
				cout << endl;

				printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
				printf("|                                               INDIVIDUAL RECORD                                                                               |\n");
				printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
				printf("| %-25s | %-25s | %-15s |  %-10s  | %-10s | %-10s | %-10s | %-10s |\n", "StaffId", "Name", "Ic", "Address", "Phone", "Ecn", "Realtion", "Relation Name");
				printf("------------------------------------------------------------------------------------------------------------------------------------------------ \n");
				while ((row = mysql_fetch_row(res)))
				{
					printf("| %-25s | %-25s | %-15s |  %-10s  | %-10s | %-10s | %-10s | %-10s | \n", row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7]);
				}
				printf("------------------------------------------------------------------------------------------------------------------------------------------------ \n");


				cout << "\n\n\t\t\t\tPress N to proceed to the Main Page or press any other key to Exit : ";
				cin >> choice;
				if (choice == 'N' || choice == 'n')
				{
					MainPage();
				}
				else
				{
					exit(0);
				}


			}

			else {

				cout << "Query Execution Problem" << mysql_errno(conn) << endl;

			}

		}

	}
	else {

		cout << "Not FOUND in database";
	}

}

void ViewSalaryDetail() {


	system("cls");

	string items[5000];
	int indexForId = 0;
	string staffid;
	char choice;
	bool HaveException = false;
	bool NotInDatabase = false;

	cout << "\n\t\t\t\t********************************************************************************* ";
	cout << "\n\t\t\t\t|                             Staff Record                                      | ";
	cout << "\n\t\t\t\t********************************************************************************* ";
	cout << "\n\t\t\t\tEnter Staff Id :";
	cin >> staffid;


	if (HaveException == false) {

		stringstream streamid;
		string strID;
		streamid << staffid;
		streamid >> strID;

		for (int i = 0; i < indexForId; i++) {

			if (strID != items[i]) {

				NotInDatabase = false;
			}
			else {

				NotInDatabase = false;
			}
		}

		if (NotInDatabase == false) {

			string findbyid_query = "SELECT * FROM salarycalculation WHERE Staffid='" + strID + "'";
			const char* qi = findbyid_query.c_str();
			qstate = mysql_query(conn, qi);


			if (!qstate)
			{
				res = mysql_store_result(conn);
				cout << endl;

				printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
				printf("|                                               INDIVIDUAL RECORD                                                                               |\n");
				printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
				printf("| %-25s | %-25s | %-15s |  %-10s  | %-10s | %-10s |\n", "StaffId","Staff Name", "working Day", "Total Payment", "Month", "Paid");
				printf("------------------------------------------------------------------------------------------------------------------------------------------------ \n");
				while ((row = mysql_fetch_row(res)))
				{
					printf("| %-25s | %-25s | %-15s |  %-10s  | %-10s | %-10s | \n", row[0], row[1], row[2], row[3], row[4], row[5]);
				}
				printf("------------------------------------------------------------------------------------------------------------------------------------------------ \n");


				cout << "\n\n\t\t\t\tPress N to proceed to the Main Page or press any other key to Exit : ";
				cin >> choice;
				if (choice == 'N' || choice == 'n')
				{
					MainPage();
				}
				else
				{
					exit(0);
				}


			}

			else {

				cout << "Query Execution Problem" << mysql_errno(conn) << endl;

			}

		}

	}
	else {

		cout << "Not FOUND in database";
	}

}

void DeleteStaffDetail() {

	system("cls");

	string name = "";
	string reason = "";
	string day = "";
	string month = "";
	string year = "";
	string amount = "";
	string payment = "";
	char choice;
	string items[5000];
	int indexForId = 0;
	string staffid;
	bool HaveException = false;
	bool NotInDatabase = false;


	cout << "DELETE STAFF RECORD \n";

	qstate = mysql_query(conn, "SELECT * FROM  stafflogin");
	if (!qstate)
	{

		res = mysql_store_result(conn);

		printf("------------------------------------------------------------ \n");
		printf("|                       LIST ALL STAFF RECORD              | \n");
		printf("-------------------------------------------------------------\n");
		printf("| %-10s | %-25s | %-15s || %-10s | %-25s | %-15s | %-15s | \n", "Id", "Name", "IC","Address","Phone","Ecn","Relation","Realtion Name");
		printf("-------------------------------------------------------------\n");
		while ((row = mysql_fetch_row(res)))
		{
			printf("| %-10s | %-25s | %-15s || %-10s | %-25s | %-15s | %-15s | \n", row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7]);
			items[indexForId] = row[0];
			indexForId++;
		}
		printf("-------------------------------------------------------------\n");


	}
	else {

		cout << "Query Execute Problem" << mysql_errno(conn) << endl;

	}

	try
	{
		cout << endl;
		cout << "Enter Staff ID: \n";
		cin >> staffid;
		cout << endl;
	}
	catch (exception e)
	{
		cout << "Please enter the valid value" << endl;
		HaveException = true;
		//goto Exit;
	}
	if (HaveException == false) {

		stringstream streamid;
		string strID;
		streamid << staffid;
		streamid >> strID;

		for (int i = 0; i < indexForId; i++) {

			if (strID != items[i]) {

				NotInDatabase = false;

			}
			else {

				NotInDatabase = false;


			}
		}

		if (NotInDatabase == false) {

			string delete_query = "DELETE FROM staffregistration WHERE Staffid =  '" + strID + "' ";
			const char* qd = delete_query.c_str();
			qstate = mysql_query(conn, qd);

			if (!qstate)
			{
				cout << endl << "\t\t\tData Delete " << endl;

				cout << "\n\n\t\t\t\tPress N to proceed to the Main Page or press any other key to Exit : ";
				cin >> choice;
				if (choice == 'N' || choice == 'n')
				{
					MainPage();
				}
				else
				{
					exit(0);
				}

			}
			else {

				cout << "\t\t\tFailed to delete" << mysql_errno(conn) << endl;

			}

		}

	}
	else {

		cout << "Not FOUND in database";
	}



}

void SalaryPayment()
{
	system("cls");

	string items[5000];
	int indexForId = 0;
	string staffid, month;
	bool HaveException = false;
	bool NotInDatabase = false;

	cout << "\n\t\t\t\t********************************************************************************* ";
	cout << "\n\t\t\t\t|                             Pending Payments                                  | ";
	cout << "\n\t\t\t\t********************************************************************************* ";


	if (HaveException == false) {

		

			string findbyid_query = "SELECT * FROM salarycalculation WHERE paid='Unpaid' ";
			const char* qi = findbyid_query.c_str();
			qstate = mysql_query(conn, qi);


			if (!qstate)
			{
				res = mysql_store_result(conn);
				cout << endl;

				printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
				printf("|                                               INDIVIDUAL RECORD                                                                               |\n");
				printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
				printf("| %-25s | %-25s | %-15s |  %-10s  | %-10s | %-10s |\n", "StaffId", "Name", "Working Days", "Total Payment", "Month", "Status");
				printf("------------------------------------------------------------------------------------------------------------------------------------------------ \n");
				while ((row = mysql_fetch_row(res)))
				{
					printf("| %-25s | %-25s | %-15s |  %-10s  | %-10s | %-10s | \n", row[0], row[1], row[2], row[3], row[4], row[5]);
				}
				printf("------------------------------------------------------------------------------------------------------------------------------------------------ \n");


				cout << "\n\n\t\t\t\tEnter staff Id : ";
				cin >> staffid;

				cout << "\n\n\t\t\t\tEnter month : ";
				cin >> month;

				string findbyid_query = "UPDATE salarycalculation SET paid = 'paid' WHERE Staffid='" + staffid + "' AND month='"+month+"'";
				const char* qi = findbyid_query.c_str();
				qstate = mysql_query(conn, qi);
				if (!qstate)
				{
					cout << endl << "Successfully saved in database" << endl;
					system("pause");
					MainPage();

				}
				else {

					cout << "Failed to update" << mysql_errno(conn) << endl;

				}
			}


			}

			else {

				cout << "Query Execution Problem" << mysql_errno(conn) << endl;

			}

	}


