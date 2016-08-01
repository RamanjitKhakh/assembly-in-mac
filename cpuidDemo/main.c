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
	printf("AVX: %d\n", cf.AVX);
	printf("F16C: %d\n", cf.F16c);
	printf("FMA: %d\n", cf.FMA);
	printf("AVX2: %d\n", cf.AVX2);
	printf("BMI1: %d\n", cf.BMI1);
	printf("BMI2: %d\n", cf.BMI2);
	printf("LZCNT: %d\n", cf.LZCNT);
	printf("MOVBE: %d\n", cf.MOVBE);
	printf("\n");
	printf("OSXSAVE %d\n", cf.OSXSAVE);
	printf("SSE_STATE %d\n", cf.SSE_STATE);
	printf("AVX_STATE %d\n", cf.AVX_STATE);
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

	if(cf->OSXSAVE){

		Uint32 xgetbv_eax, xgetbv_edx;
		Xgetbv_(0, &xgetbv_eax, &xgetbv_edx);
		cf->SSE_STATE = (xgetbv_eax & (0x1 << 1)) ? true : false;
		cf->AVX_STATE = (xgetbv_eax & (0x1 << 2)) ? true : false;

		if(cf->SSE_STATE && cf->AVX_STATE){
			cf->AVX = (cpuid01_ecx & (0x1 << 28)) ? true : false;

			if(cf->AVX){
				cf->F16c = (cpuid01_ecx & (0x1 << 29)) ? true : false;

				cf->FMA = (cpuid01_ecx & (0x1 << 12)) ? true : false;

				cf->AVX2 = (cpuid07_ebx & (0x1 << 5)) ? true : false;
			}
		}
	}
	

}
