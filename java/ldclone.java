package hello;


import java.util.*;

import java.util.*;

class Circle implements Cloneable {
    Point2 p;  // 원점
    double r; // 반지름

    Circle(Point2 p, double r) {
        this.p = p;
        this.r = r;
    }
    public Circle shallowCopy() { // 얕은 복사
        Object obj = null;
        try {
            obj = super.clone();
        } catch (CloneNotSupportedException e) {}
        return (Circle)obj;
    }
    public Circle deepCopy(){
        Object obj = null;
        try{
            obj = super.clone();
            Point2 p = new Point2(this.p.x, this.p.y);
            ((Circle)obj).p = p;
        } catch (CloneNotSupportedException e) {}
        return (Circle) obj;
    }
    public String toString() {
        return "[p=" + p + ", r="+ r +"]";
    }
}

class Point2 {
    int x;
    int y;

    Point2(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public String toString() {
        return "("+x +", "+y+")";
    }
}

class pjh {
    public static void main(String[] args) {
        Circle c1 = new Circle(new Point2(1, 1), 2.0);
        Circle c2 = c1.shallowCopy();
        Circle c3 = c1.deepCopy();

        System.out.println("c1="+c1);
        System.out.println("c2="+c2);
        System.out.println("c3="+c3);
        c1.p.x = 9;
        c1.p.y = 9;
        System.out.println("= c1의 변경 후 =");
        System.out.println("c1="+c1);
        System.out.println("c2="+c2);
        System.out.println("c3="+c3);
    }
}