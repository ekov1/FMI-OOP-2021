//Да се напише структура "Book", която съдържа следната информация(полета) :
//
//    име на книгата
//    име на автора
//    жанр
//    цена
//    брой продажби
//    други по ваш избор
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

const int SIZE = 100;

struct Book {
	char title[SIZE];
	char author[SIZE];
	char genre[SIZE];
	double price;
	int sales;
};

//Напишете функция, която прочита въведени стойности 
//и ги задава като стойности на полетата на подаден обект от горния тип.
void Initialize(Book& b) {
	cout << "Title: " << endl;
	cin.sync();
	cin.getline(b.title, SIZE);

	cout << "Author: " << endl;
	cin.sync();
	cin.getline(b.author, SIZE);

	cout << "Genre: " << endl;
	cin.sync();
	cin.getline(b.genre, SIZE);

	cout << "Price: " << endl;
	cin.sync();
	cin >> b.price;

	cout << "Sales: " << endl;
	cin.sync();
	cin >> b.sales;
	cin.ignore();
}

// Напишете функция, която отпечатва информацията от даден обект горния тип.
void Print(const Book& b) {
	cout << "Title: " << b.title << endl;
	cout << "Author: " << b.author << endl;
	cout << "Genre: " << b.genre << endl;
	cout << "Price: " << b.price << endl;
	cout << "Sales: " << b.sales << endl;
}

void PrintBookWiththeLowestPrice(const Book* books, int booksCount) {
	int lp = books[0].price;
	int bestBookId = 0;

	for (int i = 0; i < booksCount; ++i)
	{
		if (books[i].price < lp)
		{
			lp = books[i].price;
			bestBookId = i;
		}
	}

	Print(books[bestBookId]);
}

Book GetBestSellingBook(const Book* books, int booksCount) {
	int ms = books[0].price;
	int bestBookId = 0;

	for (int i = 0; i < booksCount; ++i)
	{
		if (books[i].sales > ms)
		{
			ms = books[i].sales;
			bestBookId = i;
		}
	}

	return books[bestBookId];
}

int main()
{
	const int booksCount = 3;
	Book books[booksCount];

	for (int i = 0; i < booksCount; i++)
	{
		Initialize(books[i]);
	}

	for (int i = 0; i < booksCount; i++)
	{
		Print(books[i]);
	}

	PrintBookWiththeLowestPrice(books, booksCount);

	Book bestBook = GetBestSellingBook(books, booksCount);

	Print(bestBook);

}