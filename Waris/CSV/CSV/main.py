import csv

inputFile = input("Enter input file name : ")
outputFile = input("Enter output file name : ")

with open(outputFile, mode='w',  newline='\n') as csv_file:
    writer = csv.writer(
        csv_file, delimiter=',', quotechar='"', quoting=csv.QUOTE_MINIMAL)

    with open(inputFile) as csv_file:
        csv_reader = csv.reader(csv_file, delimiter=',')
        line_count = 0
        for row in csv_reader:
            if line_count == 0:
                line_count += 1
                print(row)
                writer.writerow(row)
            else:
                line_count += 1
                if row[2] == '3' and row[3] == '2019':
                    print(row)
                    writer.writerow(row)
        print(f'Processed {line_count-1} row.')
