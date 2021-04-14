#pragma once
#ifndef __GAMEMATH__
#define __GAMEMATH__

/// <summary>
/// Generic template for 2 dimentional vector manipulation
/// </summary>
/// <typeparam name="T"></typeparam>
template <class T>
struct vec2g
{
	T x;
	T y;
	vec2g(): x(0), y(0) {};
	vec2g(T _x, T _y) : x(_x), y(_y) {};
	vec2g(const vec2g& v) : x(v.x), y(v.y) {};
	vec2g& operator=(const vec2g& v) = default;
	vec2g operator+(const vec2g& vec)const { return vec2g(this->x + vec.x, this->y + vec.y); };
	vec2g operator-(const vec2g& vec)const { return vec2g(this->x - vec.x, this->y - vec.y); };
	vec2g operator*(const vec2g& vec)const { return vec2g(this->x * vec.x, this->y * vec.y); };
	vec2g operator/(const vec2g& vec)const { return vec2g(this->x / vec.x, this->y / vec.y); };
	vec2g& operator+=(const vec2g& vec) { this->x += vec.x; this->y += vec.y; return *this; };
	vec2g& operator-=(const vec2g& vec) { this->x -= vec.x; this->y -= vec.y; return *this; };
	vec2g& operator*=(const vec2g& vec) { this->x *= vec.x; this->y *= vec.y; return *this; };
	vec2g& operator/=(const vec2g& vec) { this->x /= vec.x; this->y /= vec.y; return *this; };
	vec2g operator+(const T& value)const { return vec2g(this->x + value, this->y + value); };
	vec2g operator-(const T& value)const { return vec2g(this->x - value, this->y - value); };
	vec2g operator*(const T& value)const { return vec2g(this->x * value, this->y * value); };
	vec2g operator/(const T& value)const { return vec2g(this->x / value, this->y / value); };
	vec2g& operator+=(const T& value) { this->x += value; this->y += value; return *this; };
	vec2g& operator-=(const T& value) { this->x -= value; this->y -= value; return *this; };
	vec2g& operator*=(const T& value) { this->x *= value; this->y *= value; return *this; };
	vec2g& operator/=(const T& value) { this->x /= value; this->y /= value; return *this; };
	
	T mag() { return T(sqrt(x * x + y * y)); };
	vec2g norm() { T r = (this->mag() != 0.0) ? (1 / mag()) : 0.0;  return vec2g(this->x * r, this->y * r); };
	vec2g floor() { return vec2g(std::floor(x), std::floor(y)) };
	vec2g ceil() { return vec2g( std::ceil(x), std::ceil(y)) };
	vec2g min(const vec2g& vec) const { return vec2g( std::min(x, vec.x), std::min(y, vec.y)) };
	vec2g max(const vec2g& vec) const { return vec2g( std::max(x, vec.x), std::max(y, vec.y)) };

	operator vec2g<int>() const { return { static_cast<int>(this->x), static_cast<int>(this->y) }; };
	operator vec2g<unsigned int>() const { return { static_cast<unsigned int>(this->x), static_cast<unsigned int>(this->y) }; };
	operator vec2g<float>() const { return { static_cast<float>(this->x), static_cast<float>(this->y) }; };
	operator vec2g<double>() const { return { static_cast<double>(this->x), static_cast<double>(this->y) }; };
};

/* 2 Dimentional vector of integers */
typedef vec2g<int> vec2i;	
/* 2 Dimentional vector of unsigned int*/
typedef vec2g<unsigned int> vec2ui;
/* 2 Dimentional vector of float int*/
typedef vec2g<float> vec2f;
/* 2 Dimentional vector of double*/
typedef vec2g<double> vec2d;

/*
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
*/
#endif 