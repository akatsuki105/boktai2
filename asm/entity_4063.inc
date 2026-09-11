	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080a94c0
FUN_080a94c0: @ 0x080A94C0
	push {lr}
	ldr r0, _080A94D0 @ =0x03002C50
	ldr r0, [r0]
	cmp r0, #0
	beq _080A94D4
	ldrh r0, [r0, #0x18]
	b _080A94D6
	.align 2, 0
_080A94D0: .4byte 0x03002C50
_080A94D4:
	movs r0, #0
_080A94D6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080a94dc
FUN_080a94dc: @ 0x080A94DC
	push {lr}
	ldr r0, _080A94F0 @ =0x03002C50
	ldr r1, [r0]
	cmp r1, #0
	beq _080A94EA
	movs r0, #1
	strh r0, [r1, #0x1a]
_080A94EA:
	pop {r0}
	bx r0
	.align 2, 0
_080A94F0: .4byte 0x03002C50

	thumb_func_start Entity4063_Update
Entity4063_Update: @ 0x080A94F4
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x1a]
	cmp r0, #0
	beq _080A950A
	bl FUN_0809c58c
	adds r0, r4, #0
	bl KillEntity
	b _080A952C
_080A950A:
	ldrh r0, [r4, #0x18]
	subs r0, #1
	strh r0, [r4, #0x18]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080A952C
	bl FUN_0809c58c
	ldr r0, [r4, #0x1c]
	cmp r0, #0
	beq _080A9526
	movs r1, #0
	bl Script_ExecById
_080A9526:
	adds r0, r4, #0
	bl KillEntity
_080A952C:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start Entity4063_Destroy
Entity4063_Destroy: @ 0x080A9534
	ldr r1, _080A953C @ =0x03002C50
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080A953C: .4byte 0x03002C50

	thumb_func_start Entity4063_Init
Entity4063_Init: @ 0x080A9540
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x74
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080A9554
	bl Script_GetValue
	b _080A9558
_080A9554:
	movs r0, #0xe1
	lsls r0, r0, #3
_080A9558:
	strh r0, [r4, #0x18]
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080A9568
	bl Script_GetValue
_080A9568:
	str r0, [r4, #0x1c]
	adds r0, r4, #0
	adds r0, #0x18
	bl FUN_0809c544
	ldr r0, _080A9580 @ =0x03002C50
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080A9580: .4byte 0x03002C50

	thumb_func_start Entity4063_Create
Entity4063_Create: @ 0x080A9584
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r0, _080A95C0 @ =0x03002C50
	ldr r0, [r0]
	cmp r0, #0
	bne _080A95CE
	movs r0, #8
	movs r1, #0x20
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A95CC
	ldr r1, _080A95C4 @ =Entity4063_Update
	ldr r2, _080A95C8 @ =Entity4063_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl Entity4063_Init
	cmp r0, #0
	bge _080A95CC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A95CE
	.align 2, 0
_080A95C0: .4byte 0x03002C50
_080A95C4: .4byte Entity4063_Update
_080A95C8: .4byte Entity4063_Destroy
_080A95CC:
	adds r0, r4, #0
_080A95CE:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
