BIL105E
HomeWork 1
Small Calculator

Emin Mastizada
150120914
mastizada@itu.edu.tr

This mini calculator can calculate addition, subtraction, multiplication, division, logarithm
and circle-area.

2nd version:

All problems from 1st version are solved:

1st version was checking numbers that user entered for double's limit, but now, one
function (void TotalCheck) is calculating everything and then checking result.

Results of 1st version:

You cannot divide by 0 – Solved using if (y==0);
log is not defined for 'given_number_here' – Solved using if (x==0 || x < 0);
The result is too big/small to be represented in a 'double' variable. - Solved for variables
only. Not for
result. But already checking if result is <= DBL_MAX && total >= -DBL_MAX using bool.


Developed using Greany, Linux Terminal (g++), Ubuntu 12.10
Raport: LibreOffice
