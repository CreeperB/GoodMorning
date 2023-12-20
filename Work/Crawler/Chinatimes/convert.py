import json
import csv

data = json.load(open("data.json", "r", encoding="utf-8"))
news_month_count = {}

for url, news in data.items():
    month = news["date"][:7]
    if month not in news_month_count:
        news_month_count[month] = 0
    news_month_count[month] += 1

writer = csv.writer(open("data.csv", "w", encoding="utf-8"))

fieldnames = ["Month", "Include three kind of keywords"]
writer.writerow(fieldnames)

news_month_count = {k: v for k, v in sorted(news_month_count.items(), key=lambda item: item[0])}

for i in news_month_count:
    writer.writerow([i, news_month_count[i]])
