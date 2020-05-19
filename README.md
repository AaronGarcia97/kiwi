# kiwi

Compile and run it:   
`g++ *.cpp -std=c++11 -o main && ./main`   
One liner to compile and run it with test input:     
`g++ *.cpp -std=c++11 -o main && ./main < testinput.txt`   

The program assumes that input will be stings enclosed by `"`   
each separated by `\n` until `EOF`.   

**Example of expected input**:   
```
"Clouds are white."
"Pittsburgh is beatiful."
```
**Expected output**:
```
---------EXPECTED OUTPUT---------
are white clouds
beatiful pittsburgh is
clouds are white
is beatiful pittsburgh
pittsburgh is beatiful
white clouds are
-----------END OUTPUT------------
```
