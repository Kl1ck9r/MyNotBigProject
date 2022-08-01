#include <iostream>

using std::string;

class BusStation {
private :
	
	int numberRoute;
	int numberFreeSeats[12];
	std::string nameBus;
	std::string time;
	std::string WhereTo;
	std::string WhereFrom;

public:
	BusStation();
	BusStation(int numberRoute, int numberFreeSeats[], const string& nameBus,
		const string& time, const string& WhereTo, const string& WhereFrom);
	int NumFree();
	int NumRoute() { return numberRoute; }
	const string& TimeStart() { return time; }
	void OnlyNumber(const string &nameFile);
	void AddInFile(const BusStation &st,const string nameFile);
	void ViewOfFile(const string nameFile);
	void  RemoveChoiceString(const string& nameFile);
	virtual void Show()const;
	virtual ~BusStation() {}
};

class PricesOnBus : public BusStation
{
private:
	double price;
public:
	PricesOnBus(double price = 0.1)  {}
	PricesOnBus(int numberRoute, int numberFreeSeats[], const string& nameBus,
		const string& time, const string& WhereTo, const string& WhereFrom, double prc);
	double Price() { return price; }
	void AddInFile(const PricesOnBus &st,const string nameFile);
	void ViewOfFile( const string nameFile);
	void Show()const override;
	~PricesOnBus() {}
};
