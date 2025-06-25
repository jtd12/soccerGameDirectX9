#include"ocean.hpp"

int MaxFrames=100;

ocean::ocean(LPDIRECT3DDEVICE9 d3ddev)
{	
	d3ddev_=d3ddev;
	init();
}
ocean::~ocean()
{
cleanUp();
}
void ocean::cleanUp()
{
	MeshAllocation MeshAllocator;

    SAFE_RELEASE(AnimationController);    // release the animation controller
    D3DXFrameDestroy(TopFrame, &MeshAllocator);    // free all memory for the animated mesh
    SAFE_DELETE_ARRAY(FinalMatrices);    // free the FinalMatrices array
    SAFE_RELEASE(d3ddev_);    // close and release the 3D device

}
void ocean::init()
{
	MeshAllocation MemAllocator;    // create a mesh allocation class

    // load the mesh and call the allocation functions
    D3DXLoadMeshHierarchyFromX("data/water.x",
                               D3DXMESH_MANAGED,
                               d3ddev_,
                               &MemAllocator,
                               NULL,
                               &TopFrame,
                               &AnimationController);

    // allocate memory for the FinalMatrices array
    FinalMatrices = new D3DXMATRIX[MaxFrames];
    ZeroMemory(FinalMatrices, sizeof(D3DXMATRIX) * MaxFrames);

    // set up the ppFrameMatrices pointers
    link_frames((CUSTOM_FRAME*)TopFrame);
}
void ocean::link_frames(CUSTOM_FRAME* pFrame)
{
    // cast the pFrame's mesh container pointer to a CUSTOM_MESHCONTAINER*
    CUSTOM_MESHCONTAINER* pMeshContainer = (CUSTOM_MESHCONTAINER*)pFrame->pMeshContainer;

    // if there is a mesh container and if it has skin info...
    if(pMeshContainer && pMeshContainer->pSkinInfo)
    {
        // loop through each frame in the mesh container
        for(UINT i = 0; i < pMeshContainer->pSkinInfo->GetNumBones(); i++)
        {
            CUSTOM_FRAME* pTempFrame;    // a temporary frame pointer

            // find each frame by name
            pTempFrame = (CUSTOM_FRAME*)D3DXFrameFind(TopFrame,
                                                  pMeshContainer->pSkinInfo->GetBoneName(i));
            // and set up a pointer to it
            pMeshContainer->ppFrameMatrices[i] = &pTempFrame->CombTransformationMatrix;
        }
    }

    // run for all siblings
    if(pFrame->pFrameSibling)
        link_frames((CUSTOM_FRAME*)pFrame->pFrameSibling);

    // run for the first child (which will then run all other children)
    if(pFrame->pFrameFirstChild)
        link_frames((CUSTOM_FRAME*)pFrame->pFrameFirstChild);
}


void ocean::update_frames(CUSTOM_FRAME* pFrame, D3DXMATRIX* pParentMatrix)
{
    // combine the frame's matrix with the parent's matrix, if any
    if(pParentMatrix)
        pFrame->CombTransformationMatrix = pFrame->TransformationMatrix * *pParentMatrix;
    else
        pFrame->CombTransformationMatrix = pFrame->TransformationMatrix;

    // run for all siblings
    if(pFrame->pFrameSibling)
        update_frames((CUSTOM_FRAME*)pFrame->pFrameSibling, pParentMatrix);

    // run for the first child (which will then run all other children)
    if(pFrame->pFrameFirstChild)
        update_frames((CUSTOM_FRAME*)pFrame->pFrameFirstChild,
            &pFrame->CombTransformationMatrix);
}


void ocean::update_mesh_containers(CUSTOM_FRAME* pFrame)
{
    // cast the pFrame's mesh container pointer to a CUSTOM_MESHCONTAINER*
    CUSTOM_MESHCONTAINER* pMeshContainer = (CUSTOM_MESHCONTAINER*)pFrame->pMeshContainer;

    if(pMeshContainer && pMeshContainer->pSkinInfo)
    {
        UINT NumFrames = pMeshContainer->pSkinInfo->GetNumBones();    // find how many frames
        // for each frame in the mesh container...
        for(UINT i = 0; i < NumFrames; i++)
        {
            // set FinalMatrices to that frame's offset matrix
            FinalMatrices[i] = *pMeshContainer->pSkinInfo->GetBoneOffsetMatrix(i);

            // multiply that by the animated frame matrix
            FinalMatrices[i] *= *pMeshContainer->ppFrameMatrices[i];
        }

        void* pSrc = NULL;    // a void pointer for the original mesh
        void* pDst = NULL;    // a void pointer for the modified mesh

        // lock the two meshes
        pMeshContainer->MeshData.pMesh->LockVertexBuffer(NULL, &pSrc);
        pMeshContainer->pFinalMesh->LockVertexBuffer(NULL, &pDst);

        // store the animated mesh into FinalMesh
        pMeshContainer->pSkinInfo->UpdateSkinnedMesh(FinalMatrices, NULL, pSrc, pDst);

        // unlock the two meshes
        pMeshContainer->pFinalMesh->UnlockVertexBuffer();
        pMeshContainer->MeshData.pMesh->UnlockVertexBuffer();
    }

    // run for all siblings
    if(pFrame->pFrameSibling)
        update_mesh_containers((CUSTOM_FRAME*)pFrame->pFrameSibling);

    // run for the first child (which will then run all other children)
    if(pFrame->pFrameFirstChild)
        update_mesh_containers((CUSTOM_FRAME*)pFrame->pFrameFirstChild);
}

void ocean::draw_mesh(CUSTOM_FRAME* pFrame)
{
    // cast the pFrame's mesh container pointer to a CUSTOM_MESHCONTAINER*
    CUSTOM_MESHCONTAINER* pMeshContainer = (CUSTOM_MESHCONTAINER*)pFrame->pMeshContainer;

    if(pMeshContainer)
    {
        // for each material...
        for(UINT i = 0; i < pMeshContainer->NumMaterials; i++)
        {
            // set the material
            d3ddev_->SetMaterial(&pMeshContainer->pMaterials[i].MatD3D);
            // set the texture
            d3ddev_->SetTexture(0, pMeshContainer->pTextures[i]);

            // draw the subset!
            pMeshContainer->pFinalMesh->DrawSubset(i);
        }
    }

    // run for all siblings
    if(pFrame->pFrameSibling)
        draw_mesh((CUSTOM_FRAME*)pFrame->pFrameSibling);

    // run for the first child (which will then run all other children)
    if(pFrame->pFrameFirstChild)
        draw_mesh((CUSTOM_FRAME*)pFrame->pFrameFirstChild);
}


void ocean::render()
{
	static float index = 0.0f; index+=0.03f;    // an ever-increasing float value
    D3DXMATRIX matRotateY;    // a matrix to store the rotation for each triangle
    D3DXMATRIX matScale; 
    D3DXMatrixRotationY(&matRotateY, index);    // the rotation matrix
    D3DXMatrixScaling(&matScale, 4.02f, 4.02f, 4.02f);
    D3DMATRIX matTemp(matScale);
    d3ddev_->SetTransform(D3DTS_WORLD, &matTemp);    // set the world transform
    
  if(AnimationController)
    {
        static DWORD Time = GetTickCount();

        // move the animation forward by the elapsed time
        AnimationController->AdvanceTime((GetTickCount() - Time) * 0.00001f, NULL);

        // reset Time for the next time through
        Time = GetTickCount();
    }

    // update each combined matrix
    update_frames((CUSTOM_FRAME*)TopFrame, NULL);

    // update the mesh containers
    update_mesh_containers((CUSTOM_FRAME*)TopFrame);

    // render each mesh container
    draw_mesh((CUSTOM_FRAME*)TopFrame);
}



