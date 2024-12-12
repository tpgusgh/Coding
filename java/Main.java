class Bank {
    private String BankNumber; // 계좌 번호
    private String name;       // 이름
    protected int balance;     // 잔액

    public Bank(String BankNumber, String name, int balance) {
        this.BankNumber = BankNumber;
        this.name = name;
        this.balance = balance;
    }

    // 잔액 입금
    public void gmoney(int money) {
        if (money <= 0) {
            System.out.println("입금 금액은 0보다 커야 합니다.");
            return;
        }
        balance += money - (money / 100); // 1% 수수료
    }

    // 잔액 출금
    public void bmoney(int money, String requesterName) {
        if (!name.equals(requesterName)) {
            System.out.println("출금 실패: 예금주가 아닙니다.");
            return;
        }
        if (money > balance) {
            System.out.println("출금 실패: 잔액이 부족합니다.");
            return;
        }
        balance -= money + (money / 100); // 1% 수수료 포함
    }

    // 계좌 번호
    public String getBankNumber() {
        return BankNumber;
    }

    // 예금주 이름
    public String getName() {
        return name;
    }

    // 잔액
    public int getBalance(String retryName) {
        if (!name.equals(retryName)) {
            System.out.println("잔액 조회 실패: 예금주가 아닙니다.");
        }
        return balance;
    }

    // 계좌 정보
    public String sent() {
        return "계좌 번호: " + BankNumber + ", 예금주: " + name + ", 잔액: " + balance + "원";
    }
}


public class Main {
    public static void main(String[] args) {

        Bank[] account = new Bank[10]; //계좌 총 10개만들 수 있는 배열생성
        int accountlist = 0; // 계좌갯수

        account[accountlist++] = new Bank("123-456", "양효준", 100000);
        account[accountlist++] = new Bank("789-101", "김현호", 10000000);

        //입금
        for (int i = 0; i < accountlist; i++) {
            if(account[i].getBankNumber().equals("123-456")) {
                account[i].gmoney(5000);
                System.out.println(account[i].sent());
            }
        }

        //출금
        for (int i = 0; i < accountlist; i++) {
            if(account[i].getBankNumber().equals("789-101")) {
                account[i].bmoney(3000,"김현호");
                System.out.println(account[i].sent());

            }
        }


        //조회
        for(int i = 0; i < accountlist; i++) {
            if(account[i].getBankNumber().equals("123-456")) {
                System.out.println(account[i].sent());

            }
        }

        //조회
        for(int i = 0; i < accountlist; i++) {
            System.out.println(account[i].sent());
        }

        //잘못된 출금
        for (int i = 0; i < accountlist; i++) {
            if(account[i].getBankNumber().equals("789-101")) {
                account[i].bmoney(3000,"양효준");
                System.out.println(account[i].sent());

            }
        }
        account[accountlist++] = new Bank("789-101", "조예설", 10000000);



        //음수입금
        for (int i = 0; i < accountlist; i++) {
            if(account[i].getBankNumber().equals("123-456")) {
                account[i].gmoney(-500);
                System.out.println(account[i].sent());
            }
        }
        // TODO-1 은행 객체 생성
        // 은행 객체를 생성하여 계좌 관리 기능을 수행할 수 있도록 합니다.

        // TODO-2 계좌 생성
        // 일반 계좌와 특별 계좌를 생성합니다.
        // 일반 계좌 예: 계좌 번호 "123-456", 예금주 "홍길동", 잔액 10000원
        // 특별 계좌 예: 계좌 번호 "789-101", 예금주 "김철수", 잔액 5000원, 수수료 100원
        // 계좌 생성 시 중복된 계좌 번호가 없도록 체크해야 합니다.

        // TODO-3 계좌 예금
        // 특정 계좌에 입금 처리를 합니다.
        // 예금 시, 입금 금액이 유효한지 확인해야 합니다. (예: 음수 금액 입금 불가)

        // TODO-4 계좌 출금
        // 특정 계좌에서 출금을 수행합니다. 잔액이 부족할 경우 출금 불가 메시지를 출력합니다.
        // 출금 시 수수료가 적용됩니다. 예: 1% 수수료 적용
        // 출금 시, 예금주가 맞는지 확인하고 잔액이 충분한지 확인해야 합니다.

        // TODO-5 계좌 잔액 조회
        // 계좌의 예금주 본인만 잔액을 조회할 수 있도록 확인합니다.
        // 본인 계좌가 아닌 경우 접근 불가 메시지를 출력해야 합니다.

        // TODO-6 은행 전체 계좌 목록 조회
        // 은행에 등록된 모든 계좌의 목록을 출력합니다.
        // 출력 시, 계좌 번호, 예금주 이름, 잔액을 포함하여 출력해야 합니다.

        // TODO-7 잘못된 접근 처리
        // 예금주가 아닌 사용자가 특정 계좌에 대해 출금이나 잔액 조회를 시도할 경우 접근 불가 메시지를 출력합니다.
        // 예금주와의 이름이 다를 경우, 접근을 차단하도록 처리해야 합니다.

        // TODO-8 계좌 번호 고유성 확인
        // 계좌 생성 시 중복된 계좌 번호가 없도록 체크하고, 중복된 계좌 번호가 있을 경우 예외를 발생시킵니다.

        // TODO-9 입금 금액 유효성 체크
        // 입금 금액이 음수인 경우 예외를 발생시키고, 양수인 경우만 입금이 가능하도록 합니다.
    }
}