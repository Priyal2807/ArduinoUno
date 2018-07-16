webcamlist

cam=webcam('EasyCamera');

preview(cam)
img = snapshot(cam);
imshow(img)
clear('cam');