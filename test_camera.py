import sensor,pyb

filepath="./test.jpg"
imageCompression=100

while(True):

sensor.reset()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.VGA)
sensor.skip_frames(time = 500)

img=sensor.snapshot()
img.save(filepath,quality=imageCompression)
print("image saved")
pyb.delay(10000)
