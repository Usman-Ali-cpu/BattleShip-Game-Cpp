
def lowndes(numreps, populationlist):
    totalPopulation = 0
    for p in populationlist:
        totalPopulation += p
    divisor = totalPopulation/numreps
    quota = []
    line = "["
    for p in populationlist:
        q = p/divisor
        intq = int(q)
        deciq = q-intq
        if deciq > 0.5:
            intq += 1
        line += str(intq) + ", "
        quota.append(intq)
    line += "]\n"
    sumQuota = 0
    for q in quota:
        sumQuota += q
    print(line)
    return line


def main():
    file = open("Prob01.in.txt", 'r')
    wfile = open("Prob01.out.txt", "w+")
    for f in file:
        li = f.split(" ")
        numreps = int(li[0])
        populationlist = []
        for i in range(1, len(li)):
            populationlist.append(int(li[i]))
        print(populationlist)
        line = lowndes(numreps, populationlist)
        wfile.write(line)
        populationlist.clear()


main()
