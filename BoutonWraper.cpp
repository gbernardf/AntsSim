#include "BoutonWraper.h"

BoutonWraper::BoutonWraper(SDL_Renderer* renderer, functions* toolbox, Settings* settings){
    this->settings = settings;
    this->renderer = renderer;
    this->toolbox = toolbox;
}


void BoutonWraper::generate(){

    const std::string PNG_PATH = "../PNGs_Ants/";

    SDL_Color textColor{225,225,225};
    SDL_Color textColor2{10,10,10};
    SDL_Texture* textDiffuse = toolbox->loadTextureFromText("Duree Pheromones",textColor);
    SDL_Texture* textDiffuse2 = toolbox->loadTextureFromText("Duree Pheromones",textColor2);
    SDL_Texture* textConso = toolbox->loadTextureFromText("Consomation nourriture",textColor);
    SDL_Texture* textConso2 = toolbox->loadTextureFromText("Consomation nourriture",textColor2);
    SDL_Texture* textRandom = toolbox->loadTextureFromText("Taux de random",textColor);
    SDL_Texture* textRandom2 = toolbox->loadTextureFromText("Taux de random",textColor2);

    instructions.push_back(toolbox->loadTextureFromText("[C] - Creer colony",textColor2));
    instructions.push_back(toolbox->loadTextureFromText("[C] - Creer colony",textColor));
    instructions.push_back(toolbox->loadTextureFromText("[M] - Creer Miel",textColor2));
    instructions.push_back(toolbox->loadTextureFromText("[M] - Creer Miel",textColor));
    instructions.push_back(toolbox->loadTextureFromText("[W] - Creer Mur",textColor2));
    instructions.push_back(toolbox->loadTextureFromText("[W] - Creer Mur",textColor));
    instructions.push_back(toolbox->loadTextureFromText("[A] - Activer/Stopper fourmis",textColor2));
    instructions.push_back(toolbox->loadTextureFromText("[A] - Activer/Stopper fourmis",textColor));

    boutonsTitre.push_back(textDiffuse2);
    boutonsTitre.push_back(textDiffuse);
    boutonsTitre.push_back(textConso2);
    boutonsTitre.push_back(textConso);
    boutonsTitre.push_back(textRandom2);
    boutonsTitre.push_back(textRandom);

    Bouton* dissipationPhromnesP = new Bouton(&(settings->tauxEvaPheromones));
    dissipationPhromnesP->setUp(true);
    dissipationPhromnesP->setToolbox(toolbox);
    dissipationPhromnesP->loadTexture(PNG_PATH + "boutonPlus.png");
    dissipationPhromnesP->setValuesModifications(100,5,5);
    SDL_Rect diffuseLocationP;
    diffuseLocationP.h = 28;
    diffuseLocationP.w = 28;
    diffuseLocationP.x = 450;
    diffuseLocationP.y = 50;
    dissipationPhromnesP->setLocation(diffuseLocationP);

    Bouton* dissipationPhromnesM = new Bouton(&(settings->tauxEvaPheromones));
    dissipationPhromnesM->setUp(false);
    dissipationPhromnesM->setToolbox(toolbox);
    dissipationPhromnesM->loadTexture(PNG_PATH + "boutonMoins.png");
    dissipationPhromnesM->setValuesModifications(100,0,5);
    SDL_Rect diffuseLocationM = diffuseLocationP;
    diffuseLocationM.x = diffuseLocationP.x + 100;
    dissipationPhromnesM->setLocation(diffuseLocationM);

    Bouton* consumationT = new Bouton(&(settings->foodConsume));
    consumationT->setUp(true);
    consumationT->setToolbox(toolbox);
    consumationT->loadTexture(PNG_PATH + "boutonTrue.png");
    consumationT->setValuesModifications(1,0,1);
    SDL_Rect consomationLocationT = diffuseLocationP;
    consomationLocationT.y = diffuseLocationP.y + 50;
    consumationT->setLocation(consomationLocationT);

    Bouton* consumationF = new Bouton(&(settings->foodConsume));
    consumationF->setUp(false);
    consumationF->setToolbox(toolbox);
    consumationF->loadTexture(PNG_PATH + "boutonFalse.png");
    consumationF->setValuesModifications(1,0,1);
    SDL_Rect consomationLocationF = diffuseLocationM;
    consomationLocationF.y = diffuseLocationM.y + 50;
    consumationF->setLocation(consomationLocationF);

    Bouton* tauxRandomP = new Bouton(&(settings->randomFourmis));
    tauxRandomP->setUp(true);
    tauxRandomP->setToolbox(toolbox);
    tauxRandomP->loadTexture(PNG_PATH + "boutonPlus.png");
    tauxRandomP->setValuesModifications(1000,0,50);
    SDL_Rect tauxRandomLocationP = consomationLocationT;
    tauxRandomLocationP.y = consomationLocationT.y + 50;
    tauxRandomP->setLocation(tauxRandomLocationP);

    Bouton* tauxRandomM = new Bouton(&(settings->randomFourmis));
    tauxRandomM->setUp(false);
    tauxRandomM->setToolbox(toolbox);
    tauxRandomM->loadTexture(PNG_PATH + "boutonMoins.png");
    tauxRandomM->setValuesModifications(1000,0,50);
    SDL_Rect tauxRandomLocationM = consomationLocationF;
    tauxRandomLocationM.y = consomationLocationF.y + 50;
    tauxRandomM->setLocation(tauxRandomLocationM);


    boutons.push_back(dissipationPhromnesP);
    boutons.push_back(dissipationPhromnesM);
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
    int posYinstuctions = 400;
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

}

void BoutonWraper::handleClic(int x, int y){
    for (std::list<Bouton*>::const_iterator it = boutons.begin(), end = boutons.end(); it != end; ++it) {
        if((*it)->hit(x,y)){
            (*it)->activate();
            break;
        }
    }
}

