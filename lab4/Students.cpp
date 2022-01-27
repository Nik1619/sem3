#include "Students.h"

std::ostream& operator<<(std::ostream& out, Student::category c) {
	switch (c)
	{
	case Student::category::Junior:
		out << "Junior";
		break;
	case Student::category::Middle:
		out << "Middle";
		break;
	case Student::category::Senior:
		out << "Senior";
		break;
	default:
		break;
	}

	return out;
}

void Student::info(std::ostream& out) {
	out << "ID: " << stud_id << std::endl;
	out << "Name: " << surname << " " << initials << std::endl;
	out << "Type: " << get_category() << std::endl;
	out << "Group: " << group_index << std::endl;
	out << "Cafedra: " << cafedra << std::endl;
	out << "Semester: " << semester << std::endl;
}



void Junior::set_marks() {
	std::cout << "Enter 5 session marks: ";
	for (int i = 0; i < 5; ++i) {
		get_var(exam_marks[i]);
	}
}

void Junior::get_marks() const{
	std::cout << "Marks: ";
	for (int i = 0; i < 5; ++i) {
		std::cout << exam_marks[i] << " ";
	}
	std::cout << std::endl;
}

void Junior::info(std::ostream& out) {
	Student::info();
	get_marks();
}

void Junior::set_info() {
	set_marks();
}



void Middle::set_UIR_theme() {
	while (1) {
		std::cout << "Enter UIR theme: ";
		std::string theme;
		get_var(theme);
		if (theme == "") {
			if (std::cin.eof()) break;
			std::cout << "UIR theme can't be empty";
			continue;
		}
		UIR_theme = theme;
		break;
	}
}

void Middle::set_UIR_place() {
	while (1) {
		std::cout << "Enter UIR place: ";
		std::string place;
		get_var(place);
		if (place == "") {
			if (std::cin.eof()) break;
			std::cout << "UIR place can't be empty";
			continue;
		}
		UIR_place = place;
		break;
	}
}

void Middle::set_marks() {
	std::cout << "Enter 4 session marks: ";
	for (int i = 0; i < 4; ++i) {
		get_var(exam_marks[i]);
	}

	std::cout << "Enter UIR supervisor mark and comission mark: ";
	get_var(supervisor_mark);
	get_var(comission_mark);
}

void Middle::get_marks() const {
	std::cout << "Marks: ";
	for (int i = 0; i < 4; ++i) {
		std::cout << exam_marks[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Supervisor_mark: " << supervisor_mark << std::endl;
	std::cout << "Comission_mark: " << comission_mark << std::endl;
}

void Middle::info(std::ostream& out) {
	Student::info();
	get_marks();
	std::cout << "UIR theme: " << UIR_theme << std::endl;
	std::cout << "UIR place: " << UIR_place << std::endl;
}

void Middle::set_info() {
	set_marks();
	set_UIR_theme();
	set_UIR_place();
}




void Senior::set_diploma_theme() {
	while (1) {
		std::cout << "Enter diploma theme: ";
		std::string theme;
		get_var(theme);
		if (theme == "") {
			if (std::cin.eof()) break;
			std::cout << "Diploma theme can't be empty";
			continue;
		}
		diploma_theme = theme;
		break;
	}
}

void Senior::set_diploma_place() {
	while (1) {
		std::cout << "Enter diploma place: ";
		std::string place;
		get_var(place);
		if (place == "") {
			if (std::cin.eof()) break;
			std::cout << "Diploma place can't be empty";
			continue;
		}
		diploma_place = place;
		break;
	}
}

void Senior::set_marks() {
	std::cout << "Enter UIR supervisor mark, reviewer mark and GEK mark: ";
	get_var(supervisor_mark);
	get_var(reviewer_mark);
	get_var(GEK_mark);
}

void Senior::get_marks() const {
	std::cout << "Supervisor mark: " << supervisor_mark << std::endl;
	std::cout << "Reviever mark: " << reviewer_mark << std::endl;
	std::cout << "GEK mark: " << GEK_mark << std::endl;
}

void Senior::info(std::ostream& out) {
	Student::info();
	std::cout << "Diploma theme: " << diploma_theme << std::endl;
	std::cout << "Diploma place: " << diploma_place << std::endl;
	get_marks();
}

void Senior::set_info() {
	set_marks();
	set_diploma_theme();
	set_diploma_place();
}
