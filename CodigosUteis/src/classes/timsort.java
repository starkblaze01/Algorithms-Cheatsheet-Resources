package classes;

public class timsort{

  public static void timsort(int[] vet, int tamanho_vetor){

    int end_vetor=0;
    for(int begin_vetor=0 ; begin_vetor < tamanho_vetor ; begin_vetor = begin_vetor+32){
        if(begin_vetor+31<tamanho_vetor-1) end_vetor = begin_vetor+31;
        else end_vetor = tamanho_vetor-1;
      for(int aux=begin_vetor+1 ; aux <= end_vetor ; aux++){
        
        int temp=vet[aux];
        int pivot = aux - 1;

        while(  true  ){
          if(pivot >= begin_vetor){
            if(vet[pivot] > temp){
              vet[pivot+1] = vet[pivot];
              pivot = pivot-1;
            }
            else break;
          }
          else break;
        }
        vet[pivot+1] = temp;
      }
    }

      for(int size = 32 ; size < tamanho_vetor ; size = 2*size){
        for(int comeco_vetor = 0 ; comeco_vetor < tamanho_vetor; comeco_vetor += 2*size){
          int meio_vetor = comeco_vetor + size - 1;
          int fim_vetor;
          if ((comeco_vetor + 2*size - 1) < (tamanho_vetor - 1)) fim_vetor = comeco_vetor + 2*size - 1;
          else fim_vetor = tamanho_vetor-1;

          int tamanho_sub_vet_1 = meio_vetor - comeco_vetor;
          int tamanho_sub_vet_2 = fim_vetor - meio_vetor;
          int sub_vet_1[] = new int[tamanho_sub_vet_1];
          int sub_vet_2[] = new int[tamanho_sub_vet_2];

          for(int aux=0; aux < tamanho_sub_vet_1 ;aux++){
            sub_vet_1[aux]=vet[comeco_vetor + aux];
          }
          for(int aux=0; aux < tamanho_sub_vet_2 ;aux++){
            sub_vet_2[aux]=vet[meio_vetor + 1 + aux];
          }


          int i = 0 ;
          int j = 0 ;
          int k = comeco_vetor;

          while( i < tamanho_sub_vet_1   &&   j < tamanho_sub_vet_2 ){

            if(sub_vet_1[i] <= sub_vet_2[j]){

                vet[k] = sub_vet_1[i];
                i++;

            }

            else{
              vet[k] = sub_vet_2[j];
              j++;
            }
            k++;

          }

          while(i < tamanho_sub_vet_1){
            vet[k] = sub_vet_1[i];
            k++;
            i++;
          }

          while(j < tamanho_sub_vet_2){
            vet[k] = sub_vet_2[j];
            k++;
            j++;
          }


        }

      }


    return;
  }


}
