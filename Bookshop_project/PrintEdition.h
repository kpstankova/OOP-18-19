#ifndef PRINTEDITION_H_INCLUDED
#define PRINTEDITION_H_INCLUDED


class PrintEdition {
protected:
	double pricePerPage;
	size_t pages;
	unsigned int issue;
	char* name;
public:
	PrintEdition();
	PrintEdition(double, size_t, unsigned int, const char*);
	PrintEdition(const PrintEdition&);
	PrintEdition& operator=(const PrintEdition&);
	virtual ~PrintEdition();

	void setName(const char*);
	void setIssue(unsigned int);
	void setPages(size_t);
	void setPricePerPage(double);

	const char* getName()const;
	unsigned int getIssue()const;
	size_t getPages()const;
	double getPricePerPage() const;

	virtual double getSellPrice()const = 0;
	virtual void showInfo() const = 0;

	double getPrintPrice() const;

	bool operator==(const PrintEdition&)const;
	virtual PrintEdition* clone() const = 0;
};
#endif //PRINTEDITION_H_INCLUDED

