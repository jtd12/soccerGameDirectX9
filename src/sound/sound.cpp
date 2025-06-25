#include"sound.hpp"

	sound::sound(HWND hwnd)
	{
	initDirectSound(hwnd);	
	}
	
	sound::~sound()
	{
		delete g_pDSound;
			
		if (g_pDSound) 
		  g_pDSound->Release();
	}
	
	bool sound::initDirectSound(HWND hwnd) {
	    if (FAILED(DirectSoundCreate8(NULL, &g_pDSound, NULL))) return false;
	    if (FAILED(g_pDSound->SetCooperativeLevel(hwnd, DSSCL_PRIORITY))) return false;
	    return true;
	}
	
	LPDIRECTSOUNDBUFFER sound::loadSound(LPCSTR filename) {
    // Ouvre le fichier
    HMMIO hmmio = mmioOpenA((LPSTR)filename, NULL, MMIO_READ | MMIO_ALLOCBUF);
    if (!hmmio) return NULL;

    MMCKINFO parent;
    parent.fccType = mmioFOURCC('W', 'A', 'V', 'E');
    mmioDescend(hmmio, &parent, NULL, MMIO_FINDRIFF);

    MMCKINFO child;
    child.ckid = mmioFOURCC('f', 'm', 't', ' ');
    mmioDescend(hmmio, &child, &parent, MMIO_FINDCHUNK);

    WAVEFORMATEX wfx;
    mmioRead(hmmio, (HPSTR)&wfx, sizeof(wfx));
    mmioAscend(hmmio, &child, 0);

    child.ckid = mmioFOURCC('d', 'a', 't', 'a');
    mmioDescend(hmmio, &child, &parent, MMIO_FINDCHUNK);

    BYTE* bufferData = new BYTE[child.cksize];
    mmioRead(hmmio, (HPSTR)bufferData, child.cksize);
    mmioClose(hmmio, 0);

    DSBUFFERDESC dsbd = {};
    dsbd.dwSize = sizeof(DSBUFFERDESC);
    dsbd.dwFlags = DSBCAPS_CTRLVOLUME;
    dsbd.dwBufferBytes = child.cksize;
    dsbd.lpwfxFormat = &wfx;

    LPDIRECTSOUNDBUFFER tempBuffer;
    if (FAILED(g_pDSound->CreateSoundBuffer(&dsbd, &tempBuffer, NULL))) {
        delete[] bufferData;
        return NULL;
    }

    // Copier les données dans le buffer
    VOID* ptr1; DWORD size1;
    VOID* ptr2; DWORD size2;
    tempBuffer->Lock(0, child.cksize, &ptr1, &size1, &ptr2, &size2, 0);
    memcpy(ptr1, bufferData, size1);
    if (ptr2) memcpy(ptr2, bufferData + size1, size2);
    tempBuffer->Unlock(ptr1, size1, ptr2, size2);

    delete[] bufferData;
    return tempBuffer;
}

