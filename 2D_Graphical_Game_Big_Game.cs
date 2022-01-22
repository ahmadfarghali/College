using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Game_Project
{
    //class for hero
    public class hero
    {
        public int x, y;
        public char dir;//r or l
        public bool ontile;
        public int tile;
        public int health;
        //for each list of bitmaps
        //there is a flag and a frame_counter
        public List<Bitmap> r_stand;
        public bool rstandf;
        public int rs;

        public List<Bitmap> l_stand;
        public bool lstandf;
        public int ls;

        public List<Bitmap> r_run;
        public bool rrunf;
        public int rr;

        public List<Bitmap> l_run;
        public bool lrunf;
        public int lr;

        public List<Bitmap> r_attack;
        public bool rattackf;
        public int ra;

        public List<Bitmap> l_attack;
        public bool lattackf;
        public int la;

        public Bitmap r_jump;
        public bool rjumpf;
        public bool move_jump_r;

        public Bitmap l_jump;
        public bool ljumpf;
        public bool move_jump_l;

        public Bitmap r_sit;
        public bool rsitf;

        public Bitmap l_sit;
        public bool lsitf;

        public Bitmap r_die;
        public bool rdief;

        public Bitmap l_die;
        public bool ldief;

        public Bitmap r_fire;
        public bool rfiref;

        public Bitmap l_fire;
        public bool lfiref;
    }
    //class for one photo objs
    public class node_1
    {
        public int x, y;
        public Bitmap im;
        public char dir;
        public int speed;
    }
    //big bullet
    public class last_node
    {
        public int x, y;
        public List<Bitmap> imgs;
        public int frame;
        public char dir;
        public int speed;
    }
    //class for multi photo objs
    public class node_M
    {
        public int x, y;
        public List<Bitmap> alivelist;
        public bool aliveflag;
        public int aliveframecurrent;
        public int aliveframes;
        //dead stuff
        public List<Bitmap> deadlist;
        public bool deadflag;
        public int deadframecurrent;

        //shake for flying
        public int shake;

        public int health;
        public int speed;
        public bool fly;
    }
    //class for self drawing node
    public class self_node
    {
        public int x, y;
        public int nTiles;
        public Bitmap im;
        public int wholew;
        public int dx;
        public int dy;
        public bool obj_touch;
        public int speed;
        public void DrawYourSelf(Graphics g2, int xsrs, int ysrs)
        {
            int tx = x;
            for (int i = 0; i < nTiles; i++)
            {
                g2.DrawImage(im, tx - xsrs, y - ysrs);
                tx += im.Width;
            }
        }
    }
    public partial class Form1 : Form
    {
        //Lists
        List<hero> heros = new List<hero>();
        List<node_1> bullets = new List<node_1>();
        List<self_node> tiles = new List<self_node>();
        List<node_M> enemies = new List<node_M>();
        List<node_1> enemy_bullets = new List<node_1>();
        List<last_node> coins = new List<last_node>();
        List<last_node> bigbullets = new List<last_node>();
        List<node_M> sec_enemies = new List<node_M>();

        //standards
        Bitmap off;
        Timer t = new Timer();
        int cot_tick = 0;
        Random rr = new Random();

        //hero start hxs,and hys and avg hight and avg width
        int hxs, hys;
        int hh = 91, hw = 42;
        int hero_speed = 20;
        //jump_tick--->for it to jump in the timer
        int jump_tick = 0;

        //scrolling funs
        Bitmap background = new Bitmap("background.jpg");
        int xsrs = 0, ysrs = 312, scroll_speed = 10;
        int wsrs = 1366, hsrs = 768;
        bool scroll_move = false;
        
        //mini
        Bitmap minibackground = new Bitmap("minibackground.jpg");
        int minx, miny = 0, minw = 192 * 3, minh = 108;
        int min_x, min_y;

        //Game over things
        int game_over_x, game_over_y;
        int game_win_x, game_win_y;
        int killcot = 0, tokill = 20;

        //collision with enemies things
        int col_tick, col_time = 30;

        //active big bullet
        bool get_coin = false, startExp = false;

        public Form1()
        {
            this.WindowState = FormWindowState.Maximized;
            this.Paint += Form1_Paint;
            this.Load += Form1_Load;
            this.KeyDown += Form1_KeyDown;
            this.KeyUp += Form1_KeyUp;

            t.Tick += T_Tick;
            t.Interval = 16;
            t.Start();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            DrawDubb(e.Graphics);
        }

        void Form1_Load(object sender, EventArgs e)
        {
            off = new Bitmap(this.ClientSize.Width, this.ClientSize.Height);
            CreateActors();
            col_tick = col_time;
            minx = this.ClientSize.Width - 192 * 3;
            game_win_x = this.ClientSize.Width / 2 - 500;
            game_win_y = this.ClientSize.Height;
        }

        void DrawDubb(Graphics g)
        {
            Graphics g2 = Graphics.FromImage(off);
            DrawScene(g2);
            g.DrawImage(off, 0, 0);
        }

        void DrawScene(Graphics g2)
        {
            g2.Clear(Color.DarkSlateGray);
            //background things
            Rectangle srs = new Rectangle(xsrs, ysrs, wsrs, hsrs);
            Rectangle dst = new Rectangle(0, 0, this.ClientSize.Width, this.ClientSize.Height);
            g2.DrawImage(background, dst, srs, GraphicsUnit.Pixel);

            /////mini background
            Rectangle srs2 = new Rectangle(0, 0, minibackground.Width, minibackground.Height);
            Rectangle dst2 = new Rectangle(this.ClientSize.Width - 192 * 3, 0, 192 * 3, 108);
            g2.DrawImage(minibackground, dst2, srs2, GraphicsUnit.Pixel);
            //g2.FillEllipse(Brushes.Red, minx + (((heros[0].x / 10) * minw) / 1920 * 3), miny + ((heros[0].y * minh) / 1080), 10, 10);
            //g2.FillEllipse(Brushes.Red, minx + (((min_x / 10) * minw) / 1920 * 3), miny + ((heros[0].y * minh) / 1080), 10, 10);
            int X = minx + (((min_x / 10) * minw) / 1920 * 3);
            int Y = miny + ((heros[0].y * minh) / 1080);
            int WH = 15;
            Rectangle s = new Rectangle(X, Y, WH, WH);

            /////////////////////////////////////////////////
            Font hf = new Font("Arial Narrow", 37);
            Font of = new Font("Arial Narrow", 20);

            for (int i = 0; i < heros.Count; i++)
            {
                hero h = heros[i];
                if (h.rstandf == true)
                {
                    int j = h.rs;
                    g2.DrawImage(h.r_stand[j], h.x, h.y);
                    g2.DrawImage(h.r_stand[j], s);
                }
                if (h.lstandf == true)
                {
                    int j = h.ls;
                    g2.DrawImage(h.l_stand[j], h.x, h.y);
                    g2.DrawImage(h.l_stand[j], s);
                }

                if (h.rrunf == true)
                {
                    int j = h.rr;
                    g2.DrawImage(h.r_run[j], h.x, h.y);
                    g2.DrawImage(h.r_run[j], s);
                }
                if (h.lrunf == true)
                {
                    int j = h.lr;
                    g2.DrawImage(h.l_run[j], h.x, h.y);
                    g2.DrawImage(h.l_run[j], s);
                }

                if (h.rattackf == true)
                {
                    int j = h.ra;
                    g2.DrawImage(h.r_attack[j], h.x, h.y);
                    g2.DrawImage(h.r_attack[j], s);
                }
                if (h.lattackf == true)
                {
                    int j = h.la;
                    g2.DrawImage(h.l_attack[j], h.x, h.y);
                    g2.DrawImage(h.l_attack[j], s);
                }

                if (h.rjumpf == true)
                {
                    g2.DrawImage(h.r_jump, h.x, h.y);
                    g2.DrawImage(h.r_jump, s);
                }
                if (h.ljumpf == true)
                {
                    g2.DrawImage(h.l_jump, h.x, h.y);
                    g2.DrawImage(h.l_jump, s);
                }

                if (h.rsitf == true)
                {
                    g2.DrawImage(h.r_sit, h.x, h.y);
                    g2.DrawImage(h.r_sit, s);
                }
                if (h.lsitf == true)
                {
                    g2.DrawImage(h.l_sit, h.x, h.y);
                    g2.DrawImage(h.l_sit, s);
                }

                if (h.rdief == true)
                {
                    g2.DrawImage(h.r_die, h.x, h.y);
                    g2.DrawImage(h.r_die, s);
                }
                if (h.ldief == true)
                {
                    g2.DrawImage(h.l_die, h.x, h.y);
                    g2.DrawImage(h.l_die, s);
                }

                if (h.rfiref == true)
                {
                    g2.DrawImage(h.r_fire, h.x, h.y);
                    g2.DrawImage(h.r_fire, s);
                }
                if (h.lfiref == true)
                {
                    g2.DrawImage(h.l_fire, h.x, h.y);
                    g2.DrawImage(h.l_fire, s);
                }

                if (h.rdief == true)
                {
                    g2.DrawImage(h.r_die, h.x, h.y);
                    g2.DrawImage(h.r_die, s);
                }
                if (h.ldief == true)
                {
                    g2.DrawImage(h.l_die, h.x, h.y);
                    g2.DrawImage(h.l_die, s);
                }
            }
            for (int i = 0; i < bullets.Count; i++)
            {
                node_1 b = bullets[i];
                g2.DrawImage(b.im, b.x - xsrs, b.y - ysrs);
            }
            for (int i = 0; i < tiles.Count; i++)
            {
                self_node t = tiles[i];
                t.DrawYourSelf(g2, xsrs, ysrs);
            }
            for (int i = 0; i < enemies.Count; i++)
            {
                node_M e = enemies[i];
                if (e.aliveflag == true)
                {
                    int j = e.aliveframecurrent;
                    g2.DrawImage(e.alivelist[j], e.x - xsrs, e.y - ysrs);
                    if (e.fly == false)
                        g2.DrawString(e.health.ToString(), of, Brushes.DarkRed, e.x - xsrs, e.y - ysrs);
                    else
                        g2.DrawString(e.health.ToString(), of, Brushes.DarkRed, e.x - xsrs - 15, e.y - ysrs - 15);
                }
                if (e.deadflag == true)
                {
                    int j = e.deadframecurrent;
                    g2.DrawImage(e.deadlist[j], e.x - xsrs, e.y - ysrs);
                }
            }
            for (int i = 0; i < enemy_bullets.Count; i++)
            {
                node_1 b = enemy_bullets[i];
                g2.DrawImage(b.im, b.x - xsrs, b.y - ysrs);
            }
            for (int i = 0; i < coins.Count; i++)
            {
                last_node c = coins[i];
                int j = c.frame;
                g2.DrawImage(c.imgs[j], c.x-xsrs, c.y-ysrs);
            }
            for (int i = 0; i < bigbullets.Count; i++)
            {
                last_node c = bigbullets[i];
                int j = c.frame;
                g2.DrawImage(c.imgs[j], c.x - xsrs, c.y - ysrs);
            }
            for (int i = 0; i < sec_enemies.Count; i++)
            {
                node_M e = sec_enemies[i];
                if (e.aliveflag == true)
                {
                    int j = e.aliveframecurrent;
                    g2.DrawImage(e.alivelist[j], e.x - xsrs, e.y - ysrs);
                    g2.DrawString(e.health.ToString(), of, Brushes.DarkRed, e.x - xsrs - 15, e.y - ysrs - 15);
                }
                if (e.deadflag == true)
                {
                    int j = e.deadframecurrent;
                    g2.DrawImage(e.deadlist[j], e.x - xsrs, e.y - ysrs);
                }
            }

            Font go = new Font("Arial Narrow", 150);
            if (heros[0].health == 0 && killcot < tokill)
                g2.DrawString("GAME OVER", go, Brushes.DarkRed, game_over_x, game_over_y);
            if (killcot >= tokill)
                g2.DrawString("YOU WIN", go, Brushes.DarkGreen, game_win_x - 50, game_win_y);

            g2.DrawString("Hero Health: " + heros[0].health * 100, hf, Brushes.Green, 0, 0);
            g2.DrawString("Score: " + killcot, hf, Brushes.Blue, 0, 50);
        }

        //Timer///////////////////////////////////////////////////////////////////////////
        private void T_Tick(object sender, EventArgs e)
        {
            //hero/////////////////////////////////////////////////////////
            hero h = heros[0];
            if (cot_tick % 15 == 0)
            {
                hero_stand();
            }
            hero_run();
            hero_jump();
            if (cot_tick % 1 == 0)
            {
                if (h.rjumpf == false && h.ljumpf == false)
                    gravity();
            }
            //hero bullets
            delete_bullets();
            if (cot_tick % 1 == 0)
            {
                moveHeroBullets();
            }

            //scroll/////////////////////////////////////////////////////////
            scroll();

            //tiles//////////////////////////////////////////////////////////
            move_tiles();
            if (h.ontile == true)
                check_touch();

            //enemies///////////////////////////////////////////////////////
            if (cot_tick % 60 == 0 && h.y > this.ClientSize.Height / 2 + 200)
            {//ground robots
                creategroundenemies();
            }
            if (cot_tick % 30 == 0)
            {//ships
                createFlyEnemies();
            }
            if (cot_tick % 70 == 0)
            {//sec ships
                createSecEnemies();
            }
            if (cot_tick % 1 == 0)
            {//chase hero
                moveSecEnemies();
            }
            if (cot_tick % 1 == 0)
            {//move and change frame
                enemy_move_frame();
                enemy_gravity();
            }
            if (cot_tick % 25 == 0)
            {//shake the ship
                enemy_fly_shake();
            }
            deleteEnemies();

            //enemy bullets///////////
            deletEnemyBullets();
            if (cot_tick % 20 == 0)
            {
                createEnemyBullets();
            }
            if (cot_tick % 1 == 0)
            {
                moveEnemyBullets();
            }

            //collisions////////////////////////////////////////////////
            hero_bullet_collision();
            enemy_bllet_collision();
            if (col_tick >= col_time)
                hero_enemy_collision();
            else
                col_tick++;

            //coins//////////////////////////////////////////////////
            if (cot_tick % 5 == 0)
                changeCoinFrame();
            hero_coin_collision();

            //bigbullet
            MoveBigBullet();
            changeBigBulletFrames();

            //gameover & win
            gameOver();
            if (killcot >= tokill)
                gameWin();

            cot_tick++;
            DrawDubb(this.CreateGraphics());
        }

        void CreateActors()
        {
            CreateHero();
            createTiles();
            createCoin();
        }

        //hero functions
        void CreateHero()
        {
            hero h = new hero();
            h.dir = 'r';
            h.ontile = false;
            h.tile = -1;
            h.health = 7;

            h.r_stand = new List<Bitmap>();
            for (int i = 0; i < 5; i++)
            {
                Bitmap b = new Bitmap("rstand" + (i + 1) + ".bmp");
                b.MakeTransparent(b.GetPixel(0, 0));
                h.r_stand.Add(b);
            }
            h.rstandf = true;
            h.rs = 0;

            h.l_stand = new List<Bitmap>();
            for (int i = 0; i < 5; i++)
            {
                Bitmap b = new Bitmap("lstand" + (i + 1) + ".bmp");
                b.MakeTransparent(b.GetPixel(0, 0));
                h.l_stand.Add(b);
            }
            h.lstandf = false;
            h.ls = 0;

            h.r_run = new List<Bitmap>();
            for (int i = 0; i < 5; i++)
            {
                Bitmap b = new Bitmap("rrun" + (i + 1) + ".bmp");
                b.MakeTransparent(b.GetPixel(0, 0));
                h.r_run.Add(b);
            }
            h.rrunf = false;
            h.rr = 0;

            h.l_run = new List<Bitmap>();
            for (int i = 0; i < 5; i++)
            {
                Bitmap b = new Bitmap("lrun" + (i + 1) + ".bmp");
                b.MakeTransparent(b.GetPixel(0, 0));
                h.l_run.Add(b);
            }
            h.lrunf = false;
            h.lr = 0;

            h.r_attack = new List<Bitmap>();
            for (int i = 0; i < 2; i++)
            {
                Bitmap b = new Bitmap("rc_attack" + (i + 1) + ".bmp");
                b.MakeTransparent(b.GetPixel(0, 0));
                h.r_attack.Add(b);
            }
            h.rattackf = false;
            h.ra = 0;

            h.l_attack = new List<Bitmap>();
            for (int i = 0; i < 2; i++)
            {
                Bitmap b = new Bitmap("lc_attack" + (i + 1) + ".bmp");
                b.MakeTransparent(b.GetPixel(0, 0));
                h.l_attack.Add(b);
            }
            h.lattackf = false;
            h.la = 0;

            h.r_jump = new Bitmap("rjump.bmp");
            h.r_jump.MakeTransparent(h.r_jump.GetPixel(0, 0));
            h.l_jump = new Bitmap("ljump.bmp");
            h.l_jump.MakeTransparent(h.l_jump.GetPixel(0, 0));
            h.rjumpf = false; h.ljumpf = false;
            h.move_jump_r = false; h.move_jump_l = false;

            h.r_sit = new Bitmap("rsit.bmp");
            h.r_sit.MakeTransparent(h.r_sit.GetPixel(0, 0));
            h.l_sit = new Bitmap("lsit.bmp");
            h.l_sit.MakeTransparent(h.l_sit.GetPixel(0, 0));
            h.rsitf = false; h.lsitf = false;

            h.r_die = new Bitmap("rdie.bmp");
            h.r_die.MakeTransparent(h.r_die.GetPixel(0, 0));
            h.l_die = new Bitmap("ldie.bmp");
            h.l_die.MakeTransparent(h.l_die.GetPixel(0, 0));
            h.rdief = false; h.ldief = false;

            h.r_fire = new Bitmap("rfire.bmp");
            h.r_fire.MakeTransparent(h.r_fire.GetPixel(0, 0));
            h.l_fire = new Bitmap("lfire.bmp");
            h.l_fire.MakeTransparent(h.l_fire.GetPixel(0, 0));
            h.rfiref = false; h.lfiref = false;

            h.x = 0 + xsrs; h.y = (this.ClientSize.Height - h.r_stand[0].Height) + ysrs;
            min_x = h.x; min_y = h.y;

            heros.Add(h);
        }
        void set_true_others_false(char ch)
        {
            hero h = heros[0];
            h.rstandf = false;
            h.lstandf = false;

            h.rrunf = false;
            h.lrunf = false;

            h.rattackf = false;
            h.lattackf = false;

            h.rjumpf = false;
            h.ljumpf = false;

            h.rsitf = false;
            h.lsitf = false;

            h.rfiref = false;
            h.lfiref = false;

            h.rdief = false;
            h.ldief = false;
            if (ch == ']')
            {
                if (h.dir == 'r')
                {
                    h.rstandf = true;
                }
                else
                {
                    h.lstandf = true;
                }
            }
            if (ch == 'w')
            {
                if (h.dir == 'r')
                    h.rjumpf = true;
                else
                    h.ljumpf = true;
            }
            if (ch == 's')
            {
                if (h.dir == 'r')
                {
                    h.rsitf = true;
                    if (h.ontile == false)
                        h.y = this.ClientSize.Height - h.r_sit.Height;
                    else
                        h.y = tiles[h.tile].y - h.r_sit.Height - ysrs;
                }
                else
                {
                    h.lsitf = true;
                    if (h.ontile == false)
                        h.y = this.ClientSize.Height - h.l_sit.Height;
                    else
                        h.y = tiles[h.tile].y - h.l_sit.Height - ysrs;
                }
            }
            if (ch == 'a')
            {
                h.lrunf = true;
            }
            if (ch == 'd')
            {
                h.rrunf = true;
            }
            if (ch == 'j')
            {
                if (h.dir == 'r')
                    h.rattackf = true;
                else
                    h.lattackf = true;
            }
            if (ch == 'k')
            {
                if (h.dir == 'r')
                    h.rfiref = true;
                else
                    h.lfiref = true;
            }
            if (ch == 'q')
            {
                if (h.dir == 'r')
                    h.rdief = true;
                else
                    h.ldief = true;
            }
        }
        void hero_stand()
        {
            hero h = heros[0];
            if (h.rstandf == true)
            {
                if (h.rs == 4)
                    h.rs = 0;
                else
                    h.rs++;
            }
            if (h.lstandf == true)
            {
                if (h.ls == 4)
                    h.ls = 0;
                else
                    h.ls++;
            }
        }
        void hero_run()
        {
            hero h = heros[0];
            if (h.rrunf == true)
            {
                if (h.rr == 4)
                    h.rr = 0;
                else
                    h.rr++;
                
                if ((h.x + h.r_run[h.rr].Width) + (1 * hero_speed) <= (this.ClientSize.Width / 2))
                {
                    h.x += 1 * hero_speed;
                    min_x+= 1 * hero_speed;
                } 
                else
                    scroll_move = true;
            }
            if (h.lrunf == true)
            {
                if (h.lr == 4)
                    h.lr = 0;
                else
                    h.lr++;
                
                if (h.x - (1 * hero_speed) >= 0)
                {
                    h.x -= 1 * hero_speed;
                    min_x -= 1 * hero_speed;
                }
                    
                else
                    scroll_move = true;
            }
        }
        void hero_attack()
        {
            hero h = heros[0];
            if (h.rattackf == true)
            {
                if (h.ra == 1)
                    h.ra = 0;
                else
                    h.ra++;
            }
            if (h.lattackf == true)
            {
                if (h.la == 1)
                    h.la = 0;
                else
                    h.la++;
            }
        }
        void hero_jump()
        {
            hero h = heros[0];
            if (h.rjumpf == true)
            {
                if (jump_tick > 15)
                {
                    if ((h.y + h.r_stand[0].Height) >= this.ClientSize.Height || touch_tile() != -1)
                    {
                        if (touch_tile() != -1) h.ontile = true;

                        set_true_others_false(']');
                        jump_tick = 0;
                        h.rjumpf = false;
                    }
                    h.y += hero_speed;
                    if ((h.x + h.r_run[h.rr].Width) + (1 * hero_speed) <= (this.ClientSize.Width / 2))
                    {
                        if (h.move_jump_r == true)
                        {
                            h.x += 1 * hero_speed;
                            min_x += 1 * hero_speed;
                        }
                            
                        if (h.move_jump_l == true && (h.x - (1 * hero_speed) >= 0))
                        {
                            h.x -= 1 * hero_speed;
                            min_x -= 1 * hero_speed;
                        }
                    }
                    else
                        if (h.move_jump_r || h.move_jump_l)
                        scroll_move = true;
                }
                else
                {
                    h.y -= hero_speed;
                    if ((h.x + h.r_run[h.rr].Width) + (1 * hero_speed) <= (this.ClientSize.Width / 2))
                    {
                        if (h.move_jump_r == true)
                        {
                            h.x += 1 * hero_speed;
                            min_x += 1 * hero_speed;
                        }

                        if (h.move_jump_l == true && (h.x - (1 * hero_speed) >= 0))
                        {
                            h.x -= 1 * hero_speed;
                            min_x -= 1 * hero_speed;
                        }
                    }
                    else
                        if (h.move_jump_r || h.move_jump_l)
                        scroll_move = true;
                }
                jump_tick++;
            }
            if (h.ljumpf == true)
            {
                if (jump_tick > 15)
                {
                    if ((h.y + h.l_stand[0].Height) >= this.ClientSize.Height || touch_tile() != -1)
                    {
                        if (touch_tile() != -1) h.ontile = true;
                        set_true_others_false(']');
                        jump_tick = 0;
                        h.ljumpf = false;
                    }
                    h.y += hero_speed;
                    if (h.x - (1 * hero_speed) >= 0)
                    {
                        if (h.move_jump_r == true && (h.x + h.r_run[h.rr].Width) + (1 * hero_speed) <= (this.ClientSize.Width / 2))
                        {
                            h.x += 1 * hero_speed;
                            min_x += 1 * hero_speed;
                        }

                        if (h.move_jump_l == true)
                        {
                            h.x -= 1 * hero_speed;
                            min_x -= 1 * hero_speed;
                        }
                    }
                    else
                        if (h.move_jump_r || h.move_jump_l)
                        scroll_move = true;
                }
                else
                {
                    h.y -= hero_speed;
                    if (h.x - (1 * hero_speed) >= 0)
                    {
                        if (h.move_jump_r == true && (h.x + h.r_run[h.rr].Width) + (1 * hero_speed) <= (this.ClientSize.Width / 2))
                        {
                            h.x += 1 * hero_speed;
                            min_x += 1 * hero_speed;
                        }

                        if (h.move_jump_l == true)
                        {
                            h.x -= 1 * hero_speed;
                            min_x -= 1 * hero_speed;
                        }
                    }
                    else
                        if (h.move_jump_r || h.move_jump_l)
                        scroll_move = true;
                }
                jump_tick++;
            }
        }
        void gravity()
        {
            hero h = heros[0];
            if (h.y + hh < this.ClientSize.Height && h.ontile == false)
            {
                h.y += hero_speed;
            }
            else
            {
                if (h.ontile == true)
                {
                    if (h.rstandf == true)
                        h.y = tiles[h.tile].y - h.r_stand[h.rs].Height - ysrs;
                    if (h.lstandf == true)
                        h.y = tiles[h.tile].y - h.r_stand[h.ls].Height - ysrs;
                    if (h.rrunf == true)
                        h.y = tiles[h.tile].y - h.r_run[h.rr].Height - ysrs;
                    if (h.lrunf == true)
                        h.y = tiles[h.tile].y - h.l_run[h.lr].Height - ysrs;
                    if (h.rattackf == true)
                        h.y = tiles[h.tile].y - h.r_attack[h.ra].Height - ysrs;
                    if (h.lattackf == true)
                        h.y = tiles[h.tile].y - h.r_attack[h.la].Height - ysrs;
                    if (h.rdief == true)
                        h.y = tiles[h.tile].y - h.r_die.Height - ysrs;
                    if (h.ldief == true)
                        h.y = tiles[h.tile].y - h.l_die.Height - ysrs;
                }
                else
                {
                    if (h.rstandf == true)
                        h.y = this.ClientSize.Height - h.r_stand[h.rs].Height;
                    if (h.lstandf == true)
                        h.y = this.ClientSize.Height - h.r_stand[h.ls].Height;
                    if (h.rrunf == true)
                        h.y = this.ClientSize.Height - h.r_run[h.rr].Height;
                    if (h.lrunf == true)
                        h.y = this.ClientSize.Height - h.l_run[h.lr].Height;
                    if (h.rattackf == true)
                        h.y = this.ClientSize.Height - h.r_attack[h.ra].Height;
                    if (h.lattackf == true)
                        h.y = this.ClientSize.Height - h.r_attack[h.la].Height;
                    if (h.rdief == true)
                        h.y = this.ClientSize.Height - h.r_die.Height;
                    if (h.ldief == true)
                        h.y = this.ClientSize.Height - h.l_die.Height;
                }
            }
        }


        //enemies functions
        void creategroundenemies()
        {
            //153 is highest
            node_M e = new node_M();
            e.x = this.ClientSize.Width + xsrs;
            e.y = this.ClientSize.Height - 153 + ysrs;

            e.aliveframes = 7;
            e.alivelist = new List<Bitmap>();
            for (int i = 0; i < e.aliveframes; i++)
            {
                Bitmap eim = new Bitmap("enm" + (i + 1) + ".png");
                e.alivelist.Add(eim);
            }
            e.aliveframecurrent = 0;
            e.aliveflag = true;


            e.deadlist = new List<Bitmap>();
            for (int i = 0; i < 9; i++)
            {
                Bitmap eim = new Bitmap("fdead" + (i + 1) + ".png");
                e.deadlist.Add(eim);
            }
            e.deadframecurrent = 0;
            e.deadflag = false;

            e.health = 3;
            e.speed = 10;
            e.fly = false;
            enemies.Add(e);
        }
        void createFlyEnemies()
        {
            node_M e = new node_M();
            e.x = this.ClientSize.Width + xsrs;
            e.y = rr.Next(0, (this.ClientSize.Height / 2)) + ysrs;

            e.aliveframes = 2;
            e.alivelist = new List<Bitmap>();
            for (int i = 0; i < e.aliveframes; i++)
            {
                Bitmap eim = new Bitmap("ship" + (i) + ".png");
                e.alivelist.Add(eim);
            }
            e.aliveframecurrent = 0;
            e.aliveflag = true;

            e.deadlist = new List<Bitmap>();
            for (int i = 0; i < 9; i++)
            {
                Bitmap eim = new Bitmap("fdead" + (i + 1) + ".png");
                e.deadlist.Add(eim);
            }
            e.deadframecurrent = 0;
            e.deadflag = false;

            e.shake = 1;
            e.health = 2;
            e.speed = 10;
            e.fly = true;
            enemies.Add(e);
        }
        void enemy_move_frame()
        {
            for (int i = 0; i < enemies.Count; i++)
            {
                node_M e = enemies[i];
                if (e.aliveflag == true)
                {
                    if (e.aliveframecurrent == e.aliveframes - 1)
                        e.aliveframecurrent = 0;
                    else
                        e.aliveframecurrent++;
                    e.x -= e.speed;
                    if (e.fly == true)
                        e.y += e.shake * 2;
                }
                if (e.deadflag == true)
                {
                    if (e.deadframecurrent == 8)
                        e.deadframecurrent = 0;
                    else
                        e.deadframecurrent++;
                }
            }
        }
        void enemy_fly_shake()
        {
            for (int i = 0; i < enemies.Count; i++)
            {
                node_M e = enemies[i];
                if (e.fly == true)
                    e.shake *= -1;
            }
            for (int i = 0; i < sec_enemies.Count; i++)
            {
                node_M e = sec_enemies[i];
                if (e.fly == true)
                    e.shake *= -1;
            }
        }
        void enemy_gravity()
        {
            for (int i = 0; i < enemies.Count; i++)
            {
                node_M e = enemies[i];
                //1080 1017
                if (e.fly == false)
                {
                    if (e.aliveflag == true)
                    {//153 highest --> 2
                        if (e.y + e.alivelist[2].Height - ysrs < this.ClientSize.Height)
                        {
                            e.y += e.speed;
                        }
                        else
                        {
                            //e.y = this.ClientSize.Height - e.alivelist[e.aliveframecurrent].Height + ysrs;
                        }
                    }
                    else
                    {
                        if (e.y + e.deadlist[e.deadframecurrent].Height - ysrs < this.ClientSize.Height)
                        {
                            e.y += e.speed;
                        }
                        else
                        {
                            //e.y = this.ClientSize.Height - e.deadlist[e.deadframe].Height;
                        }
                    }
                }
            }
            for (int i = 0; i < sec_enemies.Count; i++)
            {
                node_M e = sec_enemies[i];
                if (e.fly == false)
                {
                    if (e.aliveflag == true)
                    {
                        if (e.y + e.alivelist[2].Height - ysrs < this.ClientSize.Height)
                        {
                            e.y += e.speed;
                        }
                        else
                        {
                        }
                    }
                    else
                    {
                        if (e.y + e.deadlist[e.deadframecurrent].Height - ysrs < this.ClientSize.Height)
                        {
                            e.y += e.speed;
                        }
                        else
                        {
                        }
                    }
                }
            }
        }
        void deleteEnemies()
        {
            for (int i = 0; i < enemies.Count; i++)
            {
                node_M e = enemies[i];
                if (
                    e.aliveflag == true
                 && ((e.x - xsrs) + e.alivelist[e.aliveframecurrent].Width) < 0
                  )
                {
                    enemies.RemoveAt(i);
                }
            }
            for (int i = 0; i < sec_enemies.Count; i++)
            {
                node_M e = sec_enemies[i];
                if (
                    e.aliveflag == true
                 && ((e.x - xsrs) + e.alivelist[e.aliveframecurrent].Width) < 0
                  )
                {
                    sec_enemies.RemoveAt(i);
                }
            }
        }
        void killAllLiving()
        {
            for (int i = 0; i < enemies.Count; i++)
            {
                node_M e = enemies[i];
                if (e.aliveflag == true)
                {
                    if (e.fly == true)
                        e.fly = false;
                    e.aliveflag = false;
                    e.deadflag = true;
                    e.health = 0;
                    killcot++;
                }
            }
            for (int i = 0; i < sec_enemies.Count; i++)
            {
                node_M e = sec_enemies[i];
                if (e.aliveflag == true)
                {
                    if (e.fly == true)
                        e.fly = false;
                    e.aliveflag = false;
                    e.deadflag = true;
                    e.health = 0;
                    killcot++;
                }
            }
        }
        //sec_enemies
        void createSecEnemies()
        {
            node_M e = new node_M();
            e.x = this.ClientSize.Width + xsrs;
            e.y = rr.Next(0, (this.ClientSize.Height / 2)) + ysrs;

            e.aliveframes = 2;
            e.alivelist = new List<Bitmap>();
            for (int i = 0; i < e.aliveframes; i++)
            {
                Bitmap eim = new Bitmap("ship" + (i) + ".png");
                e.alivelist.Add(eim);
            }
            e.aliveframecurrent = 0;
            e.aliveflag = true;

            e.deadlist = new List<Bitmap>();
            for (int i = 0; i < 9; i++)
            {
                Bitmap eim = new Bitmap("fdead" + (i + 1) + ".png");
                e.deadlist.Add(eim);
            }
            e.deadframecurrent = 0;
            e.deadflag = false;

            e.shake = 1;
            e.health = 1;
            e.speed = 10;
            e.fly = true;
            sec_enemies.Add(e);
        }
        void moveSecEnemies()
        {
            for (int i = 0; i < sec_enemies.Count; i++)
            {
                node_M e = sec_enemies[i];
                if (e.aliveflag == true)
                {
                    if (e.aliveframecurrent == e.aliveframes - 1)
                        e.aliveframecurrent = 0;
                    else
                        e.aliveframecurrent++;
                    if (e.fly == true)
                        e.y += e.shake * 2;
                    chase_hero();
                }
                if (e.deadflag == true)
                {
                    if (e.deadframecurrent == 8)
                        e.deadframecurrent = 0;
                    else
                        e.deadframecurrent++;
                }
            }
        }
        void chase_hero()
        {
            hero h = heros[0];
            for (int i = 0; i < sec_enemies.Count; i++)
            {
                node_M e = sec_enemies[i];
                if (e.aliveflag == true)
                {
                    if (e.x - xsrs > h.x)
                        e.x -= e.speed;
                    if (e.x - xsrs < h.x)
                        e.x += e.speed;
                }
            }
        }

        //hero bullets
        void createHeroBullet()
        {
            hero h = heros[0];
            node_1 b = new node_1();
            b.speed = 30;
            if (h.dir == 'r')
            {
                b.x = h.x + 35 + xsrs;
                b.y = h.y + 20 + ysrs;
                b.im = new Bitmap("rbullet.png");
                b.dir = 'r';
                bullets.Add(b);
            }
            else
            {
                b.x = h.x - 5 + xsrs;
                b.y = h.y + 20 + ysrs;
                b.im = new Bitmap("lbullet.png");
                b.dir = 'l';
                bullets.Add(b);
            }
        }
        void moveHeroBullets()
        {
            for (int i = 0; i < bullets.Count; i++)
            {
                node_1 b = bullets[i];
                if (b.dir == 'r')
                {
                    b.x += b.speed;
                }
                else
                {
                    b.x -= b.speed;
                }
            }
        }
        void delete_bullets()
        {
            for (int i = 0; i < bullets.Count; i++)
            {
                node_1 b = bullets[i];
                if (b.x - xsrs >= this.ClientSize.Width || b.x - xsrs < 0) bullets.RemoveAt(i);
            }
        }
        //Big bullet things
        void createBigBullet()
        {
            hero h = heros[0];
            last_node c = new last_node();
            c.imgs = new List<Bitmap>();
            for (int i = 0; i < 10; i++)
            {
                Bitmap cc = new Bitmap("bigbullet" + (i + 1) + ".png");
                c.imgs.Add(cc);
            }
            c.x = h.x + xsrs;
            c.y = h.y + ysrs;
            c.frame = 0;
            c.speed = 20;
            bigbullets.Add(c);
        }
        void MoveBigBullet()
        {
            int midx = this.ClientSize.Width / 2, midy = this.ClientSize.Height / 2;
            for(int i = 0; i < bigbullets.Count; i++)
            {
                last_node b = bigbullets[i];
                if(b.y - ysrs > midy|| b.x - xsrs <= midx)
                {
                    if (b.y - ysrs > midy)
                        b.y -= b.speed;
                    if (b.x - xsrs <= midx)
                        b.x += b.speed;
                }
                else
                    startExp = true;
            }
        }
        void changeBigBulletFrames()
        {
            for(int i = 0; i < bigbullets.Count; i++)
            {
                last_node b = bigbullets[i];
                if (startExp == true)
                {
                    if (b.frame == 9)
                    {
                        killAllLiving();
                        startExp = false;
                        get_coin = false;
                        bigbullets.RemoveAt(i);
                    }
                    else
                        b.frame++;
                }
            }
        }

        //coin for big bullet
        void createCoin()
        {
            int coinx = 550;
            for (int j = 0; j < 3; j++)
            {
                last_node c = new last_node();
                c.imgs = new List<Bitmap>();
                for (int i = 0; i < 4; i++)
                {
                    Bitmap cc = new Bitmap("coin" + (i + 1) + ".png");
                    c.imgs.Add(cc);
                }
                c.x = coinx + xsrs;
                c.y = this.ClientSize.Height - c.imgs[0].Height + ysrs;
                c.frame = 0;
                coins.Add(c);
                coinx += 1200;
            }
        }
        void changeCoinFrame()
        {
            for (int i = 0; i < coins.Count; i++)
            {
                last_node c = coins[i];
                if (c.frame < 3)
                    c.frame++;
                else
                    c.frame = 0;
            }
        }
        void hero_coin_collision()
        {
            hero h = heros[0];
            for (int i = 0; i < coins.Count; i++)
            {
                last_node e = coins[i];
                if (
                (
                (h.x >= e.x - xsrs
                 && h.x < e.x + e.imgs[e.frame].Width - xsrs
                 && h.y >= e.y - ysrs
                 && h.y < e.y + e.imgs[e.frame].Height - ysrs
                 )
                 ||
                 (e.x - xsrs >= h.x - 10
                 && e.x - xsrs <= h.x + hw + 10
                 && e.y - ysrs >= h.y
                 && e.y - ysrs <= h.y + hh)
                 )
                 && (h.health > 0)
                 )
                {
                    get_coin = true;
                    coins.RemoveAt(i);
                }
            }
        }

        //enemy bullets
        void createEnemyBullets()
        {
            node_1 b;
            if (enemies.Count > 0)
            {
                int ee = rr.Next(0, enemies.Count - 1);
                node_M e = enemies[ee];
                if (e.aliveflag == true)
                {
                    b = new node_1();
                    b.speed = 25;
                    if (e.fly == false)
                    {
                        b.x = e.x;
                        b.y = e.y + 55;
                        b.im = new Bitmap("genmbullet.png");
                        b.dir = 'l';
                    }
                    else
                    {
                        b.x = e.x;
                        b.y = e.y + 10;
                        b.im = new Bitmap("fenmbullet.png");
                        b.dir = 'd';
                    }
                    enemy_bullets.Add(b);
                }
            }
            if (sec_enemies.Count > 0)
            {
                int ee = rr.Next(0, sec_enemies.Count - 1);
                node_M e = sec_enemies[ee];
                if (e.aliveflag == true)
                {
                    b = new node_1();
                    b.speed = 25;
                    if (e.fly == false)
                    {
                        b.x = e.x;
                        b.y = e.y + 55;
                        b.im = new Bitmap("genmbullet.png");
                        b.dir = 'l';
                    }
                    else
                    {
                        b.x = e.x;
                        b.y = e.y + 10;
                        b.im = new Bitmap("fenmbullet.png");
                        b.dir = 'd';
                    }
                    enemy_bullets.Add(b);
                }
            }
        }
        void moveEnemyBullets()
        {
            for (int i = 0; i < enemy_bullets.Count; i++)
            {
                node_1 b = enemy_bullets[i];
                if (b.dir == 'l')
                {
                    b.x -= b.speed;
                }
                else
                {
                    b.y += b.speed;
                }
            }
        }
        void deletEnemyBullets()
        {
            for (int i = 0; i < enemy_bullets.Count; i++)
            {
                node_1 b = enemy_bullets[i];
                if (b.y - ysrs > this.ClientSize.Height || b.x - xsrs < 0) enemy_bullets.RemoveAt(i);
            }
        }

        //Collisions
        void hero_bullet_collision()
        {
            hero h = heros[0];
            for (int i = 0; i < bullets.Count; i++)
            {
                node_1 b = bullets[i];
                for (int k = 0; k < enemies.Count; k++)
                {
                    node_M e = enemies[k];
                    if (b.x >= e.x
                     && b.x < e.x + e.alivelist[e.aliveframecurrent].Width
                     && b.y >= e.y
                     && b.y < e.y + e.alivelist[e.aliveframecurrent].Height
                     && e.aliveflag == true
                        )
                    {
                        if (e.health == 1)
                        {
                            killcot++;
                            e.aliveflag = false;
                            e.deadflag = true;
                            e.fly = false;
                        }
                        else
                        {
                            e.health--;
                        }
                        bullets.RemoveAt(i);
                    }
                }
                for (int k = 0; k < sec_enemies.Count; k++)
                {
                    node_M e = sec_enemies[k];
                    if (b.x >= e.x
                     && b.x < e.x + e.alivelist[e.aliveframecurrent].Width
                     && b.y >= e.y
                     && b.y < e.y + e.alivelist[e.aliveframecurrent].Height
                     && e.aliveflag == true
                        )
                    {
                        if (e.health == 1)
                        {
                            killcot++;
                            e.aliveflag = false;
                            e.deadflag = true;
                            e.fly = false;
                        }
                        else
                        {
                            e.health--;
                        }
                        bullets.RemoveAt(i);
                    }
                }
            }
        }
        void enemy_bllet_collision()
        {
            hero h = heros[0];
            for (int i = 0; i < enemy_bullets.Count; i++)
            {
                node_1 b = enemy_bullets[i];
                if (b.x - xsrs >= h.x - 10
                    && b.x - xsrs <= h.x + hw + 10
                    && b.y - ysrs >= h.y
                    && b.y - ysrs <= h.y + hh
                    && h.rdief == false
                    && h.ldief == false
                    && killcot < tokill
                    )
                {
                    if (h.health == 1)
                    {
                        set_true_others_false('q');
                        h.health--;
                        game_over_x = this.ClientSize.Width / 2 - 500;
                        game_over_y = this.ClientSize.Height;
                    }
                    else
                    {
                        h.health--;
                    }
                    enemy_bullets.RemoveAt(i);
                }
            }
        }
        void hero_enemy_collision()
        {
            hero h = heros[0];
            for (int i = 0; i < enemies.Count; i++)
            {
                node_M e = enemies[i];
                if (
                (
                (h.x >= e.x - xsrs
                 && h.x < e.x + e.alivelist[e.aliveframecurrent].Width - xsrs
                 && h.y >= e.y - ysrs
                 && h.y < e.y + e.alivelist[e.aliveframecurrent].Height - ysrs)
                 ||
                 (e.x - xsrs >= h.x - 10
                 && e.x - xsrs <= h.x + hw + 10
                 && e.y - ysrs >= h.y
                 && e.y - ysrs <= h.y + hh)
                 )
                 && (e.aliveflag == true)
                 && (h.health > 0)
                 )
                {
                    if (h.rattackf == false && h.lattackf == false && killcot < tokill)
                    {
                        if (h.health == 1)
                        {
                            set_true_others_false('q');
                            h.health--;
                            game_over_x = this.ClientSize.Width / 2 - 500;
                            game_over_y = this.ClientSize.Height;
                        }
                        else
                        {
                            h.health--;
                        }
                        col_tick = 0;
                    }
                    else
                    {
                        if (h.rattackf == true || h.lattackf == true)
                        {
                            if (e.health == 1)
                            {
                                e.aliveflag = false;
                                e.deadflag = true;
                                e.fly = false;
                            }
                            else
                            {
                                e.health--;
                            }
                        }
                    }
                    break;
                }
            }
            for (int i = 0; i < sec_enemies.Count; i++)
            {
                node_M e = sec_enemies[i];
                if (
                (
                (h.x >= e.x - xsrs
                 && h.x < e.x + e.alivelist[e.aliveframecurrent].Width - xsrs
                 && h.y >= e.y - ysrs
                 && h.y < e.y + e.alivelist[e.aliveframecurrent].Height - ysrs)
                 ||
                 (e.x - xsrs >= h.x - 10
                 && e.x - xsrs <= h.x + hw + 10
                 && e.y - ysrs >= h.y
                 && e.y - ysrs <= h.y + hh)
                 )
                 && (e.aliveflag == true)
                 && (h.health > 0)
                 )
                {
                    if (h.rattackf == false && h.lattackf == false && killcot < tokill)
                    {
                        if (h.health == 1)
                        {
                            set_true_others_false('q');
                            h.health--;
                            game_over_x = this.ClientSize.Width / 2 - 500;
                            game_over_y = this.ClientSize.Height;
                        }
                        else
                        {
                            h.health--;
                        }
                        col_tick = 0;
                    }
                    else
                    {
                        if (h.rattackf == true || h.lattackf == true)
                        {
                            if (e.health == 1)
                            {
                                e.aliveflag = false;
                                e.deadflag = true;
                                e.fly = false;
                            }
                            else
                            {
                                e.health--;
                            }
                        }
                    }
                    break;
                }
            }
        }

        //background and scrolling things
        void scroll()
        {
            hero h = heros[0];
            if (h.dir == 'r' && !h.rstandf && !h.rattackf && !h.rsitf && !h.move_jump_l)
            {
                if (scroll_move == true && (xsrs + wsrs) <= (1920 * 3) && h.health > 0)
                {
                    xsrs += scroll_speed;
                    min_x += scroll_speed;
                }
            }
            else
            {
                if (h.dir == 'l' && !h.lstandf && !h.lattackf && !h.lsitf && !h.move_jump_r && h.health > 0)
                {
                    if (scroll_move == true && (xsrs - scroll_speed >= 0))
                    {
                        xsrs -= scroll_speed;
                        min_x -= scroll_speed;
                    }
                }
            }
            //up and down
            if (ysrs - scroll_speed >= 0 && h.y < this.ClientSize.Height / 2 && h.health > 0)
            {
                ysrs -= scroll_speed;
            }
            if ((ysrs + hsrs) < 1080 && h.y > this.ClientSize.Height / 2 && h.health > 0)
            {
                ysrs += scroll_speed;
            }
        }

        //tiles
        void createTiles()
        {
            int tilex = 50 + xsrs, tiley = this.ClientSize.Height - 63 + ysrs;
            for (int i = 0; i < 5; i++)
            {
                self_node t = new self_node();
                t.im = new Bitmap("tile1.jpg");
                t.x = tilex;
                t.y = tiley;
                t.nTiles = 3;
                t.wholew = t.nTiles * t.im.Width;
                t.dx = 0;
                t.dy = -1;
                t.speed = 10;
                t.obj_touch = false;
                tiles.Add(t);
                tilex += 1400;
                tiley -= 200;
            }
        }
        void move_tiles()
        {
            hero h = heros[0];
            for (int i = 0; i < tiles.Count; i++)
            {
                self_node t = tiles[i];
                t.x += t.dx * t.speed;
                t.y += t.dy * t.speed;
                if (h.ontile == true && h.tile == i)
                {
                    h.x += t.dx * t.speed;
                    h.y += t.dy * t.speed;
                }
                if (t.dy == 1)
                {
                    if (t.y - ysrs + t.im.Height >= this.ClientSize.Height)
                    {
                        t.dy = -1;
                    }
                }
                else
                {
                    if (t.dy == -1)
                    {
                        if (t.y - ysrs <= 200)
                        {
                            t.dy = 1;
                        }
                    }
                }
            }
        }
        int touch_tile()
        {
            hero h = heros[0];
            for (int i = 0; i < tiles.Count; i++)
            {
                self_node t = tiles[i];
                if (h.x >= t.x - xsrs
                 && h.x < t.x + t.wholew - xsrs
                 && h.y + hh >= t.y - ysrs - hh
                 && h.y + hh <= t.y - ysrs
                  )
                {
                    h.tile = i;
                    return i;
                }
            }
            return -1;
        }
        void check_touch()
        {
            hero h = heros[0];
            self_node t = tiles[h.tile];
            if (h.x < t.x - xsrs
                || h.x > t.x + t.wholew - xsrs
                //|| h.y + hh >= t.y - ysrs - hh
                //|| h.y + hh <= t.y - ysrs
                )
            {
                h.ontile = false;
                h.tile = -1;
            }
        }

        //game over & win
        void gameOver()
        {
            if (game_over_y > this.ClientSize.Height / 2)
                game_over_y -= 20;
        }
        void gameWin()
        {
            if (game_win_y > this.ClientSize.Height / 2)
                game_win_y -= 20;
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            hero h = heros[0];
            if (h.rdief == false && h.ldief == false && killcot < tokill)
            {
                switch (e.KeyCode)
                {
                    case Keys.W://Up
                        set_true_others_false('w');
                        break;
                    case Keys.S://down
                        if (h.rjumpf == false && h.ljumpf == false)
                            set_true_others_false('s');
                        break;
                    case Keys.A://Left
                        if (h.rjumpf == false && h.ljumpf == false)
                        {
                            h.dir = 'l';
                            set_true_others_false('a');
                        }
                        if (h.ljumpf == true)
                            h.move_jump_l = true;
                        if (h.rjumpf == true)
                            h.move_jump_l = true;
                        break;
                    case Keys.D://Right
                        if (h.rjumpf == false && h.ljumpf == false)
                        {
                            h.dir = 'r';
                            set_true_others_false('d');
                        }
                        if (h.ljumpf == true)
                            h.move_jump_r = true;
                        if (h.rjumpf == true)
                            h.move_jump_r = true;
                        break;
                    case Keys.J://Attack
                        if (h.rjumpf == false && h.ljumpf == false)
                        {
                            set_true_others_false('j');
                            hero_attack();
                        }
                        break;
                    case Keys.K://Fire bullets
                        if (h.rjumpf == false && h.ljumpf == false && (h.rstandf == true || h.lstandf == true) && (h.rsitf == false || h.lsitf == false))
                            set_true_others_false('k');
                        if (get_coin == false)
                            createHeroBullet();
                        else
                            createBigBullet();
                        break;
                }
            }
        }

        private void Form1_KeyUp(object sender, KeyEventArgs e)
        {
            hero h = heros[0];
            if (h.rdief == false && h.ldief == false && killcot < tokill)
            {
                switch (e.KeyCode)
                {
                    case Keys.W://up
                        //set_true_others_false(']');
                        break;
                    case Keys.S://Down
                        if (h.rjumpf == false && h.ljumpf == false)
                            set_true_others_false(']');
                        break;
                    case Keys.A://Left
                        if (h.rjumpf == false && h.ljumpf == false)
                            set_true_others_false(']');
                        h.move_jump_r = false;
                        h.move_jump_l = false;
                        h.lr = 0;
                        scroll_move = false;
                        break;
                    case Keys.D://Right
                        if (h.rjumpf == false && h.ljumpf == false)
                            set_true_others_false(']');
                        h.move_jump_r = false;
                        h.move_jump_l = false;
                        h.rr = 0;
                        scroll_move = false;
                        break;
                    case Keys.J://attack
                        if (h.rjumpf == false && h.ljumpf == false)
                            set_true_others_false(']');
                        break;
                    case Keys.K://Fire
                        if (h.rjumpf == false && h.ljumpf == false && h.rrunf == false && h.lrunf == false && h.rsitf == false && h.lsitf == false)
                            set_true_others_false(']');
                        break;
                }
            }
        }
    }
}
