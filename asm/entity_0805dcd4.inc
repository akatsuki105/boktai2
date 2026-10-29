	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0805d918
FUN_0805d918: @ 0x0805D918
	bx lr
	.align 2, 0

	thumb_func_start FUN_0805d91c
FUN_0805d91c: @ 0x0805D91C
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x2c
	adds r4, r0, #0
	adds r6, r1, #0
	movs r0, #0
	mov r8, r0
	str r0, [r6, #4]
	add r5, sp, #0x14
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _0805D9C8 @ =0x05000002
	bl CpuSet
	adds r0, r6, #0
	adds r0, #0xc
	adds r4, #0x1c
	movs r1, #2
	str r1, [sp]
	mov r1, r8
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	str r5, [sp, #0xc]
	adds r1, r4, #0
	movs r2, #0
	movs r3, #1
	bl MainSprite_Setup
	adds r5, r6, #0
	adds r5, #0x6c
	ldr r2, _0805D9CC @ =0xFFFF0000
	ldr r0, [sp, #0x1c]
	ands r0, r2
	movs r4, #0x60
	orrs r0, r4
	ldr r1, _0805D9D0 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x1c]
	add r3, sp, #0x1c
	ldr r0, [r3, #4]
	ands r0, r2
	orrs r0, r4
	str r0, [r3, #4]
	str r1, [sp, #0x24]
	add r1, sp, #0x24
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _0805D9D4 @ =0x00002001
	movs r0, #0x10
	str r0, [sp]
	str r3, [sp, #4]
	str r1, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	ldr r1, _0805D9D8 @ =FUN_0805d918
	adds r0, r5, #0
	adds r2, r6, #0
	bl Hitbox_SetHandler
	mov r0, r8
	str r0, [sp]
	movs r0, #0x40
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r1, #0x32
	movs r2, #0x40
	movs r3, #0
	bl Hitbox_SetAttack
	add sp, #0x2c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0805D9C8: .4byte 0x05000002
_0805D9CC: .4byte 0xFFFF0000
_0805D9D0: .4byte 0x0000FFFF
_0805D9D4: .4byte 0x00002001
_0805D9D8: .4byte FUN_0805d918

	thumb_func_start FUN_0805d9dc
FUN_0805d9dc: @ 0x0805D9DC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r0, r1, #0
	adds r5, r2, #0
	ldr r1, [r0, #0x14]
	movs r4, #1
	orrs r1, r4
	str r1, [r0, #0x14]
	adds r0, #0xc
	bl MainSprite_Remove
	lsls r4, r5
	ldr r0, [r6, #0x18]
	bics r0, r4
	str r0, [r6, #0x18]
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805da00
FUN_0805da00: @ 0x0805DA00
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	adds r2, r1, #0
	ldr r0, [r2, #4]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _0805DAC0
	adds r6, r2, #0
	adds r6, #0xc
	ldr r4, _0805DA5C @ =0x0203B400
	ldr r3, _0805DA60 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _0805DA64 @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	ldrh r5, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r1, r0
	mov r3, sp
	adds r4, r1, #0
	adds r4, #0x10
	ldr r2, _0805DA68 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _0805DA6C
	asrs r1, r0, #0xc
	b _0805DA72
	.align 2, 0
_0805DA5C: .4byte 0x0203B400
_0805DA60: .4byte 0x030046B8
_0805DA64: .4byte 0x000003FF
_0805DA68: .4byte gSineTable
_0805DA6C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805DA72:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	movs r0, #0xff
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _0805DA8E
	asrs r0, r0, #0xc
	b _0805DA94
_0805DA8E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805DA94:
	strh r0, [r3, #4]
	mov r2, sp
	mov r1, sp
	ldrh r0, [r6, #0x20]
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r6, #0x22]
	adds r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r6, #0x24]
	ldrh r1, [r2, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	adds r2, r7, #0
	adds r2, #0x3c
	movs r0, #0
	mov r1, sp
	bl Entity08015584_Spawn
_0805DAC0:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start Entity0805dcd4_Update
Entity0805dcd4_Update: @ 0x0805DAC8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r7, r0, #0
	adds r5, r7, #0
	adds r5, #0x64
	movs r0, #0
	mov r8, r0
	movs r0, #1
	mov sb, r0
_0805DAE0:
	mov r1, sb
	mov r0, r8
	lsls r1, r0
	ldr r0, [r7, #0x18]
	ands r0, r1
	cmp r0, #0
	beq _0805DBEA
	adds r6, r5, #0
	adds r6, #0xc
	adds r2, r5, #0
	adds r2, #0x6c
	ldrb r4, [r5]
	cmp r4, #1
	beq _0805DB4C
	cmp r4, #1
	bgt _0805DB06
	cmp r4, #0
	beq _0805DB10
	b _0805DBDA
_0805DB06:
	cmp r4, #2
	beq _0805DB8A
	cmp r4, #3
	beq _0805DBB6
	b _0805DBDA
_0805DB10:
	adds r0, r7, #0
	adds r1, r5, #0
	bl FUN_0805da00
	ldr r0, [r5, #4]
	cmp r0, #0x1d
	bls _0805DBDA
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	str r4, [r5, #4]
	ldr r0, [r6, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #8]
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r7, #0
	adds r1, #0x1c
	movs r2, #0x2a
	movs r3, #2
	bl MainSprite_SetAnim
	movs r0, #0xbc
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _0805DBDA
_0805DB4C:
	ldrh r0, [r6, #0x14]
	cmp r0, #4
	bhi _0805DB5E
	adds r0, r7, #0
	adds r1, r5, #0
	str r2, [sp, #4]
	bl FUN_0805da00
	ldr r2, [sp, #4]
_0805DB5E:
	ldr r0, [r5, #4]
	cmp r0, #0xe
	bls _0805DB6A
	adds r0, r2, #0
	bl Hitbox_Register
_0805DB6A:
	ldrb r0, [r6, #0x1d]
	ands r4, r0
	cmp r4, #0
	beq _0805DBDA
	ldrb r0, [r5]
	adds r0, #1
	movs r1, #0
	strb r0, [r5]
	str r1, [r5, #4]
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r7, #0
	adds r1, #0x1c
	movs r2, #0x2b
	b _0805DBAE
_0805DB8A:
	adds r0, r2, #0
	bl Hitbox_Register
	ldr r1, [r5, #4]
	ldr r0, [r5, #8]
	cmp r1, r0
	blo _0805DBDA
	ldrb r0, [r5]
	adds r0, #1
	movs r1, #0
	strb r0, [r5]
	str r1, [r5, #4]
	movs r0, #6
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r7, #0
	adds r1, #0x1c
	movs r2, #0x2a
_0805DBAE:
	movs r3, #2
	bl MainSprite_SetAnim
	b _0805DBDA
_0805DBB6:
	ldrh r0, [r6, #0x14]
	cmp r0, #4
	bhi _0805DBC4
	adds r0, r7, #0
	adds r1, r5, #0
	bl FUN_0805da00
_0805DBC4:
	ldrb r1, [r6, #0x1d]
	mov r0, sb
	ands r0, r1
	cmp r0, #0
	beq _0805DBDA
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, r8
	bl FUN_0805d9dc
	b _0805DBEA
_0805DBDA:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r1, #0x1c
	bl MainSprite_AdvanceAnim
	ldr r0, [r5, #4]
	adds r0, #1
	str r0, [r5, #4]
_0805DBEA:
	movs r0, #1
	add r8, r0
	adds r5, #0xbc
	mov r0, r8
	cmp r0, #7
	bgt _0805DBF8
	b _0805DAE0
_0805DBF8:
	movs r0, #0
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity0805dcd4_Destroy
Entity0805dcd4_Destroy: @ 0x0805DC08
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x64
	movs r4, #0
_0805DC12:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r6, #0x18]
	ands r0, r1
	cmp r0, #0
	beq _0805DC28
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0805d9dc
_0805DC28:
	adds r4, #1
	adds r5, #0xbc
	cmp r4, #7
	ble _0805DC12
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start Entity0805dcd4_Init
Entity0805dcd4_Init: @ 0x0805DC38
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r4, #0
	str r4, [r6, #0x18]
	ldr r0, _0805DC54 @ =0x0000CB05
	ldr r1, _0805DC58 @ =0x0000D3FA
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	bne _0805DC5C
	movs r0, #1
	rsbs r0, r0, #0
	b _0805DCCC
	.align 2, 0
_0805DC54: .4byte 0x0000CB05
_0805DC58: .4byte 0x0000D3FA
_0805DC5C:
	adds r1, r6, #0
	adds r1, #0x1c
	adds r0, r2, #0
	ldm r0!, {r3, r5, r7}
	stm r1!, {r3, r5, r7}
	ldm r0!, {r3, r5, r7}
	stm r1!, {r3, r5, r7}
	ldm r0!, {r3, r5}
	stm r1!, {r3, r5}
	adds r0, r6, #0
	adds r0, #0x1c
	adds r1, r2, #0
	bl OpenMainSpriteFile
	adds r0, r6, #0
	adds r0, #0x3c
	movs r1, #7
	strh r1, [r6, #0x3c]
	movs r1, #0xc0
	lsls r1, r1, #6
	strh r1, [r0, #2]
	movs r1, #0x40
	strh r1, [r0, #6]
	strh r4, [r0, #8]
	strh r4, [r0, #0xa]
	movs r1, #3
	strh r1, [r0, #0xc]
	strh r1, [r0, #0xe]
	strh r4, [r0, #0x10]
	strh r4, [r0, #0x12]
	strh r4, [r0, #0x14]
	adds r1, #0xfd
	strh r1, [r0, #0x16]
	movs r1, #0x80
	lsls r1, r1, #2
	strh r1, [r0, #0x18]
	strh r4, [r0, #0x1a]
	strh r4, [r0, #0x1c]
	strh r4, [r0, #0x1e]
	strh r1, [r0, #0x20]
	strh r4, [r0, #0x22]
	strh r4, [r0, #0x24]
	strh r4, [r0, #0x26]
	adds r5, r6, #0
	adds r5, #0x64
	movs r4, #0
_0805DCB8:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0805d91c
	adds r4, #1
	adds r5, #0xbc
	cmp r4, #7
	ble _0805DCB8
	movs r0, #0
_0805DCCC:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity0805dcd4_Create
Entity0805dcd4_Create: @ 0x0805DCD4
	push {r4, lr}
	ldr r1, _0805DD00 @ =0x00000644
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0805DD0C
	ldr r1, _0805DD04 @ =Entity0805dcd4_Update
	ldr r2, _0805DD08 @ =Entity0805dcd4_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity0805dcd4_Init
	cmp r0, #0
	bge _0805DD0C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0805DD0E
	.align 2, 0
_0805DD00: .4byte 0x00000644
_0805DD04: .4byte Entity0805dcd4_Update
_0805DD08: .4byte Entity0805dcd4_Destroy
_0805DD0C:
	adds r0, r4, #0
_0805DD0E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805dd14
FUN_0805dd14: @ 0x0805DD14
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r3, #0x64
	movs r2, #0
	movs r5, #1
	ldr r4, [r0, #0x18]
_0805DD20:
	adds r0, r5, #0
	lsls r0, r2
	ands r0, r4
	cmp r0, #0
	bne _0805DD30
	str r2, [r1]
	adds r0, r3, #0
	b _0805DD3C
_0805DD30:
	adds r2, #1
	adds r3, #0xbc
	cmp r2, #7
	ble _0805DD20
	movs r0, #0
	str r0, [r1]
_0805DD3C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0805dd44
FUN_0805dd44: @ 0x0805DD44
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	mov sl, r1
	adds r5, r2, #0
	mov sb, r3
	add r1, sp, #8
	bl FUN_0805dd14
	adds r6, r0, #0
	cmp r6, #0
	beq _0805DDCA
	adds r4, r6, #0
	adds r4, #0xc
	movs r0, #0x6c
	adds r0, r0, r6
	mov r8, r0
	movs r0, #0
	strb r0, [r6]
	str r0, [r6, #4]
	str r5, [r6, #8]
	adds r1, r7, #0
	adds r1, #0x1c
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0x2a
	movs r3, #2
	bl MainSprite_SetAnim
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r6, #0x2c]
	str r1, [r6, #0x30]
	adds r0, r4, #0
	movs r1, #0
	bl Video_AddMainSpriteIntoDrawList
	movs r0, #0x80
	lsls r0, r0, #0xb
	str r0, [sp]
	movs r0, #0x40
	str r0, [sp, #4]
	mov r0, r8
	mov r1, sl
	movs r2, #0x40
	movs r3, #0
	bl Hitbox_SetAttack
	mov r0, r8
	mov r1, sb
	movs r2, #0
	bl Hitbox_SetPos
	ldr r0, [sp, #8]
	movs r1, #1
	lsls r1, r0
	ldr r0, [r7, #0x18]
	orrs r0, r1
	str r0, [r7, #0x18]
	movs r0, #0
	b _0805DDCE
_0805DDCA:
	movs r0, #1
	rsbs r0, r0, #0
_0805DDCE:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
