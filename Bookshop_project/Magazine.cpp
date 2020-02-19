#include "pch.h"
#include "Magazine.h"
#include<iostream>

Magazine::Magazine() :PrintEdition() {
	this->hasPosters = true;
	this->numberOfInterviews = 3;
}

Magazine::Magazine(double pricePerPage, size_t pages, unsigned int issue, const char *name, bool hasPosters, size_t numberOfInterviews) : PrintEdition(pricePerPage, pages, issue, name) {
	this->hasPosters = hasPosters;
	this->numberOfInterviews = numberOfInterviews;
}

double Magazine::getSellPrice() const {
	return getPrintPrice() + ((hasPosters) ? 1.5 : 0) + numberOfInterviews * 1;
}

void Magazine::showInfo() const {
	std::cout << "Name of the print edition: " << name << std::endl;
	std::cout << "Issue: " << issue << std::endl;
	std::cout << "Pages: " << pages << std::endl;
	std::cout << "Price per page: " << pricePerPage << std::endl;
	std::cout << "The magazine " << ((hasPosters) ? "has" : "doesn't have") << " posters" << std::endl;
	std::cout << "The magazine has " << numberOfInterviews << " interviews" << std::endl;
	std::cout << "Price of the magazine: " << getSellPrice() << std::endl;
}

PrintEdition * Magazine::clone() const
{
	return new Magazine(*this);
}
