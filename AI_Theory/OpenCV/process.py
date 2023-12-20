import cv2


def image_process(src):
    dstx = cv2.Sobel(src, cv2.CV_32F, 1, 0)  # 計算 x 軸影像梯度
    dsty = cv2.Sobel(src, cv2.CV_32F, 0, 1)  # 計算 y 軸影像梯度
    dstx = cv2.convertScaleAbs(dstx)  # 將負值轉正值
    dsty = cv2.convertScaleAbs(dsty)  # 將負值轉正值
    dst = cv2.addWeighted(dstx, 0.5, dsty, 0.5, 0)  # 影像融合
    cv2.imwrite("sobel_processings.jpg", dst)  # 將影像寫入檔案
