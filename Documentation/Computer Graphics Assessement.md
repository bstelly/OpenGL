# **Computer Graphics**

This project makes use of OpenGL and therefore requires that the glfw3.h header file and GLM libraries are linked to the project. The glfw3 header file gives access to the OpenGL library and the GLM libraries are OpenGL mathematics libraries for doing calculations. These files can be found online.

## **Cameras and Projections**

### **Application class that derives from the application class**

**Pre-conditions:** In order to create a class for the Camera application that derives from an application class, you will first need to make an application class with functions for startup, shutdown, update, draw, clearScreen, and run. The startup, shutdown, update, and draw functions should be made to be pure virtual functions, so that they can be overridden.

The CameraApplication class derives from the Application class and there are override functions for all of the pure virtual functions in the application class. Since the CameraApplication class derives from the Application class, you must override all pure virtual functions. The CameraApplication class has access to all non-pure virtual functions, and so, I do not have to overwrite them. Instead, the CameraApplication class will use the code that was already written for those methods. This gives me the ability to create different applications, that derive from the Application class, with different functionalities.








Inline `code`

```c++
int BlockedCode;
```