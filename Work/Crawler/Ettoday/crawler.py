from bs4 import BeautifulSoup
import requests
import json
import concurrent.futures
import time
import os

URL = "https://star.ettoday.net/news/{id}"
data = json.load(open("first.json", "r", encoding="utf-8"))
total = len(data["result"])


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


def get_news(id: int):
    r = requests.get(URL.format(id=id))
    soup = BeautifulSoup(r.text, "html.parser")
    try:
        contents = soup.select("div.story p")
        contents = filter(lambda x: x.select_one("span") is None, contents)
        content = "\n".join(map(lambda x: x.text, contents))
        date = soup.select_one("meta[name='pubdate']").get("content")
        tags = []
        for i in keyword_groups:
            if keyword_groups.index(i) - len(tags) > 0:
                break
            for j in i.keywords:
                if j in content:
                    tags.append(i.name)
                    break
        print(f"{id}: {date}")
        if len(tags) == 3:
            # global data
            if str(id) in data["result"]:
                print("Same ID: " + str(id))
                return False
            data["result"][id] = {
                "content": content,
                "date": date,
            }
            data["last"] = id
            json.dump(data, open("first.json", "w", encoding="utf-8"), ensure_ascii=False, indent=4)
            global total
            total += 1
            print(total)
        # print(content + '\n' + date)
    except KeyboardInterrupt:
        print("Saving...")
        closing(id)
    except Exception as e:
        print(f"{id}: {e}")
        return False
    return True


def connection(id: int):
    success = False
    connect_times = 0
    while not success:
        while True:
            try:
                get_news(id)
                success = True
                break
            except KeyboardInterrupt:
                closing(id)
            except Exception as e:
                connect_times += 1
                if connect_times == 6:
                    print(e)
                    print("Error: " + str(id))
                    print("Saving...")
                    closing(id)
                print(f"{id}: Reconnecting...{connect_times} time{'' if connect_times == 1 else 's'}")
                time.sleep(0.1)
                continue


def closing(id: int):
    data["last"] = id
    json.dump(data, open("first.json", "w", encoding="utf-8"), ensure_ascii=False, indent=4)
    print("Shutting down...")
    executor.shutdown(wait=True)
    os.system("shutdown now")


if __name__ == "__main__":
    id = data["last"]
    for id in range(id, 0, -100):
        data["last"] = id
        json.dump(data, open("first.json", "w", encoding="utf-8"), ensure_ascii=False, indent=4)
        start_time = time.time()
        with concurrent.futures.ThreadPoolExecutor(max_workers=100) as executor:
            executor.map(connection, [id - i for i in range(100) if id - i > 0])
        print(f"Time: {time.time() - start_time:.2f}s")
    print("Final Done!")
    print("Total: " + str(total))