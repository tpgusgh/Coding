from google.cloud import vision
import io

# Google Cloud Vision 클라이언트 생성
client = vision.ImageAnnotatorClient()

# 이미지 파일 읽기
with io.open('path_to_image.jpg', 'rb') as image_file:
    content = image_file.read()

image = vision.Image(content=content)

# 이미지에 대한 레이블 감지 수행
response = client.label_detection(image=image)
labels = response.label_annotations

# 감지된 레이블 출력
for label in labels:
    print(label.description, label.score)
