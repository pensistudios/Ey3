#include "Ey3Math.h"

using namespace Ey3;

const float Math::PI = (float)(4.0*atan(1.0));
const float Math::TWOPI = PI * 2.0f;
const float Math::DEG_TO_RAD = PI/180.0f;
const float Math::RAD_TO_DEG = 180.0f/PI;

float Math::InvSqrt (float fValue)
{//Quake3 algorithm
    float fHalf = 0.5f*fValue;
    int i  = *(int*)&fValue;
    i = 0x5f3759df - (i >> 1);
    fValue = *(float*)&i;
    fValue = fValue*(1.5f - fHalf*fValue*fValue);
    return fValue;
}

Radian::Radian(const Degree &d) : _value((d._value*Math::PI)/180) {}
Radian& Radian::operator=(const Degree &d) {_value = Radian(d)._value; return *this; }
Radian Radian::operator+(const Degree &a) { return Radian(_value+Radian(a)._value); }
Radian& Radian::operator+=(const Degree &a) { _value += Radian(a)._value; return *this; }
Radian Radian::operator-(const Degree &a) { return Radian(_value-Radian(a)._value); }
Radian& Radian::operator-=(const Degree &a) { _value -= Radian(a)._value; return *this; }
Radian Radian::operator*(const Degree &a) { return Radian(_value*Radian(a)._value); }
Radian& Radian::operator*=(const Degree &a) { _value *= Radian(a)._value; return *this; }
Radian Radian::operator/(const Degree &a) { return Radian(_value/Radian(a)._value); }
Radian& Radian::operator/=(const Degree &a) { _value /= Radian(a)._value; return *this; }

Degree::Degree(const Radian &x) : _value((x._value*180)/Math::PI) {}
Degree& Degree::operator=(const Radian &a) {_value = Degree(a)._value; return *this; }
Degree Degree::operator+(const Radian &a) { return Degree(_value+Degree(a)._value); }
Degree& Degree::operator+=(const Radian &a) { _value += Degree(a)._value; return *this; }
Degree Degree::operator-(const Radian &a) { return Degree(_value-Degree(a)._value); }
Degree& Degree::operator-=(const Radian &a) { _value -= Degree(a)._value; return *this; }
Degree Degree::operator*(const Radian &a) { return Degree(_value*Degree(a)._value); }
Degree& Degree::operator*=(const Radian &a) { _value *= Degree(a)._value; return *this; }
Degree Degree::operator/(const Radian &a) { return Degree(_value/Degree(a)._value); }
Degree& Degree::operator/=(const Radian &a) { _value /= Degree(a)._value; return *this; }

	