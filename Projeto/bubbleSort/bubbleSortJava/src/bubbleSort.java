import java.util.*;
import java.io.*;

public class bubbleSort {
    
    public static void BubbleSort(int[] arr) {
        int n = arr.length;
        boolean trocou;
        
        for (int i = 0; i < n - 1; i++) {
            trocou = false; 
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    trocou = true;
                }
            }
            if (!trocou) {
                break;
            }
        }
    }
    
    public static void main(String[] args) {
        int[] entradas = {100, 1000, 10000, 100000, 1000000};

        for (int j = 0; j < 4; j++) {
        
            String nomeArquivoDuracao = "Algoritmos/Projeto/bubbleSort/bubbleSortJava/src/" + (j + 1) + "-duracao.txt";

            try (BufferedWriter duracaoWriter = new BufferedWriter(new FileWriter(nomeArquivoDuracao, true))){
                for (int n : entradas) {
                    String nomeArquivoEntrada = "Algoritmos/Projeto/bubbleSort/bubbleSortJava/src/" + n + "-entradas-ivertidas.txt";

                    File file = new File(nomeArquivoEntrada);
                    if (!file.exists()) {
                        System.out.println("Erro ao abrir o arquivo " + nomeArquivoEntrada);
                        return;
                    }

                    List<Integer> numeros = new ArrayList<>();
                    try (Scanner scanner = new Scanner(file)) {
                        while (scanner.hasNextInt()) {
                            numeros.add(scanner.nextInt());
                        }
                    }

                    int[] arr = numeros.stream().mapToInt(i -> i).toArray();

                    long start = System.nanoTime();
                    BubbleSort(arr);
                    long end = System.nanoTime();

                    double tempo = (end - start) / 1e9;

                    duracaoWriter.write(String.format("Tempo de execucao: %.6f segundos para %d entradas\n", tempo, n));
                    System.out.printf("Tempo de execucao: %.6f segundos para %d entradas\n", tempo, n);

                }
            } catch (IOException e) {
                System.out.println("Erro ao escrever no arquivo de duração!");
            }
        }
    }
}
