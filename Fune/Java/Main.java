
public class Main {
	
	public static void main(String[] args){
		Fune fune = new Fune();

		Thread tp0 = new Thread(new T0(fune));
		Thread tp1 = new Thread(new T1(fune));

		tp0.start();
		tp1.start();

		try {
			tp0.join();
			tp1.join();
		} catch(InterruptedException e){
			e.printStackTrace();
		}

		System.out.println("La partita è terminata " + fune.getV0() + " - " + fune.getV1());
	}
}