class Vehicle{
	private int vehicleId;
	private String model;
	private int year;


	public Vehicle(int vehicleId, String model, int year){
		this.vehicleId = vehicleId;
		this.model = model;
		this.year = year;
	}
	public Vehicle(){

	}

	public int getVehicleId(){
		return this.vehicleId;
	}

	public void setVehicleId(int vehicleId){
		this.vehicleId = vehicleId;
	}
	public String getModel(){
		return this.model;
	}

	public void setModel(String model){
		this.model = model;
	}
	public int getYear(){
		return this.year;
	}

	public void setYear(int year){
		this.year = year;
	}

}

public class Main{
	public static void main(String[] args){
		Vehicle car = new Vehicle();
		car.setVehicleId(123);
		System.out.println(" Printing Car Id: "+ car.getVehicleId());
		Vehicle car1 = new Vehicle(131,"Honda City",1999);
		System.out.println(" Printing Car Id: "+ car1.getVehicleId() +
		 " and model : "+ car1.getModel() + " and year : "+ car1.getYear());

	}
}