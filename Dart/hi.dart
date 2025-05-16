import 'dart:ffi';        // FFI 라이브러리
import 'package:ffi/ffi.dart'; // 메모리 할당 도구

void main() {
  // int32 타입의 포인터를 할당
  Pointer<Int32> intPointer = malloc<Int32>();

  // 값 할당
  intPointer.value = 42;

  // 값 읽기
  print('Pointer value: ${intPointer.value}');

  // 메모리 해제
  malloc.free(intPointer);
}
