import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.*;
import java.util.StringTokenizer;
import java.util.concurrent.Callable;
import java.util.concurrent.CompletionService;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorCompletionService;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class CompletionServiceTask implements Callable<Boolean> {
    private final int c;
    private final int d;
    private final boolean isBracket;
    private URL url;

    private static final int TOTAL_FILE_COUNT = 6000;
    private static final int THREAD_COUNT = 60;
    private static Integer count = 0;
    private static Integer readFileCount = 0;
    private static Double sum = 0.0;
    private static Double max = Double.MIN_VALUE;
    private static int maxC = 0;
    private static int maxD = 0;
    private static int maxRow = 0;
    private static int maxColumn = 0;
    private static Double min = Double.MAX_VALUE;
    private static int minC = 0;
    private static int minD = 0;
    private static int minRow = 0;
    private static int minColumn = 0;

    private static ExecutorService threadPool = Executors.newFixedThreadPool(THREAD_COUNT);
    private static CompletionService<Boolean> completionService = new ExecutorCompletionService<>(threadPool);

    public CompletionServiceTask(int c, int d, boolean isBracket) {
        this.c = c;
        this.d = d;
        this.isBracket = isBracket;
    }

    public static void main(String args[]) throws IOException, InterruptedException, ExecutionException {
        long sum = 0;
        int n = 5;

        for (int i = 0; i < n; i++) {
            System.out.printf("Attempt %d out of %d%s", i + 1, n, System.lineSeparator());
            init();
            long st = System.currentTimeMillis();
            shootFuture();
            long end = System.currentTimeMillis();
            sum += (end - st);
        }
        threadPool.shutdown();
        System.out.println("Average: " + sum / n);
    }

    public Boolean call() throws IOException, InterruptedException {
        try {
            if (isBracket) {
                url = new URL(String.format("random_URL"));
            } else {
                url = new URL(String.format("random_URL"));
            }

            InputStream in = url.openStream();
            BufferedReader bfr = new BufferedReader(new InputStreamReader(in));
            String line;
            String numStr;
            int row = 1;
            while ((line = bfr.readLine()) != null) {
                int col = 1;
                StringTokenizer tokenizer = new StringTokenizer(line);
                while (tokenizer.hasMoreTokens()) {
                    numStr = tokenizer.nextToken();
                    calculate(Double.parseDouble(numStr), c, d, row, col);
                    col++;
                }
                row++;
            }
            synchronized (readFileCount) {
                readFileCount++;
            }
            return true;
        } catch (SocketException | SocketTimeoutException e) {
            completionService.submit(new CompletionServiceTask(c, d, isBracket));
            return false;
        } catch (FileNotFoundException e) {
            throw e;
        } catch (Exception e) {
            e.printStackTrace();
            throw e;
        }
    }

    private static synchronized void calculate(final double num, final int c, final int d, final int row,
            final int col) {
        count++;
        sum += num;
        if (num > max) {
            max = num;
            maxC = c;
            maxD = d;
            maxRow = row;
            maxColumn = col;
            return;
        }

        if (num < min) {
            min = num;
            minC = c;
            minD = d;
            minRow = row;
            minColumn = col;
        }
    }

    public static void shootFuture() throws InterruptedException {
        for (int c = 1; c <= 50; c++) {
            for (int d = 1; d <= 60; d++) {
                completionService.submit(new CompletionServiceTask(c, d, true));
                completionService.submit(new CompletionServiceTask(c, d, false));
            }
        }

        int received = 0;

        while (received < TOTAL_FILE_COUNT) {
            Future<Boolean> resultFuture = completionService.take();
            try {
                Boolean ret = resultFuture.get();
                if (ret) {
                    received++;
                }
            } catch (Exception e) {
                received++;
            }
        }

        System.out.printf("c: %d    d: %d   row: %d     col: %d     max: %f%s", maxC, maxD, maxRow, maxColumn, max,
                System.lineSeparator());
        System.out.printf("c: %d    d: %d   row: %d     col: %d     min: %f%s", minC, minD, minRow, minColumn, min,
                System.lineSeparator());
        System.out.printf("avg: %.3f%s", sum / count, System.lineSeparator());
        System.out.printf("number of missing file: %d%s%s", 3000 - readFileCount, System.lineSeparator(),
                System.lineSeparator());
    }

    private static void init() {
        count = 0;
        readFileCount = 0;
        sum = 0.0;
        max = Double.MIN_VALUE;
        maxC = 0;
        maxD = 0;
        maxRow = 0;
        maxColumn = 0;
        min = Double.MAX_VALUE;
        minC = 0;
        minD = 0;
        minRow = 0;
        minColumn = 0;
    }
}