
// If you have classes that contain const data, or derive from bases that contain const data
// then you will receive these two warnings when compiling on level 4
//
// Essentially, because of the const data, the default copy constructor and assignment operator
// functions cannot be automatically created.

#pragma warning(disable:4511)
#pragma warning(disable:4512)
