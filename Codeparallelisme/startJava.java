
class startJava implements Runnable {
    int num;
    startJava(int num) {
	this.num = num;
    }
    public void run() {
	try {
	    System.out.println("Hello from "+num);
	    Thread.sleep(5000);
	}
	catch (Exception e) {
	   System.err.println("Erreur dans le sleep: " + e.getMessage()); 
	}
    }

    public static void main(String args[]) {
	Thread tab[] = new Thread[10];
	for(int i=0; i < 10; i++) {
	    tab[i] = new Thread(new startJava(i));
	    tab[i].start();
	}
	for(int i=0; i < 10; i++) {
	    try {
		tab[i].join();
	    }
	    catch(Exception e) {
		System.err.println("Erreur dans le join: " + e.getMessage()); 	
	    }
	}
	
    }
}


