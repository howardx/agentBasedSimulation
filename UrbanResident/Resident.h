/*
 * Resident.h
 *
 *  Created on: Oct 9, 2012
 *      Author: howard
 */

#ifndef RESIDENT_H_
#define RESIDENT_H_
using namespace std;

class Resident
{
public:
	Resident(int age, bool marriage, bool inhouse, bool isMigrant, double location, double scale);
	// constructor
	virtual ~Resident();
	// destructor
	void step();
	int getAge();
	void setAge(int); // set age ---- SETTER
	bool getMarriage();
	void setMarriage(bool); // set marriage status ---- SETTER
	bool getInhouse();
	void setInhouse(bool);
	bool getMigrant();
	void setMigrant(bool);
	double getLocation();
	void setLocation(double);
	double getScale();
	void setScale(double);


private:
	int age;
	bool marriage;
	bool inhouse;
	bool isMigrant;
	double location;
	double scale;
};

#endif /* RESIDENT_H_ */
