#include"pch.h"
#include <iostream>
#include<cstring>
#include "PrintEdition.h"

PrintEdition::PrintEdition() {
	setName("Defaut");
	setIssue(1000);
	setPages(10);
	setPricePerPage(0.5);
}

PrintEdition::PrintEdition(double pricePerPage, size_t pages, unsigned int issue, const char *name) :name(nullptr) {
	setName(name);
	setPages(pages);
	setIssue(issue);
	setPricePerPage(pricePerPage);
}

PrintEdition::PrintEdition(const PrintEdition & other) {
	setName(other.name);
	setPages(other.pages);
	setIssue(other.issue);
	setPricePerPage(other.pricePerPage);
}

PrintEdition & PrintEdition::operator=(const PrintEdition & other) {
	if (this != &other) {
		setName(other.name);
		setPages(other.pages);
		setIssue(other.issue);
		setPricePerPage(other.pricePerPage);
	}
	return *this;
}

PrintEdition::~PrintEdition() {
	delete[] this->name;
}

void PrintEdition::setName(const char *name) {
	if (name != nullptr) {
		delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}
}

void PrintEdition::setIssue(unsigned int issue) {
	this->issue = issue;
}

void PrintEdition::setPages(size_t pages) {
	this->pages = pages;
}

void PrintEdition::setPricePerPage(double pricePerPage) {
	this->pricePerPage = pricePerPage;
}

const char * PrintEdition::getName() const {
	return this->name;
}

unsigned int PrintEdition::getIssue() const {
	return this->issue;
}

size_t PrintEdition::getPages() const {
	return this->pages;
}

double PrintEdition::getPricePerPage() const {
	return this->pricePerPage;
}

double PrintEdition::getPrintPrice() const
{
	return pages * pricePerPage;
}

bool PrintEdition::operator==(const PrintEdition & other)const{
	return strcmp(this->name,other.name)==0;
}
