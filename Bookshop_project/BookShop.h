#ifndef BOOKSHOP_H_INCLUDED
#define BOOKSHOP_H_INCLUDED
#include "PrintEdition.h"
class BookShop {
private:
	unsigned int size;
	unsigned int capacity;
	PrintEdition** editions;
	char* nameOfBookShop;
	char* location;

	void resizeUp();
	void resizeDown();
	void copyOther(const BookShop&);
	void destroy();
public:
	BookShop();
	BookShop(const char*, const char*, unsigned int);
	BookShop(const BookShop&);
	BookShop& operator=(const BookShop&);
	~BookShop();

	void setNameOfBookShop(const char*);
	void setLocation(const char*);

	void add(const PrintEdition&);
	void remove(const PrintEdition&);

	bool isFull()const;

	unsigned int getSize()const;
	unsigned int getCap()const;

	void showEditions()const;
	void getTotalPrice()const;

	void sort(bool(*comparator)(const PrintEdition&, const PrintEdition&));
	PrintEdition& getExtreme(bool(*comparator)(const PrintEdition&, const PrintEdition&));
};
#endif // BOOKSHOP_H_INCLUDED

