#prompt : python test.py
from keras.models import load_model
from time import sleep
from keras.preprocessing.image import img_to_array
from keras.preprocessing import image
import cv2 #import do opencv
import numpy as np

face_classifier = cv2.CascadeClassifier('./haarcascade_frontalface_default.xml') #Face classifier 
classifier =load_model('./Emotion_Detection.h5') #Modelo de treino da IA

class_labels = ['Angry','Happy','Neutral','Sad','Surprise'] #Emoções treinadas

cap = cv2.VideoCapture(0) #Entra na webcam

while True:
    #Pega um frame do video-----------------------------------#
    ret, frame = cap.read() # "fotografa" um frame do live feed
    labels = []
    gray = cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY) #Transforma o frame em grayscale
    faces = face_classifier.detectMultiScale(gray,1.3,5) #detecta o rosto
     #--------------------------------------------------------#

    for (x,y,w,h) in faces: #x, y , w e h são as cordanadas do rosto
        #Pega somente o rosto na imagem que está sendo processada#
        cv2.rectangle(frame,(x,y),(x+w,y+h),(255,0,0),2) #retangula o rosto
        roi_gray = gray[y:y+h,x:x+w]
        roi_gray = cv2.resize(roi_gray,(48,48),interpolation=cv2.INTER_AREA) #mesma dimensãp dos modulos treinados
        #--------------------------------------------------------#
        #Converte imagem em um array-----------------------------#
        if np.sum([roi_gray])!=0:
            roi = roi_gray.astype('float')/255.0
            roi = img_to_array(roi)
            roi = np.expand_dims(roi,axis=0)
        #--------------------------------------------------------#
        #Previsões das emoções e impressãp-----------------------#
            #Preve qual a emoção presente
            preds = classifier.predict(roi)[0]
            print("\nprediction = ",preds)
            label=class_labels[preds.argmax()]
            print("\nprediction max = ",preds.argmax())
            #----------------------------------------------------#
            print("\nlabel = ",label)
            label_position = (x,y)
            cv2.putText(frame,label,label_position,cv2.FONT_HERSHEY_SIMPLEX,2,(0,255,0),3) #Mostra na tela
        else:
            cv2.putText(frame,'No Face Found',(20,60),cv2.FONT_HERSHEY_SIMPLEX,2,(0,255,0),3)
        print("\n\n")
        #--------------------------------------------------------#
    cv2.imshow('Emotion Detector',frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()


























