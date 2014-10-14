import com.opensymphony.xwork2.Action;

public class HelloWord implements Action {


	public String getName() {
	return name;
	}
	public void setName(String name) {
	this.name = name;
	}
	public String execute() {
	name = "Hello, " + name + "!";
	return SUCCESS;
	}
}
