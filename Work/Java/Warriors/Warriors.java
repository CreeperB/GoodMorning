
import java.util.*;

class warrior {
    int Strength;
    int Range;
    int Index;

    warrior(int str, int rng, int i) {
        Strength = str;
        Range = rng;
        Index = i;
    }
}

class Warriors {
    public int[] warriors(int[] strength, int[] range) {
        int len = strength.length;
        int[] res = new int[len * 2];
        warrior[] w = new warrior[len];
        for (int i = 0; i < len; i++) {
            w[i] = new warrior(strength[i], range[i], i);
        }
        for (int i = 0; i < len; i++) {
            int l = i;
            for (int j = i - 1; j >= 0; j--) {
                if (w[j].Strength < w[i].Strength && i - j <= w[i].Range) {
                    if (w[i].Range > w[j].Range) {
                        l = res[j * 2];
                        j = l;
                        continue;
                    } else {
                        if (i - res[j * 2] <= w[i].Range) {
                            l = res[j * 2];
                            j = l;
                            continue;
                        } else {
                            l = i - w[i].Range;
                            if (l > i) {
                                l = i;
                            }
                            break;
                        }
                    }
                } else {
                    break;
                }
            }
            if (l <= i - w[i].Range) {
                l = i - w[i].Range;
            }
            res[i * 2] = l;
        }
        for (int i = len - 1; i >= 0; i--) {
            int r = i;
            for (int j = i + 1; j < len; j++) {
                if (w[j].Strength < w[i].Strength && j - i <= w[i].Range) {
                    if (w[i].Range > w[j].Range) {
                        r = res[j * 2 + 1];
                        j = r;
                        continue;
                    } else {
                        if (res[j * 2 + 1] - i <= w[i].Range) {
                            r = res[j * 2 + 1];
                            j = r;
                            continue;
                        } else {
                            r = i + w[i].Range;
                            if (r < i) {
                                r = i;
                            }
                            break;
                        }
                    }
                } else {
                    break;
                }
            }
            if (r >= i + w[i].Range) {
                r = i + w[i].Range;
            }
            res[i * 2 + 1] = r;
        }
        // find the kings that cannot be knocked down under any circumstances?

        return res; // complete the code by returning an int[]
    }

    public static void main(String[] args) {
        Warriors sol = new Warriors();
        System.out.println(Arrays.toString(
                sol.warriors(new int[] { 15, 3, 26, 2, 5, 19, 12, 8 }, new int[] { 1, 6, 1, 3, 2, 0, 1, 5 })));
    }
}