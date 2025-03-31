class MyThread extends Thread{
	String name;

	public MyThread(String name ){
		this.name = name;
	}

	void run(){
		system.out.println("starting the thread for "+ name);
		try{
			Thread.sleep(100);
		}catch(Exception e){
			e.printStackTrace();
			throw e;
		}
		System.out.println("Thread " + name + " has finished.");
	}
}

public class multithreading{
	public static void main(String[] args){
		MyThread t1 = new MyThread("A");
		MyThread t2 = new MyThread("B");

		//START THE Thread
		t1.start();
		t2.start();


		//end the thread 
		try{
			t1.join();
			t2.join();
		}catch(Exception e){
			e.printStackTrace();
		}
		System.out.println("all thread complete ");

	}
}