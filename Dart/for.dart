enum PlanetType { terrestrial, gas, ice } //타입의 다른 인스턴스가 없도록 미리 정의된 값 또는 인스턴스 집합을 열거하는 수단
void main(){
    int total = 0;
    List<int> numbers = [1,2,3,4,5,6];

    for(int = 0; i < numbers.length; i++){
        total += numbers[i];
    }
    

    print(total);
}
//주석달기