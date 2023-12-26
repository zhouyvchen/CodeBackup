package src.HomeWork.TTT;

import javax.swing.*;
import java.awt.*;
import java.util.Random;

public class ImageUpdater extends JFrame implements Runnable {
    private JLabel imageLabel;
    private ImageIcon imageIcon;
    private volatile boolean running;

    public ImageUpdater() {
        super("Image Updater");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(1000, 1000);
        setLocationRelativeTo(null);

        imageLabel = new JLabel();
        add(imageLabel);

        imageIcon = new ImageIcon(
                "src\\HomeWork\\TTT\\assets\\image\\1.png");
        imageLabel.setIcon(imageIcon);

        running = true;
    }

    public void stop() {
        running = false;
    }

    @Override
    public void run() {
        while (running) {
            updateImage();

            try {
                Thread.sleep(3000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    private void updateImage() {
        // 生成一个随机的图片路径
        Random random = new Random();
        int imageIndex = random.nextInt(5) + 1;
        String imagePath = "src\\HomeWork\\TTT\\assets\\image\\" + imageIndex + ".jpg";

        // 加载新的图片
        ImageIcon newImageIcon = new ImageIcon(imagePath);
        imageLabel.setIcon(newImageIcon);
        imageIcon = newImageIcon;

        // 重新绘制窗口
        revalidate();
        repaint();
    }
}
