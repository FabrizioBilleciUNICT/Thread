import java.util.*;

public class TI implements Runnable {
	private final MyInt mi;

	public TI(MyInt mi){
		this.mi = mi;
	}

	public void run(){
		int counter = 0;
		while(counter < 1000){
			try {
				Thread.sleep(100);
			} catch(InterruptedException e) {
				e.printStackTrace();
			}

			final int c = new Random().nextInt(10);

			if(mi.increase(c)) break;
		}
	}

}