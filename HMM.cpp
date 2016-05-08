#include "HMM.h"

HmmException::HmmException() {}

HMM::HMM(cv::Mat prior, cv::Mat transition, cv::Mat emission)
{
	this->prior = prior;
	this->transition = transition;
	this->emission = emission;

	state_num = prior.rows;
	symbol_num = emission.cols;
	if (state_num != transition.rows) throw HmmException();
	if (state_num != transition.cols) throw HmmException();
	if (state_num != emission.rows) throw HmmException();
	if (state_num != prior.rows) throw HmmException();

}


cv::Mat HMM::filter(cv::Mat& f, int symbol)
{
	cv::Mat f_t = this->emission.col(symbol).mul(transition.t() * f);
	double total = cv::sum(f_t).val[0];
	if (total == 0.0) return prior;
	return f_t / total;
}



std::vector<int> HMM::viterbi(std::vector<int> emissions)
{

	int T = emissions.size();
	std::vector<int> states(0);
	if (T == 0) return states;

	cv::Mat W = cv::Mat(state_num, T, CV_64F);
	cv::Mat path = cv::Mat(state_num, T - 1, CV_8U);

	W.col(0) = prior.mul(emission.col(emissions[0]));
	for (int i = 1; i < T; i++)
	{
		for (int j = 0; j < state_num; j++)
		{
			cv::Mat temp = transition.col(j) * (emission.at<double>(j, emissions[i]));
			temp = temp.mul(W.col(i - 1));
			std::cout << "temp = " << std::endl << temp << std::endl << std::endl;
			double min, max; cv::Point minIdx, maxIdx;
			cv::minMaxLoc(temp, &min, &max, &minIdx, &maxIdx);

			W.at<double>(j, i) = max;
			path.at<unsigned char>(j, i - 1) = maxIdx.y;
		}
	}

	std::cout << "W = " << std::endl << W << std::endl << std::endl;
	std::cout << "P = " << std::endl << path << std::endl << std::endl;


	return std::vector<int>();

}





