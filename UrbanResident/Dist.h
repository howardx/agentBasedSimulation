/*
 * Dist.h
 *
 *  Created on: Oct 10, 2012
 *      Author: howard
 */

#include "Configure.h"

#include <cstdlib>
#include <stdio.h>
#include <ctime>
#include <string.h>
#include <boost/random.hpp>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <boost/random/normal_distribution.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/variate_generator.hpp>
#include <boost/math/distributions/uniform.hpp>
#include <boost/random.hpp>
#include <boost/random/uniform_real.hpp>
#include <boost/random/uniform_int.hpp>
#include <iostream>
#include <boost/math/distributions/logistic.hpp>
using namespace std;
using namespace boost;
using namespace math;

#ifndef DIST_H_
#define DIST_H_

class Dist
{
public:
  // constructor
  Dist(int seed);

  // destructor
  virtual ~Dist();

  double GetUnifDist(double min, double max);
  double GetLogisDist(double, double, double);

  bool ChooseMarriage(int age);
  bool ChooseSurvival(int age);
  bool ChooseBuyHouse(double, double, int);

  bool GetMarried(int age);
  bool GetHouse(double, double, int);

private:
  int seed;
  boost::mt19937 PseudoGen;
};

#endif /* DIST_H_ */
