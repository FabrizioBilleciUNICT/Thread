
public class Main {
	public static Integer x = 0;
	
	public static void main(String[] args){
		Thread tA = new Thread(new Hit("A"));
		Thread tB = new Thread(new Hit("B"));

		tA.start();
		tB.start();

		try {
			tA.join();
			tB.join();
		} catch(InterruptedException e){
			e.printStackTrace();
		}
	}
}