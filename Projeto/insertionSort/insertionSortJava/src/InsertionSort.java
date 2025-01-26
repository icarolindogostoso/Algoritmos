import java.util.*;
import java.io.*;

public class InsertionSort {
    
    public static void insertionSort(int[] arr) {
        for (int i = 1; i < arr.length; i++) {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }
    
    public static void main(String[] args) {
        int[] entradas = {100, 1000, 10000, 100000, 1000000};

        for (int j = 0; j < 4; j++) {
        
            String nomeArquivoDuracao = "Algoritmos/Projeto/insertionSort/insertionSortJava/src/" + (j + 1) + "-duracao.txt";

            try (BufferedWriter duracaoWriter = new BufferedWriter(new FileWriter(nomeArquivoDuracao, true))){
                for (int n : entradas) {
                    String nomeArquivoEntrada = "Algoritmos/Projeto/insertionSort/insertionSortJava/src/" + n + "-entradas-ivertidas.txt";

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
                    insertionSort(arr);
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
