#pragma once


class Converter {
    public:
        virtual ~Converter() {};
        virtual void converting() = 0;
};

class Mute : public Converter {
    public:
        void converting();
};

class Mix : public Converter {
    public:
        void converting();
};

class Creator {
    public:
        virtual Converter *createConverter() = 0;
};

class CreatorMute : Creator {
    public:
        Converter *createConverter() {return new Mute();}
};

class CreatorMix : Creator {
    public:
        Converter *createConverter() {return new Mix();}
};