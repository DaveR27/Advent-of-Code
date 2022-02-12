package partOne;

import java.io.BufferedReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

class partOne {
    public static void main(String[] args) {
        int count = 0;

        try (BufferedReader br = Files.newBufferedReader(Paths.get("dayOne/puzzleInput.txt"))) {
            String previousLine = null;
            String currentLine = null;

            while ((currentLine = br.readLine()) != null) {
                if (previousLine != null && Integer.parseInt(previousLine) < Integer.parseInt(currentLine)) {
                    count++;
                }
                previousLine = currentLine;
            }
        } catch (IOException e) {
            System.err.format("IOException: %s%n", e);
        }
        System.out.println("The count is: " + count);
    }
}
