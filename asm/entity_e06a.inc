	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080cb254
FUN_080cb254: @ 0x080CB254
	bx lr
	.align 2, 0

	thumb_func_start FUN_080cb258
FUN_080cb258: @ 0x080CB258
	bx lr
	.align 2, 0

	thumb_func_start EntityE06A_Update
EntityE06A_Update: @ 0x080CB25C
	push {r4, lr}
	adds r1, r0, #0
	adds r4, r1, #0
	adds r4, #0x64
	adds r1, #0x38
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start EntityE06A_Destroy
EntityE06A_Destroy: @ 0x080CB27C
	push {lr}
	adds r0, #0x1c
	bl FUN_0822a4e0
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080cb28c
FUN_080cb28c: @ 0x080CB28C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x48
	ldr r1, _080CB2C4 @ =0x00009DA7
	adds r0, r4, #0
	bl Video_GetActorSprite
	adds r0, r5, #0
	adds r0, #0x1c
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080CB2C8
	bl Script_GetValue
	strh r0, [r5, #0x38]
	bl Script_GetValue
	strh r0, [r5, #0x3a]
	bl Script_GetValue
	b _080CB2CC
	.align 2, 0
_080CB2C4: .4byte 0x00009DA7
_080CB2C8:
	strh r0, [r5, #0x38]
	strh r0, [r5, #0x3a]
_080CB2CC:
	strh r0, [r5, #0x3c]
	adds r6, r5, #0
	adds r6, #0x38
	ldrh r0, [r5, #0x38]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080CB2F6
	cmp r1, #0
	blt _080CB2F6
	ldr r0, _080CB2FC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080CB2F6
	ldr r0, _080CB300 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080CB304
_080CB2F6:
	movs r4, #0
	b _080CB312
	.align 2, 0
_080CB2FC: .4byte 0x030046A8
_080CB300: .4byte 0x030046AC
_080CB304:
	ldr r0, _080CB324 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080CB312:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080CB328
	adds r0, #4
	b _080CB334
	.align 2, 0
_080CB324: .4byte 0x030046A4
_080CB328:
	ldr r0, _080CB348 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080CB334:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080CB34C
	cmp r2, #2
	beq _080CB350
	b _080CB354
	.align 2, 0
_080CB348: .4byte 0x030046A4
_080CB34C:
	ldrb r0, [r6, #4]
	b _080CB352
_080CB350:
	ldrb r0, [r6]
_080CB352:
	subs r1, r1, r0
_080CB354:
	strh r1, [r5, #0x3a]
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080cb35c
FUN_080cb35c: @ 0x080CB35C
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x64
	ldr r2, _080CB3DC @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x32
	orrs r0, r3
	ldr r1, _080CB3E0 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	str r0, [r3, #4]
	ldrh r1, [r4, #0x18]
	ldr r2, _080CB3E4 @ =0x00002001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_0823646c
	ldr r0, _080CB3E8 @ =0x00040002
	str r0, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r1, #0x64
	movs r2, #0x78
	movs r3, #0
	bl FUN_082364f8
	ldr r1, _080CB3EC @ =FUN_080cb254
	adds r0, r5, #0
	adds r2, r4, #0
	bl FUN_0823651c
	adds r4, #0x38
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r5, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CB3DC: .4byte 0xFFFF0000
_080CB3E0: .4byte 0x0000FFFF
_080CB3E4: .4byte 0x00002001
_080CB3E8: .4byte 0x00040002
_080CB3EC: .4byte FUN_080cb254

	thumb_func_start FUN_080cb3f0
FUN_080cb3f0: @ 0x080CB3F0
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xb4
	ldr r2, _080CB468 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x32
	orrs r0, r3
	ldr r1, _080CB46C @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	str r0, [r3, #4]
	ldrh r1, [r4, #0x18]
	ldr r2, _080CB470 @ =0x00004001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_0823646c
	adds r0, r5, #0
	movs r1, #0xa
	movs r2, #2
	movs r3, #1
	bl FUN_08236514
	ldr r1, _080CB474 @ =FUN_080cb258
	adds r0, r5, #0
	adds r2, r4, #0
	bl FUN_0823651c
	adds r4, #0x38
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r5, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CB468: .4byte 0xFFFF0000
_080CB46C: .4byte 0x0000FFFF
_080CB470: .4byte 0x00004001
_080CB474: .4byte FUN_080cb258

	thumb_func_start EntityE06A_Init
EntityE06A_Init: @ 0x080CB478
	push {r4, lr}
	adds r4, r0, #0
	strh r1, [r4, #0x18]
	bl FUN_080cb28c
	adds r0, r4, #0
	bl FUN_080cb35c
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start EntityE06A_Create
EntityE06A_Create: @ 0x080CB490
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r1, #0x82
	lsls r1, r1, #1
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080CB4D0
	ldr r1, _080CB4C8 @ =EntityE06A_Update
	ldr r2, _080CB4CC @ =EntityE06A_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl EntityE06A_Init
	cmp r0, #0
	bge _080CB4D0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080CB4D2
	.align 2, 0
_080CB4C8: .4byte EntityE06A_Update
_080CB4CC: .4byte EntityE06A_Destroy
_080CB4D0:
	adds r0, r4, #0
_080CB4D2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
