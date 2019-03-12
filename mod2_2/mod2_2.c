//Thomas Cooper
//3/3/17
//Chapter 5 exercise 11

//preprocessor
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

//function prototypes
double roundToInteger(double rti);
double roundToTenths(double rtt);
double roundToHundredths(double rth);
double roundToThousandths(double rtts);

//main
int main ()
{
	//datatypeas double
	double x, num1, num2, num3, num4;
	bool neg = false;

	//prompt for the user and the capture of the number being entered
	printf_s("%s", "Please input a number: ");
	scanf_s("%lf", &x);

	//quick check to see if zero was entered and a fun message for the user that inputs zero.
	if (x == 0)
	{
		printf_s("%s", "\nYou have entered \"nothing\". Nothing can be done with \"nothing\". Have a nice day.");
		return 0;
	}

	//quick check to see if the inputted number is negative. The number is converted to a positive, and a negative flag is triggered for later
	if (x < 0)
	{
		x = x * -1;
		neg = true;
	}

	//sending the inputted value to each of the functions and storing the rounded number in seperate places
	num1 = roundToInteger(x);
	num2 = roundToTenths(x);
	num3 = roundToHundredths(x);
	num4 = roundToThousandths(x);

	//check if the negative flag is triggered, and all numbers are converted back to negatives
	if (neg)
	{
		x = x * -1;
		num1 = num1 * -1;
		num2 = num2 * -1;
		num3 = num3 * -1;
		num4 = num4 * -1;
	}

	//displaying the numbers on the screen
	//original inputted number with no formatting
	//round to integer
	//round to tenths place after the decimal
	//round to hundredths place after the decimal
	//round to thousandths place after the decimal
	printf_s("\n%lf %.0lf %.1lf %.2lf %.3lf", x, num1, num2, num3, num4);
}//end main

//first function to round the inputted number to a whole number
double roundToInteger(double rti)
{
	double temp, whole;
	//getting just the number without the decimals
	whole = (int)rti;
	//getting the digits after the decimal by themselves
	temp = rti - whole;

	//check to see if the number needs to be rounded to the next digit or not, and then returning the whole number
	if (temp < 0.5)
		return whole;
	else
	{
		whole++;
		return whole;
	}
}

//function to round the number to the tenths place after the decimal
double roundToTenths(double rtt)
{
	double temp, whole;
	//to better truncate the the numbers that appear after the decimal place, the original number is multiplied by ten
	rtt = rtt * 10;
	//getting the number without decimal digits
	whole = (int)rtt;
	//getting just the decimal digits
	temp = rtt - whole;

	//check to see if the number needs to be rounded to the next number, and then divided by ten to remove the multiplication done at the beginning
	if (temp < 0.5)
	{
		rtt = whole / 10;
		return rtt;
	}
	else
	{
		whole++;
		rtt = whole / 10;
		return rtt;
	}
}

//function to round to the hundredths place
double roundToHundredths(double rth)
{
	double temp, whole;
	//to better truncate the the numbers that appear after the decimal place, the original number is multiplied by a hundred
	rth = rth * 100;
	//getting the number without decimal digits
	whole = (int)rth;
	//getting just the decimal digits
	temp = rth - whole;

	//check to see if the number needs to be rounded to the next number, and then divided by one hundred to remove the multiplication done at the beginning
	if (temp < 0.5)
	{
		rth = whole / 100;
		return rth;
	}
	else
	{
		whole++;
		rth = whole / 100;
		return rth;
	}
}

double roundToThousandths(double rtts)
{
	double temp, whole;
	//to better truncate the the numbers that appear after the decimal place, the original number is multiplied by a thousand
	rtts = rtts * 1000;
	//getting the number without decimal digits
	whole = (int)rtts;
	//getting just the decimal digits
	temp = rtts - whole;

	//check to see if the number needs to be rounded to the next number, and then divided by one thousand to remove the multiplication done at the beginning
	if (temp < 0.5)
	{
		rtts = whole / 1000;
		return rtts;
	}
	else
	{
		whole++;
		rtts = whole / 1000;
		return rtts;
	}
}