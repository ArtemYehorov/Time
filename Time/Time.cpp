#include "Time.h"

	Time::Time()
	{
		SYSTEMTIME st;
		GetLocalTime(&st);
		SetHours(st.wHour);
		SetMinutes(st.wMinute);
		SetSeconds(st.wSecond);
	}
	Time::Time(int h, int m, int s)
	{
		SetHours(h);
		SetMinutes(m);
		SetSeconds(s);
	}

	void Time::Print()
	{
		printf("%2d:%02d:%02d\n", GetHours(), GetMinutes(), GetSeconds());
	}

	void Time::SetSeconds(int sec)
	{
		if (sec >= 0 && sec <= 59)
		{
			seconds = sec;
		}
		else
		{
			seconds = 0;
		}
	}
	void Time::SetMinutes(int min)
	{
		if (min >= 0 && min <= 59)
		{
			minutes = min;
		}
		else
		{
			minutes = 0;
		}
	}
	void Time::SetHours(int hour)
	{
		if (hour >= 0 && hour <= 23)
		{
			hours = hour;
		}
		else
		{
			hours = 0;
		}
	}

	int Time::GetSeconds() const
	{
		return seconds;
	}
	int Time::GetMinutes() const
	{
		return minutes;
	}
	int Time::GetHours() const
	{
		return hours;
	}

Time operator + (const Time& time, int sec)
{
	Time result;
	result.hours = time.hours;
	result.minutes = time.minutes;
	result.seconds = time.seconds + sec;
	for (int i = 0; true; i++)
	{
		result.seconds -= 60;
		result.minutes++;
		if (result.minutes == 60)
		{
			result.minutes = 0;
			result.hours++;
		}
		if (result.hours == 23)
		{
			result.hours = 0;
		}
		if (result.seconds >= 0 && result.seconds <= 59)
		{
			break;
		}
	}
	return result;
}

bool operator > (const Time& One, const Time& Two)
{
	return (One.GetHours() * 3600) + (One.GetMinutes() * 60) + One.GetSeconds() > (Two.GetHours() * 3600) + (Two.GetMinutes() * 60) + Two.GetSeconds();
}

bool operator < (const Time& One, const Time& Two)
{
	return (One.GetHours() * 3600) + (One.GetMinutes() * 60) + One.GetSeconds() < (Two.GetHours() * 3600) + (Two.GetMinutes() * 60) + Two.GetSeconds();
}

bool operator == (const Time& One, const Time& Two)
{
	return (One.GetHours() * 3600) + (One.GetMinutes() * 60) + One.GetSeconds() == (Two.GetHours() * 3600) + (Two.GetMinutes() * 60) + Two.GetSeconds();
}

bool operator != (const Time& One, const Time& Two)
{
	return (One.GetHours() * 3600) + (One.GetMinutes() * 60) + One.GetSeconds() != (Two.GetHours() * 3600) + (Two.GetMinutes() * 60) + Two.GetSeconds();
}

istream& operator >> (istream& is, Time& original)
{
	int a;

	cout << "Please enter hours:";
	is >> a;
	original.SetHours(a);
	cout << "Please enter minutes:";
	is >> a;
	original.SetMinutes(a);
	cout << "Please enter seconds:";
	is >> a;
	original.SetSeconds(a);
	return is;
}

ostream& operator << (ostream& os, const Time& original)
{
	os << original.hours << ":" << original.minutes << ":" << original.seconds << "\n";
	return os;
}

Time& Time::operator++()
{
	++seconds;
	if (seconds == 60)
	{
		seconds = 0;
		minutes++;
		if (minutes == 60)
		{
			minutes = 0;
			hours++;
			if (hours == 24)
			{
				hours = 0;
			}
		}
	}
	return *this;
}
Time Time::operator++(int)
{
	Time copy = *this;
	++seconds;
	if (seconds == 60)
	{
		seconds = 0;
		minutes++;
		if (minutes == 60)
		{
			minutes = 0;
			hours++;
			if (hours == 24)
			{
				hours = 0;
			}
		}
	} // изменяем оригинал
	return copy; // возвращаем копию
}

Time& Time::operator--()
{
	--seconds;
	if (seconds < 0)
	{
		seconds = 59;
		minutes--;
		if (minutes < 0)
		{
			minutes = 59;
			hours--;
			if (hours < 0)
			{
				hours = 23;
			}
		}
	}
	return *this;
}
Time Time::operator--(int)
{
	Time copy = *this;
	--seconds;
	if (seconds < 0)
	{
		seconds = 59;
		minutes--;
		if (minutes < 0)
		{
			minutes = 59;
			hours--;
			if (hours < 0)
			{
				hours = 23;
			}
		}
	} // изменяем оригинал
	return copy; // возвращаем копию
}