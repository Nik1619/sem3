#include "Table.h"

void Table::add_student(Student* st) {
	int id = st->get_id();
	tree.add(id, st);
}

Student* Table::find_st(int id) {
	auto info = tree.find(id);
	return info->second;
}

bool Table::check_st(int id) {
	return tree.key_exist(id);
}

void Table::delete_st(int id) {
	auto info = tree.find(id);
	delete info->second;
	tree.erase(id);
}

void Table::show_stud(std::ostream& out) {
	if (tree.get_size() == 0) {
		std::cout << "No students at this moment" << std::endl;
		return;
	}

	for (auto it = tree.begin(); it != tree.end(); ++it) {
		out << "ID: " << it->first << std::endl;
		out << "\tSurname: " << it->second->get_surname() << std::endl;
		out << "\tInitials: " << it->second->get_initials() << std::endl;
		out << "\tGroup: " << it->second->get_group() << std::endl;
		out << "\tType: " << it->second->get_category() << std::endl;
		out << "\tSemester: " << it->second->get_semester() << std::endl;
	}
}

void Table::change_type(int id, Student::category new_category) {
	auto it = tree.find(id);
	Student* st = it->second;
	if (st->get_category() == new_category) {
		st->set_info();
		return;
	}

	std::string surname = st->get_surname();
	std::string initials = st->get_initials();
	unsigned int semester = st->get_semester();
	int group = st->get_group();
	int cafedra = st->get_cafedra();

	Student* new_st = nullptr;

	if (new_category == Student::category::Junior) {
		new_st = new Junior(surname, initials, group, id, semester, cafedra);

		delete it->second;
		it->second = new_st;
	}

	else if (new_category == Student::category::Middle) {
		new_st = new Middle(surname, initials, group, id, semester, cafedra);

		delete it->second;
		it->second = new_st;
	}

	else if (new_category == Student::category::Senior) {
		new_st = new Senior(surname, initials, group, id, semester, cafedra);

		delete it->second;
		it->second = new_st;
	}
}





void Table::replace_student(Student* st) {
	int id = st->get_id();
	auto info = tree.find(id);
	delete info->second;
	info->second = st;
}