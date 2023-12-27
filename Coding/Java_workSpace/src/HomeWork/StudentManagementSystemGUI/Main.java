package src.HomeWork.StudentManagementSystemGUI;

import javax.swing.SwingUtilities;

public class Main {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                StudentManagementSystem system = new StudentManagementSystem();
                system.setVisible(true);
            }
        });
    }
}