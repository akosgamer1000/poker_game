
#include "widgets.hpp"
#include "base.hpp"
#include <algorithm>
#include <random>
#include <vector>
#include <map>
#include <string>
#include "imagewiewer.h"
#include "button.h"

#include "statictext.h"
#include "numberinput.hpp"

using namespace std;
using namespace genv;

struct Card {
    int rank;
    int suit;
};

class Myapp;

class JatekMester {
private:
    vector<string> deck;
    vector<string> hand;
    int ph;
    int bet_amount;
    Myapp* gui;

    void filldeck() {
        deck.clear();
        string szinek[] = {"C", "D", "H", "S"};
        string ertekek[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 13; j++) {
                deck.push_back(szinek[i] + ertekek[j]);
            }
        }
    }

    void kever() {
        static std::random_device rd;
        static std::mt19937 g(rd());
        std::shuffle(deck.begin(), deck.end(), g);
    }

    string draw_card() {
        if (deck.empty()) return "C5";
        string card = deck.back();
        deck.pop_back();
        return card;
    }

    int szorzo(string hand_type) {
        if (hand_type == "Szinsor") return 100;
        if (hand_type == "Poker") return 25;
        if (hand_type == "Full House") return 9;
        if (hand_type == "Floss") return 6;
        if (hand_type == "Sor") return 4;
        if (hand_type == "Terc") return 3;
        if (hand_type == "Ket par") return 2;
        if (hand_type == "Egy par") return 1;
        return 0;
    }

public:
    JatekMester(){
        ph = 1;
        bet_amount = 0;
        gui = nullptr;
    }





    void init_game() {
        filldeck();
        kever();
        hand.clear();
        ph = 1;
        bet_amount = 0;
    }

    void run();

    void start_draw_phase(int current_bet) {
        bet_amount = current_bet;
        hand.clear();
        for (int i = 0; i < 5; i++) {
            hand.push_back(draw_card());
        }
        ph = 2;
    }

    void start_change_phase(const vector<bool>& change) {
        for (int i = 0; i < 5; i++) {
            if (change[i]) {
                hand[i] = draw_card();
            }
        }
        ph = 3;
    }

    string result() {
        vector<Card> cr;


        for(string s : hand){
            int szin = s[0];
            string ertek_str = s.substr(1);

            int ertek = 0;
            if (ertek_str == "J") ertek = 11;
            else if (ertek_str == "Q") ertek = 12;
            else if (ertek_str == "K") ertek = 13;
            else if (ertek_str == "A") ertek = 14;
            else ertek = stoi(ertek_str);
            cr.push_back({ertek, szin});
        }


        sort(cr.begin(), cr.end(), [](const Card& a, const Card& b) {
            return a.rank < b.rank;
        });

        map<int, int> counts;
        for(auto c : cr){
            counts[c.rank]++;
        }

        vector<int> v;
        for(auto const& [rank, count] : counts) {
            v.push_back(count);
        }
        sort(v.rbegin(), v.rend());

        bool egyformaSzin = true;
        for(int i = 1; i < 5; i++) {
            if(cr[i].suit != cr[0].suit) egyformaSzin = false;
        }

        bool sor = true;
        for(int i = 0; i < 4; i++) {
            if(cr[i+1].rank != cr[i].rank + 1) sor = false;
        }

        if (sor && egyformaSzin) return "Szinsor";
        if (v[0] == 4)           return "Poker";
        if (v[0] == 3 && v[1] == 2) return "Full House";
        if (egyformaSzin)        return "Floss";
        if (sor)                 return "Sor";
        if (v[0] == 3)           return "Terc";
        if (v[0] == 2 && v[1] == 2) return "Ket par";
        if (v[0] == 2)           return "Egy par";
        return "Magas lap";
    }

    int get_winnings() {
        return bet_amount * szorzo(result());
    }

    int get_phase() const { return ph; }
    vector<string> get_hand() const { return hand; }
};



class Myapp : public Base {
private:
    JatekMester* jatekMester;

    int b_p;
    int button_ofset;

    imagewiewer *image1, *image2, *image3, *image4, *image5;
    Button *b1, *b2, *b3, *b4, *b5;
    Button *phase_btn;
    Number_input *bet_input;
    statictext* tx;

    vector<imagewiewer*> hand_widgets;
    vector<Button*> card_buttons;


    void card_button_pressed(Button* b, imagewiewer* w) {
        if (w->getCere()) {
            w->setCere(false);
            b->setTtext("hold");
        } else {
            w->setCere(true);
            b->setTtext("drop");
        }
    }

    void next_step() {
        int aktualis_fazis = jatekMester->get_phase();
        int current_bet = bet_input->get_number();
        if (aktualis_fazis == 1) {
            if (current_bet <= 0) {
                tx->setContent("Kerlek tegy meg egy tetet! (Min. 1)");
                return;
            }
            jatekMester->start_draw_phase(current_bet);
        }
        else if (aktualis_fazis == 2) {
            vector<bool> cserelendok(5, false);
            for (int i = 0; i < 5; i++) {
                if (hand_widgets[i]->getCere()) {
                    cserelendok[i] = true;
                }
            }
            jatekMester->start_change_phase(cserelendok);

        }
        else {
            jatekMester->init_game();
        }

        update_ui();
    }

public:
    Myapp(int _w, int _h, JatekMester* jm) : Base(_w, _h) {
        jatekMester = jm;
        b_p = 370;
        button_ofset = 30;
        int text_width = 300;

        image1 = new imagewiewer(this, 50,  300, 40, 50, "C5.bmp.kep");
        image2 = new imagewiewer(this, 150, 300, 40, 50, "C5.bmp.kep");
        image3 = new imagewiewer(this, 250, 300, 40, 50, "C5.bmp.kep");
        image4 = new imagewiewer(this, 350, 300, 40, 50, "C5.bmp.kep");
        image5 = new imagewiewer(this, 450, 300, 40, 50, "C5.bmp.kep");

        tx = new statictext(this, (_w - text_width) / 2, 100, text_width, 20);

        hand_widgets.push_back(image1);
        hand_widgets.push_back(image2);
        hand_widgets.push_back(image3);
        hand_widgets.push_back(image4);
        hand_widgets.push_back(image5);

        b1 = new Button(this,  50 - button_ofset, b_p, 40, 30, [=](){ card_button_pressed(b1, image1); }, "hold");
        b2 = new Button(this, 150 - button_ofset, b_p, 40, 30, [=](){ card_button_pressed(b2, image2); }, "hold");
        b3 = new Button(this, 250 - button_ofset, b_p, 40, 30, [=](){ card_button_pressed(b3, image3); }, "hold");
        b4 = new Button(this, 350 - button_ofset, b_p, 40, 30, [=](){ card_button_pressed(b4, image4); }, "hold");
        b5 = new Button(this, 450 - button_ofset, b_p, 40, 30, [=](){ card_button_pressed(b5, image5); }, "hold");

        card_buttons.push_back(b1);
        card_buttons.push_back(b2);
        card_buttons.push_back(b3);
        card_buttons.push_back(b4);
        card_buttons.push_back(b5);

        phase_btn = new Button(this, 500, b_p, 60, 30, [=](){ next_step(); }, "draw");
        bet_input = new Number_input(this, 500, b_p - 40, 70, 30, 0, 1000);
    }

    void action(string id) override {}

    void update_ui() {
        int aktualis_fazis = jatekMester->get_phase();
        vector<string> aktualis_lapok = jatekMester->get_hand();

        if (aktualis_fazis == 1) {
            tx->setContent("bet phase");
            phase_btn->setTtext("draw");
            bet_input->set_number(0);


            for (size_t i = 0; i < hand_widgets.size(); i++) {
                hand_widgets[i]->setVisibility(false);
                hand_widgets[i]->setCere(false);
                card_buttons[i]->setActiv(false);
                card_buttons[i]->setVisibility(false);
                card_buttons[i]->setTtext("hold");
            }
        }
        else if (aktualis_fazis == 2) {
            tx->setContent("drop phase");
            phase_btn->setTtext("change");

            for (size_t i = 0; i < hand_widgets.size(); i++) {
                hand_widgets[i]->setSource(aktualis_lapok[i] + ".bmp.kep");
                hand_widgets[i]->setVisibility(true);
                card_buttons[i]->setActiv(true);
                card_buttons[i]->setVisibility(true);
                card_buttons[i]->setTtext("hold");
            }
        }
        else if (aktualis_fazis == 3) {
            for (size_t i = 0; i < hand_widgets.size(); i++) {
                hand_widgets[i]->setSource(aktualis_lapok[i] + ".bmp.kep");
                card_buttons[i]->setActiv(false);
                card_buttons[i]->setTtext("hold");

            }

            string res = jatekMester->result();
            int nyeremeny = jatekMester->get_winnings();
            tx->setContent(res + " nyeremeny:" + to_string(nyeremeny));
            phase_btn->setTtext("new game");
        }
    }
};


void JatekMester::run() {
    gui = new Myapp(600, 400, this);
    init_game();
    gui->update_ui();
    gui->opengui();
    gui->event_loop();
}

int main() {
    JatekMester jatek;
    jatek.run();
    return 0;
}
