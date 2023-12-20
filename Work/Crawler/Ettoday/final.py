import json
import requests
from bs4 import BeautifulSoup

URL = "https://star.ettoday.net/news/{id}"
data = json.load(open("first.json", "r", encoding="utf-8"))
# transfer = json.load(open("transfer.json", "r", encoding="utf-8"))
transfer = {}


def get_title(soup: BeautifulSoup):
    title = soup.select_one("head title").text
    print(title)
    return title


def get_time(id):
    date = ""
    date = data["result"][str(id)]["date"][:10].replace("-", "/")
    return date


def get_preview(id):
    preview = data["result"][str(id)]["content"][:100].replace("\n", " ")
    return preview


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


def get_keywords(id):
    keywords = {
        "經濟類": [],
        "不確定類": [],
        "政策類": [],
    }
    for i in keyword_groups:
        for j in i.keywords:
            if j in data["result"][str(id)]["content"]:
                keywords[i.name].append(j)
    return keywords


if __name__ == "__main__":
    for id in data["result"]:
        while True:
            try:
                print(id)
                r = requests.get(URL.format(id=id))
                soup = BeautifulSoup(r.text, "html.parser")
                url = r.url.replace("?redirect=1", "")
                transfer[url] = {
                    "title": get_title(soup),
                    "time": get_time(id),
                    "preview": get_preview(id),
                    "keywords": get_keywords(id),
                }
                break
            except:
                continue
    json.dump(transfer, open("data.json", "w", encoding="utf-8"), indent=4, ensure_ascii=False)