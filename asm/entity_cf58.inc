	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080a5e4c
FUN_080a5e4c: @ 0x080A5E4C
	push {lr}
	ldr r0, _080A5E64 @ =0x0300014C
	ldr r0, [r0]
	cmp r0, #0
	beq _080A5E5E
	adds r1, r0, #0
	adds r1, #0x9c
	movs r0, #1
	str r0, [r1]
_080A5E5E:
	pop {r0}
	bx r0
	.align 2, 0
_080A5E64: .4byte 0x0300014C

	thumb_func_start FUN_080a5e68
FUN_080a5e68: @ 0x080A5E68
	adds r2, r0, #0
	adds r2, #0xac
	str r1, [r2]
	adds r0, #0x9a
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_080a5e78
FUN_080a5e78: @ 0x080A5E78
	push {lr}
	adds r1, r0, #0
	adds r0, #0xa0
	ldr r2, [r0]
	cmp r2, #0
	beq _080A5E8C
	adds r0, #4
	ldr r0, [r0]
	bl _call_via_r2
_080A5E8C:
	pop {r0}
	bx r0

	thumb_func_start FUN_080a5e90
FUN_080a5e90: @ 0x080A5E90
	push {lr}
	adds r0, #0xa8
	ldr r0, [r0]
	cmp r0, #0
	beq _080A5EA0
	movs r1, #0
	bl VM_ExecByID
_080A5EA0:
	pop {r0}
	bx r0

	thumb_func_start FUN_080a5ea4
FUN_080a5ea4: @ 0x080A5EA4
	push {lr}
	adds r1, r0, #0
	adds r0, #0x98
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A5EB8
	adds r0, r1, #0
	bl FUN_080a5e78
	b _080A5EBE
_080A5EB8:
	adds r0, r1, #0
	bl FUN_080a5e90
_080A5EBE:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a5ec4
FUN_080a5ec4: @ 0x080A5EC4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r0, #0x9a
	ldrh r0, [r0]
	cmp r0, #0
	bne _080A5ED6
	ldr r0, _080A5F38 @ =0x000002C2
	bl PlaySound_082406e0
_080A5ED6:
	adds r0, r4, #0
	adds r0, #0x4c
	ldrh r0, [r0]
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bhi _080A5EF8
	adds r0, r4, #0
	adds r0, #0x44
	ldrh r0, [r0]
	cmp r0, #0
	bne _080A5EF8
	movs r0, #0x87
	lsls r0, r0, #2
	bl PlaySound_082406e0
_080A5EF8:
	adds r1, r4, #0
	adds r1, #0x9a
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	adds r5, r4, #0
	adds r5, #0x38
	adds r6, r4, #0
	adds r6, #0x18
	adds r0, r5, #0
	adds r1, r6, #0
	bl MainSprite_AdvanceAnim
	cmp r0, #0
	beq _080A5F30
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0x24
	movs r3, #1
	bl MainSprite_SetPose
	ldr r1, _080A5F3C @ =FUN_080a5f40
	adds r0, r4, #0
	bl FUN_080a5e68
	adds r0, r4, #0
	bl FUN_080a5ea4
_080A5F30:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A5F38: .4byte 0x000002C2
_080A5F3C: .4byte FUN_080a5f40

	thumb_func_start FUN_080a5f40
FUN_080a5f40: @ 0x080A5F40
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r7, #0
	adds r4, #0x9a
	ldrh r0, [r4]
	cmp r0, #0
	bne _080A5F54
	ldr r0, _080A5F90 @ =0x000002C3
	bl PlaySound_082406e0
_080A5F54:
	ldrh r0, [r4]
	cmp r0, #7
	bhi _080A5FA0
	ldr r6, _080A5F94 @ =0x0203B400
	ldr r5, _080A5F98 @ =0x030046B8
	ldr r1, [r5]
	adds r1, #1
	ldr r3, _080A5F9C @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r4, #3
	ands r0, r4
	subs r0, #2
	adds r2, r7, #0
	adds r2, #0x58
	strh r0, [r2]
	adds r1, #1
	ands r1, r3
	str r1, [r5]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r0, [r1]
	ands r0, r4
	subs r0, #2
	adds r1, r7, #0
	adds r1, #0x5a
	strh r0, [r1]
	b _080A5FB0
	.align 2, 0
_080A5F90: .4byte 0x000002C3
_080A5F94: .4byte 0x0203B400
_080A5F98: .4byte 0x030046B8
_080A5F9C: .4byte 0x000003FF
_080A5FA0:
	cmp r0, #8
	bne _080A5FB0
	adds r0, r7, #0
	adds r0, #0x58
	movs r1, #0
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
_080A5FB0:
	adds r1, r7, #0
	adds r1, #0x9a
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bls _080A5FC8
	adds r0, r7, #0
	bl KillEntity
_080A5FC8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a5fd0
FUN_080a5fd0: @ 0x080A5FD0
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x9a
	ldrh r0, [r4]
	cmp r0, #0
	bne _080A5FE6
	movs r0, #0xa5
	lsls r0, r0, #2
	bl PlaySound_082406e0
_080A5FE6:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x59
	bls _080A6000
	adds r0, r5, #0
	bl FUN_080a5ea4
	adds r0, r5, #0
	bl KillEntity
_080A6000:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start EntityCF58_Update
EntityCF58_Update: @ 0x080A6008
	push {lr}
	adds r2, r0, #0
	adds r0, #0x9c
	ldr r0, [r0]
	cmp r0, #0
	beq _080A601C
	adds r0, r2, #0
	bl KillEntity
	b _080A6028
_080A601C:
	adds r0, r2, #0
	adds r0, #0xac
	ldr r1, [r0]
	adds r0, r2, #0
	bl _call_via_r1
_080A6028:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EntityCF58_Destroy
EntityCF58_Destroy: @ 0x080A6030
	push {lr}
	adds r0, #0x38
	bl MainSprite_Remove
	ldr r1, _080A6044 @ =0x0300014C
	movs r0, #0
	str r0, [r1]
	pop {r1}
	bx r1
	.align 2, 0
_080A6044: .4byte 0x0300014C

	thumb_func_start FUN_080a6048
FUN_080a6048: @ 0x080A6048
	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _080A60B4 @ =0x0000CB05
	ldr r1, _080A60B8 @ =0x0000DCC1
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	beq _080A6108
	adds r1, r4, #0
	adds r1, #0x18
	ldm r0!, {r3, r6, r7}
	stm r1!, {r3, r6, r7}
	ldm r0!, {r3, r6, r7}
	stm r1!, {r3, r6, r7}
	ldm r0!, {r3, r6}
	stm r1!, {r3, r6}
	adds r7, r4, #0
	adds r7, #0x18
	adds r0, r7, #0
	adds r1, r2, #0
	bl OpenMainSpriteFile
	ldr r1, _080A60BC @ =0xFFFF0000
	movs r6, #0
	str r6, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	cmp r5, #0
	bne _080A60C0
	adds r4, #0x38
	str r5, [sp]
	str r5, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	add r0, sp, #0x10
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #0x20
	movs r3, #0x30
	bl MainSprite_Add
	str r5, [sp]
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #0
	movs r3, #2
	bl MainSprite_SetAnim
	b _080A6108
	.align 2, 0
_080A60B4: .4byte 0x0000CB05
_080A60B8: .4byte 0x0000DCC1
_080A60BC: .4byte 0xFFFF0000
_080A60C0:
	cmp r5, #1
	bne _080A60E0
	adds r0, r4, #0
	adds r0, #0x38
	str r6, [sp]
	str r6, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r7, #0
	movs r2, #0x25
	movs r3, #0x30
	bl MainSprite_Add
	b _080A6108
_080A60E0:
	adds r4, #0x38
	str r6, [sp]
	str r6, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	add r3, sp, #0x10
	str r3, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #0x20
	movs r3, #0x30
	bl MainSprite_Add
	str r6, [sp]
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #0
	movs r3, #2
	bl MainSprite_SetAnim
_080A6108:
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a6110
FUN_080a6110: @ 0x080A6110
	push {lr}
	cmp r1, #0
	bne _080A6124
	ldr r1, _080A6120 @ =0x080A5EC5
	bl FUN_080a5e68
	b _080A613A
	.align 2, 0
_080A6120: .4byte 0x080A5EC5
_080A6124:
	cmp r1, #1
	bne _080A6134
	ldr r1, _080A6130 @ =0x080A5FD1
	bl FUN_080a5e68
	b _080A613A
	.align 2, 0
_080A6130: .4byte 0x080A5FD1
_080A6134:
	ldr r1, _080A6140 @ =0x080A5EC5
	bl FUN_080a5e68
_080A613A:
	pop {r0}
	bx r0
	.align 2, 0
_080A6140: .4byte 0x080A5EC5

	thumb_func_start FUN_080a6144
FUN_080a6144: @ 0x080A6144
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	ldr r5, [sp, #0x10]
	adds r1, r4, #0
	adds r1, #0x98
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xa0
	str r3, [r0]
	adds r0, #4
	str r5, [r0]
	subs r0, #0xb
	strb r2, [r0]
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_080a6048
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_080a6110
	ldr r1, _080A617C @ =0x0300014C
	str r4, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A617C: .4byte 0x0300014C

	thumb_func_start FUN_080a6180
FUN_080a6180: @ 0x080A6180
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	adds r7, r1, #0
	mov r8, r2
	adds r5, r3, #0
	ldr r0, _080A61CC @ =0x0300014C
	ldr r0, [r0]
	cmp r0, #0
	bne _080A61DA
	movs r0, #4
	movs r1, #0xb0
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A61D8
	ldr r1, _080A61D0 @ =EntityCF58_Update
	ldr r2, _080A61D4 @ =EntityCF58_Destroy
	bl SetEntityRoutine
	str r5, [sp]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	mov r3, r8
	bl FUN_080a6144
	cmp r0, #0
	bge _080A61D8
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A61DA
	.align 2, 0
_080A61CC: .4byte 0x0300014C
_080A61D0: .4byte EntityCF58_Update
_080A61D4: .4byte EntityCF58_Destroy
_080A61D8:
	adds r0, r4, #0
_080A61DA:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EntityCF58_Init
EntityCF58_Init: @ 0x080A61E8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x98
	movs r1, #1
	strb r1, [r0]
	movs r0, #0x6d
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A6204
	bl VM_GetValue
	adds r5, r0, #0
	b _080A6206
_080A6204:
	movs r5, #0
_080A6206:
	movs r0, #0x66
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A6214
	bl VM_GetValue
_080A6214:
	adds r1, r4, #0
	adds r1, #0x99
	strb r0, [r1]
	movs r0, #0x70
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A6232
	bl VM_GetValue
	adds r1, r4, #0
	adds r1, #0xa8
	str r0, [r1]
	b _080A6238
_080A6232:
	adds r0, r4, #0
	adds r0, #0xa8
	str r1, [r0]
_080A6238:
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_080a6048
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_080a6110
	ldr r1, _080A6254 @ =0x0300014C
	str r4, [r1]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080A6254: .4byte 0x0300014C

	thumb_func_start EntityCF58_Create
EntityCF58_Create: @ 0x080A6258
	push {r4, lr}
	ldr r0, _080A628C @ =0x0300014C
	ldr r0, [r0]
	cmp r0, #0
	bne _080A629A
	movs r0, #4
	movs r1, #0xb0
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A6298
	ldr r1, _080A6290 @ =EntityCF58_Update
	ldr r2, _080A6294 @ =EntityCF58_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl EntityCF58_Init
	cmp r0, #0
	bge _080A6298
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A629A
	.align 2, 0
_080A628C: .4byte 0x0300014C
_080A6290: .4byte EntityCF58_Update
_080A6294: .4byte EntityCF58_Destroy
_080A6298:
	adds r0, r4, #0
_080A629A:
	pop {r4}
	pop {r1}
	bx r1
