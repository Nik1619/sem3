#pragma once

#include <string>
#include <iostream>
#include <vector>

template<typename T>
bool get_var(T& a, std::istream& in = std::cin) {
	while (1) {
		in >> a;
		if (!in.good()) {
			if (in.eof()) return false; //^Z
			in.clear();
			in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		return true;
	}
}

class Student {
	unsigned int semester;
	std::string surname;
	std::string initials;
	int group_index;
	int stud_id;
	int cafedra;
public:
	Student(std::string surname, std::string initials, int group, int id, int sem, int cafedra) : surname(surname), initials(initials), group_index(group), stud_id(id), semester(sem), cafedra(cafedra)
	{
		if (semester > 9 || semester == 0) throw std::logic_error("Semester can't be more then 10");
	}

	enum class category {
		Junior,
		Middle,
		Senior
	};

	virtual void info(std::ostream& out = std::cout);

	virtual void set_marks() = 0;
	virtual void set_info() = 0;
	void set_group(int index) { group_index = index; }	
	virtual void get_marks() const = 0;
	void increase_semester() { ++semester; }

	virtual category get_category() const = 0;
	int get_id() { return stud_id; }
	std::string get_surname() const { return surname; }
	std::string get_initials() const { return initials; }
	int get_group() const { return group_index; }
	unsigned int get_semester() const { return semester; }
	int get_cafedra() const { return cafedra; }
};

std::ostream& operator<<(std::ostream& out, Student::category c);


class Junior : public Student {
	int exam_marks[5];

public:
	Junior(std::string surname, std::string initials, int group, int id, int sem, int cafedra, int marks[5]) : Student(surname, initials, group, id, sem, cafedra) {
		for (int i = 0; i < 5; ++i) {
			exam_marks[i] = marks[i];
		}
	}

	Junior(std::string surname, std::string initials, int group, int id, int sem, int cafedra) : Student(surname, initials, group, id, sem, cafedra) {
		set_marks();
	}

	Student::category get_category() const override { return Student::category::Junior; }

	void set_marks() override;
	void get_marks() const override;

	void info(std::ostream& out) override;
	void set_info() override;
};


class Middle : public Student {
	int exam_marks[4];
	std::string UIR_theme;	
	std::string UIR_place;
	int supervisor_mark;
	int comission_mark;

public:
	Middle(std::string surname, std::string initials, int group, int id, int sem, int cafedra, int marks[4],
			std::string theme, std::string place, int supervisor_mark, int comission_mark) :
				Student(surname, initials, group, id, sem, cafedra), UIR_theme(theme), UIR_place(place),
				supervisor_mark(supervisor_mark), comission_mark(comission_mark)
	{ 
		for (int i = 0; i < 4; ++i) 
		{
			exam_marks[i] = marks[i];
		}
	}

	Middle(std::string surname, std::string initials, int group, int id, int sem, int cafedra) : Student(surname, initials, group, id, sem, cafedra) {
		set_info();
	}

	Student::category get_category() const override { return Student::category::Middle; }

	std::string get_UIR_theme() const { return UIR_theme; };
	void set_UIR_theme();

	std::string get_UIR_place() const { return UIR_place; };
	void set_UIR_place();

	void set_marks() override;
	void get_marks() const override;

	void info(std::ostream& out) override;
	void set_info() override;
};


class Senior : public Student {
	std::string diploma_theme;
	std::string diploma_place;
	int supervisor_mark;
	int reviewer_mark;
	int GEK_mark;

public:
	Senior(std::string surname, std::string initials, int group, int id, int sem, int cafedra,
		std::string theme, std::string place, int supervisor_mark, int reviewer_mark, int GEK_mark) :
			Student(surname, initials, group, id, sem, cafedra), diploma_theme(theme), diploma_place(place),
			supervisor_mark(supervisor_mark), reviewer_mark(reviewer_mark), GEK_mark(GEK_mark)
	{ }


	Senior(std::string surname, std::string initials, int group, int id, int sem, int cafedra) : Student(surname, initials, group, id, sem, cafedra) {
		set_info();
	}

	Student::category get_category() const override { return Student::category::Senior; }

	void set_marks() override;
	void get_marks() const override;

	void info(std::ostream& out) override;
	void set_info() override;

	std::string get_diploma_theme() const { return diploma_theme; };
	void set_diploma_theme();

	std::string get_diploma_place() const { return diploma_place; };
	void set_diploma_place();
};