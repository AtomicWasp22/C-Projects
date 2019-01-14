#pragma once

#ifndef ToDo_H_
#define ToDo_H_

#include <string>

class ToDo
{

public:
	std::string task;
	int priority;
	ToDo();
	~ToDo();
};

#endif