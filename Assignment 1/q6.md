Problem 6: Amusement Park Ride eligibility 
Safari park is a famous amusement park situated in Karachi that has specific height and age requirements for its rides. For The Dragon Roller Coaster, visitors must be at least 48 inches tall and 10 years old. The Sky Swing requires visitors to be at least 54 inches tall, with no age restriction. The Carousel has no height requirement but visitors must be at least 5 years old.  A visitor is wearing a band so he may take as many rides as he wants until he is tired. Design a  solution that determines if a visitor meets the criteria to go on a chosen ride based on their height, age, and selected ride.

IPO CHART:

input: height,age,ride

process: check if wearing band, check which ride, check if meets the criteria for the ride

output: criteria_meet

PSEUDOCODE:
1. input height,age,ride
2. IF wearing band THEN
3.     IF ride = "the carousel" AND age >= 5
4.        print "you meet the criteria for the carousel ride"
5.     else print "sorry, you do no meet the criteria"
6.     IF ride = "the dragon roller coaster" AND height >=48 AND height >=10
7.        print "you meet the criteria for the dragon roller coaster ride"
8.     else print "sorry, you do no meet the criteria"
9.     IF ride = "sky swing" AND height >= 54
10.       print "you meet the criteria for the sky swing ride"
11.     else print "sorry, you do no meet the criteria"
