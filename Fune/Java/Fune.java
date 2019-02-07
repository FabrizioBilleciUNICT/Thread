

public class Fune {
	
	private int posizione = 0;
	private int vittorie_tp0 = 0, vittorie_tp1 = 0;

	public Fune() {}


	public synchronized void decrease(int forza){
		if(posizione >= 10){
			vittorie_tp1++;
			System.out.println("Sono T0. T1 ha vinto.");
			posizione = 0;
			notifyAll();
		} else {
			posizione -= forza;
			if(posizione <= -10){
				try {
					wait();
				} catch(InterruptedException e){
					e.printStackTrace();
				}
			}
		}
	}

	public synchronized void increase(int forza){
		if(posizione <= -10){
			vittorie_tp0++;
			System.out.println("Sono T1. T0 ha vinto.");
			posizione = 0;
			notifyAll();
		} else {
			posizione += forza;
			if(posizione >= 10){
				try {
					wait();
				} catch(InterruptedException e){
					e.printStackTrace();
				}
			}
		}
	}

	public boolean isGame(){
		return (vittorie_tp0 < 10 && vittorie_tp1 < 10);
	}

	public int getV0(){ return this.vittorie_tp0; }
	public int getV1(){ return this.vittorie_tp1; }
}