from bs4 import BeautifulSoup
import requests
import json
import concurrent.futures
import time

URL = "https://www.chinatimes.com/search/{keyword}?page={page}"
data = json.load(open("data.json", "r", encoding="utf-8"))


class KeywordGroup:

    def __init__(self, name: str, keywords: list[str]):
        self.name = name
        self.keywords = keywords


keyword_groups = [
    KeywordGroup(
        "經濟類",
        [
            "不動產",
            "房地產",
            "房產",
            "房價",
        ],
    ),
    KeywordGroup(
        "不確定類",
        [
            "不確定",
            "不明確",
            "不明朗",
            "不透明",
            "不穩定",
            "難以預料",
            "難以預測",
            "難以預計",
            "難以估計",
            "不安",
            "歧見",
            "未明",
            "動盪",
            "疑惑",
            "惶恐",
        ],
    ),
    KeywordGroup(
        "政策類",
        [
            "施政",
            "稅",
            "稅制",
            "課稅",
            "稅務",
            "稅改",
            "法案",
            "法規",
            "投資",
            "改革",
            "房貸",
            "房屋貸款",
            "利率",
            "匯率",
            "貨幣",
            "政策",
            "政府",
            "官邸",
            "國會",
            "立法院",
            "中央銀行",
            "央行",
            "泡沫",
            "泡沫化",
            "貸款成數",
            "房貸成數",
            "措施",
        ],
    ),
]


def get_page(page):
    while True:
        try:
            r = requests.get(URL.format(keyword=j, page=page))
            soup = BeautifulSoup(r.text, "html.parser")
            contents = soup.select(".vertical-list li")
            if len(contents) == 0:
                global stop
                stop = True
                return
            for content in contents:
                url = content.select_one(".title a").get("href")
                exist = url in data
                if not exist and i != keyword_groups[0]:
                    continue
                if not exist and i == keyword_groups[0]:
                    data[url] = {
                        "title": content.select_one(".title a").text,
                        "date": content.select_one(".date").text,
                        "preview": content.select_one("p").text,
                        "keywords": {
                            "經濟類": [],
                            "不確定類": [],
                            "政策類": [],
                        },
                    }
                if j not in data[url]["keywords"][i.name]:
                    data[url]["keywords"][i.name].append(j)
            # json.dump(data, open("first.json", "w", encoding="utf-8"), ensure_ascii=False, indent=4)
            return
        except KeyboardInterrupt:
            json.dump(data, open("first.json", "w", encoding="utf-8"), ensure_ascii=False, indent=4)
            executor.shutdown(wait=True)
            exit()
        except Exception as e:
            print(e)
            continue


if __name__ == "__main__":
    global i
    for i in keyword_groups:
        print(i)
        global j
        for j in i.keywords:
            print(j)
            global stop
            stop = False
            for k in range(1, 2501, 100):
                start_time = time.time()
                with concurrent.futures.ThreadPoolExecutor(max_workers=100) as executor:
                    executor.map(get_page, [l for l in range(k, k + 100)])
                    executor.shutdown(wait=True)
                print("time:", round(time.time() - start_time, 2))
                if stop:
                    break
            json.dump(data, open("first.json", "w", encoding="utf-8"), ensure_ascii=False, indent=4)