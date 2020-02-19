#include "pch.h"
#include "BookShop.h"
#include<cstring>
#include<iostream>

void BookShop::resizeUp(){
	capacity *= 2;

	PrintEdition** temp = new PrintEdition*[capacity];

	for (unsigned int i = 0; i < size; ++i) {
		temp[i] = editions[i];
	}

	delete[] editions;

	editions = temp;

}

void BookShop::resizeDown(){
	capacity /= 2;

	PrintEdition** temp = new PrintEdition*[capacity];

	for (unsigned int i = 0; i < size; ++i) {
		temp[i] = editions[i];
	}

	delete[] editions;

	editions = temp;
}

void BookShop::copyOther(const BookShop & other){
	setNameOfBookShop(other.nameOfBookShop);
	setLocation(other.location);
	size = other.size;
	capacity = other.capacity;
	editions = new PrintEdition*[other.capacity];

	for (unsigned int i = 0; i < size; ++i) {
		editions[i] = other.editions[i]->clone();
	}
}

void BookShop::destroy(){
	for (unsigned int i = 0; i < size; ++i) {
		delete editions[i];
	}
	delete[] editions;
	delete[] location;
	delete[] nameOfBookShop;
}

BookShop::BookShop():BookShop("Default","Default",4)
{}

BookShop::BookShop(const char * nameOfBookShop, const char * location, unsigned int capacity){
	this->size = 0;
	this->capacity = (capacity >= 4) ? capacity : 4;
	this->editions = new PrintEdition*[this->capacity];
	setNameOfBookShop(nameOfBookShop);
	setLocation(location);
}

BookShop::BookShop(const BookShop & other){
	copyOther(other);
}

BookShop & BookShop::operator=(const BookShop &other){
	if (this!=&other){
		destroy();
		copyOther(other);
	}
	return *this;
}

BookShop::~BookShop(){
	destroy();
}

void BookShop::setNameOfBookShop(const char *nameOfBookShop){
	if (nameOfBookShop!=nullptr){
		delete[] this->nameOfBookShop;
		this->nameOfBookShop = new char[strlen(nameOfBookShop) + 1];
		strcpy_s(this->nameOfBookShop, strlen(nameOfBookShop) + 1, nameOfBookShop);
	}
}

void BookShop::setLocation(const char * location){
	if (location!=nullptr){
		delete[] this->location;
		this->location = new char[strlen(location) + 1];
		strcpy_s(this->location, strlen(location) + 1, location);
	}
}

void BookShop::add(const PrintEdition & edition){
	if (isFull()) resizeUp();

	editions[size++] = edition.clone();
}

void BookShop::remove(const PrintEdition & edition){
	for (unsigned int i = 0; i < size; ++i) {
		if (*(editions[i]) == edition) {
			delete editions[i];

			editions[i] = editions[size - 1];
			size--;

			if (size < capacity / 2) resizeDown();

			break;
		}
	}
}

bool BookShop::isFull() const{
	return size==capacity;
}

unsigned int BookShop::getSize() const{
	return this->size;
}

unsigned int BookShop::getCap() const{
	return this->capacity;
}

void BookShop::showEditions() const{
	for (unsigned int i = 0; i < size; ++i) {
		editions[i]->showInfo();
		std::cout << std::endl;
	}
	
	
}


void BookShop::getTotalPrice() const{
	double totalPrice = 0;

	for (unsigned int i = 0; i < size; ++i) {
		totalPrice += editions[i]->getSellPrice();
	}

	std::cout <<"The price is:"<< totalPrice << std::endl;
}

void BookShop::sort(bool(*comparator)(const PrintEdition & , const PrintEdition &)){
	for (unsigned int i = 0; i < this->getSize()-1; i++){
		for (unsigned int  j = i+1; j < this->getSize(); j++){
			if (comparator(*editions[i],*editions[j])){
				std::swap(editions[i], editions[j]);
			}
		}
	}
	showEditions();
}

PrintEdition & BookShop::getExtreme(bool(*comparator)(const PrintEdition &, const PrintEdition &)){
	PrintEdition* edition = this->editions[0];
	for (unsigned int i = 1; i < this->getSize(); i++){
		if (comparator(*editions[i],*edition)){
			edition = editions[i];
		}
	}
	edition->showInfo();
	return *edition;
	
	
	
}

