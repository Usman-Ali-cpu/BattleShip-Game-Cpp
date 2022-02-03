
public class Mission{
    private String name;
    private boolean completed;


    Mission(){
        setName("Unknow");
        setCompleted(false);
    }
    Mission(String n, boolean b){
        setName(n);
        setCompleted(b);
    }
    public String getName() {
        return name;
    }
    public boolean isCompleted() {
        return completed;
    }
    public void setName(String name) {
        this.name = name;
    }
    public void setCompleted(boolean completed) {
        this.completed = completed;
    }
    @Override
    public String toString() {
        // TODO Auto-generated method stub
        return "Mission {name = " +  this.getName() + ", completed = " + completed + "}";
    }

    






}