import csv
import sys


def main():

    if len(sys.argv) - 1 != 2:
        print("Try again")
        return 1;
    which_csv = sys.argv[1]
    which_dna = sys.argv[2]
    # TODO: Read database file into a variable
    with open(which_csv) as csv_file:
        csv_reader = csv.reader(csv_file, delimiter=',')
        line = 0
        list_headers = []
        list_subjects = []
        for i in csv_reader:
            if line == 0:
                list_headers = i
                line+=1
            else:
                list_subjects.append(i)


    # TODO: Read DNA sequence file into a variable
    with open(which_dna, 'r') as f:
        final_dna = f.read()

    # TODO: Find longest match of each STR in DNA sequence
    # Using own for loop to do this instead of using helper function
    list_check = list_headers[1:]
    b1 = False
    k1 = 0
    list_check_dna = []
    while b1==False:
        if k1==len(list_check):
            break
        ref_check = list_check[k1]
        index = []
        for i in range(len(final_dna)-(len(ref_check)-1)):
            if final_dna[i:i+len(ref_check)] == ref_check:
                index.append(i)
        if len(index) == 1:
            list_check_dna.append(1)
            k1+=1
            continue
        streak = 0
        max1 = 0
        for i in range(len(index)-1):
            if index[i+1] - index[i] == len(ref_check):
                streak+=1
                if streak + 1 > max1:
                    max1 = streak + 1
            else:
                streak = 0
        list_check_dna.append(max1)
        k1+=1
    list_final = []
    for i in list_check_dna:
        list_final.append(str(i))


    # TODO: Check database for matching profiles

    flag = 0
    for i in list_subjects:
        if i[1:]==list_final:
            print(i[0])
            flag+=1
            break
    if flag==0:
        print("No match")

    return

main()
