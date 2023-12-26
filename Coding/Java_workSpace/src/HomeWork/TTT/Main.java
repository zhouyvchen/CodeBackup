package src.HomeWork.TTT;

import javax.swing.SwingUtilities;

public class Main {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            ImageUpdater imageUpdater = new ImageUpdater();
            Thread thread = new Thread(imageUpdater);
            thread.start();
            imageUpdater.setVisible(true);
        });
    }
}
