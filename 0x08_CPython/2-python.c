#include <stdio.h>
#include <Python.h>

/**
 * print_python_bytes - Prints bbo
 * @p: pointer to pbo
 */

void print_python_bytes(PyObject *p)
{
	ssize_t size = 0;
	ssize_t i = 0;

	printf("[.] bytes object info\n");
	if (p->ob_type != &PyBytes_Type)
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}

	size = ((PyVarObject *)p)->ob_size;
	printf("  size: %ld\n", size);
	printf("  trying string: %s\n", ((PyBytesObject *)p)->ob_sval);
	if (size < 9 )
		size++;
	else
		size = 10;

	printf("  first %ld bytes: ", size);
	for (i = 0; i < size; i++)
		printf("%02hhx%c",
			((PyBytesObject *)p)->ob_sval[i], i + 1 == size ? '\n' : ' ');
}


/**
 * print_python_list - Prints info about python list
 * @p: PyObject pointer
 * Return: Void
 */


void print_python_list(PyObject *p)
{
	ssize_t size = ((PyVarObject *)p)->ob_size;
	ssize_t i = 0;

	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %lu\n", Py_SIZE(p));
	printf("[*] Allocated = %lu\n", ((PyListObject *)p)->allocated);
	for (i = 0; i < size; i++)
	{
		PyObject *pobj = ((PyListObject *)p)->ob_item[i];
		printf("Element %ld: %s\n", i, pobj->ob_type->tp_name);
		if (pobj->ob_type == &PyBytes_Type)
			print_python_bytes(pobj);
	}
}
