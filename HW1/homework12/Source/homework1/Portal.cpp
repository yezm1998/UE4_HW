// Fill out your copyright notice in the Description page of Project Settings.


#include "Portal.h"

// Sets default values
APortal::APortal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//实例化根组件
	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));
	RootComponent = RootScene;

	//创建静态模型组件
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	StaticMesh->SetupAttachment(RootComponent);
	StaticMesh->SetCollisionProfileName(FName("CubeProfile"));

}


//// Called every frame
//void APortal::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}

void APortal::ReceiveBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 20, FColor::Yellow, "Cube Begin---------");
	}
}

void APortal::ReceiveEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 20, FColor::Yellow, "Cube End---------");
	}
}

void APortal::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 20, FColor::Yellow, "ACubeActor OnHit---------");
	}
}

void APortal::BeginPlay()
{
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, TEXT("PLAY"));
	StaticMesh->OnComponentBeginOverlap.AddDynamic(this, &APortal::ReceiveBeginOverlap);       // 当此组件与某对象重叠时，设置通知
	StaticMesh->OnComponentEndOverlap.AddDynamic(this, &APortal::ReceiveEndOverlap);       // 当此组件与某对象重叠时，设置通知

}
