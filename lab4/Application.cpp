#include "Application.h"

void Application::add_student() {
	Student* st;
	int id, cafedra;
	std::string surname, initials;
	unsigned int group;
	while (1) {
		cout << "Enter new student id: ";
		get_var(id);
		if (tab.check_st(id)) {
			cout << "Key repeats" << endl;
			continue;
		}
		break;
	}
	std::cout << "Enter surname and initials: ";
	get_var(surname);
	get_var(initials);

	std::cout << "Enter group (integer): ";
	get_var(group);

	std::cout << "Enter cafedra (integer): ";
	get_var(cafedra);
	int marks[5] = { 0, 0, 0, 0, 0 };
	st = new Junior(surname, initials, group, id, 1, cafedra, marks);

	tab.add_student(st);
}
 
void Application::delete_student() {
	int id;
	cout << "Enter id: ";
	get_var(id);
	try {
		tab.delete_st(id);
	}
	catch (std::exception& ex) { cout << ex.what(); }
}

void Application::show_stud_info() {
	int id;
	cout << "Enter id: ";
	get_var(id);
	Student* st;
	try {
		st = tab.find_st(id);
	}
	catch (std::exception& ex) {
		cout << ex.what();
		return;
	}

	st->info();
}

void Application::change_stud_info() {
	int id;
	cout << "Enter id: ";
	get_var(id);
	Student* st;
	try {
		st = tab.find_st(id);
	}
	catch (std::exception& ex) {
		cout << ex.what();
		return;
	}
	st->set_info();
}

void Application::increase_semester() {
	int id;
	cout << "Enter id: ";
	get_var(id);
	Student* st;
	try {
		st = tab.find_st(id);
	}
	catch (std::exception& ex) {
		cout << ex.what();
		return;
	}

	cout << "Current semester: " << st->get_semester() << endl;
	st->increase_semester();
	if (st->get_semester() == 5) {
		tab.change_type(id, Student::category::Middle);
	}

	else if (st->get_semester() == 7) {
		tab.change_type(id, Student::category::Senior);
	}

	else if (st->get_semester() == 9) {
		cout << "Student " << st->get_id() << ": " << st->get_surname() << " " << st->get_initials() << " graduated! He will be deleted." << endl;
		tab.delete_st(id);
	}

	else {
		st->set_info();
	}
}

void Application::start() {
	bool finish = false;
	while (!finish && !std::cin.eof()) {
		cout << endl << endl << "\t\t\tMENU:" << endl;
		cout << "1) Show short info about all students" << endl;
		cout << "2) Add new student" << endl;
		cout << "3) Delete student" << endl;
		cout << "4) Show info about student by id" << endl;
		cout << "5) Change info about student by id" << endl;
		cout << "6) Increase semester of student by id" << endl;
		cout << "0) Exit" << endl << endl;
		int answer = 0;
		get_var(answer);

		switch (answer)
		{
		case 1:
			show_short_info();
			break;
		case 2:
			add_student();
			break;
		case 3:
			delete_student();
			break;
		case 4:
			show_stud_info();
			break;
		case 5:
			change_stud_info();
			break;
		case 6:
			increase_semester();
			break;
		case 0:
			finish = true;
			cout << "Bye";
			break;
		default:
			cout << "Repeat" << endl;
			break;
		}
	}
}


// Senior* s = dynamic_cast<Senior*>(student);