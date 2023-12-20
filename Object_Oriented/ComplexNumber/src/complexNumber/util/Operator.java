package complexNumber.util;

public class Operator {
    public Complex addition(Complex a, Complex b) {
        Complex c = new Complex();
        c.rel = a.rel + b.rel;
        c.img = a.img + b.img;
        return c;
    }

    public Complex substraction(Complex a, Complex b) {
        Complex c = new Complex();
        c.rel = a.rel - b.rel;
        c.img = a.img - b.img;
        return c;
    }

    public Complex multiplication(Complex a, Complex b) {
        Complex c = new Complex();
        c.rel = a.rel * b.rel - a.img * b.img;
        c.img = a.rel * b.img + a.img * b.rel;
        return c;
    }

    public Complex division(Complex a, Complex b) {
        Complex c = new Complex();
        double div = b.img * b.img + b.rel * b.rel;
        c.rel = (a.rel * b.rel + a.img * b.img) / div;
        c.img = (-(a.rel * b.img) + a.img * b.rel) / div;
        return c;
    }

    public Complex absolute(Complex a) {
        Complex c = new Complex();
        c.rel = Math.sqrt(a.rel * a.rel + a.img * a.img);
        c.img = 0;
        return c;
    }
}