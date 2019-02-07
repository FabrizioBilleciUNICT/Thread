import java.util.*;

public class Hit implements Runnable {
	private final String name;

	public Hit(String name) {
		this.name = name;
	}

	public void run(){
		int hit = 0;
		while(true){
			try {
				Thread.sleep(new Random().nextInt(10) + 1);
			} catch(InterruptedException e){
				e.printStackTrace();
			}

			synchronized(Main.x){
				if(Main.x > 500) break;
				else {
					hit++;
					Main.x++;
				}
			}
		}
		System.out.println(name + " -> " + hit);
	}
}