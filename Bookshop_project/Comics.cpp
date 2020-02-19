#include "pch.h"
#include "Comics.h"
#include<iostream>
#include<cstring>

Comics::Comics() :PrintEdition() {
	setGenre("Default");
	this->hasGift = true;
	this->numberOfImages = 5;
}

Comics::Comics(double pricePerPage, size_t pages, unsigned int issue,
	           const char * name, bool hasGift, const char * genre, size_t numberOfImages)
	           : PrintEdition(pricePerPage, pages, issue, name){
	setGenre(genre);
	this->hasGift = hasGift;
	this->numberOfImages = numberOfImages;
}

Comics::Comics(const Comics & other):PrintEdition(other){
	setGenre(other.genre);
	this->hasGift = other.hasGift;
	this->numberOfImages = other.numberOfImages;
}

Comics & Comics::operator=(const Comics & other){
	if (this!=&other){
		PrintEdition::operator=(other);
		setGenre(other.genre);
		this->hasGift = other.hasGift;
		this->numberOfImages = other.numberOfImages;
	}
	return *this;
}

Comics::~Comics() {
	delete[] this->genre;
}

void Comics::setGenre(const char * genre) {
	if (genre != nullptr) {
		delete[] this->genre;
		this->genre = new char[strlen(genre) + 1];
		strcpy_s(this->genre, strlen(genre) + 1, genre);
	}
}

double Comics::getSellPrice() const
{
	return getPrintPrice() + ((hasGift)? 2 : 0)+numberOfImages*0.3;
}

void Comics::showInfo() const{
	std::cout << "Name of the print edition: " << name << std::endl;
	std::cout << "Issue: " << issue << std::endl;
	std::cout << "Pages: " << pages << std::endl;
	std::cout << "Price per page: " << pricePerPage << std::endl;
	std::cout << "The comics " << ((hasGift) ? "has" : "doesn't have") << " a gift" << std::endl;
	std::cout << "The comics has " << numberOfImages << " images" << std::endl;
	std::cout << "Price of the magazine: " << getSellPrice() << std::endl;
}

PrintEdition * Comics::clone() const
{
	return new Comics (*this);
}
