class SimpleLock{

	private int isLocked = false;


	public void lock(){
		while(true){
			if(!isLocked){
				isLocked = true;
				break;
			}
		}
	}

	public void unlock(){
		isLocked = false;
	}

}
public class Main(){
	public static void main(String[] args){

		SimpleLock lockObj = new SimpleLock();

		lockObj.lock();
		lockObj.unlock();
	}
}