package RationalNumber;

import java.util.Scanner;

public class RationalNumber {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("a = ");
        String[] s = sc.nextLine().split("/");
        Fraction a = new Fraction(s);

        System.out.print("b = ");
        s = sc.nextLine().split("/");
        Fraction b = new Fraction(s);

        System.out.print("c = ");
        s = sc.nextLine().split("/");
        Fraction c = new Fraction(s);

        System.out.print("d = ");
        s = sc.nextLine().split("/");
        Fraction d = new Fraction(s);

        System.out.print("e = ");
        s = sc.nextLine().split("/");
        Fraction e = new Fraction(s);

        System.out.print("---------------------\n\n");
        System.out.printf("a+b = %s\n", calcFraction(a, b, '+'));
        System.out.printf("c-d = %s\n", calcFraction(c, d, '-'));
        System.out.printf("a*b = %s\n", calcFraction(a, b, '*'));
        System.out.printf("c/d = %s\n", calcFraction(c, d, '/'));
        System.out.printf("|e| = %s\n", calcFraction(e, e, '|'));
        System.out.printf("a*|d-b|-(b+c/a)*|b*e-c/d| = %s", calcFraction(a, b, c, d, e));
        sc.close();
    }

    public static String calcFraction(Fraction a, Fraction b, char op) {
        double tmp = 0.0;
        int nume = 0, deno = 0, gcd = 0;
        if (op == '+') {
            tmp = a.getNum() + b.getNum();
            nume = a.getNume() * b.getDeno()
                    + b.getNume() * a.getDeno();
            deno = a.getDeno() * b.getDeno();
            gcd = getGcd(nume, deno);
            nume /= gcd;
            deno /= gcd;
        } else if (op == '-') {
            tmp = a.getNum() - b.getNum();
            nume = a.getNume() * b.getDeno()
                    - b.getNume() * a.getDeno();
            deno = a.getDeno() * b.getDeno();
            gcd = getGcd(nume, deno);
            nume /= gcd;
            deno /= gcd;
        } else if (op == '*') {
            tmp = a.getNum() * b.getNum();
            nume = a.getNume() * b.getNume();
            deno = a.getDeno() * b.getDeno();
            gcd = getGcd(nume, deno);
            nume /= gcd;
            deno /= gcd;
        } else if (op == '/') {
            tmp = a.getNum() / b.getNum();
            nume = a.getNume() * b.getDeno();
            deno = a.getDeno() * b.getNume();
            gcd = getGcd(nume, deno);
            nume /= gcd;
            deno /= gcd;
        } else if (op == '|') {
            tmp = a.getNum() / b.getNum();
            nume = Math.abs(a.getNume());
            deno = Math.abs(a.getDeno());
        }
        if (tmp == 0.0) {
            return "0";
        }
        if (deno < 0) {
            nume *= -1;
            deno *= -1;
        }
        if (deno == 1)
            return Integer.toString(nume);
        return Integer.toString(nume) + "/" + Integer.toString(deno);
    }

    private static int getGcd(int a, int b) {
        if (b == 0)
            return a;
        return getGcd(b, a % b);
    }

    private static String calcFraction(Fraction a, Fraction b, Fraction c, Fraction d, Fraction e) {
        int adbNume = Math.abs(d.getNume() * b.getDeno() - b.getNume() * d.getDeno());
        int adbDeno = Math.abs(d.getDeno() * b.getDeno());
        adbNume *= a.getNume();
        adbDeno *= a.getDeno();

        int bcaNume = c.getNume() * a.getDeno();
        int bcaDeno = c.getDeno() * a.getNume();
        bcaNume = b.getNume() * bcaDeno + bcaNume * b.getDeno();
        bcaDeno = b.getDeno() * bcaDeno;

        int beNume = b.getNume() * e.getNume();
        int beDeno = b.getDeno() * e.getDeno();
        int cdNume = c.getNume() * d.getDeno();
        int cdDeno = c.getDeno() * d.getNume();

        int becdNume = Math.abs(beNume * cdDeno - cdNume * beDeno);
        int becdDeno = Math.abs(beDeno * cdDeno);

        int p = bcaNume * becdNume;
        int q = bcaDeno * becdDeno;
        p = adbNume * q - p * adbDeno;
        q = adbDeno * q;
        int gcd = getGcd(p, q);
        p /= gcd;
        q /= gcd;

        if (q == 1)
            return Integer.toString(p);
        if (q < 0) {
            p *= -1;
            q *= -1;
        }
        return Integer.toString(p) + "/" + Integer.toString(q);
    }
}

class Fraction {
    private int p;
    private int q;
    private double num;

    public Fraction() {
        this.p = 0;
        this.q = 1;
        this.num = 0;
    }

    public Fraction(int p) {
        this.p = p;
        this.q = 1;
        this.num = p;
    }

    public Fraction(int p, int q) {
        this.p = p;
        this.q = q;
        this.num = p / q;
    }

    public Fraction(String[] s) {
        this.p = Integer.parseInt(s[0]);
        if (s.length == 2) {
            this.q = Integer.parseInt(s[1]);
        } else {
            this.q = 1;
        }
        this.num = p / q;
    }

    public void setNume(int p) {
        this.p = p;
        this.num = p / q;
    }

    public void setDeno(int q) {
        if (q == 0)
            throw new IllegalArgumentException("Argument \'denominator\' is 0");
        this.q = q;
        this.num = p / q;
    }

    public int getNume() {
        return this.p;
    }

    public int getDeno() {
        return this.q;
    }

    public double getNum() {
        return this.num;
    }

    public void printRational() {
        System.out.printf("%d/%d", this.p, this.q);
    }
}