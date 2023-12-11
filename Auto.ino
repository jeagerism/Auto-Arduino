// Arduino Line Follower Robot Code
// <<=== ขา ปรับตาม การต่อสายเรา ===>>
#define enA 3  // Enable1 L293 Pin enA
#define in1 2  // Motor1  L293 Pin in1
#define in2 4  // Motor1  L293 Pin in1

#define enB 5  // Enable2 L293 Pin enB
#define in3 6  // Motor2  L293 Pin in1
#define in4 7  // Motor2  L293 Pin in1

#define R_S 8  // ir sensor Right
#define L_S 9  // ir sensor Left

// Motor speed variables (adjust these values for your desired speed)
int motorSpeed = 250;  // Range: 0 to 255, where 0 is off and 255 is full speed

// Global Count variable
int Count = 0;

// ฟังชั่นที่ทำงานแค่ครั้งเดียวเมื่อเริ่มทำงาน
void setup()
{

  Serial.begin(9600);

  // กำหนดโหมดของพิน enA เป็นขาจ่ายสัญญาณ
  pinMode(enA, OUTPUT);

  // กำหนดโหมดของพิน in1 เป็นขาจ่ายสัญญาณ
  pinMode(in1, OUTPUT);

  // กำหนดโหมดของพิน in2 เป็นขาจ่ายสัญญาณ
  pinMode(in2, OUTPUT);

  // กำหนดโหมดของพิน enB เป็นขาจ่ายสัญญาณ
  pinMode(enB, OUTPUT);

  // กำหนดโหมดของพิน in3 เป็นขาจ่ายสัญญาณ
  pinMode(in3, OUTPUT);

  // กำหนดโหมดของพิน in4 เป็นขาจ่ายสัญญาณ
  pinMode(in4, OUTPUT);

  // กำหนดโหมดของพิน R_S เป็นขารับสัญญาณ
  pinMode(R_S, INPUT);

  // กำหนดโหมดของพิน L_S เป็นขารับสัญญาณ
  pinMode(L_S, INPUT);

  // ควบคุมความเร็วมอเตอร์
  analogWrite(enA, motorSpeed);
  analogWrite(enB, motorSpeed);

  // กำหนดให้ มอเตอร์ ทำงาน
  digitalWrite(enA, HIGH);
  digitalWrite(enB, HIGH);

  // หน่วงเวลา 1 วินาที (1000 มิลลิวินาที) แล้วเริ่มทำงาน ที่ฟังก์ชันต่อไป คือการเริ่ม start void loop
  delay(1000);
}

void loop()
{
  mainFunction();
  // ตรวจสอบว่าเซ็นเซอร์ทั้งสองตัวอ่านค่าเป็น 1 ซึ่งหมายความว่าทั้งสองตัวอยู่บนพื้นสีดำ
  if ((digitalRead(R_S) == 1) && (digitalRead(L_S) == 1))
  {
    // ถ้าเป็นจริง จะเรียกฟังก์ชัน Stop() ให้รถโรบอทหยุด ใน Stop() มีการเรียก backward()
    Stop();
    backward();
    delay(500);

    turnLeft();
    delay(500);

    mainFunction();
  // ตรวจสอบว่าเซ็นเซอร์ทั้งสองตัวอ่านค่าเป็น 1 ซึ่งหมายความว่าทั้งสองตัวอยู่บนพื้นสีดำ
    if ((digitalRead(R_S) == 1) && (digitalRead(L_S) == 1))
    {
      // ถ้าเป็นจริง จะเรียกฟังก์ชัน Stop() ให้รถโรบอทหยุด ใน Stop() มีการเรียก backward()
      Stop();
      backward();
      delay(500);

      turnLeft();
      delay(500);

      mainFunction();
      // ตรวจสอบว่าเซ็นเซอร์ทั้งสองตัวอ่านค่าเป็น 1 ซึ่งหมายความว่าทั้งสองตัวอยู่บนพื้นสีดำ
      if ((digitalRead(R_S) == 1) && (digitalRead(L_S) == 1))
      {
        // ถ้าเป็นจริง จะเรียกฟังก์ชัน Stop() ให้รถโรบอทหยุด ใน Stop() มีการเรียก backward()
        Stop();
        backward();
        delay(500);

        turnRight();
        delay(500);

        mainFunction();
        // ตรวจสอบว่าเซ็นเซอร์ทั้งสองตัวอ่านค่าเป็น 1 ซึ่งหมายความว่าทั้งสองตัวอยู่บนพื้นสีดำ
        if ((digitalRead(R_S) == 1) && (digitalRead(L_S) == 1))
        {
          // ถ้าเป็นจริง จะเรียกฟังก์ชัน Stop() ให้รถโรบอทหยุด ใน Stop() มีการเรียก backward()
          Stop();
          backward();
          delay(500);

          turnRight();
          delay(500);

           mainFunction();
          // ตรวจสอบว่าเซ็นเซอร์ทั้งสองตัวอ่านค่าเป็น 1 ซึ่งหมายความว่าทั้งสองตัวอยู่บนพื้นสีดำ
          if ((digitalRead(R_S) == 1) && (digitalRead(L_S) == 1))
          {
            // ถ้าเป็นจริง จะเรียกฟังก์ชัน Stop() ให้รถโรบอทหยุด ใน Stop() มีการเรียก backward()
            Stop();
            backward();
            delay(500);

            turnLeft();
            delay(500);


          }
        }
      }
    }
  }
}

void forward()
{ // forword
  digitalWrite(in1, HIGH); // Right Motor forword Pin
  digitalWrite(in2, LOW);  // Right Motor backword Pin
  digitalWrite(in3, LOW);  // Left Motor backword Pin
  digitalWrite(in4, HIGH); // Left Motor forword Pin
}

void turnRight()
{ // turnRight
  digitalWrite(in1, LOW);  // Right Motor forword Pin
  digitalWrite(in2, HIGH); // Right Motor backword Pin
  digitalWrite(in3, LOW);  // Left Motor backword Pin
  digitalWrite(in4, HIGH); // Left Motor forword Pin
}

void turnLeft()
{ // turnLeft
  digitalWrite(in1, HIGH); // Right Motor forword Pin
  digitalWrite(in2, LOW);  // Right Motor backword Pin
  digitalWrite(in3, HIGH); // Left Motor backword Pin
  digitalWrite(in4, LOW);  // Left Motor forword Pin
}

void Stop()
{ // stop
  digitalWrite(in1, LOW); // Right Motor forword Pin
  digitalWrite(in2, LOW); // Right Motor backword Pin
  digitalWrite(in3, LOW); // Left Motor backword Pin
  digitalWrite(in4, LOW); // Left Motor forword Pin
  // Stop for 1 second before moving backward
  delay(500);
}

void backward()
{
  digitalWrite(in1, LOW);  // Right Motor forword Pin
  digitalWrite(in2, HIGH); // Right Motor backword Pin
  digitalWrite(in3, HIGH); // Left Motor backword Pin
  digitalWrite(in4, LOW);  // Left Motor forword Pin
}

void mainFunction(){
  // ตรวจสอบว่าเซ็นเซอร์ทั้งสองตัวอ่านค่าเป็น 0 ซึ่งหมายความว่าทั้งสองตัวอยู่บนพื้นสีขาว
  if ((digitalRead(R_S) == 0) && (digitalRead(L_S) == 0))
  {
    // ถ้าเป็นจริง จะเรียกฟังก์ชัน forward() ให้รถโรบอทเคลื่อนที่ไปข้างหน้า
    forward();
  }

  // ตรวจสอบว่าเซ็นเซอร์ด้านขวาอ่านค่าเป็น 1 (พื้นดำ) และเซ็นเซอร์ด้านซ้ายอ่านค่าเป็น 0 (พื้นขาว)
  if ((digitalRead(R_S) == 1) && (digitalRead(L_S) == 0))
  {
    // ถ้าเป็นจริง จะเรียกฟังก์ชัน turnLeft() ให้รถโรบอทเลี้ยวซ้าย
    turnLeft();
  }
  // ตรวจสอบว่าเซ็นเซอร์ด้านขวาอ่านค่าเป็น 0 (พื้นขาว) และเซ็นเซอร์ด้านซ้ายอ่านค่าเป็น 1 (พื้นดำ)
  if ((digitalRead(R_S) == 0) && (digitalRead(L_S) == 1))
  {
    // ถ้าเป็นจริง จะเรียกฟังก์ชัน turnRight() ให้รถโรบอทเลี้ยวขวา
    turnRight();
  }
}
