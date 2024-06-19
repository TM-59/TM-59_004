#include <gtk/gtk.h>
#include <plplot.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_POINTS 1000

double x[MAX_POINTS];
double y[MAX_POINTS];
int num_points = 0;
char xlabel[100], ylabel[100]; // ラベル名を格納するための変数

void load_csv_data(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("File opening failed");
        return;
    }

    // ラベル名の読み込み
    if (fscanf(file, "%99[^,],%99[^\n]\n", xlabel, ylabel) != 2) {
        perror("Failed to read labels");
        fclose(file);
        return;
    }

    printf("num_points: %d\n", num_points);
    printf("MAX_POINTS: %d\n", MAX_POINTS);
    
    while (fscanf(file, "%lf,%lf", &x[num_points], &y[num_points]) == 2 && num_points < MAX_POINTS) {
        num_points++;
    }

    fclose(file);
}

// PLplot の描画を行う関数
void plot_data() {
    //plinit();
    plenv(0.0, 13.0, 125000000.0, 127000000.0, 0, 0); // 軸の範囲を設定
    pllab(xlabel, ylabel, ""); // 軸のラベルを設定
    //plcol0(1); // 色を設定
    plline(num_points, x, y); // データのプロット
    plend();
}

// GTK+ の描画エリアの "draw" イベントに対するコールバック関数
static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data) {
    plot_data(); // PLplot を使用してデータをプロット
    return FALSE;
}

// アプリケーションの終了時に plend を呼び出すためのコールバック関数
void on_app_destroy(GtkWidget *widget, gpointer data) {
    //plend(); // PLplot の終了処理
    gtk_main_quit();
}

int main(int argc, char *argv[]) {
    printf("Hello, world!\n");

    // CSVデータの読み込み
    load_csv_data("sample_data/sample.csv");

    // PLplot の初期化をここで行う
    plsdev("xcairo"); // 外部 Cairo デバイスドライバを使用
    plinit();

    // PLplot を使用してデータをプロット
    plot_data();

    // PLplot の終了処理
    plend();

    return 0;
}

