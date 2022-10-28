import difflib
import sys


def diff(myfile, standard):
    with open(myfile) as mine: mycontent = mine.readlines()
    with open(standard) as std: stdcontent = std.readlines()
    df = difflib.HtmlDiff()
    return df.make_file(mycontent, stdcontent)


def main(argv):
    root = './test/test_1_r01'
    myfile = root+'.out'
    standard = root+'1.out'
    print(diff(myfile, standard))

if __name__ == '__main__':
    main(sys.argv[1:])

