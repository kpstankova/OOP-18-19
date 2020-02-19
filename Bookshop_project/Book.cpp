#include "pch.h"
#include "Book.h"
#include<cstring>
#include<iostream>

Book::Book() :PrintEdition() {
	setAuthorName("Default");
	this->hasHardcovers = true;
	this->year = 2011;
}

Book::Book(double pricePerPage, size_t pages, unsigned int issue, const char * name, const char * authorName, bool hasHardcovers, int year)
	:PrintEdition(pricePerPage, pages, issue, name) {
	setAuthorName(authorName);
	this->hasHardcovers = hasHardcovers;
	this->year = year;
}

Book::Book(const Book & other) : PrintEdition(other) {
	setAuthorName(other.authorName);
	this->hasHardcovers = other.hasHardcovers;
	this->year = other.year;
}

Book & Book::operator=(const Book &other) {
	if (this != &other) {
		PrintEdition::operator=(other);
		setAuthorName(other.authorName);
		this->hasHardcovers = other.hasHardcovers;
		this->year = other.year;
	}
	return *this;
}

Book::~Book() {
	delete[] this->authorName;
}

void Book::setAuthorName(const char * authorName) {
	delete[] this->authorName;
	this->authorName = new char[strlen(authorName) + 1];
	strcpy_s(this->authorName, strlen(authorName) + 1, authorName);
}

double Book::getSellPrice() const {
	return getPrintPrice() + ((hasHardcovers) ? 5 : 2.5);
}

void Book::showInfo() const {
	std::cout << "Name of the print edition: " << name << std::endl;
	std::cout << "Issue: " << issue << std::endl;
	std::cout << "Pages: " << pages << std::endl;
	std::cout << "Price per page: " << pricePerPage << std::endl;
	std::cout << "Name of the author: " << authorName << std::endl;
	std::cout << "The book " << ((hasHardcovers) ? "has" : "doesn't have") << " hard covers" << std::endl;
	std::cout << "Year of publishing: " << year << std::endl;
	std::cout << "Price of the book: " << getSellPrice() << std::endl;
}

PrintEdition * Book::clone() const
{
	return new Book(*this);
}

