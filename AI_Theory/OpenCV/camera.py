import cv2
import process as prs

# 開啟攝影鏡頭
cap = cv2.VideoCapture(1)

# 設置攝影鏡頭的畫面寬度和高度
cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)

if not cap.isOpened():
    print("Cannot open camera")
    exit()

while True:
    # 讀取當前幀的畫面
    ret, frame = cap.read()

    # 將畫面轉換為灰度圖像
    # gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    # 顯示灰度圖像
    # cv2.imshow('Camera', gray)

    # 顯示彩色圖像
    cv2.imshow('Camera', frame)
    cv2.imwrite('capture.jpg', frame)
    prs.image_process(frame)

    # 等待按下 'q' 鍵退出程式
    if cv2.waitKey(1) == ord('q'):

        break

    if cv2.waitKey(1) == ord('s'):
        cv2.imwrite('capture.jpg', frame)

# 釋放攝影鏡頭
cap.release()

# 關閉所有視窗
cv2.destroyAllWindows()