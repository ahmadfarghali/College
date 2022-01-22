using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Mini_Game
{
    public class rec
    {
        public int x, y, w, h;
        public int n;
        public bool flag;
        public Color color;
    }
    public partial class Form1 : Form
    {
        rec[,] recs = new rec[4, 4];
        int[] nums = new int[11] { 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048 };

        Timer t = new Timer();
        int cot_tick = 0;
        Bitmap off;

        Random rr = new Random();
        int score;
        bool lf = false, rf = false, uf = false, df = false;
        bool last_num = false, game_over = false;

        public Form1()
        {
            //this.WindowState = FormWindowState.Maximized;
            this.Width = 660;
            this.Height = 472;
            this.Paint += Form1_Paint;
            this.Load += Form1_Load;
            this.KeyDown += Form1_KeyDown;

            t.Tick += T_Tick;
            t.Interval = 16;
            t.Start();
        }

        private void T_Tick(object sender, EventArgs e)
        {
            if (game_win_check()) last_num = true;
            if (!game_checkv()) game_over = true;

            cot_tick++;
            DrawDubb(this.CreateGraphics());
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            DrawDubb(e.Graphics);
        }

        void Form1_Load(object sender, EventArgs e)
        {
            off = new Bitmap(this.ClientSize.Width, this.ClientSize.Height);
            CreateActors();
        }

        void DrawDubb(Graphics g)
        {
            Graphics g2 = Graphics.FromImage(off);
            DrawScene(g2);
            g.DrawImage(off, 0, 0);
        }

        void DrawScene(Graphics g2)
        {
            g2.Clear(Color.Black);
            for (int i = 0; i < 4; i++)
            {
                for (int k = 0; k < 4; k++)
                {
                    rec r = recs[i, k];
                    r.color = get_color(r.n);
                    Brush b = new SolidBrush(r.color);
                    g2.FillRectangle(b, r.x, r.y, r.w, r.h);

                    //Font Fn = new Font("System", 10);
                    //g2.DrawString(i+" "+k, Fn, Brushes.Black, r.x + 20, r.y + 10);
                    if (r.n != 0)
                    {
                        Font Fn = new Font("Sytem", 20);
                        g2.DrawString(r.n.ToString(), Fn, Brushes.Black, r.x + 10, r.y + 10);
                    }
                }
            }
            score = get_score();
            Font f2 = new Font("Arial Narrow", 20);
            g2.DrawString("Your Score is: " + score.ToString(), f2, Brushes.SkyBlue, 440, 20);

            if (last_num == true)
            {
                g2.DrawString("You Win", f2, Brushes.Green, 440, 50);
            }
            if (game_over == true)
            {
                g2.DrawString("Game Over", f2, Brushes.Red, 440, 100);
            }
        }

        void CreateActors()
        {
            //first
            rec r;
            int rx = 0, ry = 0;
            int rw = 100, rh = 100;
            for (int i = 0; i < 4; i++)
            {
                rx = 0;
                for (int k = 0; k < 4; k++)
                {
                    recs[i, k] = new rec();
                    r = recs[i, k];
                    r.n = 0;
                    r.x = rx; r.y = ry;
                    r.w = rw; r.h = rh;
                    r.color = get_color(r.n);
                    r.flag = true;
                    rx += rw + 10;
                }
                ry += rh + 10;
            }
            //first random
            int rrx, rry;
            for (int i = 0; i < 2; i++)
            {
                rrx = rr.Next(0, 3);
                rry = rr.Next(0, 3);
                while (recs[rrx, rry].n != 0)
                {
                    rrx = rr.Next(0, 3);
                    rry = rr.Next(0, 3);
                }
                recs[rrx, rry].n = 2;
            }
            //recs[0, 0].n = 32;
            //recs[0, 1].n = 32;
            //recs[0, 2].n = 64;
            //recs[0, 3].n = 128;
        }
        Color get_color(int n)
        {
            if (n == 2)
                return Color.Beige;
            if (n == 4)
                return Color.Bisque;
            if (n == 8)
                return Color.BurlyWood;
            if (n == 16)
                return Color.Chocolate;
            if (n == 32)
                return Color.Crimson;
            if (n == 64)
                return Color.DarkRed;
            if (n == 128)
                return Color.LightYellow;
            if (n == 256)
                return Color.LightYellow;
            if (n == 512)
                return Color.GreenYellow;
            if (n == 1024)
                return Color.LightGoldenrodYellow;
            if (n == 2048)
                return Color.Indigo;
            return Color.White;
        }

        int get_score()
        {
            rec r;
            int tot = 0;
            for (int i = 0; i < 4; i++)
            {
                for (int k = 0; k < 4; k++)
                {
                    r = recs[i, k];
                    tot += r.n;
                }
            }
            tot -= 4;
            return tot;
        }
        int get_max()
        {
            rec r;
            int max = 0;
            for (int i = 0; i < 4; i++)
            {
                for (int k = 0; k < 4; k++)
                {
                    r = recs[i, k];
                    if (r.n > max) max = r.n;
                }
            }
            return max;
        }
        int get_num()
        {
            rec r;
            int num = 0;
            for (int i = 0; i < 4; i++)
            {
                for (int k = 0; k < 4; k++)
                {
                    r = recs[i, k];
                    if (r.n == 0) num++;
                }
            }
            return num;
        }
        void generate_random()
        {
            int rrx = 0, rry = 0;
            if (get_num() <= 7)
            {
                for (int i = 0; i < 4; i++)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        if (recs[i, k].n == 0)
                        {
                            rrx = i; rry = k;
                            break;
                        }
                    }
                }
            }
            else
            {
                rrx = rr.Next(0, 3);
                rry = rr.Next(0, 3);
                while (recs[rrx, rry].n != 0)
                {
                    rrx = rr.Next(0, 3);
                    rry = rr.Next(0, 3);
                }
            }

            int n;
            //n = rr.Next(0, 10);
            //while (nums[n] > get_max())
            //{
            //    n = rr.Next(0, 10);
            //}
            n = rr.Next(0, 1);
            recs[rrx, rry].n = nums[n];
        }
        void replace(int i, int k, int ii, int kk)
        {
            rec r1 = recs[i, k], r2 = recs[ii, kk];
            r1.n += r2.n;
            r2.n = 0;
            //if (r1.n == 2048) last_num = true;
        }
        void set_true()
        {
            for(int i = 0; i < 4; i++)
            {
                for(int k = 0; k < 4; k++)
                {
                    recs[i, k].flag = true;
                }
            }
        }

        void left()
        {
            rec r;
            int tx, ty;
            for (int i = 0; i < 4; i++)
            {
                set_true();
                for (int k = 1; k < 4; k++)
                {
                    if (recs[i, k].n != 0)
                    {
                        tx = i; ty = (k - 1);
                        r = recs[i, k];
                        while (recs[tx, ty].n == 0)
                        {
                            if (ty == 0 || recs[tx, ty].n != 0) break;
                            ty--;
                        }
                        if (r.n == recs[tx, ty].n && recs[tx, ty].flag == true)
                        {
                            recs[tx, ty].flag = false;
                            if (r.n != 0) lf = true;
                            replace(tx, ty, i, k);
                        }
                        else
                        {
                            if (ty == 0)
                            {
                                if (recs[tx, ty].n == 0)
                                {
                                    if (r.n != 0) lf = true;
                                    replace(tx, ty, i, k);
                                }
                                else
                                {
                                    if (ty + 1 != k)
                                    {
                                        if (r.n != 0) lf = true;
                                        replace(tx, ty + 1, i, k);
                                    }
                                }
                            }
                            else
                            {
                                if (ty + 1 != k)
                                {
                                    if (r.n != 0) lf = true;
                                    replace(tx, ty + 1, i, k);
                                }
                            }
                        }
                    }
                }
            }
        }
        void right()
        {
            rec r;
            int tx, ty;
            for (int i = 0; i < 4; i++)
            {
                set_true();
                for (int k = 2; k >= 0; k--)
                {
                    if (recs[i, k].n != 0)
                    {
                        tx = i; ty = (k + 1);
                        r = recs[i, k];
                        while (recs[tx, ty].n == 0)
                        {
                            if (ty == 3 || recs[tx, ty].n != 0) break;
                            ty++;
                        }
                        if (r.n == recs[tx, ty].n && recs[tx, ty].flag == true)
                        {
                            recs[tx, ty].flag = false;
                            if (r.n != 0) rf = true;
                            replace(tx, ty, i, k);
                        }
                        else
                        {
                            if (ty == 3)
                            {
                                if (recs[tx, ty].n == 0)
                                {
                                    if (r.n != 0) rf = true;
                                    replace(tx, ty, i, k);
                                }
                                else
                                {
                                    if (ty - 1 != k)
                                    {
                                        if (r.n != 0) rf = true;
                                        replace(tx, ty - 1, i, k);
                                    }
                                }
                            }
                            else
                            {
                                if (ty - 1 != k)
                                {
                                    if (r.n != 0) rf = true;
                                    replace(tx, ty - 1, i, k);
                                }
                            }
                        }
                    }
                }
            }
        }
        void up()
        {
            rec r;
            int tx, ty;
            for (int k = 0; k < 4; k++)
            {
                set_true();
                for (int i = 1; i < 4; i++)
                {
                    if (recs[i, k].n != 0)
                    {
                        tx = i - 1; ty = k;
                        r = recs[i, k];
                        while (recs[tx, ty].n == 0)
                        {
                            if (tx == 0 || recs[tx, ty].n != 0) break;
                            tx--;
                        }
                        if (r.n == recs[tx, ty].n && recs[tx, ty].flag == true)
                        {
                            recs[tx, ty].flag = false;
                            if (r.n != 0) uf = true;
                            replace(tx, ty, i, k);
                        }
                        else
                        {
                            if (tx == 0)
                            {
                                if (recs[tx, ty].n == 0)
                                {
                                    if (r.n != 0) uf = true;
                                    replace(tx, ty, i, k);
                                }
                                else
                                {
                                    if (tx + 1 != i)
                                    {
                                        if (r.n != 0) uf = true;
                                        replace(tx + 1, ty, i, k);
                                    }
                                }
                            }
                            else
                            {
                                if (tx + 1 != i)
                                {
                                    if (r.n != 0) uf = true;
                                    replace(tx + 1, ty, i, k);
                                }
                            }
                        }
                    }
                }
            }
        }
        void down()
        {
            rec r;
            int tx, ty;
            for (int k = 0; k < 4; k++)
            {
                set_true();
                for (int i = 2; i >= 0; i--)
                {
                    if (recs[i, k].n != 0)
                    {
                        tx = i + 1; ty = k;
                        r = recs[i, k];
                        while (recs[tx, ty].n == 0)
                        {
                            if (tx == 3 || recs[tx, ty].n != 0) break;
                            tx++;
                        }
                        if (r.n == recs[tx, ty].n && recs[tx, ty].flag == true)
                        {
                            recs[tx, ty].flag = false;
                            if (r.n != 0) df = true;
                            replace(tx, ty, i, k);
                        }
                        else
                        {
                            if (tx == 3)
                            {
                                if (recs[tx, ty].n == 0)
                                {
                                    if (r.n != 0) df = true;
                                    replace(tx, ty, i, k);
                                }
                                else
                                {
                                    if (tx - 1 != i)
                                    {
                                        if (r.n != 0) df = true;
                                        replace(tx - 1, ty, i, k);
                                    }
                                }
                            }
                            else
                            {
                                if (tx - 1 != i)
                                {
                                    if (r.n != 0) df = true;
                                    replace(tx - 1, ty, i, k);
                                }
                            }
                        }
                    }
                }
            }
        }
        
        bool game_checkv()
        {
            rec r;
            int tx, ty;
            for (int i = 0; i < 4; i++)
            {
                set_true();
                for (int k = 1; k < 4; k++)
                {
                    if (recs[i, k].n != 0)
                    {
                        tx = i; ty = (k - 1);
                        r = recs[i, k];
                        while (recs[tx, ty].n == 0)
                        {
                            if (ty == 0 || recs[tx, ty].n != 0) break;
                            ty--;
                        }
                        if (r.n == recs[tx, ty].n && recs[tx, ty].flag == true)
                        {
                            return true;
                        }
                        else
                        {
                            if (ty == 0)
                            {
                                if (recs[tx, ty].n == 0)
                                {
                                    return true;
                                }
                                else
                                {
                                    if (ty + 1 != k)
                                    {
                                        return true;
                                    }
                                }
                            }
                            else
                            {
                                if (ty + 1 != k)
                                {
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
            for (int i = 0; i < 4; i++)
            {
                set_true();
                for (int k = 2; k >= 0; k--)
                {
                    if (recs[i, k].n != 0)
                    {
                        tx = i; ty = (k + 1);
                        r = recs[i, k];
                        while (recs[tx, ty].n == 0)
                        {
                            if (ty == 3 || recs[tx, ty].n != 0) break;
                            ty++;
                        }
                        if (r.n == recs[tx, ty].n && recs[tx, ty].flag == true)
                        {
                            return true;
                        }
                        else
                        {
                            if (ty == 3)
                            {
                                if (recs[tx, ty].n == 0)
                                {
                                    return true;
                                }
                                else
                                {
                                    if (ty - 1 != k)
                                    {
                                        return true;
                                    }
                                }
                            }
                            else
                            {
                                if (ty - 1 != k)
                                {
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
            for (int k = 0; k < 4; k++)
            {
                set_true();
                for (int i = 1; i < 4; i++)
                {
                    if (recs[i, k].n != 0)
                    {
                        tx = i - 1; ty = k;
                        r = recs[i, k];
                        while (recs[tx, ty].n == 0)
                        {
                            if (tx == 0 || recs[tx, ty].n != 0) break;
                            tx--;
                        }
                        if (r.n == recs[tx, ty].n && recs[tx, ty].flag == true)
                        {
                            return true;
                        }
                        else
                        {
                            if (tx == 0)
                            {
                                if (recs[tx, ty].n == 0)
                                {
                                    return true;
                                }
                                else
                                {
                                    if (tx + 1 != i)
                                    {
                                        return true;
                                    }
                                }
                            }
                            else
                            {
                                if (tx + 1 != i)
                                {
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
            for (int k = 0; k < 4; k++)
            {
                set_true();
                for (int i = 2; i >= 0; i--)
                {
                    if (recs[i, k].n != 0)
                    {
                        tx = i + 1; ty = k;
                        r = recs[i, k];
                        while (recs[tx, ty].n == 0)
                        {
                            if (tx == 3 || recs[tx, ty].n != 0) break;
                            tx++;
                        }
                        if (r.n == recs[tx, ty].n && recs[tx, ty].flag == true)
                        {
                            return true;
                        }
                        else
                        {
                            if (tx == 3)
                            {
                                if (recs[tx, ty].n == 0)
                                {
                                    return true;
                                }
                                else
                                {
                                    if (tx - 1 != i)
                                    {
                                        return true;
                                    }
                                }
                            }
                            else
                            {
                                if (tx - 1 != i)
                                {
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
            return false;
        }
        bool game_win_check()
        {
            for (int i = 0; i < 4; i++)
            {
                for (int k = 0; k < 4; k++)
                {
                    if (recs[i, k].n == 2048) return true;
                }
            }
            return false;
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            if (last_num == false && game_over == false)
            {
                switch (e.KeyCode)
                {
                    case Keys.Up:
                        up();
                        if (uf == true)
                        {
                            generate_random();
                            uf = false;
                        }
                        break;
                    case Keys.Down:
                        down();
                        if (df == true)
                        {
                            generate_random();
                            df = false;
                        }
                        break;
                    case Keys.Left:
                        left();
                        if (lf == true)
                        {
                            generate_random();
                            lf = false;
                        }
                        break;
                    case Keys.Right:
                        right();
                        if (rf == true)
                        {
                            generate_random();
                            rf = false;
                        }
                        break;
                    case Keys.Space:
                        CreateActors();
                        last_num = false;
                        game_over = false;
                        break;
                }
            }
            else
            {
                if(e.KeyCode  == Keys.Space)
                {
                    CreateActors();
                    last_num = false;
                    game_over = false;
                }
            }
        }
    }
}