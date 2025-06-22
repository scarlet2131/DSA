abstract class Vehicle{
	abstract void brake();
	abstract void accelerate();

}

class Car extends Vehicle{

	@Override
	void brake(){
		System.out.println(" Car stopped");
	}

	@Override
	void accelerate(){
		System.out.println("Car speed Up");
	}
}
public class Main{
	public static void main(String[] args){
		Vehicle stud = new Car();
		stud.brake();
		stud.accelerate();

	}
}