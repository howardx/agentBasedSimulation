/*
 * go.h
 *
 *  Created on: Oct 17, 2012
 *      Author: howard
 */

#ifndef GO_H_
#define GO_H_

#include "Resident.h"
#include "Dist.h"
#include "Configure.h"
#include <iostream>
#include <list>
#include <fstream>
using namespace std;

void go(list<Resident>&, const int *, bool, Dist &); // pass by reference C++ for the std::list

#endif /* GO_H_ */
