# Vector2
[//]: # (explain need for vector2 class, and how we created it to be type efficient)
During development of the IMU positioning system, and the implementation of the movement function of the input tracker, we determined that it would be necessary to have a simple vector 2 class. This class would act as a simple array with a length of 2 except with X/Y components replacing indices. This makes it easier to think about joysticks, after all they have X and Y components, not just indices. It was decided that representing the vector 2 as class would be best. The vector 2 class was implemented to not rely on type, and can actually store any types, be it numbers, or even strings. 

[//]: # (show vector2 class definition)

[//]: # (show vector2 class example)