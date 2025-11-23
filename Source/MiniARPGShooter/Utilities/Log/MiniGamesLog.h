// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "Logging/LogMacros.h"

class UObject;
// 自定义log 类型，指定输出log字段，便于debug
MINIARPGSHOOTER_API DECLARE_LOG_CATEGORY_EXTERN(LogMiniGame, Log, All);
MINIARPGSHOOTER_API DECLARE_LOG_CATEGORY_EXTERN(LogMiniGameExperience, Log, All);
MINIARPGSHOOTER_API DECLARE_LOG_CATEGORY_EXTERN(LogMiniGameAbilitySystem, Log, All);
MINIARPGSHOOTER_API DECLARE_LOG_CATEGORY_EXTERN(LogMiniGameTeams, Log, All);
MINIARPGSHOOTER_API DECLARE_LOG_CATEGORY_EXTERN(LogMiniGameRendering, Log, All);
MINIARPGSHOOTER_API DECLARE_LOG_CATEGORY_EXTERN(LogMiniGameNet, Log, All);