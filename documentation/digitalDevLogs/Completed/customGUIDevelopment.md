# Easy GUI code
[//]: # (explain our want for, and development of easy GUI code)
During our early stages of development we knew that we would want to create an extensive GUI -graphical user interface- for our robot. However, to create something as simple as button with a plain color we would have to not only declare a button object variable, but a label object variable, and a styling variable. This made it so that to create such a single simple button and nicely position it we would need around 10 lines of code, which is huge if you have upwards of 10 buttons. So during as we were developing our input tracking system we created an easy GUI set of classes for labels and buttons that would allow the creation of a simple button in just one line and one variable.

[//]: # (explain why the easy GUI code had to be scrapped)
This system worked great on a surface level, however due to auto code cleaning by our c++ compiler we had to end up scrapping this idea. What would happen is the button needs the style variable to never be deleted while the button is alive, and because this style variable was created in the class constructor it would get deleted. This made it so we couldn't have any colors on our buttons, which were needed for ease of use. So we had to end up scrapping this idea, though once we have time we will begin trying to reimplement this easy GUI coding if we figure out a way to reimplement.

[//]: # (show implementation of label, then button, then a use of both)