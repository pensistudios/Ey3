/****************************************************************/
/*  File: Ey3Math.h
/*	Functionality: A general purpose Math file which has constants
/*	and useful functions
/*
/*	Class: Radian
/*  Definition: A class used for describing numbers in Radian 
/*	measure
/*  
/*	Class: Degree
/*  Definition: A class used for describing numbers in Degree 
/*	measure
******************************************************************/

#ifndef _EY3MATH_H_
#define _EY3MATH_H_

#include "Ey3Def.h"

namespace Ey3
{

	class Radian;

	class Ey3Export Math
	{
	public:

		static const float PI;
		static const float TWOPI;
		static const float DEG_TO_RAD;
		static const float RAD_TO_DEG;

		static float ACos(Radian& v);
		static float ASin(Radian& v);
		static float ATan(Radian& v);
		static float ATan2(Radian& v);
		static float Sin(Radian& v);
		static float Cos(Radian& v);
		static float Tan(Radian& v);
		static float Ceil(float v);
		static float Floor(float v);
		static float FAbs(float v);
		static float Fmod(float x, float y);
		static float Sqrt(float v);
		static float InvSqrt(float v);
		static float Log(float v);
		static float Pow(float base, float exp);
		static float Exp(float v);
		static float Sqr(float v);
		static int Sign(int v);
		

	};

	class Ey3Export Radian
	{
	public:
		float _value;
	
		Radian(float x=0.0f) : _value(x) {}
		explicit Radian(const Degree &theta);
		Radian& operator=(float x) { _value = x; return *this; }
		Radian& operator=(const Radian &a) {_value = a._value; return *this; }
		Radian& operator=(const Degree &d);
		
		Radian operator+(const Radian &a) { return Radian(_value+a._value); }
		Radian& operator+=(const Radian &a) { _value += a._value; return *this; }
		Radian operator-(const Radian &a) { return Radian(_value-a._value); }
		Radian& operator-=(const Radian &a) { _value -= a._value; return *this; }
		Radian operator*(const Radian &a) { return Radian(_value*a._value); }
		Radian& operator*=(const Radian &a) { _value *= a._value; return *this; }
		Radian operator/(const Radian &a) { return Radian(_value/a._value); }
		Radian& operator/=(const Radian &a) { _value /= a._value; return *this; }

		Radian operator-() { return Radian(-_value); }

		Radian operator+(const Degree &a);
		Radian& operator+=(const Degree &a);
		Radian operator-(const Degree &a);
		Radian& operator-=(const Degree &a);
		Radian operator*(const Degree &a);
		Radian& operator*=(const Degree &a);
		Radian operator/(const Degree &a);
		Radian& operator/=(const Degree &a);

		bool operator == ( const Radian &a ) const { return _value == a._value; }
		bool operator != ( const Radian &a ) const { return _value != a._value; }
		bool operator <  ( const Radian &a ) const { return _value <  a._value; }
		bool operator <= ( const Radian &a ) const { return _value <= a._value; }	
		bool operator >= ( const Radian &a ) const { return _value >= a._value; }
		bool operator >  ( const Radian &a ) const { return _value >  a._value; }

		float degreeValue() { return (180*_value)/Math::PI; }

	};

	class Ey3Export Degree
	{
	public:
		float _value;
	
		Degree(float x=0.0f) : _value(x) {}
		explicit Degree(const Radian& x);
		Degree& operator=(float x) { _value = x; return *this; }
		Degree& operator=(const Radian &a);
		Degree& operator=(const Degree &d) {_value = d._value; return *this; }
		
		Degree operator+(const Degree &a) { return Degree(_value+a._value); }
		Degree& operator+=(const Degree &a) { _value += a._value; return *this; }
		Degree operator-(const Degree &a) { return Degree(_value-a._value); }
		Degree& operator-=(const Degree &a) { _value -= a._value; return *this; }
		Degree operator*(const Degree &a) { return Degree(_value*a._value); }
		Degree& operator*=(const Degree &a) { _value *= a._value; return *this; }
		Degree operator/(const Degree &a) { return Degree(_value/a._value); }
		Degree& operator/=(const Degree &a) { _value /= a._value; return *this; }

		Degree operator-() { return Degree(-_value); }

		Degree operator+(const Radian &a);
		Degree& operator+=(const Radian &a);
		Degree operator-(const Radian &a);
		Degree& operator-=(const Radian &a);
		Degree operator*(const Radian &a);
		Degree& operator*=(const Radian &a);
		Degree operator/(const Radian &a);
		Degree& operator/=(const Radian &a);

		bool operator == ( const Degree &a ) const { return _value == a._value; }
		bool operator != ( const Degree &a ) const { return _value != a._value; }
		bool operator <  ( const Degree &a ) const { return _value <  a._value; }
		bool operator <= ( const Degree &a ) const { return _value <= a._value; }	
		bool operator >= ( const Degree &a ) const { return _value >= a._value; }
		bool operator >  ( const Degree &a ) const { return _value >  a._value; }

		float radianValue() { return (Math::PI*_value)/180; }

	};

	
};

#endif
