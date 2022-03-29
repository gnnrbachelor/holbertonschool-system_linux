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
	size = size < 9 ? size + 1 : 10;
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
	int i;

	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %lu\n", Py_SIZE(p));
	printf("[*] Allocated = %lu\n", ((PyListObject *)p)->allocated);
	for (i = 0; i < Py_SIZE(p); i++)
		printf("Element %d: %s\n", i,
		       Py_TYPE(PyList_GetItem(p, i))->tp_name);
}
