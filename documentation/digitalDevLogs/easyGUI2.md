# Easy GUI code V2
[//]: # (Explain idea, the why it works / needed to be built like this, implementation)
A little while after our failure writing an easy GUI implementation, an idea was hatched involving global arrays that would allow us to solve our problem. What we came up with, was we were going to use a function to create variables due the simplicity. But mainly, we were going to use global arrays for object pointers and styles so that our code can select a variable that won't be deleted and is easily accessible using only a number.

To implement this we created two arrays, one array of lv_object_t pointers, and one array of lv_style_t. These would allow us to easily allocate more buttons/styles for use in our code without having to create a new variable for each, thus abstracting memory worries from the user a bit. This would also allow the code to dynamically set a memory location in our function using only a button number, as mentioned before. We then created a function that would use lvgl code to create a button using passed parameters a button number, a width, a height, a shift x, a shift y, an alignment, a color, and a button text. This function would also use the aforementioned global arrays.

[//]: # (Show code)

