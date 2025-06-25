#include"passsystem.hpp"
#include<dos.h>   //for delay()

inline float distance3D(float x1, float y1, float z1, float x2, float y2, float z2) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    float dz = z2 - z1;
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}

inline int randMToN(int M, int N)
{

    return M + (rand() / ( RAND_MAX / (N-M) ) ) ;  
}


	pass::pass(HWND hwnd){
	rand=0.0f;
	tir=false;
	timer=0.1f;	
	delay=15;
	speed=0.002f;


    zones.push_back(new Zone{ -150, 100,    -100,   100, 0,  8 });
    zones.push_back(new Zone{ -180, 0, -200,  200, 3,  9 });
    zones.push_back(new Zone{ 50, 60,  -100,   300, 2,  8 });
    zones.push_back(new Zone{  -180, 80,  -100,   400, 1, 7 });
    zones.push_back(new Zone{ 70, 150,  -100,   500, 0,  8 });
	zones.push_back(new Zone{ -50, 50,  0,   10, 1,  5 });
    zones.push_back(new Zone { -180, 60, -100,  20, 1,  8 });
    zones.push_back(new Zone { -180, 40,  70,   100, 2,  5 });
    zones.push_back(new Zone { -180, 50, 0,  80, 2,  9 });
    zones.push_back(new Zone {  -180, 20, -100,  0, 2,  7 });
    zones.push_back(new Zone { -180, 10, -100,   100, 1,  8 });
    son=new sound(hwnd);
    balleSound = son->loadSound("data/sound/balle.wav");
    
}

pass::~pass()
{
for (std::vector<Zone*>::iterator it = zones.begin(); it != zones.end(); ++it) {
    Zone* z = *it;
    delete z;
}

delete son;

if (balleSound) 
  balleSound->Release();


zones.clear();
}

void pass::update(balle* b,std::vector<robot*> player,
		std::vector<robot*> playerAI){
	
	for (std::vector<Zone*>::iterator it = zones.begin(); it != zones.end(); ++it) {
    Zone* zone = *it;
    
    for (int i = zone->playerMin; i <= zone->playerMax && i < playerAI.size(); i++)
                      {
                          robot* playerAI_ = playerAI[i];
                          if (playerAI_->gethastheball())
                          {
                              // On cherche le joueur humain le plus proche
                              robot* joueurHumainLePlusProche = NULL;
                              float inf = std::numeric_limits<float>::infinity();
                              float distanceMin = inf;

                            	for (std::vector<robot*>::iterator it = player.begin(); it != player.end(); ++it) {
    							  robot* playerHumain = *it;
                                  float distHumainAI = distance3D(playerAI_->getLocation().x,playerAI_->getLocation().y,playerAI_->getLocation().z, playerHumain->getLocation().x,
								  playerHumain->getLocation().y,playerHumain->getLocation().z);
                                  if (distHumainAI < distanceMin)
                                  {
                                      distanceMin = distHumainAI;
                                      joueurHumainLePlusProche = playerHumain;
                                  }
                          }

                        

                                // Si un joueur humain est assez proche (par exemple moins de 3 unités)
                                if (joueurHumainLePlusProche != NULL && distanceMin < 50.0f)
                                {
                                	
                                  //  PlaySound(TEXT("data/sound/balle.wav"), NULL, SND_FILENAME | SND_ASYNC);
                                    // Alors on fait une passe du joueurAI vers un autre joueurAI dans la même zone
                                    balleSound->SetCurrentPosition(0);
        							balleSound->Play(0, 0, 0);
                                    PasserAI(playerAI,playerAI_, zone->xMin, zone->xMax, zone->zMin, zone->zMax, b);
                                }
                              
                            }
                          }
                      
          }
            
            
	}
	


   
void pass::PasserAI(std::vector<robot*>playerAI,robot* player, float xmin, float xmax, float zmin, float zmax, balle* b){
	
   		D3DXVECTOR3 pos = player->getLocation();

    if (pos.x > xmin && pos.x < xmax && pos.z > zmin && pos.z < zmax) {
        // Vérifie s'il y a un coéquipier trop proche
        for (size_t i = 0; i < playerAI.size(); ++i) {
            robot* other = playerAI[i];
            if (other != player) {
                float dist = distance3D(pos.x, pos.y, pos.z, other->getLocation().x, other->getLocation().y, other->getLocation().z);
                if (dist < 20.0f) { // Seuil de proximité à ajuster
                    std::cout << "Un coéquipier est trop proche, pas de passe.\n";
                    return; // Ne pas faire de passe, continuer à avancer
                }
            }
        }
    
  
            std::cout<<player->getLocation()<< " est dans la zone de passe"<<std::endl;

            // Tourner vers la balle
            float dx = b->getLocation().x - pos.x;
            float dz = b->getLocation().z - pos.z;
            D3DXVECTOR3 dir(dx, 0.0f, dz);
			D3DXVec3Normalize(&dir, &dir);
            D3DXVECTOR3 forward(0.0f, 0.0f, 1.0f);
			float angleY = atan2f(dx, dz); // rotation autour de Y
			player->setRot(angleY);

	            // Chercher une cible
	         std::vector<robot*> joueursCibles;
	
			for (size_t i = 0; i < playerAI.size(); ++i) {
			    robot* candidate = playerAI[i];
			
			    if (candidate == player) continue; // exclure soi-même
			
			    D3DXVECTOR3 pos = candidate->getLocation();
			
			    if (pos.x > xmin && pos.x < xmax &&
			        pos.z > zmin && pos.z < zmax) 
			    {
			        joueursCibles.push_back(candidate);
			    }
			}
              
            if (joueursCibles.size() > 0)
            {
				
				robot* cible = joueursCibles[std::rand() % joueursCibles.size()];
				D3DXVECTOR3 directionPasse = cible->getLocation() - b->getLocation();
				D3DXVec3Normalize(&directionPasse, &directionPasse);
				
				// Ajoute une probabilité d’échec
				float chanceDeReussite = 0.7f;
				float randValue = static_cast<float>(std::rand()) / RAND_MAX;

                if (randValue > chanceDeReussite) {
			    std::cout << "?? La passe a échoué volontairement !\n";
			    directionPasse.x += ((static_cast<float>(std::rand()) / RAND_MAX) - 0.5f) * 2.0f; // [-1.0, 1.0]
			    directionPasse.z += ((static_cast<float>(std::rand()) / RAND_MAX) - 0.5f) * 2.0f;
			    D3DXVec3Normalize(&directionPasse, &directionPasse);
			}
        
                float puissancePasse = 30.0f;

				    // Génère une hauteur aléatoire (entre 2.0 et 5.0 par exemple)
				float variation = static_cast<float>(std::rand()) / RAND_MAX;
				float hauteur = 2.0f + variation * 30.0f; // entre 2.0 et 5.0
				
				// Ajoute la composante Y pour la hauteur
				D3DXVECTOR3 vitessePasse(
				    directionPasse.x * puissancePasse,
				    hauteur,  // hauteur vers le haut
				    directionPasse.z * puissancePasse
				);
				
				// Applique la vitesse à la balle
				b->setVelocity(vitessePasse);
                

                // Joueur en passe -> empêche de recoller la balle
                //var controller = player.GetComponent<ThirdPersonController2_final>();
                player->sethastheball(false);
                player->startBallCooldown(1.0f); // empêche de reprendre la balle trop vite
    

            }
        }


	//std::cout<<tir<<std::endl;
}

void pass::setTir(bool t)
{
	tir=t;
}
bool pass::getTir()
{
	return tir;
}

void pass::setSpeed(float s)
{
	speed=s;
}



	
	
		
	
