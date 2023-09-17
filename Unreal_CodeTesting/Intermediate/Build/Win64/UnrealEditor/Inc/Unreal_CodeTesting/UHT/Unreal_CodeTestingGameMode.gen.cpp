// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Unreal_CodeTesting/Unreal_CodeTestingGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUnreal_CodeTestingGameMode() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UNREAL_CODETESTING_API UClass* Z_Construct_UClass_AUnreal_CodeTestingGameMode();
	UNREAL_CODETESTING_API UClass* Z_Construct_UClass_AUnreal_CodeTestingGameMode_NoRegister();
	UPackage* Z_Construct_UPackage__Script_Unreal_CodeTesting();
// End Cross Module References
	void AUnreal_CodeTestingGameMode::StaticRegisterNativesAUnreal_CodeTestingGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AUnreal_CodeTestingGameMode);
	UClass* Z_Construct_UClass_AUnreal_CodeTestingGameMode_NoRegister()
	{
		return AUnreal_CodeTestingGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AUnreal_CodeTestingGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AUnreal_CodeTestingGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_Unreal_CodeTesting,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AUnreal_CodeTestingGameMode_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AUnreal_CodeTestingGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "Unreal_CodeTestingGameMode.h" },
		{ "ModuleRelativePath", "Unreal_CodeTestingGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AUnreal_CodeTestingGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AUnreal_CodeTestingGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AUnreal_CodeTestingGameMode_Statics::ClassParams = {
		&AUnreal_CodeTestingGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AUnreal_CodeTestingGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AUnreal_CodeTestingGameMode_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_AUnreal_CodeTestingGameMode()
	{
		if (!Z_Registration_Info_UClass_AUnreal_CodeTestingGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AUnreal_CodeTestingGameMode.OuterSingleton, Z_Construct_UClass_AUnreal_CodeTestingGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AUnreal_CodeTestingGameMode.OuterSingleton;
	}
	template<> UNREAL_CODETESTING_API UClass* StaticClass<AUnreal_CodeTestingGameMode>()
	{
		return AUnreal_CodeTestingGameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AUnreal_CodeTestingGameMode);
	AUnreal_CodeTestingGameMode::~AUnreal_CodeTestingGameMode() {}
	struct Z_CompiledInDeferFile_FID_Unreal_CodeTesting_Source_Unreal_CodeTesting_Unreal_CodeTestingGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_CodeTesting_Source_Unreal_CodeTesting_Unreal_CodeTestingGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AUnreal_CodeTestingGameMode, AUnreal_CodeTestingGameMode::StaticClass, TEXT("AUnreal_CodeTestingGameMode"), &Z_Registration_Info_UClass_AUnreal_CodeTestingGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AUnreal_CodeTestingGameMode), 873813699U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_CodeTesting_Source_Unreal_CodeTesting_Unreal_CodeTestingGameMode_h_3196461728(TEXT("/Script/Unreal_CodeTesting"),
		Z_CompiledInDeferFile_FID_Unreal_CodeTesting_Source_Unreal_CodeTesting_Unreal_CodeTestingGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_CodeTesting_Source_Unreal_CodeTesting_Unreal_CodeTestingGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
