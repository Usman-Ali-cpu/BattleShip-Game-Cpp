from Asset import Asset


print("Wellcome to the Depreciation Calculator ")
while True:
    choice = input("Do you have an Asset? (Y/N): ")
    if choice == "Y" or choice == "y":

        cost = int(input("Asset Cost: "))
        salvage = int(input("Salvage Value: "))
        life = int(input("Life (years): "))
        asset = Asset(cost, salvage, life)
        if asset.isValid() == False:
            continue
        else:
            print(
                "For Straight Line the annual depreciation is : $"
                + str(asset.getAnnDep())
            )
            print(
                "For SYD the first year depreciation is : $" + str(asset.getfirstSYD())
            )
        ch = input("Whould you like to see a schedule? (Y/N): ")
        if ch == "Y" or ch == "y":
            asset.drawSchedule()

    else:
        print("Thanks for using the Depreciation Calculator!")
        exit(0)
