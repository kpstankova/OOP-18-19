#ifndef NEWSPAPER_H_INCLUDED
#define NEWSPAPER_H_INCLUDED
#include"PrintEdition.h"
class Newspaper : public PrintEdition {
private:
	char printDate[11];
	size_t numberOfAds;
public:
	Newspaper();
	Newspaper(double, size_t, unsigned int, const char*, const char*, size_t);

	void setNumberOfAds(size_t);

	const char* getPrintDate()const;
	size_t getNumberOfAds() const;

	double getSellPrice() const override;
	void showInfo() const override;
	virtual PrintEdition* clone() const override;
};
#endif //NEWSPAPER_H_INCLUDED
