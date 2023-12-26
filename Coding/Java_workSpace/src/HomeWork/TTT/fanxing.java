package src.HomeWork.TTT;

import java.util.LinkedList;

import javax.swing.text.html.HTMLDocument.Iterator;

public class fanxing {
    public static void main(String[] args) {
        // list<AAA> Student[]
        LinkedList<Student> list = new LinkedList<>();

        for (int i = 0; i < 1000; i++) {
            int[] math = { (int) (Math.random() * 100) };
            list.add(new Student(i + "go", math));
        }

        Iterator<Student> it = list.iterator();
        while (it.hasNext()) {
            Student s = it.next();
            System.out.println(it.next());
        }
    }
}
