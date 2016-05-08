#ifndef HMM_H
#define HMM_H

#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include <opencv2\core.hpp>

class HmmException : public std::exception
{
public:
	HmmException();
};


class HMM
{
private:

	unsigned int state_num;
	unsigned int symbol_num;
	cv::Mat prior;
	cv::Mat transition;
	cv::Mat emission;



public:

	HMM(cv::Mat prior, cv::Mat transition, cv::Mat emission);

	std::vector<int> viterbi(std::vector<int> emission);

	cv::Mat filter(cv::Mat& f, int symbol);

};



#endif