
# Robot Arm Project

## Giới thiệu
Dự án này xây dựng và điều khiển một robot arm sử dụng ba động cơ stepper (28BYJ-48) và một servo motor (MG996) trên nền tảng Arduino Mega 2560. Robot arm thực hiện một chuỗi các động tác như xoay cánh tay, cầm đồ lên và thả đồ xuống trong một chu trình lặp đi lặp lại. Dự án này có thể ứng dụng trong các bài toán tự động hóa, robot, và học tập.

## Các thành phần chính
- **3 động cơ stepper 28BYJ-48**: Điều khiển cánh tay robot xoay và di chuyển lên xuống.
- **1 servo MG996**: Điều khiển phần cầm đồ của robot.
- **Arduino Mega 2560**: Bộ điều khiển chính điều khiển các động cơ và thiết bị đầu vào/đầu ra.

## Cấu hình phần cứng
- **Động cơ stepper 28BYJ-48** được kết nối với các chân điều khiển của Arduino Mega (IN1, IN2, IN3, IN4 cho mỗi motor).
- **Servo MG996** được kết nối với chân A1 của Arduino Mega.

## Mô tả hành động
Trong phần `loop()` của mã nguồn, robot thực hiện các động tác sau:

1. **Cầm đồ**:
   - Đầu tiên, động cơ stepper 1 và 3 làm cho robot cuối xuống (bằng cách quay động cơ 1 và 3).
   - Tiếp theo, động cơ stepper 2 quay để cánh tay robot xoay vào vị trí hợp lý.
   - Servo quay đến vị trí 90 độ để mở phần cầm đồ của robot.
   
2. **Đưa đồ lên**:
   - Sau khi cầm đồ, robot ngẩng đầu lên, bằng cách quay ngược lại động cơ stepper 1 và 3 để đưa cánh tay trở lại vị trí thẳng đứng.
   - Động cơ stepper 2 quay ngược lại để đưa cánh tay về vị trí ban đầu.

3. **Thả đồ**:
   - Để thả đồ, robot tiếp tục hạ cánh tay xuống bằng động cơ stepper 1 và 3, sau đó mở servo để thả đồ ra.

## Chi tiết Code
Phần dưới đây mô tả cách các động cơ hoạt động trong chương trình:

### Các hàm điều khiển động cơ
- **step1_xuoi**: Quay động cơ 1 (phía trái) cùng chiều kim đồng hồ.
- **step1_nguoc**: Quay động cơ 1 (phía trái) ngược chiều kim đồng hồ.
- **step2_xuoi**: Quay động cơ 2 (phía dưới) cùng chiều kim đồng hồ (giúp xoay cánh tay trái/phải).
- **step2_nguoc**: Quay động cơ 2 (phía dưới) ngược chiều kim đồng hồ.
- **step3_xuoi**: Quay động cơ 3 (phía phải) cùng chiều kim đồng hồ.
- **step3_nguoc**: Quay động cơ 3 (phía phải) ngược chiều kim đồng hồ.

### Hàm điều khiển servo
- **servorun**: Điều khiển servo motor để mở và đóng phần cầm đồ của robot. Servo quay đến góc 90 độ (mở đồ) và sau đó quay về góc 0 độ (đóng đồ).

### Phần Loop
```cpp
void loop() {
  // làm cho robot cuối xuống để gắp đồ
  step1_xuoi();
  step3_xuoi();

  // xoay cánh tay
  step2_xuoi();

  // cầm đồ
  servorun();

  // làm cho robot ngẩn đầu lên
  step1_nguoc();
  step3_nguoc();

  // xoay về vị trí cũ
  step2_nguoc();

  // làm cho robot cuối xuống để thả đồ
  step1_xuoi();
  step3_xuoi();

  // thả đồ
  servorun();
}
```

### Các động tác chi tiết
1. **Cuối xuống để gắp đồ**: Robot sử dụng động cơ stepper 1 và 3 để làm cho cánh tay đi xuống.
2. **Xoay cánh tay**: Động cơ stepper 2 giúp quay cánh tay robot để tiếp cận đồ vật.
3. **Cầm đồ**: Servo quay đến góc 90 độ để mở phần cầm đồ, sau đó robot có thể nhấc đồ lên.
4. **Ngẩn đầu lên**: Robot sử dụng động cơ stepper 1 và 3 để đưa cánh tay lên.
5. **Quay về vị trí ban đầu**: Động cơ stepper 2 quay ngược lại để đưa cánh tay trở lại vị trí cũ.
6. **Cuối xuống để thả đồ**: Robot lại hạ cánh tay xuống và thả đồ bằng cách quay servo về góc 0 độ.

## Cài đặt và sử dụng

### Yêu cầu phần mềm:
- **Arduino IDE**: Cài đặt phần mềm Arduino IDE để lập trình Arduino Mega 2560.
- **Thư viện Servo**: Cài đặt thư viện Servo cho điều khiển servo motor.
- **Thư viện Stepper**: Cài đặt thư viện Stepper cho điều khiển các động cơ stepper.

### Hướng dẫn cài đặt:
1. Mở Arduino IDE và tải mã nguồn vào Arduino Mega 2560.
2. Kết nối các động cơ và servo vào các chân như sau:
   - Động cơ 1 (28BYJ-48): Chân 2, 3, 4, 5.
   - Động cơ 2 (28BYJ-48): Chân 6, 7, 8, 9.
   - Động cơ 3 (28BYJ-48): Chân 10, 11, 12, 13.
   - Servo: Chân A1.

3. Cài đặt thư viện `Stepper` và `Servo` từ Arduino Library Manager.

## Kết luận
Dự án này mô phỏng một robot arm có thể thực hiện các thao tác đơn giản như gắp đồ và thả đồ. Dự án giúp ứng dụng việc điều khiển động cơ stepper và servo trong các hệ thống robot và tự động hóa.

