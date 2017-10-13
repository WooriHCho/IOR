#include <stdio.h>
#include <wiringPi.h>
#include <python.h>

#define LED1 13

int main (void)
{
	PyObject *PyModule, *PyFUn, *PyName, *PyArgs, *PyValue, *PyDict;
	PyObject *PyPath;
	
	Py_Initialize();
	PyName = PyString_FromString(argv[1]);
	PyModule = PyImport_Import(PyName);
	PyDict = PyModule_GetDict(PyModule);
	PyFun = PyDict_GetItemString(PyDict, argv[2]);
	if(PyCallable_Check(PyFun))
	{
		PyArgsPyTuple_New(1);
		PyValue=PyFloat_FromDouble(atof(argv[3]));
		if(PyArgs != NULL)
		{
			Py_DECREF(PyArgs);
		}
	}
	else
		PyErr_Print();

	if(PyModule != NULL)
		Py_DECREF(PyModule);

	if(PyName != NULL)
		py_DECREF(PyName);
	
	Py_Finalize();

	pName - PyString
	int i = 0;
	if(wiringPiSetupGpio() == -1)
		return 1;
	pinMode(LED1,OUTPUT);
	while(i < 5)
	{
	 digitalWrite(LED1,1);
	 delay(1000);
	 digitalWrite(LED1,0);
	 delay(1000);
	i++;
	}
  return 0;
}
