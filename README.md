# Lab3

This lab deals with testing and requirements validation

## This repo is organized to answer each question of the lab in the three branches. The main branch may be ignored.

## Unit Testing

Two main functions were tested. The unit tests for these functions were done manually with test cases in the code itself , the unity framework was not used as it was a bit much for the applcaition in this project.

REFLECTION:

R- This was a fairly straight forward experience with testing the two functions. A number of values were passed to the function and different print statements were produced for the different test cases.
I- Only two functions were tested that both had their own parameters and their own return types. It would have been a different challenge had their been extra datatypes to test or a different structure of the program that used different methods of passig the data and would not have returns .
S -To improve these set of tests, more of the functions of the system could be tested, not just two. 
E - In future, the unity test framework could be used to provide further activity. While the testing was successful for the manual method implemented , using a framework could prove educational.

## Integration Testing

In the integration tests in this system, the two functions that were unit tested . For the integration tests , it inputs a value to the first function and the value returned is used as the input to the next function. 

R - This required modification from the inital setup that had the first function call nested in the second function. Seperating them did not change the greater functionailty of the system
I - This was still a fairly straightforward test ,even though there was some modificaton required
S - Ideally, there should be more functions tested . These two were not the only functions used  in the system .
E - In the setup shown , only two functions were  tested in series, for a larger system , it would be suitable to track a single input parameter across three or more functions to see if there is any failure in a longer processing chain .

## Verification Testing

The full requirements of this modified project can be found in the file named reqs.txt. 

Since there is a timing requirement, it would be ideal to use some form of equipment that can perform precise time measurements . Something such as as stopwatch would not be appropriate here . An oscilloscope would be useful to measure the time that the pin is eitehr HIGH or LOW . Also , slow motion camera combined with some software to slow down the frames and analyse the time elapsed may also be useful .
Even if the video is not used for precius timing prupsoes, it can still be used to count the flashes of the LED which many be difficult to see , for some people .
If there were other requirements relating to analog/digital waveforms and signal intensities, other equipment may need to be used .

R - This was a much more complicated test as the system needed to run as normal and the requirements to be validated outside of the code . In the end, the button system did not work adn thus the system was not verified .
I - Initially, I was unusre as to what was causing the failures, but by crossreferencing the failure with the unit tests, I realised that the button was not configured properly . I used my DMM to check the voltage on the pin when the button was pressed and not pressed  (Pressed =3.3 V, Not pressed 2.3 V). This led to me to believe that there was some error in the setup/ configutation of the pin that the button was connected to.
S - I feel that the testing itself was succesful in that it proved that the system was not functional but still pointed out the module that was not working proplerly .
E - I would like to get the button working firstly. After that , the system would then be verified , which was the greater goal of this project to begin with .

