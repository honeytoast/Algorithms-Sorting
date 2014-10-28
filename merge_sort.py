import sys
import time

def merge_sort(l):
    if len(l) <= 1:
        return l
    else:
        half = len(l)//2
        return merge(merge_sort(l[:half]), merge_sort(l[half:]))

def merge(a, b):
    s = []
    ai = 0
    bi = 0
    while ai < len(a) and bi < len(b):
        if a[ai] <= b[bi]:
            s.append(a[ai])
            ai += 1
        else:
            s.append(b[bi])
            bi += 1
    return s + a[ai:] + b[bi:]

def print_ten_words(l):
    print('first 10 words: ', end='')
    for i in range(10):
        print('[{}]'.format(l[i]), end='')

def main():
    if len(sys.argv) != 3:
        print('Error, must supply 2 arguments.\n\n' + 
              'Usage: python3 project_3.py <text_file> <n>')
        sys.exit(1)

    filename = sys.argv[1]
    n = int(sys.argv[2])

    # read up to n words from the file
    word_list = []
    input_file = open(filename, 'r')
    for i in range(n):
        word_list.append(input_file.readline().rstrip())
    input_file.close()

    # print input information and first 10 words of input list
    print('requested n = {}'.format(n))
    print("loaded {} lines from '{}'".format(n, filename))
    print_ten_words(word_list)
    print('\nmerge sort...')

    # time the selection sort algorithm
    start = time.perf_counter()
    sorted_list = merge_sort(word_list)
    end = time.perf_counter()

    # print output information and first 10 words of sorted list
    print_ten_words(sorted_list)
    print('\nelapsed time: {} seconds'.format(end - start))

if __name__ == '__main__':
    main()
