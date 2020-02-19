#ifndef MAGAZINE_H_INCLUDED
#define MAGAZINE_H_INCLUDED
#include"PrintEdition.h"
class Magazine : public PrintEdition {
private:
	bool hasPosters;
	size_t numberOfInterviews;
public:
	Magazine();
	Magazine(double, size_t, unsigned int, const char*, bool, size_t);

	double getSellPrice()const override;
	void showInfo() const override;
	virtual PrintEdition* clone() const override;
};
#endif //MAGAZINE_H_INCLUDED
