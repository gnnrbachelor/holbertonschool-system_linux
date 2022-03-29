#include <stdio.h>
#include <Python.h>

/**
 * print_python_float - Prints pfo
 * @p: Pointer to float obj
 *
 */

void print_python_float(PyObject *p)
{
	char *str;

	setbuf(stdout, NULL);
	printf("[.] float object info\n");
	if ( !p || p->ob_type != &PyFloat_Type )
	{
		printf("  [ERROR] Invalid Float Object\n");
		return;
	}
	str = PyOS_double_to_string(((PyFloatObject *)p)->ob_fval,
			'g', 16, 0, NULL);
	printf("  value: %s%s\n", str, strchr(str, '.') ? "" : ".0");
}

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
		printf("[ERROR] Invalid Bytes Object\n");
		return;
	}

	size = ((PyVarObject *)p)->ob_size;
	printf("  size: %ld\n", size);
	printf("  trying string: %s\n", ((PyBytesObject *)p)->ob_sval);
	if (size < 9)
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
	ssize_t size;
	ssize_t i = 0;

	setbuf(stdout, NULL);
	printf("%s", "[*] Python list info\n");
	if (p == NULL || p->ob_type != &PyList_Type)
	{
		printf("  [ERROR] Invalid List Object\n");
		return;
	}
	size = ((PyVarObject *)p)->ob_size;
	printf("[*] Size of the Python List = %ld\n", size);
	printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);
	for (i = 0; i < size; i++)
	{
		PyObject *pobj = ((PyListObject *)p)->ob_item[i];

		printf("Element %ld: %s\n", i, pobj->ob_type->tp_name);
		if (pobj->ob_type == &PyBytes_Type)
			print_python_bytes(pobj);
		else if (pobj->ob_type == &PyFloat_Type)
			print_python_float(pobj);

	}
}
