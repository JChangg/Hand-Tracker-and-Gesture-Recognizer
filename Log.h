#ifndef LOGGER_H
#define LOGGER_H
#include<fstream>
#include<string>
#include<sstream>
#include<ctime>
#include<chrono>
#include"Settings.h"
#include"Exception.h"
#include<opencv2/core.hpp>
#define LOG_TIME std::chrono::time_point<std::chrono::system_clock>
#define LOG_GET_TIME() std::chrono::system_clock::now()




class Logger
{
private:
	std::ofstream file, posfile;
	std::chrono::time_point<std::chrono::system_clock> start_time;
	std::chrono::time_point<std::chrono::system_clock> frame_time;
public:
	std::string name;
	Logger();
	double ms_elapsed();
	void frame();
	void update_position(cv::Point& pt);
	void event(std::string msg);
	void except(HandException& e);
};

std::string get_name();
std::string get_name(std::string name);

class BasicLog
{
protected:
	std::string name;
	std::ofstream file;
public:	
	BasicLog();
	BasicLog(std::string name);
};



class OperationLog : public BasicLog
{
	int key_press;
	LOG_TIME frame_arrival;
	std::vector<bool> events;
public:
	OperationLog();
	OperationLog(std::string name);
	void start();
	void frame();
	void key(int keypress);
};



class ResultLog : public BasicLog
{
public:
	ResultLog();
	ResultLog(std::string name);
	void time(double ms);
	void message(std::string s);
	void position(cv::Point& p);
	void next();
};


#endif // !LOGGER_H

