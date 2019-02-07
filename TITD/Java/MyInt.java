
public class MyInt {
	private int n = 100;

	public MyInt() {}

	public synchronized boolean increase(int c){
		n += c;
		System.out.println("TI: " + n);
		return (n > 150);
	}

	public synchronized boolean decrease(int c){
		n -= c;
		System.out.println("\t\tTD: " + n);
		return (n < 80);
	}
}