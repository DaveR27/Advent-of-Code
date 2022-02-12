package partTwo;

import java.io.BufferedReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.LinkedList;

class partTwo {
    public static void main(String[] args) {
        int count = 0;

        try (BufferedReader br = Files.newBufferedReader(Paths.get("dayOne/puzzleInput.txt"))) {
            LinkedList<Integer> frames = new LinkedList<>();
            String currentLine = null;

            while ((currentLine = br.readLine()) != null) {
                frames.add(Integer.parseInt(currentLine));
                if (frames.size() == 4) {
                    int frameOneSum = frames.get(0) + frames.get(1) + frames.get(2);
                    int frameTwoSum = frames.get(1) + frames.get(2) + frames.get(3);
                    if (frameOneSum < frameTwoSum) {
                        count++;
                    }
                    frames.remove();
                }
            }
        } catch (IOException e) {
            System.err.format("IOException: %s%n", e);
        }
        System.out.println("The count is: " + count);
    }
}
