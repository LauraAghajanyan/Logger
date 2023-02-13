#include <string>
#include <ctime>
#include <iostream>
#include <iomanip>
#include "logger.h"
using namespace std;


int main() {

	Logger logg;
	string s1 = "Zero Division Error";
	string s2 = "No Errors or Warnings! Good Job!";
	string s3 = "Possible loss of data!";
	logg.log(LogLevel::ERROR, s1);
	cout << "My name" << endl;
	logg.log(LogLevel::SUCCESSFULLY_DONE, s2);
	cout << "Your name" << endl;
	logg.log(LogLevel::WARNING, s3);

	/*Logger logg;
	logg.log(LogLevel::SUCCESSFULLY_DONE, "No errors or warnings!");
	logg.log(LogLevel::WARNING, "Possible loss of data!");
	logg.log(LogLevel::ERROR, "RunTime Error!");*/
	return 0;
    

}