import math


def total_second(min, sec):
    return min * 60 + sec


def speed(time):
    return 3600 / time


pace_minutes = int(input("Minutes per mile:"))
pace_seconds = float(input("Seconds per mile:"))
miles = float(input("Total miles:"))

mph = speed(total_second(pace_minutes, pace_seconds))

print("Your speed is ", mph, "mph")

total = miles * total_second(pace_minutes, pace_seconds)
elapsed_minutes = total // 60
elapsed_seconds = total % 60

print("Your total elapsed time is ", int(elapsed_minutes), "min",
      int(elapsed_seconds), "sec")
