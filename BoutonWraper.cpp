#include "BoutonWraper.h"
#include <sstream>

SDL_Color textColor{225,225,225,0};
SDL_Color textColor2{10,10,10,0};

BoutonWraper::BoutonWraper(SDL_Renderer* renderer, functions* toolbox, Settings* settings):
  renderer(renderer),
  toolbox(toolbox),
  settings(settings)
{
}


void BoutonWraper::generate(){

    const std::string PNG_PATH = "PNG/";


    SDL_Texture* textEvaporation = toolbox->loadTextureFromText("Duree Pheromones",textColor);
    SDL_Texture* textEvaporation2 = toolbox->loadTextureFromText("Duree Pheromones",textColor2);
    SDL_Texture* textConso = toolbox->loadTextureFromText("Consomation nourriture",textColor);
    SDL_Texture* textConso2 = toolbox->loadTextureFromText("Consomation nourriture",textColor2);
    SDL_Texture* textRandom = toolbox->loadTextureFromText("Taux de random",textColor);
    SDL_Texture* textRandom2 = toolbox->loadTextureFromText("Taux de random",textColor2);

    instructions.push_back(toolbox->loadTextureFromText("[C] - Creer colonie",textColor2));
    instructions.push_back(toolbox->loadTextureFromText("[C] - Creer colonie",textColor));
    instructions.push_back(toolbox->loadTextureFromText("[M] - Creer Miel",textColor2));
    instructions.push_back(toolbox->loadTextureFromText("[M] - Creer Miel",textColor));
    instructions.push_back(toolbox->loadTextureFromText("[W] - Creer Mur",textColor2));
    instructions.push_back(toolbox->loadTextureFromText("[W] - Creer Mur",textColor));
    instructions.push_back(toolbox->loadTextureFromText("[A] - Activer/Stopper fourmis",textColor2));
    instructions.push_back(toolbox->loadTextureFromText("[A] - Activer/Stopper fourmis",textColor));
    instructions.push_back(toolbox->loadTextureFromText("[D] - Supprimer murs",textColor2));
    instructions.push_back(toolbox->loadTextureFromText("[D] - Supprimer murs",textColor));
    instructions.push_back(toolbox->loadTextureFromText("[X] - Reset",textColor2));
    instructions.push_back(toolbox->loadTextureFromText("[X] - Reset",textColor));

    boutonsTitre.push_back(textEvaporation2);
    boutonsTitre.push_back(textEvaporation);
    boutonsTitre.push_back(textConso2);
    boutonsTitre.push_back(textConso);
    boutonsTitre.push_back(textRandom2);
    boutonsTitre.push_back(textRandom);

    updateBoutonsValeurs();

    Bouton* evaporationPhromnesP = new Bouton(&(settings->tauxEvaPheromones));
    evaporationPhromnesP->setToolbox(toolbox);
    evaporationPhromnesP->configure(true);
    evaporationPhromnesP->loadTexture(PNG_PATH + "boutonPlus.png");
    evaporationPhromnesP->setValuesModifications(100,5,5);
    SDL_Rect diffuseLocationP;
    diffuseLocationP.h = 28;
    diffuseLocationP.w = 28;
    diffuseLocationP.x = 450;
    diffuseLocationP.y = 50;
    evaporationPhromnesP->setLocation(diffuseLocationP);

    Bouton* evaporationPhromnesM = new Bouton(&(settings->tauxEvaPheromones));
    evaporationPhromnesM->setToolbox(toolbox);
    evaporationPhromnesM->configure(false);
    evaporationPhromnesM->loadTexture(PNG_PATH + "boutonMoins.png");
    evaporationPhromnesM->setValuesModifications(100,0,5);
    SDL_Rect diffuseLocationM = diffuseLocationP;
    diffuseLocationM.x = diffuseLocationP.x + 100;
    evaporationPhromnesM->setLocation(diffuseLocationM);

    Bouton* consumationT = new Bouton(&(settings->foodConsume));
    consumationT->setToolbox(toolbox);
    consumationT->configure(true);
    consumationT->loadTexture(PNG_PATH + "boutonTrue.png");
    consumationT->setValuesModifications(1,0,1);
    SDL_Rect consomationLocationT = diffuseLocationP;
    consomationLocationT.y = diffuseLocationP.y + 50;
    consumationT->setLocation(consomationLocationT);

    Bouton* consumationF = new Bouton(&(settings->foodConsume));
    consumationF->setToolbox(toolbox);
    consumationF->configure(false);
    consumationF->loadTexture(PNG_PATH + "boutonFalse.png");
    consumationF->setValuesModifications(1,0,1);
    SDL_Rect consomationLocationF = diffuseLocationM;
    consomationLocationF.y = diffuseLocationM.y + 50;
    consumationF->setLocation(consomationLocationF);

    Bouton* tauxRandomP = new Bouton(&(settings->randomFourmis));
    tauxRandomP->setToolbox(toolbox);
    tauxRandomP->configure(true);
    tauxRandomP->loadTexture(PNG_PATH + "boutonPlus.png");
    tauxRandomP->setValuesModifications(1000,0,50);
    SDL_Rect tauxRandomLocationP = consomationLocationT;
    tauxRandomLocationP.y = consomationLocationT.y + 50;
    tauxRandomP->setLocation(tauxRandomLocationP);

    Bouton* tauxRandomM = new Bouton(&(settings->randomFourmis));
    tauxRandomM->setToolbox(toolbox);
    tauxRandomM->configure(false);
    tauxRandomM->loadTexture(PNG_PATH + "boutonMoins.png");
    tauxRandomM->setValuesModifications(1000,0,50);
    SDL_Rect tauxRandomLocationM = consomationLocationF;
    tauxRandomLocationM.y = consomationLocationF.y + 50;
    tauxRandomM->setLocation(tauxRandomLocationM);


    boutons.push_back(evaporationPhromnesP);
    boutons.push_back(evaporationPhromnesM);
    boutons.push_back(consumationT);
    boutons.push_back(consumationF);
    boutons.push_back(tauxRandomP);
    boutons.push_back(tauxRandomM);

}

void BoutonWraper::draw(){
    bool ombre = true;
    std::list<SDL_Texture*>::const_iterator itText = boutonsTitre.begin();
    for (std::list<Bouton*>::const_iterator it = boutons.begin(), end = boutons.end(); it != end; ++it,++itText) {
        (*it)->draw(renderer);
        if(ombre){
            toolbox->renderTexture(*itText,NULL,32,(*it)->location.y+1);
            ombre = false;
        }else{
            toolbox->renderTexture(*itText,NULL,30,(*it)->location.y);
            ombre = true;
        }

    }
    int posYinstuctions = 340;
    ombre = true;
    for (std::list<SDL_Texture*>::const_iterator it = instructions.begin(), end = instructions.end(); it != end; ++it) {
        if(ombre){
            toolbox->renderTexture(*it,NULL,32,posYinstuctions+1);
            ombre = false;

        }else{
            toolbox->renderTexture(*it,NULL,30,posYinstuctions);
            ombre = true;
            posYinstuctions+=40;
        }
    }
    drawBoutonsValeurs();
}

void BoutonWraper::handleClic(int x, int y){
    for (std::list<Bouton*>::const_iterator it = boutons.begin(), end = boutons.end(); it != end; ++it) {
        if((*it)->hit(x,y)){
            (*it)->activate();
            updateBoutonsValeurs();
            break;
        }
    }
}

string BoutonWraper::itoa(int n){
    std::ostringstream stm ;
    stm << n ;
    return stm.str();
}

void BoutonWraper::updateBoutonsValeurs(){
    boutonsValeurs.clear();
    boutonsValeurs.push_back(toolbox->loadTextureFromText(itoa(settings->tauxEvaPheromones),textColor));
    string foodConsume = "Off";
    if(settings->foodConsume == 1)foodConsume = "On";
    boutonsValeurs.push_back(toolbox->loadTextureFromText(foodConsume,textColor));
    boutonsValeurs.push_back(toolbox->loadTextureFromText(itoa((settings->randomFourmis)/10),textColor));
}

int BoutonWraper::setXposValeurBouton(int valeur){
    if(valeur<10){
        return 505;
    }else if(valeur<100){
        return 500;
    }
    return 490;
}

void BoutonWraper::drawBoutonsValeurs(){
    int posYboutonsValeurs = 50;
    int posXboutonsValeurs = 500;
    std::list<SDL_Texture*>::const_iterator it = boutonsValeurs.begin();
    posXboutonsValeurs = setXposValeurBouton(settings->tauxEvaPheromones);
    toolbox->renderTexture(*it,NULL,posXboutonsValeurs,posYboutonsValeurs);
    posYboutonsValeurs+=50;
    ++it;
    if(settings->foodConsume == 1){
        posXboutonsValeurs = 500;
    }else{
        posXboutonsValeurs = 490;
    }
    toolbox->renderTexture(*it,NULL,posXboutonsValeurs,posYboutonsValeurs);
    posYboutonsValeurs+=50;
    ++it;
    posXboutonsValeurs = setXposValeurBouton((settings->randomFourmis)/10);
    toolbox->renderTexture(*it,NULL,posXboutonsValeurs,posYboutonsValeurs);
    posYboutonsValeurs+=50;
    ++it;
}
