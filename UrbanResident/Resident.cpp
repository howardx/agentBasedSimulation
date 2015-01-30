/*
 * Resident.cpp
 *
 *  Created on: Oct 9, 2012
 *      Author: howard
 */
#include "Resident.h"
#include <iostream>

Resident::Resident(int age, bool marriage, bool inhouse, bool isMigrant, double location, double scale) :
age(age), marriage(marriage), inhouse(inhouse), isMigrant(isMigrant), location(location), scale(scale)
{
}

Resident::~Resident()
{
}

void Resident::step()
{
	int newage = getAge() + 1;
	setAge(newage);
}
void Resident::setAge(int newage)
{
	age = newage;
}
int Resident::getAge()
{
	return (age);
}
void Resident::setMarriage(bool marital)
{
	marriage = marital;
}
bool Resident::getMarriage()
{
	return (marriage);
}
bool Resident::getInhouse()
{
	return(inhouse);
}
void Resident::setInhouse(bool movein)
{
	inhouse = movein;
}
bool Resident::getMigrant()
{
	return(inhouse);
}
void Resident::setMigrant(bool migrant)
{
	isMigrant = migrant;
}
double Resident::getLocation()
{
	return(location);
}
void Resident::setLocation(double newLocation)
{
	location = newLocation;
}
double Resident::getScale()
{
	return (scale);
}
void Resident::setScale(double newScale)
{
	scale = newScale;
}
