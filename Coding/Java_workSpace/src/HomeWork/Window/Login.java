package src.HomeWork.Window;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Login extends JFrame {
    Login() {
        setTitle("学生管理系统");
        setSize(400, 600);
        setLocation(400, 400);
        setLayout(new FlowLayout());

        JLabel userL = new JLabel("用户名");
        add(userL);
        JTextField userT = new JTextField();
        add(userT);
        userT.setColumns(11);

        JLabel pwL = new JLabel("密码");
        add(pwL);
        JTextField pwT = new JTextField();
        add(pwT);
        pwT.setColumns(11);

        JButton submitB = new JButton("确定");
        add(submitB);

        submitB.addActionListener(new SbBListener());

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    class SbBListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            JOptionPane.showMessageDialog(Login.this, "登录成功");
        }
    }
}
