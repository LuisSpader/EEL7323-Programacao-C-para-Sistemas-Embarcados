class IA_Temperatura
{
private:
    /* data */
    int temperatura;
    bool IA_OK;
public:
    IA_Temperatura();
    ~IA_Temperatura();
    void Aumenta_manualmente();
    void Diminui_manualmente();
    void Monitora_temp_externa(int new_temp);
};

IA_Temperatura::IA_Temperatura(/* args */)
{
    temperatura = 1;
}

IA_Temperatura::~IA_Temperatura()
{
}

void IA_Temperatura::Aumenta_manualmente(){

}

void IA_Temperatura::Diminui_manualmente(){
    
}

void IA_Temperatura::Monitora_temp_externa(int new_temp){
    
}