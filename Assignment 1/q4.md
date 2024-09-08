Problem 4: Grocery Assistance/ Calculator
Imagine Mr. Bhoola is going to the market to buy some yummy fruits and vegetables. He's a little bit forgetful, so he doesn't always have a list or a fixed amount of money to spend. We're going to help Mr. Bhoola figure out how much he needs to pay and how much change he gets back. 
Here's what we need to know:
How much money Mr. Bhoola has today to buy fruits and vegetables.
The prices of the onions, apricots, grapes, and tomatoes at the market.
What vegetables Mr. Bhoola buys and how many of each.

Here is an example of some random day in life of Mr. Bhoola
What fruits and vegetables does Mr. Bhoola buy today?
(For example, 2kg onions, 1 kg of grapes, and 3kg tomatoes)
What are the prices of each vegetable today? 
(For example, onions cost $1 per kg, grapes cost $2 per kg, and tomatoes cost $0.50 per kg)
How much money does Mr. Bhoola have with him ? 
(For example, $10)
Design a solution to help Mr. Bhoola every time he goes shopping! 


IPO CHART:

input: -cash
       -no_of_vegetables

process:  -total = numberofonions * onionprice + numberofapricots * apricotsprice + numberofgrapes * grapesprice + numberoftomatoes * tomatoesprice

output: total

PSEUDOCODE:
1. input cash
2. input numberofonions
3. input numberofapricots
4. input numberofgrapes
5. input numberoftomatoes
6. total = numberofonions * onionprice + numberofapricots * apricotsprice + numberofgrapes * grapesprice + numberoftomatoes * tomatoesprice
7. change = cash - total
8. output total
9. output change
