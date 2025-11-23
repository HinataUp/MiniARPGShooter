// Fill out your copyright notice in the Description page of Project Settings.


#include "MiniGameplayTags.h"
#include "Utilities/Log/MiniGamesLog.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagsManager.h"

namespace MiniGameplayTags
{
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Ability_ActivateFail_IsDead, "Ability.ActivateFail.IsDead",
	                               "技能激活失败，因为其所有者已死亡。");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Ability_ActivateFail_Cooldown, "Ability.ActivateFail.Cooldown",
	                               "技能激活失败，因为处于冷却状态。");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Ability_ActivateFail_Cost, "Ability.ActivateFail.Cost",
	                               "技能激活失败，因为未能通过消耗检查。");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Ability_ActivateFail_TagsBlocked, "Ability.ActivateFail.TagsBlocked",
	                               "技能激活失败，因为标签被阻止。");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Ability_ActivateFail_TagsMissing, "Ability.ActivateFail.TagsMissing",
	                               "技能激活失败，因为缺少必要的标签。");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Ability_ActivateFail_Networking, "Ability.ActivateFail.Networking",
	                               "技能激活失败，因为未能通过网络检查。");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Ability_ActivateFail_ActivationGroup, "Ability.ActivateFail.ActivationGroup",
	                               "技能激活失败，因为其激活组限制。");

	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Ability_Behavior_SurvivesDeath, "Ability.Behavior.SurvivesDeath",
	                               "带有此类型标签的技能不应因死亡而被取消。");

	UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_Move, "InputTag.Move", "移动输入。");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_Look_Mouse, "InputTag.Look.Mouse", "视角（鼠标）输入。");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_Look_Stick, "InputTag.Look.Stick", "视角（摇杆）输入。");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_Crouch, "InputTag.Crouch", "下蹲输入。");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_AutoRun, "InputTag.AutoRun", "自动奔跑输入。");

	UE_DEFINE_GAMEPLAY_TAG_COMMENT(InitState_Spawned, "InitState.Spawned",
	                               "1： Actor/组件已初始生成，可被扩展");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(InitState_DataAvailable, "InitState.DataAvailable",
	                               "2： 所有需要的数据已加载/复制完成，准备初始化");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(InitState_DataInitialized, "InitState.DataInitialized",
	                               "3： 可用数据已为此Actor/组件初始化，但尚未准备好进行完整游戏玩法")
	;
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(InitState_GameplayReady, "InitState.GameplayReady",
	                               "4： Actor/组件已完全准备好进行活跃游戏玩法");

	UE_DEFINE_GAMEPLAY_TAG_COMMENT(GameplayEvent_Death, "GameplayEvent.Death",
	                               "死亡时触发的事件。此事件仅在服务器上触发。");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(GameplayEvent_Reset, "GameplayEvent.Reset",
	                               "玩家重置执行时触发的事件。");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(GameplayEvent_RequestReset, "GameplayEvent.RequestReset",
	                               "请求将玩家的Pawn在有效生成点即时替换为新Pawn的事件。")
	;

	UE_DEFINE_GAMEPLAY_TAG_COMMENT(SetByCaller_Damage, "SetByCaller.Damage",
	                               "由伤害性Gameplay效果使用的SetByCaller标签。");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(SetByCaller_Heal, "SetByCaller.Heal",
	                               "由治疗性Gameplay效果使用的SetByCaller标签。");

	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Cheat_GodMode, "Cheat.GodMode", "所有者的上帝模式作弊已激活。");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Cheat_UnlimitedHealth, "Cheat.UnlimitedHealth",
	                               "所有者的无限生命作弊已激活。");

	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Status_Crouching, "Status.Crouching", "目标正在下蹲。");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Status_AutoRunning, "Status.AutoRunning", "目标正在自动奔跑。");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Status_Death, "Status.Death", "目标具有死亡状态。");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Status_Death_Dying, "Status.Death.Dying", "目标已开始死亡过程。");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Status_Death_Dead, "Status.Death.Dead", "目标已完成死亡过程。");

	// 这些标签在 GetMovementModeTagMap() 中映射到移动模式
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Movement_Mode_Walking, "Movement.Mode.Walking", "默认角色移动标签");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Movement_Mode_NavWalking, "Movement.Mode.NavWalking",
	                               "默认角色移动标签");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Movement_Mode_Falling, "Movement.Mode.Falling", "默认角色移动标签");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Movement_Mode_Swimming, "Movement.Mode.Swimming", "默认角色移动标签");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Movement_Mode_Flying, "Movement.Mode.Flying", "默认角色移动标签");

	// 扩展MiniGame时，您可以创建自己的移动模式，但需要更新 GetCustomMovementModeTagMap()
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Movement_Mode_Custom, "Movement.Mode.Custom",
	                               "此标签无效，应使用自定义标签替换。请参阅 MiniGameplayTags::CustomMovementModeTagMap。");

	// Unreal Movement Modes
	const TMap<uint8, FGameplayTag> MovementModeTagMap =
	{
		{MOVE_Walking, Movement_Mode_Walking},
		{MOVE_NavWalking, Movement_Mode_NavWalking},
		{MOVE_Falling, Movement_Mode_Falling},
		{MOVE_Swimming, Movement_Mode_Swimming},
		{MOVE_Flying, Movement_Mode_Flying},
		{MOVE_Custom, Movement_Mode_Custom}
	};

	// Custom Movement Modes
	const TMap<uint8, FGameplayTag> CustomMovementModeTagMap =
	{
		// Fill these in with your custom modes
	};

	FGameplayTag FindTagByString(const FString& TagString, bool bMatchPartialString)
	{
		const UGameplayTagsManager& Manager = UGameplayTagsManager::Get();
		FGameplayTag Tag = Manager.RequestGameplayTag(FName(*TagString), false);

		if (!Tag.IsValid() && bMatchPartialString)
		{
			FGameplayTagContainer AllTags;
			Manager.RequestAllGameplayTags(AllTags, true);

			for (const FGameplayTag& TestTag : AllTags)
			{
				if (TestTag.ToString().Contains(TagString))
				{
					UE_LOG(LogMiniGame, Display,
					       TEXT("Could not find exact match for tag [%s] but found partial match on tag [%s]."),
					       *TagString, *TestTag.ToString());
					Tag = TestTag;
					break;
				}
			}
		}

		return Tag;
	}
}
