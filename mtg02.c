#include <stdio.h>

int main()
{
    int deck;                   //デッキ枚数(入力)
    int syote;                  //初手の枚数(入力)
    int keycade;                //必要なコンボの種類(入力)
    int combo[99];              //デッキ内に存在するコンボに必要なカード枚数(入力)
    int allcombo = 0;           //デッキ内に存在するコンボパーツの合計
    int i;                      //ループカウンタ
    int j;                      //ループカウンタ
    int temp[] = {1,0,0,0,0,0,0,0,0,0};  //計算領域(0は初手は何通りあるのか)(1からは対応したコンボに必要なカードを引かない場合は何通りあるのか)
    int temp1 = 1;              //計算領域(コンボに必要なカードを1枚も引かない場合は何通りあるのか)
    int temp2 = 0;              //計算領域(コンボが揃わない場合は何通りあるのか)
    double kakuritu;            //確率
    int judge;                  //プログラムの終了を判定するもの

    printf("初手で特定のコンボパーツが揃う確率計算プログラム\n");

    //入力項目

    do {
        printf("\n");                                   //デッキ枚数の入力
        printf("デッキ枚数 ==> ");
        scanf("%d", &deck);

        while (deck < 1) {                                  //エラーチェック
            printf("デッキ枚数は 1 以上の数で入力してください。\n");
            printf("デッキ枚数 ==> ");
            scanf("%d", &deck);
        }

        printf("初手の枚数 ==>");                         //初手枚数の入力
        scanf("%d", &syote);

        while (syote < 1){                                  //エラーチェック
            printf("初手の枚数は 1 以上の数で入力してください。\n");
            printf("初手の枚数 ==> ");
            scanf("%d", &syote);
        }

        printf("コンボに必要な枚数 ==> ");                      //コンボに必要な枚数を入力
        scanf("%d", &keycade);

        while (keycade < 1 || keycade > syote) {                //エラーチェック
            if (keycade < 1){
                printf(" 0 以上の数を入力してください。\n");
            } else {
                printf("コンボに必要な枚数が初手を超えています\n");
            }
            printf("コンボに必要な枚数 ==> ");
            scanf("%d", &keycade);
        }

        for (i = 1; i <= keycade; i++) {                    //各コンボパーツがデッキに何枚入っているのかを入力
            printf("コンボに必要なカード %d 種類目の枚数 ==> ", i);
            scanf("%d", &combo[i]);

            while (combo[i] < 1) {                      //エラーチェック
                printf(" 0 以上の数で入力してください。\n");
                printf("コンボに必要なカード %d 種類目の枚数 ==> ", i);
                scanf("%d", &combo[i]);
            }
            allcombo = allcombo + combo[i];                //コンボパーツの合計
        }
        //入力終わり

        //ここから計算の処理がスタート

        for (i = 0; i < syote; i++) {                  
            temp[0] = temp[0] * (deck - i);                //初手が全何通りあるのか計算
            temp1 = temp1 * ((deck - allcombo) - i);       //コンボパーツを１枚も引かない場合は何通りあるのかを計算
        }
        

        temp2 = temp1;
        for (i = 1; i <= keycade; i++) {                     //各コンボパーツを引かない場合が何通りあるのかを計算
            temp[i] = 1;           
            for (j = 0; j < syote; j++) {                   //tempにそれぞれ入れる
                temp[i] = temp[i] * (deck - combo[i] - j);
            }
            temp2 = temp2 + temp[i] - temp1;
        }

        kakuritu = (double)(temp[0] - temp2) / temp[0] * 100;

        printf("\n");
        printf("デッキ枚数 %d 枚、初手 % d でコンボパーツ %d 種類が揃う確率は...\n", deck, syote, keycade);
        printf("%.2f %%です！\n", kakuritu);

        printf("プログラムを続けるには 1 を、終了するには 1 以外を入力してください\n");
        scanf("%d", &judge);

    } while (judge == 1);

    return 0;
}