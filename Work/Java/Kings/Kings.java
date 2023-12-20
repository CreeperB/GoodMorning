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

class kingsSort implements Comparator<warrior> {
    public int compare(warrior a, warrior b) {
        if (a.Strength == b.Strength) {
            return a.Index - b.Index;
        }
        return b.Strength - a.Strength;
    }
}

class Kings {
    public int len;
    public static warrior[] w;

    public Kings(int[] strength, int[] range) {
        len = strength.length;
        w = new warrior[len];
        for (int i = 0; i < len; i++) {
            w[i] = new warrior(strength[i], range[i], i);
        }
    }

    public int[] topKKings(int k) {
        int[] data = new int[len * 2];
        for (int i = 0; i < len; i++) {
            int l = i;
            for (int j = i - 1; j >= 0; j--) {
                if (w[j].Strength < w[i].Strength && i - j <= w[i].Range) {
                    if (w[i].Range > w[j].Range) {
                        l = data[j * 2];
                        j = l;
                        continue;
                    } else {
                        if (i - data[j * 2] <= w[i].Range) {
                            l = data[j * 2];
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
            data[i * 2] = l;
        }
        for (int i = len - 1; i >= 0; i--) {
            int r = i;
            for (int j = i + 1; j < len; j++) {
                if (w[j].Strength < w[i].Strength && j - i <= w[i].Range) {
                    if (w[i].Range > w[j].Range) {
                        r = data[j * 2 + 1];
                        j = r;
                        continue;
                    } else {
                        if (data[j * 2 + 1] - i <= w[i].Range) {
                            r = data[j * 2 + 1];
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
            data[i * 2 + 1] = r;
        }
        // edit code below
        int[] left = new int[len];
        int[] right = new int[len];
        for (int i = 0; i < len; i++) {
            left[i] = data[i * 2];
            right[i] = data[i * 2 + 1];
        }
        int[] knocked = new int[len];
        int[] kingAscend = new int[len];
        for (int i = 0; i < len; i++) {
            int flag = 0;
            if (knocked[i] == 0) {
                flag = 1;
            }
            Arrays.fill(knocked, left[i], right[i] + 1, 1);
            if (flag == 1) {
                knocked[i] = 0;
            }
        }
        int count = 0;
        for (int i = 0; i < len; i++) {
            if (knocked[i] == 0) {
                kingAscend[count++] = i;
            }
        }
        ArrayList<warrior> out = new ArrayList<warrior>();
        for (int i = 0; i < count; i++) {
            out.add(new warrior(w[kingAscend[i]].Strength, w[kingAscend[i]].Range, w[kingAscend[i]].Index));
        }
        Collections.sort(out, new kingsSort());
        int[] res = new int[k];
        for (int i = 0; i < k; i++) {
            res[i] = out.get(i).Index;
        }
        return res;
    }

    public static void main(String[] args) {
        Kings sol = new Kings(
                new int[] { 8236, 63248, 44441, 68653, 5701, 78759, 94682, 42636, 24690, 59397, 31532, 28521, 8784,
                        59080, 97617, 40427, 78296, 61882, 58605, 27089, 100000, 40221, 26880, 34558, 25428, 12703,
                        59601, 48585, 94978, 15367, 100000, 71882, 39832, 14928, 92025, 78704, 8809, 31830, 82786,
                        47108, 100000, 11380, 33620, 63824, 53839, 59996, 93602, 43171, 100000, 96123, 70127, 70485,
                        1177, 82587, 86006, 11747, 88907, 23917, 59359, 2252, 18560, 25030, 24859, 57966, 87482, 53274,
                        95268, 73727, 12600, 21709, 18140, 56382, 29554, 81528, 17403, 77987, 4566, 30298, 25984, 78970,
                        17425, 38166, 90174, 15155, 59151, 31717, 89935, 50327, 65126, 31246, 61081, 32777, 20283,
                        55336, 60056, 89796, 51831, 100000, 67416, 38643 },
                new int[] { 391278, 375036, 322556, 32888, 51903, 495551, 314997, 190601, 352469, 277837, 1637, 493313,
                        254075, 239450, 388067, 222107, 123504, 393624, 127132, 402477, 0, 483717, 427024, 416208,
                        169287, 418620, 119169, 18652, 127441, 92126, 0, 329159, 300936, 261121, 489046, 31585, 408595,
                        410146, 201627, 76222, 0, 59535, 377867, 48318, 374873, 232438, 261272, 411271, 0, 135468,
                        453412, 402078, 225944, 108823, 495961, 471464, 392317, 307337, 21394, 259348, 132979, 403875,
                        122768, 429848, 277827, 157273, 309676, 216557, 76318, 108813, 326048, 421467, 330951, 229629,
                        118943, 118407, 267473, 211984, 125932, 144853, 28432, 323473, 419521, 312855, 270348, 32563,
                        231412, 335780, 70565, 269696, 313360, 103831, 174784, 484293, 59941, 496455, 409412, 0, 360550,
                        399567 });
        System.out.println(Arrays.toString(sol.topKKings(9)));
    }
}