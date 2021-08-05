public class Member {
    private String memName;
    private int numberOfMission;
    private Mission[] missionArr;
    private int current;

    Member(){
        this.memName = "Unkown";
        this.numberOfMission = 3;
        this.missionArr = new Mission[numberOfMission];
        current = 0;
    }
    Member(String name, int num){
        this.memName = name;
        this.numberOfMission = num;
        this.missionArr = new Mission[numberOfMission];
        current = 0;
    }
    public void setMemName(String memName) {
        this.memName = memName;
    }
    public void setNumberOfMission(int numberOfMission) {
        this.numberOfMission = numberOfMission;
    }
    public String getMemName() {
        return memName;
    }
    public int getCurrent() {
        return current;
    }
    public int getNumberOfMission() {
        return numberOfMission;
    }
    public Mission[] getMissionArr() {
        return missionArr;
    }
    public Mission getMission(int index){
        Mission mi = new Mission();
        if(index < numberOfMission){
            Mission m = missionArr[index];
            return m;
        }
        return mi;
    }
    public boolean completeMission(int index){
        if(index < numberOfMission){
            if(missionArr[index].isCompleted() == true){
                return false;
            }
            else {
                missionArr[index].setCompleted(true);
                return true;
            }
        }
        return false;
    }

    public void addMission(Mission m){
        if(current < numberOfMission){
            missionArr[current] = m;
        }
        current++;
    }
    public void deleteMission(int index){
        if(index < numberOfMission){
            Mission m = missionArr[current];
            missionArr[index]  = m;
            current--;
        }
    }

    @Override
    public String toString() {
        return super.toString();
    }


}
