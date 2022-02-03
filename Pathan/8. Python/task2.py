import csv


def get_month(i):
    if i == 1:
        return "January"
    if i == 2:
        return "Feburary"
    if i == 3:
        return "March"
    if i == 4:
        return "April"
    if i == 5:
        return "May"
    if i == 6:
        return "June"
    if i == 7:
        return "July"
    if i == 8:
        return "August"
    if i == 9:
        return "September"
    if i == 10:
        return "Octuber"
    if i == 11:
        return "November"
    if i == 12:
        return "December"


list_phoenix = []
amnt_of_precipitation = 0
with open('Phoenix_2020.csv') as csv_file:
    csv_reader = csv.reader(csv_file, delimiter=',')
    line_count = 0
    for row in csv_reader:
        if line_count == 0:
            line_count += 1
        else:
            phoenix_dict = {
                "STATION": "none",
                "NAME": 'none',
                "DATE": None,
                "PRCP": 0,
                "TMAX": 0,
                "TMIN": 0
            }
            phoenix_dict["STATION"] = row[0]
            phoenix_dict["NAME"] = row[1]
            phoenix_dict["DATE"] = row[2]
            phoenix_dict["PRCP"] = float(row[3])
            phoenix_dict["TMAX"] = int(row[4])
            phoenix_dict["TMIN"] = int(row[5])
            list_phoenix.append(phoenix_dict)
            amnt_of_precipitation += 1


def get_maximum(list_months):
    maxi = -1
    for m in list_months:
        if(m['TMAX'] > maxi):
            maxi = m['TMAX']
    return maxi


def get_minimum(list_months):
    mini = 12345
    for m in list_months:
        if(m['TMAX'] < mini):
            mini = m['TMAX']
    return mini


def get_month_data(month):
    list_with_month = []
    for li in list_phoenix:
        phoenix_dict = {
            "DATE": None,
            "PRCP": 0,
            "TMAX": 0,
            "TMIN": 0
        }
        date = li['DATE'].split("/")
        d = int(date[0])
        if(d == month):
            # print(li)
            phoenix_dict["DATE"] = li['DATE']
            phoenix_dict["PRCP"] = li['PRCP']
            phoenix_dict["TMAX"] = li['TMAX']
            phoenix_dict["TMIN"] = li["TMIN"]
            list_with_month.append(phoenix_dict)
    return list_with_month


def main():
    print("************** The total amount of precipitation for the year ****************")
    print("\tThe total amount of precipitation for the year: " +
          str(amnt_of_precipitation))
    print("\n********** The highest temperature for each month in 2020 *****************")
    for i in range(1, 13):
        list_of_month = get_month_data(i)
        print(
            get_month(i) + "'s temperature was " + str(get_minimum(list_of_month)))
    print("\n********** The lowest temperature for each month in 2020 *****************")
    for i in range(1, 13):
        list_of_month = get_month_data(i)
        print(
            get_month(i) + "'s temperature was " + str(get_maximum(list_of_month)))


main()
