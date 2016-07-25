#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>
#include<string.h>
#include"MiscDefs.h"

void checkId();

typedef struct{
	Uint32 EAX;
	Uint32 EBX;
	Uint32 ECX;
	Uint32 EDX;
} CpuidRegs;

typedef struct{
	Uint32 MaxEAX;
	char  VendorId[13];
	bool SSE;
	bool SSE2;
	bool SSE3;
	bool SSSE3;
	bool SSE4_1;
	bool SSE4_2;
	bool AVX;
	bool AVX2;
	bool F16c;
	bool FMA;
	bool POPCNT;
	bool BMI1;
	bool BMI2;
	bool LZCNT;
	bool MOVBE;

	bool OSXSAVE;
	bool SSE_STATE;
	bool AVX_STATE;


} CpuidFeatures;

void GetCpuidFeatures(CpuidFeatures  *cf);
void Cpuid(Uint32 r_eax, Uint32 r_ecx, CpuidRegs *out);

int main(){
	printf("\nThe size of the struct is %lu\n", sizeof(CpuidFeatures));
	CpuidFeatures cf;

	GetCpuidFeatures(&cf);
	printf("Results for cpu\n");
	printf("MaxEAX:  %dn\n" , cf.MaxEAX);
	printf("VendorId:  %s\n", cf.VendorId);
	printf("SSE: %d\n", cf.SSE);
	printf("SSE2: %d\n", cf.SSE2);
	printf("SSE3: %d\n", cf.SSE3);
	printf("SSSE3: %d\n", cf.SSSE3);
	printf("SSE4_1: %d\n", cf.SSE4_1);
	printf("SSE4_2: %d\n", cf.SSE4_2);
	printf("POPCNT: %d\n", cf.POPCNT);
	return 0;
}


void GetCpuidFeatures(CpuidFeatures  *cf){
	CpuidRegs r_out;
	memset(cf, 0, sizeof(CpuidFeatures));

	Cpuid_(0,0, &r_out);
	

	cf->MaxEAX = r_out.EAX;
	*(Uint32 *)(cf->VendorId + 0) = r_out.EBX;
	*(Uint32 *)(cf->VendorId + 4) = r_out.EDX;
	*(Uint32 *)(cf->VendorId + 8) = r_out.ECX;
	cf->VendorId[12] = '\0';

	if (cf->MaxEAX < 10){
		return;
	}
	
	Cpuid_(1,0,&r_out);
	Uint32 cpuid01_ecx = r_out.ECX;
	Uint32 cpuid01_edx = r_out.EDX;
	Cpuid_(7,0, &r_out);
	Uint32 cpuid07_ebx = r_out.EBX;


	cf->SSE = (cpuid01_edx & (0x1<<25) ? true : false);
	if(cf->SSE)
		cf->SSE2 = (cpuid01_edx & (0x1<<26) ? true : false);


	if(cf->SSE2)
		cf->SSE3 = (cpuid01_ecx & (0x1<<0) ? true : false);
	
	if(cf->SSE3)
		cf->SSSE3 = (cpuid01_ecx & (0x1<<9)? true : false);

	if(cf->SSSE3)
		cf->SSE4_1 = (cpuid01_ecx & (0x1<< 19)? true : false);
	if(cf->SSE4_1)
		cf->SSE4_2 = (cpuid01_ecx & (0x1<<20)? true : false);
	if(cf->SSE4_2)
		cf->POPCNT = (cpuid01_ecx & (0x1<<23)? true : false);


	cf->OSXSAVE = (cpuid01_ecx & (0x1<<27)) ? true : false;
	

}
