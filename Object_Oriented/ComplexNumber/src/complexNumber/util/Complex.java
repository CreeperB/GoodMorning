package complexnumber;

import java.text.DecimalFormat;

public class Complex {
    double rel, img;

    public Complex() {
        this.rel = 0.0;
        this.img = 0.0;
    }

    public Complex(double rel) {
        this.rel = rel;
        this.img = 0.0;
    }

    public Complex(double rel, double img) {
        this.rel = rel;
        this.img = img;
    }

    double getRe() {
        return this.rel;
    }

    double getIm() {
        return this.img;
    }

    void setRe(double rel) {
        this.rel = rel;
    }

    void setIm(double img) {
        this.img = img;
    }

    public void printComplex() {
        DecimalFormat df = new DecimalFormat("0.######");
        System.out.println(
                (this.rel != 0 ? df.format(this.rel) : "")
                        + (this.img == 0 ? "" : (this.img > 0 ? "+" : ""))
                        + (this.img != 0 ? df.format(this.img) + "i" : ""));
    }
}
