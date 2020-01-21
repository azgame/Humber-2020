// Fill out your copyright notice in the Description page of Project Settings.

#include "FPlaceholderTest.h"

#include "Misc/AutomationTest.h"
#include "Tests/AutomationCommon.h"
#include "Engine.h"
#include "EngineUtils.h"

#include "Engine/Engine.h"

#include "Agile4TestGameModeBase.h"

UWorld* GetTestWorld() {
	const TIndirectArray<FWorldContext>& WorldContexts = GEngine->GetWorldContexts();
	for (const FWorldContext& Context : WorldContexts) {
		if (((Context.WorldType == EWorldType::PIE) || (Context.WorldType == EWorldType::Game))
			&& (Context.World() != nullptr)) {
			return Context.World();
		}
	}

	return nullptr;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FPlaceholderTest, "Agile4Test.LaunchLevel", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ClientContext | EAutomationTestFlags::ProductFilter)

bool FPlaceholderTest::RunTest(const FString& Parameters)
{
	
	TestTrue("World created", AutomationOpenMap("/Game/Maps/TestMap"));
	GEngine->AddOnScreenDebugMessage(2, 5.f, FColor::Cyan, TEXT("Hello from automation testing"));
	UWorld* world = GetTestWorld();

	TestTrue("Game mode set correctly", world->GetAuthGameMode()->IsA<AAgile4TestGameModeBase>());
	TestTrue("World has a functional test", world->AreActorsInitialized());

	/*for (TActorIterator<"MyClassHere"> It(world, "MyClassHere"::StaticClass()); It; ++It) {
		TestTrue("Classes initialized", It->DoSomething());
	}*/

	return true;
}