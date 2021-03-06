import java.util.*;

public class T1 implements Runnable {
	private Fune fune;

	public T1(Fune fune){
		this.fune = fune;
	}

	public void run(){
		while(fune.isGame()) {
			int recupero = new Random().nextInt(4);
			int forza = new Random().nextInt(6);

			try {
				Thread.sleep(recupero);
			} catch(InterruptedException e){
				e.printStackTrace();
			}

			fune.increase(forza);
		}
	}
}