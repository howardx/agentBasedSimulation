/*
 * Configure.h
 *
 *  Created on: Oct 11, 2012
 */

//#include <string>
//using namespace std;

#ifndef CONFIGURE_H_
#define CONFIGURE_H_

//const static double ConsumerConfidence = .85; // worst scenario, equal to 0.65/0.85, makes max value as 0.65
const static double ConsumerConfidence = 1; // median case with max value as .85

const static int NumberofRuns = 1; // run the model this many times and create mean, 15% confidence band and etc.
const static int Iteration = 16; //20 for backtesting
// number of iterations/years for running the model

/* 1 million agents tried with execution time of around 2 minutes
 * 100 million agents won't work
 * 100 thousand agents takes around 2 seconds
 *
 * Using cohorts of 1000 as an agent
 */

const static int AgeGroup = 20; // count of different age groups

// array with percentage of married man, each element applies for 5 years from 15 to 65+
const static double MarriagePercentage[11] = { .0027, .2105, .7369, .8929, .9132};//, .9067, .9002, .8837, .8581, .8187, .681};

// for buy house logistic distribution CDF generating on the fly
const static double Single_MaxLocation = 6.0;
const static double Single_MinLocation = 4.0;
const static double Single_MaxScale = .6;
const static double Single_MinScale = .5;

const static double Married_MaxLocation = 6.0;
const static double Married_MinLocation = 4.0;
const static double Married_MaxScale = .6;
const static double Married_MinScale = .5;

//const static double DeathRate[17] = {.00405, .00097, .00049, .00077, .00143, .00076, .00177, .00168, .00145, .00368, .00625, .01049, .01399, .02115, .04248, .08617, .12822};
const static double DeathRate[17]={.00081, .000194, .000098, .000154, .000286, .000152, .000354, .000336, .00029, .000736, .00125, .002098, .002798, .00423, .008496, .017234, .025644};
// from www.infobase.gov.cn   Array with death rate, each element applies for 5 years from 0 to 80+

//amount of agents in age groups:   0-4, 5-9, 10-14, 15-19,20-24,25-29,30-34,35-39,40-44,45-49,50-54,55-59,60-64,65-69,70-74,75-79,80-84 // with 2 omitted !!
const int InitialAgents[AgeGroup]={45424,44966,48876,54855,63348,51969,48174,60490,62855,51619,40668,40691,28463,20158,16039,11427,6253,2691,841,172}; // -- 2010

//BACK-TESTING NUMBERS
//const int InitialAgents[AgeGroup]={19250,21503,20748,28856,33626,32424,27392,25515,18231,14097,13730,12019,9016,6398,4193,2599,1300,502,102,16};
// -- 1993 without migrants counted

/*
 * The following integer arrays may be change into percentages indicating the weight of
 * each age group within rural immigration population; in order to change the sum of
 * rural immigration population and apply beta distribution for generating actual numbers for amounts of
 * immigration age groups.
 */
// migrations from 2011 to 2015, range from 20 to 39, age distribution skew toward younger group, then linear decrease


const double MigrantPercentage[AgeGroup] = {0,0,0,0,.4,.3,.2,.1,0,0,0,0,0,0,0,0,0,0,0,0}; //sum up to 100% , amount of 10 MLN(1000 cohort) -- 1993

//const double MigrantSum[Iteration] = {20000,20000,20000,20000,20000,20000,20000,20000,20000,20000,20000,20000,20000,20000,20000,20000,20000,20000,20000,20000};
// 1993 to 2012 including head & tail 20 years

const double MigrantSum[Iteration] = {20000,18800,17600,16400,15200,14000,13400,12800,12200,11600,11000,10200,9400,8600,7800,7000};

/*
///////////////////////////// BLOOMBERG NUMBER ////////////////////////////
2011-2015 20MLN   2016-2020 15MLN    2021-2025 12MLN  (Annual Migration Number)
 */
#endif /* CONFIGURE_H_ */
