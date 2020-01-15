using System;
using System.Collections.Generic;

namespace LV7_Zad_1
{
    class Program
    {
        static void Main(string[] args)
        {
            List<IPayable> accountList= new List<IPayable>();
            BankAccount bankAccount = new BankAccount(1500, 1000, "Visa");
            BankAccount bankAccount2 = new BankAccount(1950, 3000, "American");
            MobileAccount mobileAccount = new MobileAccount("+385950000000", 57.5, 0.50);
            MobileAccount mobileAccount2 = new MobileAccount("+385950000001", 67.5, 0.40);
            Random random = new Random();
            accountList.Add(bankAccount);
            accountList.Add(bankAccount2);
            accountList.Add(mobileAccount);
            accountList.Add(mobileAccount2);
            foreach(IPayable account in accountList)
            {
                Console.WriteLine(account.getIznos() + "\t");
                account.addToIznos(random.Next(1,10));
                Console.WriteLine(account.getIznos() + "\t");
                account.subtractFromIznos(random.Next(1, 10));
                Console.WriteLine(account.getIznos()+"\t");
                Console.WriteLine("\n");
            }
        }
        class BankAccount:IPayable
        {
            double iznos;
            double maxMinus;
            string ime;

            public BankAccount(double iznos, double maxMinus, string ime)
            {
                this.iznos = iznos;
                this.maxMinus = maxMinus;
                this.ime = ime;
            }
            public double getIznos()
            {
                return this.iznos;
            }
            public void addToIznos(double iznos)
            {
                this.iznos += iznos;
            }
            public void subtractFromIznos(double iznos)
            {
                if(iznos<=(this.iznos+this.maxMinus))
                this.iznos -= iznos;
            }
        }
        class MobileAccount:IPayable
        {
            string broj;
            double stanje;
            double cijenaSMS;
            public MobileAccount(string broj, double stanje, double cijenaSMS)
            {
                this.broj = broj;
                this.stanje = stanje;
                this.cijenaSMS = cijenaSMS;
                
            }
            public double getIznos()
            {
                return this.stanje;
            }
            public void addToIznos(double iznos)
            {
                this.stanje += iznos;
            }
            public void subtractFromIznos(double iznos)
            {
                if(iznos<=this.stanje)
                this.stanje -= iznos;
            }
        }
        interface IPayable
        {
            double getIznos();
            void addToIznos(double iznos);
            void subtractFromIznos(double iznos);
        }
    }
}
