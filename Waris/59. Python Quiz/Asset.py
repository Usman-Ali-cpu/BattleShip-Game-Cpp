class Asset:
    def __init__(self, a_cost, a_salvage, a_life) -> None:
        self.cost = a_cost
        self.salvage = a_salvage
        self.value = 0
        self.life = a_life
        self.beginningBal = []
        self.endingBal = []
        self.depreciationRate = []
        self.sysdep = []
        self.endsl = []
        anuuladep = self.cost
        self.elspSL = self.getAnnDep()
        self.currentbeg = self.cost
        firstyear = self.getfirstSYD()
        val = firstyear / self.life

        years = (self.life * (self.life + 1)) / 2
        for i in reversed(range(self.life + 1)):
            sysper = i / years
            self.beginningBal.append(self.currentbeg)
            self.depreciationRate.append(sysper)
            self.currentbeg -= firstyear
            self.sysdep.append(firstyear)
            firstyear -= val
            self.endingBal.append(self.currentbeg)
            anuuladep = anuuladep - self.elspSL
            self.endsl.append(anuuladep)

    def getCost(self):
        return self.cost

    def getSalvage(self):
        return self.salvage

    def getLife(self):
        return self.life

    def isValid(self):
        if self.cost < 0 or self.life <= 0:
            print("Asset Error: Life must be positive.")
            return False
        if self.salvage < 0:
            print("Asset Error: Salvage must be positive.")
            return False
        if self.salvage > self.cost:
            print("Asset Error: Salvage must be less than cost")
            return False
        return True

    def getBegBal(self, yr):
        return self.beginningBal[yr - 1]

    def getAnnDepRate(self, yr):
        return self.depreciationRate[yr - 1]
        # years = 0
        # for i in range(1, self.life + 1):
        #     years += i
        # per = yr / years
        # per = per / 100
        # return per

    def getEndBal(self, yr):
        return self.endingBal[yr - 1]

    def getEndBalSL(self, yr):
        # yr = (self.life + 1) - yr
        # anuuladep = (self.cost - self.salvage) / self.life
        # endSL = self.cost - (anuuladep * yr)
        return self.endingBal[yr - 1]

    def getAnnDep(self, yr=0):
        if self.isValid():
            if yr == 0:
                return (self.cost - self.salvage) / self.life

        else:
            if yr >= 1:
                return self.sysdep[yr - 1]

    def getfirstSYD(self):
        if self.isValid():
            years = (self.life * (self.life + 1)) / 2
            sysper = self.life / years
            return sysper * (self.cost - self.salvage)

    def drawSchedule(self):
        if self.isValid():
            print(
                "Year\tYear SYD Beg.Bal.\tSYD Dep.\tSYD Rates\t SYD End.Bal.\t  SL End.Bal.\n"
            )
            for i in range(0, self.life):
                print(
                    "%.2d \t %.2f \t     %.2f \t      %.2f \t    %.2f \t\t %.2f\n"
                    % (
                        (i + 1),
                        self.beginningBal[i],
                        self.sysdep[i],
                        self.depreciationRate[i] * 100,
                        self.endingBal[i],
                        self.endsl[i],
                    )
                )
