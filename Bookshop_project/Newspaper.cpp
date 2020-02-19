#include "pch.h"
#include<iostream>
#include<cstring>
#include "Newspaper.h"

Newspaper::Newspaper() :PrintEdition() {
	strcpy_s(this->printDate, 11, "DD:MM:YYYY");
	setNumberOfAds(1);
}

Newspaper::Newspaper(double pricePerPage, size_t pages, unsigned int issue, const char * name, const char * printDate, size_t numberOfAds) : PrintEdition(pricePerPage, pages, issue, name) {

	strcpy_s(this->printDate, 11, printDate);
	setNumberOfAds(numberOfAds);
}

void Newspaper::setNumberOfAds(size_t numberOfAds) {
	this->numberOfAds = numberOfAds;
}

const char * Newspaper::getPrintDate() const {
	return this->printDate;
}

size_t Newspaper::getNumberOfAds() const {
	return this->numberOfAds;
}

double Newspaper::getSellPrice() const {
	return getPrintPrice() + numberOfAds * (-0.05);
}

void Newspaper::showInfo() const {
	std::cout << "Name of the print edition: " << name << std::endl;
	std::cout << "Issue: " << issue << std::endl;
	std::cout << "Pages: " << pages << std::endl;
	std::cout << "Price per page: " << pricePerPage << std::endl;
	std::cout << "The newspaper has " << numberOfAds << " ads" << std::endl;
	std::cout << "Print date: " << printDate << std::endl;
	std::cout << "Price: " << getSellPrice() << std::endl;
}

PrintEdition * Newspaper::clone() const
{
	return new Newspaper(*this);
}
