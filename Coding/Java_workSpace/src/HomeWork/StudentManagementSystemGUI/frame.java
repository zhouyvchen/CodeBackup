package src.HomeWork.StudentManagementSystemGUI;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;
import javax.swing.table.DefaultTableModel;

public class frame extends JFrame {
    frame() {
        // 用户名
        JTextField userName = new JTextField(10);
        // 密码
        JPasswordField userPassword = new JPasswordField(10);
        // 确认登录
        JButton loginButton = new JButton("确认登录");
        // 输入学生信息
        JButton enterInformatinButton = new JButton("输出学生信息");

        // 创建横向盒子1，包含用户名标签和用户名文本框
        Box hBox1 = Box.createHorizontalBox();
        hBox1.add(new JLabel("用户名："));
        hBox1.add(Box.createHorizontalStrut(10)); // 添加水平间距
        hBox1.add(userName);

        Box hBox2 = Box.createHorizontalBox();
        hBox2.add(new JLabel("密码："));
        hBox2.add(Box.createHorizontalStrut(10));
        hBox2.add(userPassword);

        Box hBox3 = Box.createHorizontalBox();
        hBox3.add(loginButton);

        Box hBox4 = Box.createVerticalBox();
        hBox4.add(enterInformatinButton);

        // 创建整体纵向盒子
        Box vBox1 = Box.createVerticalBox();
        vBox1.add(hBox1);
        vBox1.add(Box.createVerticalStrut(10));
        vBox1.add(hBox2);
        vBox1.add(Box.createHorizontalStrut(10));
        vBox1.add(hBox3);
        vBox1.add(hBox4);

        setTitle("学生管理系统");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        getContentPane().add(vBox1);
        setSize(700, 400);
        setVisible(true);

        loginButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String username = userName.getText();
                String password = new String(userPassword.getPassword());

                if (username.equals("admin") && password.equals("password")) {
                    studenTable();
                } else {
                    JOptionPane.showMessageDialog(frame.this, "登录失败，请检查用户名和密码！", "错误", JOptionPane.ERROR_MESSAGE);
                }
            }
        });

        enterInformatinButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                enterInformatin();
            }
        });
    }

    public void studenTable() {
        DefaultTableModel tableModel = new DefaultTableModel();
        tableModel.addColumn("学号");
        tableModel.addColumn("姓名");
        tableModel.addColumn("成绩");

        tableModel.addRow(new Object[] { "001", "张三", 85 });
        tableModel.addRow(new Object[] { "002", "李四", 92 });
        tableModel.addRow(new Object[] { "003", "王五", 78 });

        JTable table = new JTable(tableModel);
        JScrollPane scrollPane = new JScrollPane(table);
        Box vBox = Box.createVerticalBox();
        vBox.add(scrollPane);

        // 设置窗口内容面板
        setContentPane(vBox);

        // 刷新窗口
        revalidate();
    }

    public void enterInformatin() {
        // 输入学生姓名
        JTextField studentName = new JTextField();
        // 输入学生学号
        JTextField studentID = new JTextField();
        // 输入学生成绩
        JTextField studentScore = new JTextField();

        Box hBox1 = Box.createHorizontalBox();
        hBox1.add(new JLabel("学生姓名"));
        hBox1.add(Box.createHorizontalStrut(10));
        hBox1.add(studentName);

        Box hBox2 = Box.createHorizontalBox();
        hBox1.add(new JLabel("学号"));
        hBox1.add(Box.createHorizontalStrut(10));
        hBox1.add(studentID);

        Box hBox3 = Box.createHorizontalBox();
        hBox1.add(new JLabel("成绩"));
        hBox1.add(Box.createHorizontalStrut(10));
        hBox1.add(studentScore);
    }
}
