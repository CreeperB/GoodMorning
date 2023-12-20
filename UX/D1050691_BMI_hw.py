name_set = []
bmi_set = []
w_set = []
h_set = []
status_set = []


def calculate(w, h):
    return w / (h * h)  # calculate BMI


def get_data():
    try:
        name = str(input("Please enter the name: "))  # input name
        if name == "-1": return None, None, None, None
        w = float(input("Please input the weight(kg): "))  # input weight
        h = float(input("Please input the height(cm): "))  # input height
        if h > 5: h /= 100  # cm to m
        bmi = calculate(w, h)
        return name, w, h, bmi
    except ValueError:  # BMI out of range or input error
        print("Not a right data, please enter your data again")
    except TypeError:
        print("Not a right data, please enter your data again")
    except Exception as e:
        print(e)
        exit()


def append_data(name, w, h, bmi):
    name_set.append(name)  # add name to list
    w_set.append(w)  # add weight to list
    h_set.append(h)  # add height to list
    bmi_set.append(bmi)  # add BMI to list
    status_set.append("Underweight" if bmi < 18.5 else "Normal" if bmi < 25 else "Overweight" if bmi < 30 else "Obese")  # add status to list


def start_program():
    while True:
        name, w, h, bmi = get_data()
        if name is None: break
        append_data(name, w, h, bmi)


if __name__ == "__main__":
    print("Input your name, weight, height to calculate BMI")  # print the instruction of the program
    print("Input -1 in name to stop")  # print the instruction of stop
    start_program()
    [print(f"{name_set[i]:10s}: Weight = {w_set[i]:.2f}kg Height = {h_set[i]}m BMI = {bmi_set[i]:.2f} Status = {status_set[i]}") for i in range(len(bmi_set))]  # print result
    print(f"There are {len(bmi_set)} people in total")  # print the number of people
    print(f"Status: Underweight = {status_set.count('Underweight')} Normal = {status_set.count('Normal')} Overweight = {status_set.count('Overweight')} Obese = {status_set.count('Obese')}")  # print the number of each status