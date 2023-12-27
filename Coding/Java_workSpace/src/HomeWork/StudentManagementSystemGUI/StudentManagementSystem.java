import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

class StudentManagementSystem extends JFrame {
    private ArrayList<Student> students;
    private JTextField nameTextField, ageTextField, gradeTextField;
    private JTextArea outputTextArea;

    public StudentManagementSystem() {
        students = new ArrayList<>();

        setTitle("学生管理系统");
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel inputPanel = new JPanel();
        inputPanel.setLayout(new GridLayout(4, 2));

        JLabel nameLabel = new JLabel("姓名:");
        nameTextField = new JTextField();
        JLabel ageLabel = new JLabel("年龄:");
        ageTextField = new JTextField();
        JLabel gradeLabel = new JLabel("年级:");
        gradeTextField = new JTextField();

        inputPanel.add(nameLabel);
        inputPanel.add(nameTextField);
        inputPanel.add(ageLabel);
        inputPanel.add(ageTextField);
        inputPanel.add(gradeLabel);
        inputPanel.add(gradeTextField);

        JButton addButton = new JButton("添加");
        addButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String name = nameTextField.getText();
                int age = Integer.parseInt(ageTextField.getText());
                String grade = gradeTextField.getText();

                Student student = new Student(name, age, grade);
                students.add(student);

                nameTextField.setText("");
                ageTextField.setText("");
                gradeTextField.setText("");

                updateOutputTextArea();
            }
        });

        JPanel buttonPanel = new JPanel();
        buttonPanel.add(addButton);

        outputTextArea = new JTextArea();
        JScrollPane scrollPane = new JScrollPane(outputTextArea);

        setLayout(new BorderLayout());
        add(inputPanel, BorderLayout.NORTH);
        add(buttonPanel, BorderLayout.CENTER);
        add(scrollPane, BorderLayout.SOUTH);
    }

    private void updateOutputTextArea() {
        StringBuilder sb = new StringBuilder();
        for (Student student : students) {
            sb.append("姓名: ").append(student.getName())
                    .append(", 年龄: ").append(student.getAge())
                    .append(", 年级: ").append(student.getGrade())
                    .append("\n");
        }
        outputTextArea.setText(sb.toString());
    }
}
