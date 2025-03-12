#include "report.h"
#include <stdio.h>
//start the printing function
void print_tempurature(int temp, int curr, int out) {
    char unit;
    if (out == 1){
        unit = 'F';
    } else if (out == 2){
        unit = 'C';
    } else if (out == 3){
        unit = 'K';
    }
    float converted = convert_temp(temp, curr, out);//get the converted temp
    if (converted == -1) {//check if kelvin tempurature is negative
        printf("Error: Kelvin temperature cannot be negative.\n");
    } 
    else if (curr == out) {//check if no conversion is being done
        printf("Error: Must convert between unique units.\n");
    }
    else if (curr > 3 || curr < 1 || out > 3 || out < 1) {//check if it is out of bounds
        printf("Error: Not in range.\n");
    }
    else {
        printf("%.2f %c\n", converted, unit); //print converted temp
        if (curr != 2){// if the tempurature is not in celcius 
            categorize_temperature(convert_temp(temp, curr, 2));//convert to celcius, run tempurature calculator
        } else {
            categorize_temperature(temp);//or run with current temp
        }
    }
}

void categorize_temperature(float celsius) {// figure out which tempurature range it is in and print their responses
    if (celsius < 0) {
        printf("Temperature Category: Freezing\nWeather Advisory: Stay Indoors\n");
    }
    else if (celsius < 10) {
        printf("Temperature Category: Cold\nWeather Advisory: Wear a jacket\n");
    }
    else if (celsius < 25) {
        printf("Temperature Category: Comfortable\nWeather Advisory: Feels comfortable outside\n");
    }
    else if (celsius < 35) {
        printf("Temperature Category: Hot\nWeather Advisory: Use sunscreen\n");
    }
    else {
        printf("Temperature Category: Extreme Heat\nWeather Advisory: Hydrate a lot\n");
    }
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (5.0 * (fahrenheit - 32)) / 9;//convert from fahrenheit_to_celsius
}

float fahrenheit_to_kelvin(float fahrenheit) {
    return fahrenheit_to_celsius(fahrenheit) + 273.15;//convert from fahrenheit_to_kelvin
}

float celsius_to_fahrenheit(float celsius) {
    return ((9.0 * celsius) / 5) + 32;//convert from celsius_to_fahrenheit
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;//convert from celsius_to_kelvin
}

float kelvin_to_fahrenheit(float kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));//convert from kelvin_to_fahrenheit
}

float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;//convert from kelvin_to_celsius
}

float convert_temp(int temp, int curr, int out) {// convert from one unit to another
    if (curr == 3 && temp < 0) {// if kelvin is negative return one
        return -1;
    }

    if (curr == 1) { // Fahrenheit starting
        if (out == 2) return fahrenheit_to_celsius(temp);
        if (out == 3) return fahrenheit_to_kelvin(temp);
    } 
    else if (curr == 2) { // Celsius starting
        if (out == 1) return celsius_to_fahrenheit(temp);
        if (out == 3) return celsius_to_kelvin(temp);
    } 
    else if (curr == 3) { // Kelvin starting
        if (out == 1) return kelvin_to_fahrenheit(temp);
        if (out == 2) return kelvin_to_celsius(temp);
    }

    return temp;//return new temp
}