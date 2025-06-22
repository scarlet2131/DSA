import java.util.Scanner;


public class SecondHighest{

	public static void main( String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();

		int[] arr = new int[n];
		for(int i=0;i<n;i++){
			arr[i] = sc.nextInt();
		}

		Integer firstHigh= null;
		Integer secondHigh = null;

		for(int i=0;i<n;i++){

			if(firstHigh == null || arr[i]> firstHigh){
				secondHigh = firstHigh;
				firstHigh = arr[i];
			}
			else if(arr[i]!=firstHigh && (secondHigh==null || arr[i]> secondHigh) ){
				secondHigh = arr[i];
			}

		}

		System.out.println(" The second highest number is "+ secondHigh);

 		sc.close();
	}
}
