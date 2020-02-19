#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED
#include "PrintEdition.h"
#include<iostream>
using namespace std;
class Book : public PrintEdition {
private:
	char* authorName;
	bool hasHardcovers;
	int year;
public:
	Book();
	Book(double, size_t, unsigned int, const char*, const char*, bool, int);
	Book(const Book&);
	Book& operator=(const Book&);
	~Book();

	void setAuthorName(const char*);

	double getSellPrice() const override;
	void showInfo() const override;
	virtual PrintEdition* clone() const override;

};
#endif //BOOK_H_INCLUDED
