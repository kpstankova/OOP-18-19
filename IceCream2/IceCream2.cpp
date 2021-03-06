#include "pch.h"
#include <iostream>
#include<cstring>
#include "IceCream2.h"

IceCream::IceCream()
{
	setName("Default");
	setNumberOfBalls(2);
	IceCreamFlavour();
}

IceCream::IceCream(const char *name, int numberOfBalls, IceCreamFlavour flavour):name(nullptr)
{
	this->setName(name);
	this->setNumberOfBalls(numberOfBalls);
	this->setIceCreamFlavour(flavour);
}

IceCream::IceCream(const IceCream& other)
{
	setName(other.name);
	setNumberOfBalls(other.numberOfBalls);
	setIceCreamFlavour(other.flavour);
}

IceCream & IceCream::operator=(const IceCream & other)
{
	if (this!=&other)
	{
		setName(other.name);
		setNumberOfBalls(other.numberOfBalls);
		setIceCreamFlavour(other.flavour);
	}
	return *this;
}

IceCream::~IceCream()
{
	delete[] this->name;
}

void IceCream::setName(const char *name)
{
	if (name!=nullptr)
	{
		delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}
}

void IceCream::setNumberOfBalls(int numberOfBalls)
{
	this->numberOfBalls = numberOfBalls;
}

void IceCream::setIceCreamFlavour(IceCreamFlavour flavour)
{
	this->flavour = flavour;
}

const char * IceCream::getName() const
{
	return this->name;
}

int IceCream::getNumberOfBalls() const
{
	return this->numberOfBalls;
}

IceCreamFlavour IceCream::getIceCreamFlavour() const
{
	return this->flavour;
}

double IceCream::getPrice() const
{
	return numberOfBalls * flavour.pricePerBall;
}

void IceCream::print() const
{
	cout <<"Flavour: "<< flavour.name << endl;
	cout <<"Price per ball: "<< flavour.pricePerBall << endl;
	cout <<"Name of the IceCream: "<< name << endl;
	cout <<"Number of balls: "<< numberOfBalls << endl;
}

bool IceCream::operator<(const IceCream &other)const
{
	if (strcmp(this->flavour.getNameF(),other.flavour.getNameF())<0 && (this->flavour.getPricePerBall()<other.flavour.getPricePerBall()) && (this->getNumberOfBalls()<other.getNumberOfBalls())&&strcmp(this->getName(),other.getName())<0)
	{
		return true;
	}
	return false;
}

bool IceCream::operator>(const IceCream & other)const
{
	if (strcmp(this->flavour.getNameF(), other.flavour.getNameF()) > 0 && (this->flavour.getPricePerBall() > other.flavour.getPricePerBall()) && (this->getNumberOfBalls() > other.getNumberOfBalls()) && strcmp(this->getName(), other.getName()) > 0)
	{
		return true;
	}
	return false;
}

bool IceCream::operator<=(const IceCream &other)const
{
	if (strcmp(this->flavour.getNameF(), other.flavour.getNameF()) <= 0 && (this->flavour.getPricePerBall() <= other.flavour.getPricePerBall()) && (this->getNumberOfBalls() <= other.getNumberOfBalls()) && strcmp(this->getName(), other.getName()) <= 0)
	{
		return true;
	}
	return false;
}

bool IceCream::operator>=(const IceCream &other)const
{
	if (strcmp(this->flavour.getNameF(), other.flavour.getNameF()) >= 0 && (this->flavour.getPricePerBall() >= other.flavour.getPricePerBall()) && (this->getNumberOfBalls() >= other.getNumberOfBalls()) && strcmp(this->getName(), other.getName()) >= 0)
	{
		return true;
	}
	return false;
}

bool IceCream::operator==(const IceCream& other)const
{
	if (strcmp(this->flavour.getNameF(), other.flavour.getNameF()) == 0 && (this->flavour.getPricePerBall() == other.flavour.getPricePerBall()) && (this->getNumberOfBalls() == other.getNumberOfBalls()) && strcmp(this->getName(), other.getName()) == 0)
	{
		return true;
	}
	return false;
}

bool IceCream::operator!=(const IceCream& other)const
{
	if (strcmp(this->flavour.getNameF(), other.flavour.getNameF()) != 0 && (this->flavour.getPricePerBall() != other.flavour.getPricePerBall()) && (this->getNumberOfBalls() != other.getNumberOfBalls()) && strcmp(this->getName(), other.getName()) != 0)
	{
		return true;
	}
	return false;
}

IceCreamFlavour::IceCreamFlavour()
{
	name[0] = '\0';
	pricePerBall = 0;
}

IceCreamFlavour::IceCreamFlavour(char name[32], double pricePerBall)
{
	strcpy_s(this->name, strlen(name) + 1, name);
	this->pricePerBall = pricePerBall;
}
const char * IceCreamFlavour::getNameF() const
{
	return this->name;
}
double IceCreamFlavour::getPricePerBall() const
{
	return this->pricePerBall;
}
void printIceCreamWithFlavour(IceCream* arr, int size, IceCreamFlavour searchedFlavour)
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(arr[i].getIceCreamFlavour().name, searchedFlavour.name) == 0)
		{
			arr[i].print();
		}
	}
}
IceCream bestIceCream(IceCream* arr, int size, double money)
{
	int idx = -1, coutBallsMax = -1;
	double price = -5;
	for (int i = 0; i < size; i++)
	{
		if ((arr[i].getPrice() < money && arr[i].getNumberOfBalls() > coutBallsMax) || (arr[i].getPrice() > price && arr[i].getNumberOfBalls() == coutBallsMax))
		{
			idx = i;
			coutBallsMax = arr[i].getNumberOfBalls();
			price = arr[i].getPrice();
		}
	}
	return arr[idx];
}

void IceCreamContainer::resize()
{
	this->capacity *= 2;
	IceCream* newIceCream = new IceCream[this->capacity];
	for (size_t i = 0; i < this->size; i++)
	{
		newIceCream[i] = iceCreams[i];
	}
	delete[] this->iceCreams;
	iceCreams = newIceCream;
}
void IceCreamContainer::unsize()
{
	if(this->size<=(1/4)*this->capacity)
	{
		this->capacity /= 2;
		IceCream* newIceCream = new IceCream[this->capacity];
		for (size_t i = 0; i < this->size; i++)
		{
			newIceCream[i] = iceCreams[i];
		}
		delete[] this->iceCreams;
		iceCreams = newIceCream;
	}
}
void IceCreamContainer::popAt(size_t index)
{
	for (size_t i = index; i < this->size; i++)
	{
		this->iceCreams[i] = this->iceCreams[i + 1];
	}
	this->size--;
}

IceCreamContainer::IceCreamContainer()
{
	setSize(0);
	setCap(1);
	iceCreams = new IceCream[getSize() + 1];
}

IceCreamContainer::IceCreamContainer(IceCream * iceCreams, int size, int capacity)
{
	setSize(size);
	setCap(capacity);
	iceCreams = new IceCream[getSize() + 1];
}

IceCreamContainer::IceCreamContainer(const IceCreamContainer & other)
{
	for (int i = 0; i < other.getSize(); i++)
	{
		iceCreams[i] = other.iceCreams[i];
	}
	setSize(other.size);
	setCap(other.capacity);
}

IceCreamContainer & IceCreamContainer::operator=(const IceCreamContainer & other)
{
	if (this != &other)
	{
		for (int i = 0; i < other.getSize(); i++)
		{
			iceCreams[i] = other.iceCreams[i];
		}
		setSize(other.size);
		setCap(other.capacity);
	}
	return *this;
}
IceCreamContainer::~IceCreamContainer()
{
	delete[] this->iceCreams;
}

void IceCreamContainer::setSize(int size)
{
	this->size = size;
}

void IceCreamContainer::setCap(int capacity)
{
	this->capacity = capacity;
}

int IceCreamContainer::getSize() const
{
	return this->size;
}

int IceCreamContainer::getCap() const
{
	return this->capacity;
}

void IceCreamContainer::addIceCream(const IceCream & obj)
{
	if (this->size>=this->capacity)
	{
		this->resize();
	}
	this->iceCreams[this->size++] = obj;
}

void IceCreamContainer::removeIceCream(int index)//removes an ice cream by name
{
	if (index >= getSize()) return;
	
	this->size--;
	for (size_t i = index; i < getSize(); i++)
	{
		iceCreams[i] = iceCreams[i + 1];
	}
}

bool IceCreamContainer::has(const IceCream & obj)
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(iceCreams[i].getIceCreamFlavour().name,obj.getIceCreamFlavour().name)==0 
			&& strcmp(iceCreams[i].getName(),obj.getName())==0 
			&& (iceCreams[i].getIceCreamFlavour().pricePerBall)==(obj.getIceCreamFlavour().pricePerBall)
			&& iceCreams[i].getPrice()==obj.getPrice())
		{
			return true;
		}
	}
	return false;
}

double IceCreamContainer::fullPriceOfIceCreams() const
{
	double fullPrice = 0;
	for (int i = 0; i < size; i++)
	{
		fullPrice = fullPrice + iceCreams[i].getPrice();
	}
	return fullPrice;
}

