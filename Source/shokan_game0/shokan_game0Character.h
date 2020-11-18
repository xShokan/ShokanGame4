// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "shokan_game0Character.generated.h"

UCLASS(config=Game)
class Ashokan_game0Character : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

public:
	Ashokan_game0Character();

	// Called every frame
	virtual void Tick(float DeltaTime) override;
		
	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class USkeletalMeshComponent* HandWeapon;					//��������

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool isHip = true;																// �����Ƿ񿪾�

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool isFire = false;																// �����Ƿ񿪻�

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UAnimMontage* FireMontage;									// ���忪ǹ����

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UAnimMontage* CutMontage;									// ���� sword attack ����

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USoundBase* FireSound;											// ���忪ǹ����

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USoundBase* CutSound;											// ���� sword attack ����

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Score = 0;														            // ����÷�

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int KindOfWeapon = 1;														// �����������࣬0ΪGun��1ΪSword

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon")			
	class USkeletalMesh* GunMesh;						//��������Gun��Mesh

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	class USkeletalMesh* SwordMesh;					//��������Sword��Mesh

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool isFreeView = false;																// �����Ƿ��������ӽ�

protected:

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	void IronsightDown();
	void IronsightUp();

	void Fire();
	void FireDown();
	void FireUp();

	void RunDown();
	void RunUp();

	void SwitchGun();
	void SwitchSword();

	void FreeViewDown();
	void FreeViewUp();

	FHitResult OutHit;

};
