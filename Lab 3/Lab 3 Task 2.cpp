#include <iostream>
#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"

using namespace std;


void Package::setSenderName(const string& name)
{
    this->senderName = name;
};

string Package::getSenderName() const
{
    return this->senderName;

};

void Package::setSenderAddress(const string& name)
{
    this->senderAddress = name;
};

string Package::getSenderAddress() const
{
    return this->senderAddress;

};

void Package::setSenderCity(const string& name)
{
    this->senderCity = name;
};

string Package::getSenderCity() const
{
    return this->senderCity;

};

void Package::setSenderState(const string& name)
{
    this->senderState = name;
};

string Package::getSenderState() const
{
    return this->senderState;

};

void Package::setSenderZIP(int name)
{
    this->senderZIP = name;
};

int Package::getSenderZIP() const
{
    return this->senderZIP;

};


void Package::setRecipientName(const string& name)
{
    this->recipientName = name;
};

string Package::getRecipientName() const
{
    return this->recipientName;

};

void Package::setRecipientAddress(const string& name)
{
    this->recipientAddress = name;
};

string Package::getRecipientAddress() const
{
    return this->recipientAddress;

};

void Package::setRecipientCity(const string& name)
{
    this->recipientCity = name;
};

string Package::getRecipientCity() const
{
    return this->recipientCity;

};

void Package::setRecipientState(const string& name)
{
    this->recipientState = name;
};

string Package::getRecipientState() const
{
    return this->recipientState;

};

void Package::setRecipientZIP(int name)
{
    this->recipientZIP = name;
};

int Package::getRecipientZIP() const
{
    return this->recipientZIP;

};

void Package::setCostPerOunce(double weight)
{
    this->costPerKg = weight;
};

double Package::getCostPerKg() const
{
    return this->costPerKg;
};

void Package::setWeight(double weight)
{
    this->weight = weight;
}

double Package::getWeight() const
{
    return this->weight;
};

double Package::calculateCost() const
{
    return this->weight * this->costPerKg;
}

Package::Package(const string& sname, const string& saddr, const string& scity, const string& sstate, int szip, 
const string& rname, const string& raddr, const string& rcity, const string& rstate, 
int rzip, double weight, double costpkg)
{
    Package::setSenderName(sname);
    Package::setSenderAddress(saddr);
    Package::setSenderCity(scity);
    Package::setSenderState(sstate);
    Package::setSenderZIP(szip);

    Package::setRecipientName(rname);
    Package::setRecipientAddress(raddr);
    Package::setRecipientCity(rcity);
    Package::setRecipientState(rstate);
    Package::setRecipientZIP(rzip);

    Package::setWeight(weight);
    Package::setCostPerOunce(costpkg);

};

void OvernightPackage::setOvernightFeePerKg(double price)
{
    this->overnightFeePerKg = price;
};

double OvernightPackage::getOvernightFeePerKg() const
{
    return this->overnightFeePerKg;
};

double OvernightPackage::calculateCost() const
{
    return ( (this->getWeight() * this->getCostPerKg()) + (this->getOvernightFeePerKg() * this->getWeight()) );
};

void TwoDayPackage::setFlatFee(double price)
{
    this->flatFee = price;
};

double TwoDayPackage::getFlatFee() const
{
    return this->flatFee;
};

double TwoDayPackage::calculateCost() const
{
    return ( (this->getWeight() * this->getCostPerKg()) + this->getFlatFee());
};



OvernightPackage::OvernightPackage(const string& sname, const string& saddr, const string& scity, const string& sstate, int szip, 
const string& rname, const string& raddr, const string& rcity, const string& rstate, 
int rzip, double weight, double costpkg, double overnightfee) : Package (sname, saddr, scity, sstate, szip, 
                rname, raddr, rcity,rstate, 
                        rzip, weight,costpkg)
{
    OvernightPackage::setOvernightFeePerKg(overnightfee);
};

TwoDayPackage::TwoDayPackage(const string& sname, const string& saddr, const string& scity, const string& sstate, int szip, 
const string& rname, const string& raddr, const string& rcity, const string& rstate, 
int rzip, double weight, double costpkg, double flatfee) : Package (sname, saddr, scity, sstate, szip, 
                rname, raddr, rcity,rstate, 
                        rzip, weight,costpkg)
{
    TwoDayPackage::setFlatFee(flatfee);
};


int main() 
{
	Package pk1("Bruce Lee", "1 Fighting Rd", "Hong Kong", "China", 12345, "Alice Wong", "Jurong Ave 1", "Jurong", "Singapore", 23456, 10.5, 0.65);

    TwoDayPackage pk2("Donald Trump", "1600 Pen Ave", "Washington", "USA"
    , 34567, "Barack Obama", "21 Demo St", "Washington", "USA", 34556, 10.5, 0.65, 2.0);

    OvernightPackage pk3 ("Lee Hsien Loong", "1 Parliament", "CBD", "Singapore", 456456, "Bob Tan",
    "Yishun Ave 1", "Yishun", "Singapore", 234234, 12.25,0.7,0.25);

    cout<< "Package 1:"<<endl;
    cout<< "Sender: " << pk1.getSenderName() << endl;
    cout<< pk1.getSenderAddress() << " " << pk1.getSenderCity() << " " <<  pk1.getSenderState() << endl;

    cout<< "Recipient: " << pk1.getRecipientName() << endl;
    cout<< pk1.getRecipientAddress()<< " " <<  pk1.getRecipientCity() << " " <<  pk1.getRecipientState() << endl;

    cout<< "Cost: " << pk1.calculateCost() << endl << endl;

    cout<< "Package 2:"<<endl;
    cout<< "Sender: " << pk2.getSenderName() << endl;
    cout<< pk2.getSenderAddress() << " " << pk2.getSenderCity() << " " <<  pk2.getSenderState() << endl;

    cout<< "Recipient: " << pk2.getRecipientName() << endl;
    cout<< pk2.getRecipientAddress()<< " " <<  pk2.getRecipientCity() << " " <<  pk2.getRecipientState() << endl;

    cout<< "Cost: " << pk2.calculateCost() << endl << endl;

    cout<< "Package 3:"<<endl;
    cout<< "Sender: " << pk3.getSenderName() << endl;
    cout<< pk3.getSenderAddress() << " " << pk3.getSenderCity() << " " <<  pk3.getSenderState() << endl;

    cout<< "Recipient: " << pk3.getRecipientName() << endl;
    cout<< pk3.getRecipientAddress()<< " " <<  pk3.getRecipientCity() << " " <<  pk3.getRecipientState() << endl;

    cout<< "Cost: " << pk3.calculateCost() << endl << endl;

	return 0;
  // the code of this task can be quite long and detailed. so i share the code for package, 
  // twodaypackage, and overnightpackage with you. 
  // please integrate the files and complete this main function. 
}
