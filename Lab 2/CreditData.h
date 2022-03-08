#pragma once

#include <iostream>

using namespace std;

class CreditData {
private:
	double currentBalance;
	double maxBalance;
public:
	CreditData() = default;
	CreditData(double, double = 0);
	void displayCreditData();
};