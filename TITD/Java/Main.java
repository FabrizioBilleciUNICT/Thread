
public class Main {
	
	public static void main(String[] args){
		MyInt mi = new MyInt();
		Thread tI = new Thread(new TI(mi));
		Thread tD = new Thread(new TD(mi));

		tI.start();
		tD.start();

		try {
			tI.join();
			tD.join();
		} catch(InterruptedException e) {
			e.printStackTrace();
		}
	}
}