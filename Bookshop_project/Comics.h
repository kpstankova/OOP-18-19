#ifndef COMICS_H_INCLUDED
#define COMICS_H_INCLUDED
#include "PrintEdition.h"
class Comics : public PrintEdition {
private:
	bool hasGift;
	char* genre;
	size_t numberOfImages;
public:
	Comics();
	Comics(double, size_t, unsigned int, const char*, bool, const char*, size_t);
	Comics(const Comics&);
	Comics& operator=(const Comics&);
	~Comics();

	void setGenre(const char*);

	double getSellPrice()const override;
	void showInfo() const override;
	virtual PrintEdition* clone() const override;

};
#endif //COMICS_H_INCLUDED
