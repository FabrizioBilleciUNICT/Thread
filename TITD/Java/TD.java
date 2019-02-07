import java.util.*;

public class TD implements Runnable {
	private final MyInt mi;

	public TD(MyInt mi){
		this.mi = mi;
	}

	public void run(){
		int counter = 0;
		while(counter < 1000){
			try {
				Thread.sleep(300);
			} catch(InterruptedException e) {
				e.printStackTrace();
			}
			
			final int c = new Random().nextInt(10);

			if(mi.decrease(c)) break;
		}
	}

}