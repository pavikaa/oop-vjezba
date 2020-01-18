//Napravite igru križić-kružić(iks-oks) korištenjem znanja stečenih na ovoj
//laboratorijskoj vježbi.Omogućiti pokretanje igre, unos imena dvaju igrača, ispis
//koji igrač je trenutno na potezu, igranje igre s iscrtavanjem križića i kružića na
//odgovarajućim mjestima te ispis dijaloga s porukom o pobjedi, odnosno
//neriješenom rezultatu kao i praćenje ukupnog rezultata.
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LV7_analizaa
{
    public partial class Form1 : Form
    {
        string playerOne, playerTwo;
        bool turn = true;
        bool check = false;
        int counter =0;
        int firstPlayerWins = 0;
        int secondPlayerWins = 0;
        private void start_Click(object sender, EventArgs e)
        {
            if (tB1.Text != "" && tB2.Text != "")
            {
                playerOne = tB1.Text;
                playerTwo = tB2.Text;
                check = true;
                onTurn.Text = playerOne;
            }
        }

        private void button_click(object sender, EventArgs e)
        {
            if(check)
            {
                Button b = (Button)sender;
                if(turn)
                {
                    onTurn.Text = playerTwo;
                    b.Text = "X";
                    turn = !turn;
                   
                }
                else
                {
                    onTurn.Text = playerOne;
                    b.Text = "O";
                    turn = !turn;
                }
                b.Enabled = false;
                counter++;
                checkWin();
            }
            else
                MessageBox.Show("Molim unesite imena igrača i stisnite Pokreni.");
        }
        public void checkWin()
        {
            if((A1.Text==A2.Text)&&(A1.Text==A3.Text)&&!A1.Enabled&&!A2.Enabled&&!A3.Enabled)
            {
                if (turn)
                {
                    MessageBox.Show("Pobjednik je:" + playerTwo);
                    secondPlayerWins++;
                }
                else
                {
                    MessageBox.Show("Pobjednik je:" + playerOne);
                    firstPlayerWins++;
                }
                firstPlayerResult.Text = firstPlayerWins.ToString();
                secondPlayerResult.Text = secondPlayerWins.ToString();
                B1.Enabled = false;
                B2.Enabled = false;
                B3.Enabled = false;
                C1.Enabled = false;
                C2.Enabled = false;
                C3.Enabled = false;
            }
            else if ((B1.Text == B2.Text) && (B1.Text == B3.Text) && !B1.Enabled && !B2.Enabled && !B3.Enabled)
            {
                if (turn)
                {
                    MessageBox.Show("Pobjednik je:" + playerTwo);
                    secondPlayerWins++;
                }
                else
                {
                    MessageBox.Show("Pobjednik je:" + playerOne);
                    firstPlayerWins++;
                }
                firstPlayerResult.Text = firstPlayerWins.ToString();
                secondPlayerResult.Text = secondPlayerWins.ToString();
                A1.Enabled = false;
                A2.Enabled = false;
                A3.Enabled = false;
                C1.Enabled = false;
                C2.Enabled = false;
                C3.Enabled = false;
            }
            else if ((C1.Text == C2.Text) && (C1.Text == C3.Text) && !C1.Enabled && !C2.Enabled && !C3.Enabled)
            {
                if (turn)
                {
                    MessageBox.Show("Pobjednik je:" + playerTwo);
                    secondPlayerWins++;
                }
                else
                {
                    MessageBox.Show("Pobjednik je:" + playerOne);
                    firstPlayerWins++;
                }
                firstPlayerResult.Text = firstPlayerWins.ToString();
                secondPlayerResult.Text = secondPlayerWins.ToString();
                B1.Enabled = false;
                B2.Enabled = false;
                B3.Enabled = false;
                A1.Enabled = false;
                A2.Enabled = false;
                A3.Enabled = false;
            }
            else if ((A1.Text == B1.Text) && (A1.Text == C1.Text) && !A1.Enabled && !B1.Enabled && !C1.Enabled)
            {
                if (turn)
                {
                    MessageBox.Show("Pobjednik je:" + playerTwo);
                    secondPlayerWins++;
                }
                else
                {
                    MessageBox.Show("Pobjednik je:" + playerOne);
                    firstPlayerWins++;
                }
                firstPlayerResult.Text = firstPlayerWins.ToString();
                secondPlayerResult.Text = secondPlayerWins.ToString();
                A2.Enabled = false;
                B2.Enabled = false;
                C2.Enabled = false;
                A3.Enabled = false;
                B3.Enabled = false;
                C3.Enabled = false;
            }
            else if ((A2.Text == B2.Text) && (A2.Text == C2.Text) && !A2.Enabled && !B2.Enabled && !C2.Enabled)
            {
                if (turn)
                {
                    MessageBox.Show("Pobjednik je:" + playerTwo);
                    secondPlayerWins++;
                }
                else
                {
                    MessageBox.Show("Pobjednik je:" + playerOne);
                    firstPlayerWins++;
                }
                firstPlayerResult.Text = firstPlayerWins.ToString();
                secondPlayerResult.Text = secondPlayerWins.ToString();
                A1.Enabled = false;
                B1.Enabled = false;
                C1.Enabled = false;
                A3.Enabled = false;
                B3.Enabled = false;
                C3.Enabled = false;
            }
            else if ((A3.Text == B3.Text) && (A3.Text == C3.Text) && !A3.Enabled && !B3.Enabled && !C3.Enabled)
            {
                if (turn)
                {
                    MessageBox.Show("Pobjednik je:" + playerTwo);
                    secondPlayerWins++;
                }
                else
                {
                    MessageBox.Show("Pobjednik je:" + playerOne);
                    firstPlayerWins++;
                }
                firstPlayerResult.Text = firstPlayerWins.ToString();
                secondPlayerResult.Text = secondPlayerWins.ToString();
                A2.Enabled = false;
                B2.Enabled = false;
                C2.Enabled = false;
                A1.Enabled = false;
                B1.Enabled = false;
                C1.Enabled = false;
            }
            else if ((A1.Text == B2.Text) && (A1.Text == C3.Text) && !A1.Enabled && !B2.Enabled && !C3.Enabled)
            {
                if (turn)
                {
                    MessageBox.Show("Pobjednik je:" + playerTwo);
                    secondPlayerWins++;
                }
                else
                {
                    MessageBox.Show("Pobjednik je:" + playerOne);
                    firstPlayerWins++;
                }
                firstPlayerResult.Text = firstPlayerWins.ToString();
                secondPlayerResult.Text = secondPlayerWins.ToString();
                A2.Enabled = false;
                A3.Enabled = false;
                B1.Enabled = false;
                B3.Enabled = false;
                C1.Enabled = false;
                C2.Enabled = false;
            }
            else if ((A3.Text == B2.Text) && (A3.Text == C1.Text) && !A3.Enabled && !B2.Enabled && !C1.Enabled)
            {
                if (turn)
                {
                    MessageBox.Show("Pobjednik je:" + playerTwo);
                    secondPlayerWins++;
                }
                else
                {
                    MessageBox.Show("Pobjednik je:" + playerOne);
                    firstPlayerWins++;
                }
                firstPlayerResult.Text = firstPlayerWins.ToString();
                secondPlayerResult.Text = secondPlayerWins.ToString();
                A1.Enabled = false;
                A2.Enabled = false;
                B1.Enabled = false;
                B3.Enabled = false;
                C2.Enabled = false;
                C3.Enabled = false;
            }
            else if(counter==9)
                MessageBox.Show("Nerijeseno je.");

        }
        private void close_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void restart_Click(object sender, EventArgs e)
        {
            
            counter = 0;
            A1.Enabled = true;
            A2.Enabled = true;
            A3.Enabled = true;
            B1.Enabled = true;
            B2.Enabled = true;
            B3.Enabled = true;
            C1.Enabled = true;
            C2.Enabled = true;
            C3.Enabled = true;
            A1.Text = "";
            A2.Text = "";
            A3.Text = "";
            B1.Text = "";
            B2.Text = "";
            B3.Text = "";
            C1.Text = "";
            C2.Text = "";
            C3.Text = "";
        }

        public Form1()
        {
            InitializeComponent();
        }
    }
}
