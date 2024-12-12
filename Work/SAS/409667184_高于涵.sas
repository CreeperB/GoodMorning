proc import datafile="C:\Users\409667184\Desktop\F18.xlsx" out=Fuel2018 dbms=xlsx replace;
run;

proc import datafile="C:\Users\409667184\Desktop\F19.xlsx" out=Fuel2019 dbms=xlsx replace;
run;

proc import datafile="C:\Users\409667184\Desktop\L18.xlsx" out=Labor2018 dbms=xlsx replace;
run;

proc import datafile="C:\Users\409667184\Desktop\L19.xlsx" out=Labor2019 dbms=xlsx replace;
run;

/* Merge fuel and labor data for 2018 */
data combined2018;
    merge Fuel2018(in=a) Labor2018(in=b);
    by carrier CARRIER_NAME year quarter;
    if a & b; /* Keep only observations present in both datasets */
run;

/* Merge fuel and labor data for 2019 */
data combined2019;
    merge Fuel2019(in=a) Labor2019(in=b);
    by carrier CARRIER_NAME year quarter;
    if a & b; /* Keep only observations present in both datasets */
run;

/* Combine all years */
data airlines_combined;
    set combined2018 combined2019;
run;

data airlines_combined;
    set airlines_combined;
    PL = Salaries000 * 1000 / Employee;
    PF = Fuel_Cost / Fuel_Gallons;
    label PL = "Price for labor"
          PF = "Price for fuel";
run;

proc summary data=airlines_combined nway;
    class carrier;
    var PL PF;
    output out=Sumout (drop=_type_ _freq_)
        mean=Mean_PL Mean_PF
        std=StdDev_PL StdDev_PF;
run;

proc datasets lib=work;
    modify Sumout;
    label Mean_PL = "Mean PL"
          Mean_PF = "Mean PF"
          StdDev_PL = "StdDev_PL"
          StdDev_PF = "StdDev_PF";
quit;


proc rank data=Sumout out=Final ties=low;
    var Mean_PL Mean_PF;
    ranks rank_PL rank_PF;
run;
