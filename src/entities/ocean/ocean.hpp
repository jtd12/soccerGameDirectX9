#ifndef DEF_OCEAN_HPP
#define DEF_OCAN_HPP
#include <windows.h>
#include <windowsx.h>
#include"../../device.hpp"
#include <d3d9.h>
#include <d3dx9.h>
#include <algorithm>    // std::max
#define SAFE_RELEASE(p){if(p) {(p)->Release(); (p)=NULL;}}
#define SAFE_DELETE(p) {if(p) {delete(p); (p)=NULL;}}
#define SAFE_DELETE_ARRAY(p) {if(p) {delete[](p); (p)=NULL;}}

 extern int MaxFrames;

struct CUSTOM_FRAME : public D3DXFRAME
{
    D3DXMATRIX CombTransformationMatrix;    // transform data multiplied by all parents' data
};

struct CUSTOM_MESHCONTAINER : public D3DXMESHCONTAINER
{
    D3DXMATRIX** ppFrameMatrices;    // an array of matrices to store current animation data
    LPD3DXMESH pFinalMesh;    // a duplicate of the mesh, representing it's current pose
    LPDIRECT3DTEXTURE9* pTextures;    // an array of applicable textures
};


class MeshAllocation : public ID3DXAllocateHierarchy
{
public:


 STDMETHOD(CreateFrame)(LPCSTR Name, LPD3DXFRAME* ppNewFrame)
    {
        // Create and initialize the custom frame struct
        CUSTOM_FRAME* pFrame = new CUSTOM_FRAME;
        *ppNewFrame = pFrame;
        ZeroMemory(pFrame, sizeof(CUSTOM_FRAME));

        // Copy the name
        if(Name)
        {
            UINT len = strlen(Name) + 1;
            pFrame->Name = new char[len];
            memcpy(pFrame->Name, Name, len);
        }

        return S_OK;
    }

 STDMETHOD(CreateMeshContainer)(LPCSTR Name,
                                   CONST D3DXMESHDATA* pMeshData,
                                   CONST D3DXMATERIAL* pMaterials,
                                   CONST D3DXEFFECTINSTANCE* pEffectInstances,
                                   DWORD NumMaterials,
                                   CONST DWORD* pAdjacency,
                                   LPD3DXSKININFO pSkinInfo,
                                   LPD3DXMESHCONTAINER* ppNewMeshContainer)   
    {
    	
        // Create and initialize the custom mesh container
        struct CUSTOM_MESHCONTAINER *pMeshContainer = new CUSTOM_MESHCONTAINER;
        *ppNewMeshContainer = pMeshContainer;
        ZeroMemory(pMeshContainer, sizeof(CUSTOM_MESHCONTAINER));

        // Check to make sure its a normal mesh
        if(pMeshData->Type != D3DXMESHTYPE_MESH)
        {
            DestroyMeshContainer(pMeshContainer);
            return E_FAIL;
        }

        // Copy the name
        if(Name)
        {
            UINT len = strlen(Name) + 1;
            pMeshContainer->Name = new char[len];
            memcpy(pMeshContainer->Name, Name, len);
        }

        // Copy the mesh data
        pMeshContainer->MeshData.Type = pMeshData->Type;
        pMeshContainer->MeshData.pMesh = pMeshData->pMesh;
        pMeshContainer->MeshData.pMesh->AddRef();

        // Copy the materials
        pMeshContainer->pMaterials = new D3DXMATERIAL[NumMaterials];
        for(DWORD i = 0; i < NumMaterials; i++)
        {
            pMeshContainer->pMaterials[i] = pMaterials[i];
            pMeshContainer->pMaterials[i].MatD3D.Ambient = pMaterials[i].MatD3D.Diffuse;
        }

        // Don't bother with the effect instance
        pMeshContainer->pEffects = NULL;

        // Copy the number of materials
        pMeshContainer->NumMaterials = std::max(1,(int) NumMaterials);

        // Copy the adjacency data
        pMeshContainer->pAdjacency = new DWORD[pMeshData->pMesh->GetNumFaces() * 3];
        memcpy(pMeshContainer->pAdjacency,
               pAdjacency,
               sizeof(DWORD) * pMeshData->pMesh->GetNumFaces() * 3);

        // Only do these steps if there is skin info
        if(pSkinInfo)
        {
            // Copy the skin data
            pMeshContainer->pSkinInfo = pSkinInfo;
            pSkinInfo->AddRef();

            // Allocate memory for the pointers to the frame matrices
            pMeshContainer->ppFrameMatrices = new D3DXMATRIX*[pSkinInfo->GetNumBones()];
            for(DWORD i = 0; i < pSkinInfo->GetNumBones(); i++)
            {
                pMeshContainer->ppFrameMatrices[i] = NULL;
            }
        }

        // Create a duplicate of the mesh
        pMeshContainer->MeshData.pMesh->CloneMesh(D3DXMESH_MANAGED,
                                                
                                                  NULL,d3ddev,
                                                  &pMeshContainer->pFinalMesh);

        // Load the textures for each material (if any)
        pMeshContainer->pTextures = new LPDIRECT3DTEXTURE9[pMeshContainer->NumMaterials];
        for(DWORD i = 0; i < NumMaterials; i++)
        {
            pMeshContainer->pTextures[i] = 0;
            if(pMaterials[i].pTextureFilename)
            {
                D3DXCreateTextureFromFileA(d3ddev,
                                           pMeshContainer->pMaterials[i].pTextureFilename,
                                           &pMeshContainer->pTextures[i]);
            }
        }

        // Find the maximum number of frames
        if(pMeshContainer->pSkinInfo)
            MaxFrames = std::max(MaxFrames, (int)pMeshContainer->pSkinInfo->GetNumBones());

        return S_OK;
    }

  STDMETHOD(DestroyFrame)(LPD3DXFRAME pFrameToFree)
    {
        // free the name and the frame
        SAFE_DELETE_ARRAY(pFrameToFree->Name);
        SAFE_DELETE(pFrameToFree);

        return S_OK;
    }

  STDMETHOD(DestroyMeshContainer)(LPD3DXMESHCONTAINER pMeshContainerToFree)
    {
        // cast the pointer to a CUSTOM_MESHCONTAINER
        CUSTOM_MESHCONTAINER* pMeshContainer = (CUSTOM_MESHCONTAINER*)pMeshContainerToFree;

        // free or release all the allocated memory
        SAFE_DELETE_ARRAY(pMeshContainer->Name);
        SAFE_RELEASE(pMeshContainer->MeshData.pMesh);
        SAFE_RELEASE(pMeshContainer->pFinalMesh);
        SAFE_DELETE_ARRAY(pMeshContainer->pMaterials);
        SAFE_DELETE_ARRAY(pMeshContainer->pAdjacency);
        SAFE_RELEASE(pMeshContainer->pSkinInfo);
        SAFE_DELETE_ARRAY(pMeshContainer->ppFrameMatrices);
        for(UINT i = 0; i < pMeshContainer->NumMaterials; i++)
            SAFE_RELEASE(pMeshContainer->pTextures[i]);
        SAFE_DELETE(pMeshContainer);

        return S_OK;
    }
    

};


class ocean
{
	public:
		
ocean(LPDIRECT3DDEVICE9 d3ddev);
~ocean();
void init();
void cleanUp();
void link_frames(CUSTOM_FRAME* pFrame);
void update_frames(CUSTOM_FRAME* pFrame, D3DXMATRIX* pParentMatrix);
void update_mesh_containers(CUSTOM_FRAME* pFrame);
void draw_mesh(CUSTOM_FRAME* pFrame);
void render();

private:
	
LPD3DXMESH meshSpaceship;    // define the mesh pointer
D3DMATERIAL9* material;    // define the material object
LPDIRECT3DTEXTURE9* texture;    // a pointer to a texture
DWORD numMaterials;    // stores the number of materials in the mesh
LPD3DXFRAME TopFrame = NULL;    // the top-most frame of the model
LPD3DXANIMATIONCONTROLLER AnimationController = NULL;    // an object that handles animation
D3DXMATRIX* FinalMatrices = NULL;    // a buffer for the matrices in their final state
LPDIRECT3DDEVICE9 d3ddev_;

	
};



#endif

