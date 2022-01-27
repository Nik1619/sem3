#pragma once
#include "Table.h"

using std::cout;
using std::endl;
 
class Application {
	Table tab;
private:
	void show_short_info() { tab.show_stud(); }
	void add_student();
	void delete_student();
	void show_stud_info();
	void change_stud_info();
	void increase_semester();
public:
	void start();
};
