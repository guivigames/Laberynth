#include "GameMath.h"
#include <cmath>

/*
* Functions for vector of doubles. 
*/

vec2d vec2d::operator+(const vec2d& vec)
{
	vec2d _vec;
	_vec.x = this->x + vec.x;
	_vec.y = this->y + vec.y;
	return _vec;
}

vec2d vec2d::operator-(const vec2d& vec)
{
	vec2d _vec;
	_vec.x = this->x - vec.x;
	_vec.y = this->y - vec.y;
	return _vec;
}

vec2d vec2d::operator*(const vec2d& vec)
{
	vec2d _vec;
	_vec.x = this->x * vec.x;
	_vec.y = this->y * vec.y;
	return _vec;
}

vec2d vec2d::operator*(const int& value)
{
	vec2d _vec;
	_vec.x = this->x * value;
	_vec.y = this->y * value;
	return _vec;
}

vec2d vec2d::operator*(const double& value)
{
	vec2d _vec;
	_vec.x = this->x * value;
	_vec.y = this->y * value;
	return _vec;
}

vec2d vec2d::operator/(const vec2d& vec)
{
	vec2d _vec;
	_vec.x = this->x / vec.x;
	_vec.y = this->y / vec.y;
	return _vec;
}

vec2d& vec2d::operator+=(const vec2d& vec)
{
	this->x += vec.x;
	this->y += vec.y;
	return *this;
}

vec2d& vec2d::operator-=(const vec2d& vec)
{
	this->x -= vec.x;
	this->y -= vec.y;
	return *this;
}

vec2d& vec2d::operator*=(const vec2d& vec)
{
	this->x *= vec.x;
	this->y *= vec.y;
	return *this;
}

vec2d& vec2d::operator/=(const vec2d& vec)
{
	this->x /= vec.x;
	this->y /= vec.y;
	return *this;
}

vec2d& vec2d::operator=(const vec2d& vec)
{
	this->x = vec.x;
	this->y = vec.y;
	return *this;
}

vec2d::operator vec2i()
{
	return vec2i{(int)this->x, (int) this->y};
}

double vec2d::mag()
{
	double mag = 0.0;
	mag = pow( this->x*this->x + this->y*this->y, 0.5);
	return mag;
}

vec2d vec2d::norm()
{
	vec2d _vec;
	double mag;
	mag = this->mag();	
	_vec.x = this->x / mag;
	_vec.y = this->y / mag;
	return _vec;
}


/**
*	Functions for the implementation of the int vrctor.
*/

vec2i vec2i::operator+(const vec2i& vec)
{
	vec2i _vec;
	_vec.x = this->x + vec.x;
	_vec.y = this->y + vec.y;
	return _vec;
}

vec2i vec2i::operator-(const vec2i& vec)
{
	vec2i _vec;
	_vec.x = this->x - vec.x;
	_vec.y = this->y - vec.y;
	return _vec;
}

vec2i vec2i::operator*(const vec2i& vec)
{
	vec2i _vec;
	_vec.x = this->x * vec.x;
	_vec.y = this->y * vec.y;
	return _vec;
}

vec2i vec2i::operator*(const int& value)
{
	vec2i _vec;
	_vec.x = this->x * value;
	_vec.y = this->y * value;
	return _vec;
}

vec2i vec2i::operator*(const double& value)
{
	vec2i _vec;
	_vec.x = this->x * value;
	_vec.y = this->y * value;
	return _vec;
}

vec2i vec2i::operator/(const vec2i& vec)
{
	vec2i _vec;
	_vec.x = this->x / vec.x;
	_vec.y = this->y / vec.y;
	return _vec;
}

vec2i& vec2i::operator+=(const vec2i& vec)
{
	this->x += vec.x;
	this->y += vec.y;
	return *this;
}

vec2i& vec2i::operator-=(const vec2i& vec)
{
	this->x -= vec.x;
	this->y -= vec.y;
	return *this;
}

vec2i& vec2i::operator*=(const vec2i& vec)
{
	this->x *= vec.x;
	this->y *= vec.y;
	return *this;
}

vec2i& vec2i::operator/=(const vec2i& vec)
{
	this->x /= vec.x;
	this->y /= vec.y;
	return *this;
}

vec2i& vec2i::operator=(const vec2i& vec)
{
	this->x = vec.x;
	this->y = vec.y;
	return *this;
}

vec2i::operator vec2d()
{
	return	vec2d{ (double)this->x, (double)this->y};
}

double vec2i::mag()
{
	double mag;
	mag = pow((this->x * this->x + this->y * this->y), 0.5);
	return mag;
}

vec2d vec2i::norm()
{
	double mag;
	vec2d _vec;
	mag = this->mag();
	_vec.x = this->x / mag;
	_vec.y = this->y / mag;
	return _vec;
}
