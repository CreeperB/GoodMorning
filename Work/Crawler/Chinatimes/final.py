import json

data = json.load(open("first.json", "r", encoding="utf-8"))
transfer = {}

for i in data:
    print(i)
    if len(data[i]["keywords"]["經濟類"]) and len(data[i]["keywords"]["不確定類"]) and len(data[i]["keywords"]["政策類"]):
        transfer[i] = data[i]

json.dump(transfer, open("data.json", "w", encoding="utf-8"), ensure_ascii=False, indent=4)