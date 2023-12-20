import java.util.*;
import java.lang.Integer;

public class Triathlon {

    static class athlete {
        int SerialNo;
        String name;
        String swimTime;
        String bikeTime;
        String runTime;
        String totalTime;
        int totalTimeinSec;

        athlete(int sn, String n, String st, String bt, String rt) {
            SerialNo = sn;
            name = n;
            swimTime = st;
            bikeTime = bt;
            runTime = rt;
            int sttime[] = new int[3];
            int bttime[] = new int[3];
            int rttime[] = new int[3];
            int tttime[] = new int[3];
            int carry = 0;
            for (int i = 2; i >= 0; i--) {
                sttime[i] = Integer.parseInt(swimTime.split(":")[i]);
                bttime[i] = Integer.parseInt(bikeTime.split(":")[i]);
                rttime[i] = Integer.parseInt(runTime.split(":")[i]);
                tttime[i] = sttime[i] + bttime[i] + rttime[i];
                if (carry > 0) {
                    tttime[i] += carry;
                    carry = 0;
                }
                if (tttime[i] >= 60) {
                    carry = tttime[i] / 60;
                    tttime[i] = tttime[i] % 60;
                }
            }
            totalTime = String.format("%02d:%02d:%02d", tttime[0], tttime[1], tttime[2]);
            totalTimeinSec = tttime[0] * 3600 + tttime[1] * 60 + tttime[2];
        }
    }

    static class athletesSort implements Comparator<athlete> {
        public int compare(athlete a, athlete b) {
            if (a.totalTime == b.totalTime) {
                return a.SerialNo - b.SerialNo;
            }
            return a.totalTimeinSec - b.totalTimeinSec;
        }
    }

    public static void main(String[] args) {
        ArrayList<athlete> athletes = new ArrayList<athlete>();
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of athletes: ");
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            int SerialNo = sc.nextInt();
            String firstName = sc.next();
            String lastName = sc.next();
            String swimTime = sc.next();
            String bikeTime = sc.next();
            String runTime = sc.next();
            athlete athlete = new athlete(SerialNo, firstName + ' ' + lastName, swimTime, bikeTime, runTime);
            athletes.add(athlete);
        }
        sc.close();
        Collections.sort(athletes, new athletesSort());
        System.out.println("Rank \tNo. \tName \t\tSwimming \tBiking \t\tRunning \tTotalTime\t");
        System.out.println(
                "-------------------------------------------------------------------------------------------");
        for (int i = 0; i < athletes.size(); i++) {
            athlete athlete = athletes.get(i);
            System.out.printf("%d \t%d \t%s \t%s \t%s \t%s \t%s \t \n", i + 1, athlete.SerialNo, athlete.name,
                    athlete.swimTime, athlete.bikeTime, athlete.runTime, athlete.totalTime);
        }
    }
}