#pragma once

#include "Binary_tree.h"
#include "Students.h"

class Table {
private:
	Binary_tree<int, Student*> tree;

public:
	Table() { }

	~Table() {
		for (auto it = tree.begin(); it != tree.end(); ++it) {
			Student* st = it->second;
			delete st;
		}
	}
	
	Binary_tree<int, Student*>::iterator begin() { return tree.begin(); }
	Binary_tree<int, Student*>::iterator end() { return tree.end(); }

	void add_student(Student* st);
	void replace_student(Student* st);

	Student* find_st(int id);
	bool check_st(int id);
	void delete_st(int id);

	void show_stud(std::ostream& out = std::cout);
	void change_type(int id, Student::category new_category);
};
