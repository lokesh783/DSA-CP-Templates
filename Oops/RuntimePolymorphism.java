/**
 * RuntimePolymorphism
 */

class parent{
    public void display(){
        System.out.println("display parent");
    }
}

class child extends parent{
    @Override
    public void display(){
        System.out.println("display child");
    }
}


public class RuntimePolymorphism {
    public static void main(String[] args) {
        parent par = new child();
        par.display();
    }
}