from rplidar import RPLidar
import serial
import time


arduino_port = '/dev/ttyACM0'  # Define the serial port of the Arduino
baud_rate = 9600
# Initialize the serial connection
ser = serial.Serial(arduino_port, baud_rate)


serial_port = '/dev/ttyUSB0' # Define the serial port of the RPLidar

lidar = RPLidar(serial_port)
scanning = True

try:
    # Start the RPLidar
    lidar.connect()
    lidar.start_motor()

    command = 'g'
    ser.write(command.encode())
    # Read data from the RPLidar
    for scan in lidar.iter_scans():
        for (_, angle, distance) in scan:
            # Convert distance from mm to cm
            distance_cm = distance / 10

            if 320 <= angle <= 360:
                print(f"Angle: {angle}, Distance: {distance_cm} cm")
               

                # Check if an object is within the specified range (0-90 degrees) and 30 cm away
                if scanning and distance_cm <= 30:
                    print("Object detected within range (0-90 degrees) and 30 cm away. Scanning paused.")
                    command = 'r'
                    ser.write(command.encode())
                    scanning = False
                    

                elif not scanning and distance_cm > 30:
                    print("Object removed. Resuming scanning.")
                    command = 'g'
                    ser.write(command.encode())
                    scanning = True
                 
except KeyboardInterrupt:
    lidar.stop_motor()
    lidar.disconnect()
