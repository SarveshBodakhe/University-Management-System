#include<iostream>
#include<mysql.h>
#include<mysqld_error.h>
#include<windows.h>
#include<sstream>

using namespace std;

const char* HOST= "localhost";
const char* USER= "root"; 
const char* PW="Ekshula#2002";
const char* DB="University_Management_System";

class University{
	private:
		// basic information
		int StudentId;
		string Name, Email, ContactNumber, Address;
		
		// Academic details
		int EnrollmentNumber, Semester;
		string Program, Department, Subjects[]; 
		float CGPA;
		
		// Administrative details
	    string AdmissionDate;
		string Status;
		float FeesDue;
		
		
	public:
		University(): StudentId(0), Name(""), Email(""), ContactNumber(""), Address(""), 
		EnrollmentNumber(0), Semester(0), Program(""), Department(""), CGPA(0.0), 
		AdmissionDate(""), Status("Active"), FeesDue(0.0){}

		
		// basic info - setter functions
		// Setter for Student ID
		void setStudentId(int id) {
		    StudentId = id;
		}
		
		// Setter for Name
		void setName(string name) {
		    Name = name;
		}
		
		// Setter for Email
		void setEmail(string email) {
		    Email = email;
		}
		
		// Setter for Contact Number
		void setContactNumber(string contactNumber) {
		    ContactNumber = contactNumber;
		}
		
		// Setter for Address
		void setAddress(string address) {
		    Address = address;
		}
		
		// academic details
		// Setter for Enrollment Number
		void setEnrollmentNumber(int enrollmentNumber) {
		    EnrollmentNumber = enrollmentNumber;
		}
		
		// Setter for Semester
		void setSemester(int semester) {
		    Semester = semester;
		}
		
		// Setter for Program
		void setProgram(string program) {
		    Program = program;
		}
		
		// Setter for Department
		void setDepartment(string department) {
		    Department = department;
		}
		
		// Setter for Subjects
		void setSubjects(string subjects[], int subjectCount) {
		    for(int i = 0; i < subjectCount; i++) {
		        Subjects[i] = subjects[i];
		    }
		}
		
		// Setter for CGPA
		void setCGPA(float cgpa) {
		    CGPA = cgpa;
		}

        // administrative details
        // Setter for Admission Date
		void setAdmissionDate(string admissionDate) {
		    AdmissionDate = admissionDate;
		}
		
		// Setter for Status
		void setStatus(string status) {
		    Status = status;
		}
		
		// Setter for Fees Due
		void setFeesDue(float feesDue) {
		    FeesDue = feesDue;
		}

		
		// Basic Information - getter functions
		// Getter for Student ID
		int getStudentId() {
		    return StudentId;
		}
		
		// Getter for Name
		string getName() {
		    return Name;
		}
		
		// Getter for Email
		string getEmail() {
		    return Email;
		}
		
		// Getter for Contact Number
		string getContactNumber() {
		    return ContactNumber;
		}
		
		// Getter for Address
		string getAddress() {
		    return Address;
		}
		
		// Academic Details
		
		// Getter for Enrollment Number
		int getEnrollmentNumber() {
		    return EnrollmentNumber;
		}
		
		// Getter for Semester
		int getSemester() {
		    return Semester;
		}
		
		// Getter for Program
		string getProgram() {
		    return Program;
		}
		
		// Getter for Department
		string getDepartment() {
		    return Department;
		}
		
		// Getter for Subjects
		string* getSubjects() {
		    return Subjects;
		}
		
		// Getter for CGPA
		float getCGPA() {
		    return CGPA;
		}
		
		// Getter for Admission Date
		string getAdmissionDate() {
		    return AdmissionDate;
		}
		
		// Getter for Status
		string getStatus() {
		    return Status;
		}
		
		// Getter for Fees Due
		float getFeesDue() {
		    return FeesDue;
		}
		


};


//Insert function
void insertStudentBasicInfo(MYSQL* conn, University u) {
    int studentId;
    string name, email, contactNumber, address;

    // Collect basic info
    cout << "Enter Student ID: ";
    cin >> studentId;
    u.setStudentId(studentId);

    cout << "Enter Name: ";
    cin >> name;
    u.setName(name);

    cout << "Enter Email: ";
    cin >> email;
    u.setEmail(email);

    cout << "Enter Contact Number: ";
    cin >> contactNumber;
    u.setContactNumber(contactNumber);

    cout << "Enter Address: ";
    cin >> address;
    u.setAddress(address);

    // Insert into Student_Basic_Info
    stringstream ss;
    ss << studentId;
    string sStudentId = ss.str();

    string insertBasic = "INSERT INTO Student_Basic_Info (StudentId, Name, Email, ContactNumber, Address) VALUES ('" + sStudentId + "', '" + u.getName() + "', '" + u.getEmail() + "', '" + u.getContactNumber() + "', '" + u.getAddress() + "')";

    if (mysql_query(conn, insertBasic.c_str())) {
        cout << "Error in Basic Info Insertion: " << mysql_error(conn) << endl;
    } else {
        cout << "Basic Info Inserted Successfully." << endl;
    }
    Sleep(3000);
}

void insertStudentAcademicInfo(MYSQL* conn, University u) {
    int studentId, enrollmentNumber, semester;
    string program, department;
    float cgpa;

    // Collect academic info
    cout << "Enter Student ID: ";
    cin >> studentId;
    u.setStudentId(studentId);

    cout << "Enter Enrollment Number: ";
    cin >> enrollmentNumber;
    u.setEnrollmentNumber(enrollmentNumber);

    cout << "Enter Program: ";
    cin >> program;
    u.setProgram(program);

    cout << "Enter Department: ";
    cin >> department;
    u.setDepartment(department);

    cout << "Enter Semester: ";
    cin >> semester;
    u.setSemester(semester);

    cout << "Enter CGPA: ";
    cin >> cgpa;
    u.setCGPA(cgpa);

    // Insert into Student_Academic_Info
    stringstream ss;
    ss << studentId;
    string sStudentId = ss.str();

    ss.str("");
    ss << enrollmentNumber;
    string sEnrollmentNumber = ss.str();

    ss.str("");
    ss << semester;
    string sSemester = ss.str();

    ss.str("");
    ss << cgpa;
    string sCGPA = ss.str();

    string insertAcademic = "INSERT INTO Student_Academic_Info (StudentId, EnrollmentNumber, Program, Department, Semester, CGPA) VALUES ('" + sStudentId + "', '" + sEnrollmentNumber + "', '" + program + "', '" + department + "', '" + sSemester + "', '" + sCGPA + "')";

    if (mysql_query(conn, insertAcademic.c_str())) {
        cout << "Error in Academic Info Insertion: " << mysql_error(conn) << endl;
    } else {
        cout << "Academic Info Inserted Successfully." << endl;
    }
    Sleep(3000);
}

void insertStudentAdministrativeInfo(MYSQL* conn, University u) {
    int studentId;
    string admissionDate, status;
    float feesDue;

    // Collect administrative info
    cout << "Enter Student ID: ";
    cin >> studentId;
    u.setStudentId(studentId);

    cout << "Enter Admission Date (YYYY-MM-DD): ";
    cin >> admissionDate;
    u.setAdmissionDate(admissionDate);

    cout << "Enter Fees Due: ";
    cin >> feesDue;
    u.setFeesDue(feesDue);

    cout << "Enter Status: ";
    cin >> status;
    u.setStatus(status);

    // Insert into Student_Administrative_Info
    stringstream ss;
    ss << studentId;
    string sStudentId = ss.str();

    ss.str("");
    ss << feesDue;
    string sFeesDue = ss.str();

    string insertAdmin = "INSERT INTO Student_Administrative_Info (StudentId, AdmissionDate, FeesDue, Status) VALUES ('" + sStudentId + "', '" + admissionDate + "', '" + sFeesDue + "', '" + status + "')";

    if (mysql_query(conn, insertAdmin.c_str())) {
        cout << "Error in Administrative Info Insertion: " << mysql_error(conn) << endl;
    } else {
        cout << "Administrative Info Inserted Successfully." << endl;
    }
    Sleep(3000);
}

void insertStudentSubjects(MYSQL* conn, University u) {
    int studentId;
    string subjects[5];

    // Collect subjects info
    cout << "Enter Student ID: ";
    cin >> studentId;
    u.setStudentId(studentId);

    cout << "Enter Subjects (max 5): ";
    for (int i = 0; i < 5; i++) {
        cout << "Subject " << (i + 1) << ": ";
        cin >> subjects[i];
    }
    u.setSubjects(subjects, 5);

    // Insert into Student_Subjects
    stringstream ss;
    ss << studentId;
    string sStudentId = ss.str();

    for (int i = 0; i < 5; i++) {
        string insertSubject = "INSERT INTO Student_Subjects (StudentId, Subject) VALUES ('" + sStudentId + "', '" + subjects[i] + "')";
        if (mysql_query(conn, insertSubject.c_str())) {
            cout << "Error in Subject Insertion: " << mysql_error(conn) << endl;
        }
    }
    Sleep(3000);
}


//Show function

// Show Basic Information
void showBasicInfo(MYSQL* conn) {
    string query = "SELECT * FROM Student_Basic_Info";
    if (mysql_query(conn, query.c_str())) {
        cout << "Error: " << mysql_error(conn) << endl;
    } else {
        MYSQL_RES* res = mysql_store_result(conn);
        if (res) {
            int num_fields = mysql_num_fields(res);
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(res))) {
                for (int i = 0; i < num_fields; i++) {
                    cout << (row[i] ? row[i] : "NULL") << "\t";
                }
                cout << endl;
            }
            mysql_free_result(res);
        }
    }
    Sleep(3000);
}

// Show Academic Information
void showAcademicInfo(MYSQL* conn) {
    string query = "SELECT * FROM Student_Academic_Info";
    if (mysql_query(conn, query.c_str())) {
        cout << "Error: " << mysql_error(conn) << endl;
    } else {
        MYSQL_RES* res = mysql_store_result(conn);
        if (res) {
            int num_fields = mysql_num_fields(res);
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(res))) {
                for (int i = 0; i < num_fields; i++) {
                    cout << (row[i] ? row[i] : "NULL") << "\t";
                }
                cout << endl;
            }
            mysql_free_result(res);
        }
    }
    Sleep(3000);
}

// Show Administrative Information
void showAdministrativeInfo(MYSQL* conn) {
    string query = "SELECT * FROM Student_Administrative_Info";
    if (mysql_query(conn, query.c_str())) {
        cout << "Error: " << mysql_error(conn) << endl;
    } else {
        MYSQL_RES* res = mysql_store_result(conn);
        if (res) {
            int num_fields = mysql_num_fields(res);
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(res))) {
                for (int i = 0; i < num_fields; i++) {
                    cout << (row[i] ? row[i] : "NULL") << "\t";
                }
                cout << endl;
            }
            mysql_free_result(res);
        }
    }
    Sleep(3000);
}

// Show Subjects Information
void showSubjects(MYSQL* conn) {
    string query = "SELECT * FROM Student_Subjects";
    if (mysql_query(conn, query.c_str())) {
        cout << "Error: " << mysql_error(conn) << endl;
    } else {
        MYSQL_RES* res = mysql_store_result(conn);
        if (res) {
            int num_fields = mysql_num_fields(res);
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(res))) {
                for (int i = 0; i < num_fields; i++) {
                    cout << (row[i] ? row[i] : "NULL") << "\t";
                }
                cout << endl;
            }
            mysql_free_result(res);
        }
    }
    Sleep(3000);
}

void showAllRecords(MYSQL* conn) {
    cout << "Showing Basic Information:" << endl;
    showBasicInfo(conn);
    cout << "Showing Academic Information:" << endl;
    showAcademicInfo(conn);
    cout << "Showing Administrative Information:" << endl;
    showAdministrativeInfo(conn);
    cout << "Showing Subjects Information:" << endl;
    showSubjects(conn);
}

// search funtion

void searchStudentBasicInfo(MYSQL* conn) {
	int id;
    cout << "Enter Student ID: " << endl;
    cin >> id;

    // Convert the ID to a string
    stringstream ss;
    ss << id;
    string sId = ss.str();
    
    string query = "SELECT * FROM Student_Basic_Info WHERE StudentId = '" + sId + "'";
    
    if (mysql_query(conn, query.c_str())) {
        cout << "Error: " << mysql_error(conn) << endl;
    } else {
        MYSQL_RES* res = mysql_store_result(conn);
        if (res) {
            MYSQL_ROW row = mysql_fetch_row(res);
            if (row) {
                cout << "Basic Info:" << endl;
                int num_fields = mysql_num_fields(res);
                for (int i = 0; i < num_fields; i++) {
                    cout << (row[i] ? row[i] : "NULL") << "\t";
                }
                cout << endl;
            } else {
                cout << "No basic info found for Student ID: " << sId << endl;
            }
            mysql_free_result(res);
        }
    }
}
void searchStudentAcademicInfo(MYSQL* conn) {
	int id;
    cout << "Enter Student ID: " << endl;
    cin >> id;

    // Convert the ID to a string
    stringstream ss;
    ss << id;
    string sId = ss.str();
    
    string query = "SELECT * FROM Student_Academic_Info WHERE StudentId = '" + sId + "'";
    
    if (mysql_query(conn, query.c_str())) {
        cout << "Error: " << mysql_error(conn) << endl;
    } else {
        MYSQL_RES* res = mysql_store_result(conn);
        if (res) {
            MYSQL_ROW row = mysql_fetch_row(res);
            if (row) {
                cout << "Academic Info:" << endl;
                int num_fields = mysql_num_fields(res);
                for (int i = 0; i < num_fields; i++) {
                    cout << (row[i] ? row[i] : "NULL") << "\t";
                }
                cout << endl;
            } else {
                cout << "No academic info found for Student ID: " << sId << endl;
            }
            mysql_free_result(res);
        }
    }
}
void searchStudentAdministrativeInfo(MYSQL* conn) {
	int id;
    cout << "Enter Student ID: " << endl;
    cin >> id;

    // Convert the ID to a string
    stringstream ss;
    ss << id;
    string sId = ss.str();
    
    string query = "SELECT * FROM Student_Administrative_Info WHERE StudentId = '" + sId + "'";
    
    if (mysql_query(conn, query.c_str())) {
        cout << "Error: " << mysql_error(conn) << endl;
    } else {
        MYSQL_RES* res = mysql_store_result(conn);
        if (res) {
            MYSQL_ROW row = mysql_fetch_row(res);
            if (row) {
                cout << "Administrative Info:" << endl;
                int num_fields = mysql_num_fields(res);
                for (int i = 0; i < num_fields; i++) {
                    cout << (row[i] ? row[i] : "NULL") << "\t";
                }
                cout << endl;
            } else {
                cout << "No administrative info found for Student ID: " << sId << endl;
            }
            mysql_free_result(res);
        }
    }
}

void searchStudentSubjects(MYSQL* conn) {
	int id;
    cout << "Enter Student ID: " << endl;
    cin >> id;

    // Convert the ID to a string
    stringstream ss;
    ss << id;
    string sId = ss.str(); 
    
    string query = "SELECT * FROM Student_Subjects WHERE StudentId = '" + sId + "'";
    
    if (mysql_query(conn, query.c_str())) {
        cout << "Error: " << mysql_error(conn) << endl;
    } else {
        MYSQL_RES* res = mysql_store_result(conn);
        if (res) {
            MYSQL_ROW row = mysql_fetch_row(res);
            if (row) {
                cout << "Subjects Info:" << endl;
                int num_fields = mysql_num_fields(res);
                for (int i = 0; i < num_fields; i++) {
                    cout << (row[i] ? row[i] : "NULL") << "\t";
                }
                cout << endl;
            } else {
                cout << "No subjects info found for Student ID: " << sId << endl;
            }
            mysql_free_result(res);
        }
    }
}

// Update function

void updateStudentBasicInfo(MYSQL* conn) {
	int id;
    cout << "Enter Student ID: " << endl;
    cin >> id;

    // Convert the ID to a string
    stringstream ss;
    ss << id;
    string sId = ss.str();
    
    string name, email, contactNumber, address;
    cout << "Enter New Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter New Email: ";
    cin >> email;
    cout << "Enter New Contact Number: ";
    cin >> contactNumber;
    cout << "Enter New Address: ";
    cin.ignore();
    getline(cin, address);

    string update = "UPDATE Student_Basic_Info SET Name='" + name + "', Email='" + email + "', ContactNumber='" + contactNumber + "', Address='" + address + "' WHERE StudentId='" + sId + "'";
    if (mysql_query(conn, update.c_str())) {
        cout << "Error: " << mysql_error(conn) << endl;
    } else {
        cout << "Basic Information Updated Successfully." << endl;
    }
}
void updateStudentAcademicInfo(MYSQL* conn) {
    int enrollmentNumber, semester;
    string program, department;
    float cgpa;

    cout << "Enter New Enrollment Number: ";
    cin >> enrollmentNumber;
    cout << "Enter New Semester: ";
    cin >> semester;
    cout << "Enter New Program: ";
    cin.ignore();
    getline(cin, program);
    cout << "Enter New Department: ";
    getline(cin, department);
    cout << "Enter New CGPA: ";
    cin >> cgpa;
    
    int id;
    cout << "Enter Student ID: " << endl;
    cin >> id;

    // Convert the ID to a string
    stringstream ss;
    ss << id;
    string sId = ss.str();

    ss.str(""); // Reset the stringstream
    ss << enrollmentNumber;
    string sEnrollmentNumber = ss.str();
    
    ss.str(""); // Reset the stringstream
    ss << semester;
    string sSemester = ss.str();
    
    ss.str(""); // Reset again
    ss << cgpa;
    string sCGPA = ss.str();

    string update = "UPDATE Student_Academic_Info SET EnrollmentNumber='" + sEnrollmentNumber + "', Semester='" + sSemester + "', Program='" + program + "', Department='" + department + "', CGPA='" + sCGPA + "' WHERE StudentId='" + sId + "'";
    if (mysql_query(conn, update.c_str())) {
        cout << "Error: " << mysql_error(conn) << endl;
    } else {
        cout << "Academic Information Updated Successfully." << endl;
    }
}

void updateStudentAdministrativeInfo(MYSQL* conn) {
	int id;
    cout << "Enter Student ID: " << endl;
    cin >> id;

    // Convert the ID to a string
    stringstream ss;
    ss << id;
    string sId = ss.str();
    
    float feesDue;
    cout << "Enter New Fees Due: ";
    cin >> feesDue;

    ss.str(""); // reset stringstream
    ss << feesDue;
    string sFeesDue = ss.str();

    string update = "UPDATE Student_Administrative_Info SET FeesDue='" + sFeesDue + "' WHERE StudentId='" + sId + "'";
    if (mysql_query(conn, update.c_str())) {
        cout << "Error: " << mysql_error(conn) << endl;
    } else {
        cout << "Administrative Information Updated Successfully." << endl;
    }
}


// Delete function
// Delete from Student_Basic_Info
void deleteFromStudentBasicInfo(MYSQL* conn) {
	int id;
    cout << "Enter Student ID: " << endl;
    cin >> id;

    stringstream ss;
    ss << id;
    string sId = ss.str();
    
    string del = "DELETE FROM Student_Basic_Info WHERE StudentId='" + sId + "'";
    if (mysql_query(conn, del.c_str())) {
        cout << "Error: " << mysql_error(conn) << endl;
    } else {
        cout << "Basic Information Deleted Successfully." << endl;
    }
}

// Delete from Student_Academic_Info
void deleteFromStudentAcademicInfo(MYSQL* conn) {
	int id;
    cout << "Enter Student ID: " << endl;
    cin >> id;

    stringstream ss;
    ss << id;
    string sId = ss.str();
    
    string del = "DELETE FROM Student_Academic_Info WHERE StudentId='" + sId + "'";
    if (mysql_query(conn, del.c_str())) {
        cout << "Error: " << mysql_error(conn) << endl;
    } else {
        cout << "Academic Information Deleted Successfully." << endl;
    }
}

// Delete from Student_Administrative_Info
void deleteFromStudentAdministrativeInfo(MYSQL* conn) {
	int id;
    cout << "Enter Student ID: " << endl;
    cin >> id;

    stringstream ss;
    ss << id;
    string sId = ss.str();
    
    string del = "DELETE FROM Student_Administrative_Info WHERE StudentId='" + sId + "'";
    if (mysql_query(conn, del.c_str())) {
        cout << "Error: " << mysql_error(conn) << endl;
    } else {
        cout << "Administrative Information Deleted Successfully." << endl;
    }
}

// Delete from Student_Subjects
void deleteFromStudentSubjects(MYSQL* conn) {
	int id;
    cout << "Enter Student ID: " << endl;
    cin >> id;

    stringstream ss;
    ss << id;
    string sId = ss.str();
    
    string del = "DELETE FROM Student_Subjects WHERE StudentId='" + sId + "'";
    if (mysql_query(conn, del.c_str())) {
        cout << "Error: " << mysql_error(conn) << endl;
    } else {
        cout << "Subjects Information Deleted Successfully." << endl;
    }
}



int main() {
    University u;
    MYSQL* conn;
    conn = mysql_init(NULL);

    // Establish connection with the database
    if (!mysql_real_connect(conn, HOST, USER, PW, DB, 3306, NULL, 0)) {
        cout << "Error: " << mysql_error(conn) << endl;
        return 1;
    } else {
        cout << "Logged in!" << endl;
    }

    Sleep(3000); // Sleep for 3 seconds (Windows-specific)

    bool exit = false;
    while (!exit) {
        system("cls"); // Clears the screen (Windows-specific)
        
        cout << "Welcome to our University Management System" << endl;
        cout << "*******************************************" << endl;
        
        int mainChoice, subChoice;
        cout<<"Main Functionalities: "<<endl;
        cout << "1. Insert Student Data" << endl;
        cout << "2. Show Student Data" << endl;
        cout << "3. Search Student Data" << endl;
        cout << "4. Update Student Data" << endl;
        cout << "5. Delete Student Data" << endl;
        cout << "0. Exit from the system" << endl;
        cout << "Enter choice: ";
        cin >> mainChoice;
        cout << endl;

        switch (mainChoice) {
            case 1: {
            	cout<<"Insert into: "<<endl;
            	cout << "1. Insert into Student_Basic_Info" << endl;
		        cout << "2. Insert into Student_Academic_Info" << endl;
		        cout << "3. Insert into Student_Administrative_Info" << endl;
		        cout << "4. Insert into Student_Subjects" << endl;
		        cout<<"Enter sub-choice: "<<endl;
		        cin >> subChoice;

                switch (subChoice) {
                case 1:
                    cout << "Inserting into Student_Basic_Info..." << endl;
                    insertStudentBasicInfo(conn,u);
                    break;
                case 2:
                    cout << "Inserting into Student_Academic_Info..." << endl;
                    insertStudentAcademicInfo(conn, u);
                    break;
                case 3:
                    cout << "Inserting into Student_Administrative_Info..." << endl;
                    insertStudentAdministrativeInfo(conn, u);
                    break;
                case 4:
                    cout << "Inserting into Student_Subjects..." << endl;
                    insertStudentSubjects(conn, u);
                    break;
                default:
                    cout << "Invalid sub-choice!" << endl;
                    break;
            }
            break;
            }
            
            case 2:{
            	cout<<"Show Student Data: "<<endl;
            	cout << "1. Show Student_Basic_Info" << endl;
		        cout << "2. Show Student_Academic_Info" << endl;
		        cout << "3. Show Student_Administrative_Info" << endl;
		        cout << "4. Show Student_Subjects" << endl;
		        cout << "5. Show All Records" << endl;
		        cout<<"Enter sub-choice: "<<endl;
		        cin >> subChoice;

            	switch (subChoice) {
                case 1:
                    cout << "Show Student_Basic_Info..." << endl;
                    showBasicInfo(conn);
                    break;
                case 2:
                    cout << "Show Student_Academic_Info..." << endl;
                    showAcademicInfo(conn);
                    break;
                case 3:
                    cout << "Show Student_Administrative_Info..." << endl;
                    showAdministrativeInfo(conn);
                    break;
                case 4:
                    cout << "Show Student_Subjects..." << endl;
                    showSubjects(conn);
                    break;
                case 5:
                	cout << "Show All Records..." << endl;
                	showAllRecords(conn);
                	break;
                default:
                    cout << "Invalid sub-choice!" << endl;
                    break;
            }
				break;
			}
			
			case 3:{
				cout<<"Search Student Data: "<<endl;
            	cout << "1. Search Student_Basic_Info" << endl;
		        cout << "2. Search Student_Academic_Info" << endl;
		        cout << "3. Search Student_Administrative_Info" << endl;
		        cout << "4. Search Student_Subjects" << endl;
		        cout<<"Enter sub-choice: "<<endl;
		        cin >> subChoice;

            	switch (subChoice) {
                case 1:
                    cout << "Searching Student_Basic_Info..." << endl;
                    searchStudentBasicInfo(conn);
                    break;
                case 2:
                    cout << "Searching Student_Academic_Info..." << endl;
                    searchStudentAcademicInfo(conn);
                    break;
                case 3:
                    cout << "Searching Student_Administrative_Info..." << endl;
                    searchStudentAdministrativeInfo(conn);
                    break;
                case 4:
                    cout << "Searching Student_Subjects..." << endl;
                    searchStudentSubjects(conn);
                    break;
                default:
                    cout << "Invalid sub-choice!" << endl;
                    break;
            }
				break;
			}
			
			case 4:{
				cout<<"Update Student Data: "<<endl;
            	cout << "1. Update Student_Basic_Info" << endl;
		        cout << "2. Update Student_Academic_Info" << endl;
		        cout << "3. Update Student_Administrative_Info" << endl;
		        cout<<"Enter sub-choice: "<<endl;
		        cin >> subChoice;

            	switch (subChoice) {
                case 1:
                    cout << "Updating Student_Basic_Info..." << endl;
                    updateStudentBasicInfo(conn);
                    break;
                case 2:
                    cout << "Updating Student_Academic_Info..." << endl;
                    updateStudentAcademicInfo(conn);
                    break;
                case 3:
                    cout << "Updating Student_Administrative_Info..." << endl;
                    updateStudentAdministrativeInfo(conn);
                    break;
                default:
                    cout << "Invalid sub-choice!" << endl;
                    break;
            }
				break;
			}
			case 5:{
				cout<<"Delete Student Data: "<<endl;
            	cout << "1. Delete Student_Basic_Info" << endl;
		        cout << "2. Delete Student_Academic_Info" << endl;
		        cout << "3. Delete Student_Administrative_Info" << endl;
		        cout<<"Enter sub-choice: "<<endl;
		        cin >> subChoice;

            	switch (subChoice) {
                case 1:
                    cout << "Deleting Student_Basic_Info..." << endl;
                    deleteFromStudentBasicInfo(conn);
                    break;
                case 2:
                    cout << "Deleting Student_Academic_Info..." << endl;
                    deleteFromStudentAcademicInfo(conn);
                    break;
                case 3:
                    cout << "Deleting Student_Administrative_Info..." << endl;
                    deleteFromStudentAdministrativeInfo(conn);
                    break;
                case 4:
                	cout << "Deleting Student_Subjects..." << endl;
                    deleteFromStudentSubjects(conn);
                    break;
                default:
                    cout << "Invalid sub-choice!" << endl;
                    break;
            }
				break;
			}
            case 0: {
                exit = true;
                cout << "Good Luck!!!" << endl;
                Sleep(3000); // Sleep for 3 seconds
                break;
            }
            default: {
                cout << "Invalid Input" << endl;
                Sleep(3000); // Sleep for 3 seconds
                break;
            }
        }
    }

    // Close the database connection
    mysql_close(conn);

    return 0;
}

