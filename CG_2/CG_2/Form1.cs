using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace CG_2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        Graphics G; // Объект графики
        string[] X;
        string[] Y;
        int GetK() {
            X = new string[10]{
                   textBox_X1.Text,
                   textBox_X2.Text,
                   textBox_X3.Text,
                   textBox_X4.Text,
                   textBox_X5.Text,
                   textBox_X6.Text,
                   textBox_X7.Text,
                   textBox_X8.Text,
                   textBox_X9.Text,
                   textBox_X10.Text,
               };
            Y = new string[] {
                   textBox_Y1.Text,
                   textBox_Y2.Text,
                   textBox_Y3.Text,
                   textBox_Y4.Text,
                   textBox_Y5.Text,
                   textBox_Y6.Text,
                   textBox_Y7.Text,
                   textBox_Y8.Text,
                   textBox_Y9.Text,
                   textBox_Y10.Text,
               };
            int k = 0;
            for (int j = 0; j < X.Length; j++)
            {
                if (X[j] != "" && Y[j] != "")
                    k++;
            }
            int ii = 0;
            while (ii < X.Length)
            {
                if (X[ii] == "" && Y[ii] == "")
                {
                    for (int j = ii; j < X.Length - 1; j++)
                    {
                        X[j] = X[j + 1];
                    }
                }
                ii++;
            }

            return k;
        }

        PointF[] Arr;
        void GetArr()
        {
            int k = GetK();
            Arr = new PointF[k];
            for (int i = 0; i < k; i++)
                if (X[i] != "" && Y[i] != "")
                {
                    Arr[i].X = int.Parse(X[i]);
                    Arr[i].Y = int.Parse(Y[i]);
                }
        }

        void DzerkY()
        {
            for (int i = 0; i < Arr.Length; i++)
            {
                Arr[i].X =600 - Arr[i].X;
            }
        }

        void DzerkX()
        {
            for (int i = 0; i < Arr.Length; i++)
            {
                Arr[i].Y =450 - Arr[i].Y;
            }
        }

        void MovArr(int x1, int y1)
        {
            for (int i = 0; i < Arr.Length; i++)
            {
                Arr[i].X += x1;
                Arr[i].Y += y1;
            }
        }

        int Fuctorial(int n) // Функция вычисления факториала
        {
            int res = 1;
            for (int i = 1; i <= n; i++)
                res *= i;
            return res;
        }
        float polinom(int i, int n, float t)// Функция вычисления полинома Бернштейна
        {
            return (Fuctorial(n) / (Fuctorial(i) * Fuctorial(n - i))) * (float)Math.Pow(t, i) * (float)Math.Pow(1 - t, n - i);
        }
        void Draw()// Функция рисования кривой
        {
            int j = 0;
            float step = 0.01f;// Возьмем шаг 0.01 для большей точности

            PointF[] result = new PointF[101];//Конечный массив точек кривой
            for (float t = 0; t < 1; t += step)
            {
                float ytmp = 0;
                float xtmp = 0;
                for (int i = 0; i < Arr.Length; i++)
                { // проходим по каждой точке
                    float b = polinom(i, Arr.Length - 1, t); // вычисляем наш полином Берштейна
                    xtmp += Arr[i].X * b; // записываем и прибавляем результат
                    ytmp += Arr[i].Y * b;
                }
                result[j] = new PointF(xtmp, ytmp);
                j++;

            }
            G.DrawLines(new Pen(Color.Red), result);// Рисуем полученную кривую Безье
        }
       
        private void Start_Click(object sender, EventArgs e)
        {
            GetArr();
            DrawAgain();
        }

        private Image originalImage;

        private void Form1_Load(object sender, EventArgs e)
        {
            originalImage = pictureBox1.Image;
        }
        private void button1_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = originalImage;
        }

        float anglelft = 0;
        float anglerght = 0;
        private void BtnLeft_Click(object sender, EventArgs e)
        {
            G = Graphics.FromHwnd(pictureBox1.Handle);
            G.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.AntiAlias;
            anglelft += float.Parse(textBox1.Text);
            G.TranslateTransform(float.Parse(textBoxCenterX.Text), float.Parse(textBoxCenterY.Text));
            G.RotateTransform(anglelft);
            Draw();
            G.DrawLines(new Pen(Color.Gray), Arr);
        }
        private void BtnRight_Click(object sender, EventArgs e)
        {
            G = Graphics.FromHwnd(pictureBox1.Handle);
            G.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.AntiAlias;
            anglerght += float.Parse(textBox1.Text);
            G.TranslateTransform(float.Parse(textBoxCenterX.Text), float.Parse(textBoxCenterY.Text));
            G.RotateTransform(-anglerght);
            Draw();
            G.DrawLines(new Pen(Color.Gray), Arr);
            anglerght += float.Parse(textBox1.Text);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            textBox_X1.Text = ""; textBox_X6.Text = "";
            textBox_X2.Text = ""; textBox_X7.Text = "";
            textBox_X3.Text = ""; textBox_X8.Text = "";
            textBox_X4.Text = ""; textBox_X9.Text = "";
            textBox_X5.Text = ""; textBox_X10.Text = "";
            textBox_Y1.Text = ""; textBox_Y6.Text = "";
            textBox_Y2.Text = ""; textBox_Y7.Text = "";
            textBox_Y3.Text = ""; textBox_Y8.Text = "";
            textBox_Y4.Text = ""; textBox_X9.Text = "";
            textBox_Y5.Text = ""; textBox_Y10.Text = "";
        }

        private void DrawAgain()
        {
            G = Graphics.FromHwnd(pictureBox1.Handle);
            G.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.AntiAlias;
            Draw();
            G.DrawLines(new Pen(Color.Gray), Arr);
        }

        private void btn_Up_Click(object sender, EventArgs e)
        {
            MovArr(0, -int.Parse(textBox2.Text));
            DrawAgain();
        }

        private void btn_Down_Click(object sender, EventArgs e)
        {
            MovArr(0, int.Parse(textBox2.Text));
            DrawAgain();
        }

        private void btn_Left_Click(object sender, EventArgs e)
        {
            MovArr(-int.Parse(textBox2.Text), 0);
            DrawAgain();
        }

        private void btn_Right_Click(object sender, EventArgs e)
        {
            //pictureBox1.Image = originalImage;
            // System.Threading.Thread.Sleep(100);
            MovArr(int.Parse(textBox2.Text), 0);
            DrawAgain();
        }

        float zoomdx = 100, zoomdy = 100;
        private void btnZoomPl_Click(object sender, EventArgs e)
        {
            G = Graphics.FromHwnd(pictureBox1.Handle);
            G.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.AntiAlias;
            zoomdx += float.Parse(textBoxZoomDx.Text);
            zoomdy += float.Parse(textBoxZoomDy.Text);
            G.TranslateTransform(float.Parse(textBoxCenterX.Text), float.Parse(textBoxCenterY.Text));
            G.ScaleTransform(zoomdx / 100F, zoomdy / 100F);
            Draw();
            G.DrawLines(new Pen(Color.Gray), Arr);
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            G = Graphics.FromHwnd(pictureBox1.Handle);
            G.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.AntiAlias;
        //    G.TranslateTransform(float.Parse(textBoxCenterX.Text), float.Parse(textBoxCenterY.Text));
            //G.RotateTransform(90F);
            DzerkY();
            Draw();
            G.DrawLines(new Pen(Color.Gray), Arr);
            System.Threading.Thread.Sleep(2000);
            DzerkX();
            Draw();
            G.DrawLines(new Pen(Color.Gray), Arr);
        }

        private void btnZoomMin_Click(object sender, EventArgs e)
        {
            G = Graphics.FromHwnd(pictureBox1.Handle);
            G.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.AntiAlias;
            zoomdx -= float.Parse(textBoxZoomDx.Text);
            zoomdy -= float.Parse(textBoxZoomDy.Text);
            if (zoomdx <= 0) zoomdx = float.Parse(textBoxZoomDx.Text);
            if (zoomdy <= 0) zoomdy = float.Parse(textBoxZoomDy.Text);
            G.TranslateTransform(float.Parse(textBoxCenterX.Text), float.Parse(textBoxCenterY.Text));
            G.ScaleTransform(zoomdx / 100F, zoomdy / 100F);
            Draw();
            G.DrawLines(new Pen(Color.Gray), Arr);
        }
    }
}