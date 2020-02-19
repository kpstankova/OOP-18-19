#include "pch.h"
#include <iostream>
#include<iomanip>
#include"PrintEdition.h"
#include "Newspaper.h"
#include "Magazine.h"
#include "Book.h"
#include "Comics.h"
#include "BookShop.h"
bool mostPages(const PrintEdition & pe1, const PrintEdition & pe2)
{
	return pe1.getPages() > pe2.getPages();
}
bool mostExpensive(const PrintEdition & pe1, const PrintEdition & pe2) {
	return pe1.getSellPrice() > pe2.getSellPrice();
}
int main()
{
	Newspaper newspaper1(0.5, 20, 1500, "Daily", "27.04.19", 13),
	          newspaper2 (0.5, 18, 1501, "Daily", "28.04.19", 7);

	Magazine magazine1(0.7, 32, 2000, "Cosmopolitan", true, 7),
	         magazine2 (0.7, 33, 2000, "Elle", false, 0);
	
	Book book1(0.3, 500, 1000, "Song of Ice and Fire", "J.R.R. Martin", true, 2005),
		 book2(0.3, 600, 1001, "Song of Ice and Fire", "J.R.R.Martin", false, 2006);
	
	Comics comics1(0.2, 13, 2000, "Justice League of America", true, "Superhero", 15),
		   comics2(0.2, 17, 2001, "Batman", false, "SuperHero", 20);

	BookShop bookshop;

	bookshop.add(newspaper1);
	bookshop.add(newspaper2);
	bookshop.add(magazine1);
	bookshop.add(magazine2);
	bookshop.add(book1);
	bookshop.add(book2);
	bookshop.add(comics1);
	bookshop.add(comics2);

	do
	{
		std::cout<<std::setw(37) << "CHOOSE AN OPTION" << std::endl;
		std::cout << "-------------------------------------------------------------------+" << std::endl;
		std::cout << "->Press 1 to print all of the editions                             |" << std::endl;
		std::cout << "-------------------------------------------------------------------+" << std::endl;
		std::cout << "->Press 2 to see the most expensive edition in the Book Shop       |" << std::endl;
		std::cout << "-------------------------------------------------------------------+" << std::endl;
		std::cout << "->Press 3 to see the fullprice of all the editions in the Book Shop|" << std::endl;
		std::cout << "-------------------------------------------------------------------+" << std::endl;
		std::cout << "->Press 4 to sort the editions by their pages                      |" << std::endl;
		std::cout << "-------------------------------------------------------------------+" << std::endl;
		std::cout << "->Press 5 to sort the editions by their price                      |" << std::endl;
		std::cout << "-------------------------------------------------------------------+" << std::endl;
		std::cout << "->Press 6 to see the edition with most pages                       |" << std::endl;
		std::cout << "-------------------------------------------------------------------+" << std::endl;
		std::cout << "->Press anything else then 'Enter' to exit                                      |" << std::endl;
		std::cout << "-------------------------------------------------------------------+" << std::endl;

		int choise;
		std::cout << "Enter your choise: ";
		std::cin >> choise;

		switch (choise)
		{
		case 1: bookshop.showEditions();
			std::cout << std::endl;
			std::cout << std::endl;
			break;
		case 2: bookshop.getExtreme(mostExpensive);
			std::cout << std::endl;
			std::cout << std::endl;
			break;
		case 3: bookshop.getTotalPrice();
			std::cout << std::endl;
			std::cout << std::endl;
			break;
		case 4: bookshop.sort(mostPages);
			std::cout << std::endl;
			std::cout << std::endl;
			break;
		case 5: bookshop.sort(mostExpensive);
			std::cout << std::endl;
			std::cout << std::endl;
			break;
		case 6: bookshop.getExtreme(mostPages);
			std::cout << std::endl;
			std::cout << std::endl;
			break;
		default: return 0;
			break;
		}
	} while (true);

	return 0;

}
