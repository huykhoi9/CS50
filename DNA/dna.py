import csv
import sys

def main():
    #create command-line arguments
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py CSV file Text file ")

    #this is a list, later we put dict inside it
    STR_memory = []

    STR_file = sys.argv[1]

    #Use csv libary because we are reading csv
    #This is how u open the file in python, with "r" is reading mode
    # csv.reader returns a reader object(trả lại hết nội dung nhưng theo từng hàng) which iterates over lines of a CSV file
    # use csv.reader or csv.DictReader(kiểu một element(row) là 1 hàng) then the loop of reading each line in the file

    with open(STR_file, "r") as file:
        reader =  csv.DictReader(file)
        for row in reader:
            collumn_names = reader.fieldnames
            for i in range(1, len(collumn_names)):
                row[collumn_names[i]] = int(row[collumn_names[i]])
            STR_memory.append(row)

    #This file is text
    DNA_file = sys.argv[2]

    with open(DNA_file, "r") as file1:
        reader1 = file1.read()              #read everything it has in the file
        DNA_memory = reader1                # put it in a string, not a list or a dict

    #create a place to count the repeated STRs from text file
    count_STR = []
    for i in range(0, len(collumn_names) -1):
        count_STR.append(0)

    #compute the longest run of consecutive repeats of the STR and contain them in count_STR
    # i loops of going through all the STR names
    # j loops for slicing to the end of DNA_memory, check if the STR is repeated till the end of the string
    for i in range (1, len(collumn_names)):
        for j in range (0, len(DNA_memory) - len(collumn_names[i])):
                count_max = keep_checking(DNA_memory, collumn_names[i], j, 0, len(collumn_names[i])) #AGATC,TTTTTTCT,AATG,TCTAG,GATA,TATC,GAAA,TCTG
                count_STR[i -1] = check_max(count_max, count_STR[i-1])

    # i loop to check whose repeated STRs are
    for i in range(len(STR_memory)):
        matches = 0                                                         #the match reset when move to next person
        for j in range(1, len(collumn_names)):                              #exclude the people name column, therefore count_STR must minus 1
            if count_STR[j -1] == STR_memory[i][collumn_names[j]]:
                matches +=1
            if matches == len(collumn_names) -1:
                print(STR_memory[i]['name'])
                exit(0)
    print('No match')
    return

def keep_checking(string, b, i, count, increment):
    while i != len(string):
        if b in string[i:i +increment]:                                         #use slicing in string, string[i:j]
            count +=1
            count = keep_checking(string, b, i+increment, count, increment)     #use recursive
            return count
        elif b not in string[i:i +increment]:
            return count
    return count

def check_max(count_max, count):                                                #check to get the maximum
    if count_max is None:
        count = count
    elif count_max > count:
        count = count_max
    return count

if __name__ == "__main__":
    main()
