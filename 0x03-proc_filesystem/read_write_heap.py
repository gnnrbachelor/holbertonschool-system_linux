#!/usr/bin/python3

import sys

def print_and_exit():
    print('Usage: {} pid search write'.format(sys.argv[0]))
    sys.exit(1)

def read_write_heap(pid, search_str, replace_str):
    """read_write_heap function"""
    try:
        maps_file = open("/proc/{}/maps".format(pid), 'r')
    except Exception as e:
        print(e)
        exit(1)

    try:
        mem_file = open("/proc/{}/mem".format(pid), 'r+b', 0)
    except Exception as e:
        maps_file.close()
        print(e)
        exit(1)

    heap_found = False
    for line in maps_file.readlines():
        s_line = line.split()
        if s_line[len(s_line) - 1] == "[heap]":
            heap_found = True
            mem_range = s_line[0].split('-')
            start = int(mem_range[0], 16)
            end = int(mem_range[1], 16)
            mem_file.seek(start)
            s = mem_file.read(end - start)
            index_search_str = s.find(bytes(search_str, 'utf-8'))

            if index_search_str == -1:
                break

            mem_file.seek(start + index_search_str)
            mem_file.write(bytes(write_str, 'utf-8') + b'\x00')
            break

    maps_file.close()
    mem_file.close()

    if index_search_str == -1:
        exit(1)

    if not heap_found:
        exit(1)

    print("replacing string")


if __name__=='__main__':
    if len(sys.argv) != 4:
        print_and_exit()

    try:
        pid = int(sys.argv[1])
    except ValueError:
        print_and_exit()

    search_str = str(sys.argv[2])
    if search_str == "":
        print_and_exit()

    write_str = str(sys.argv[3])
    if write_str == "":
        print_and_exit()

    if len(write_str) > len(search_str):
        exit(1)

    try:
        read_write_heap(pid, search_str, write_str)
    except Exception as e:
        print(e)
        exit(1)

