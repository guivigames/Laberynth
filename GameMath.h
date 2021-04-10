#pragma once
#ifndef __GAMEMATH__
#define __GAMEMATH__
class vec2d;
class vec2i;

class vec2d 
{
public:
	double x, y;
	vec2d() { x = 0; y = 0; };
	vec2d(double _x, double _y) { x = _x; y = _y; };
	vec2d operator+(const vec2d& vec);
	vec2d operator-(const vec2d& vec);
	vec2d operator*(const vec2d& vec);
	vec2d operator*(const int& value);
	vec2d operator*(const double& value);
	vec2d operator/(const vec2d & vec);
	vec2d& operator+=(const vec2d& vec);
	vec2d& operator-=(const vec2d& vec);
	vec2d& operator*=(const vec2d& vec);
	vec2d& operator/=(const vec2d& vec);
	vec2d& operator=(const vec2d& vec);
	operator vec2i();
	double mag();
	vec2d norm();
};

class vec2i 
{
public:
	int x, y;
	vec2i() { x = 0; y = 0; };
	vec2i(int _x, int _y) { x = _x; y = _y; };
	vec2i operator+(const vec2i& vec);
	vec2i operator-(const vec2i& vec);
	vec2i operator*(const vec2i& vec);
	vec2i operator*(const int& value);
	vec2i operator*(const double& value);
	vec2i operator/(const vec2i& vec);
	vec2i& operator+=(const vec2i& vec);
	vec2i& operator-=(const vec2i& vec);
	vec2i& operator*=(const vec2i& vec);
	vec2i& operator/=(const vec2i& vec);
	vec2i& operator=(const vec2i& vec);
	operator vec2d();
	double mag();
	vec2d norm();
};

#endif 