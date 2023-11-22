package src;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class LoginFrame extends JFrame {
    private JTextField usernameField;
    private JPasswordField passwordField;

    public LoginFrame() {
        // 设置窗口标题
        setTitle("登录");

        // 创建用户名标签和文本框
        JLabel usernameLabel = new JLabel("用户名:");
        usernameField = new JTextField(20);

        // 创建密码标签和密码框
        JLabel passwordLabel = new JLabel("密码:");
        passwordField = new JPasswordField(20);

        // 创建登录按钮
        JButton loginButton = new JButton("登录");
        loginButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String username = usernameField.getText();
                String password = new String(passwordField.getPassword());

                // 在这里编写验证用户名和密码的逻辑
                // 可以与预先定义的用户名和密码进行比较

                if (username.equals("admin") && password.equals("password")) {
                    JOptionPane.showMessageDialog(LoginFrame.this, "登录成功");
                } else {
                    JOptionPane.showMessageDialog(LoginFrame.this, "登录失败");
                }
            }
        });

        // 创建布局管理器
        setLayout(new GridBagLayout());
        GridBagConstraints constraints = new GridBagConstraints();

        // 添加用户名标签和文本框
        constraints.gridx = 0;
        constraints.gridy = 0;
        constraints.anchor = GridBagConstraints.LINE_END;
        constraints.insets = new Insets(5, 5, 5, 5);
        add(usernameLabel, constraints);

        constraints.gridx = 1;
        constraints.anchor = GridBagConstraints.LINE_START;
        add(usernameField, constraints);

        // 添加密码标签和密码框
        constraints.gridx = 0;
        constraints.gridy = 1;
        constraints.anchor = GridBagConstraints.LINE_END;
        add(passwordLabel, constraints);

        constraints.gridx = 1;
        constraints.anchor = GridBagConstraints.LINE_START;
        add(passwordField, constraints);

        // 添加登录按钮
        constraints.gridx = 1;
        constraints.gridy = 2;
        constraints.anchor = GridBagConstraints.CENTER;
        constraints.insets = new Insets(10, 0, 0, 0);
        add(loginButton, constraints);

        // 设置窗口大小、位置和关闭操作
        pack();
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                LoginFrame loginFrame = new LoginFrame();
                loginFrame.setVisible(true);
            }
        });
    }
}
