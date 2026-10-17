	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0805d5dc
FUN_0805d5dc: @ 0x0805D5DC
	movs r0, #0x3c
	str r0, [r2]
	bx lr
	.align 2, 0

	thumb_func_start FUN_0805d5e4
FUN_0805d5e4: @ 0x0805D5E4
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x20
	adds r4, r0, #0
	adds r6, r1, #0
	movs r0, #0
	mov r8, r0
	stm r1!, {r0}
	str r0, [sp, #0xc]
	add r0, sp, #0xc
	ldr r2, _0805D67C @ =0x05000002
	bl CpuSet
	adds r0, r6, #0
	adds r0, #0xc
	adds r4, #0x1c
	adds r1, r4, #0
	movs r2, #1
	bl AuxSprite_Setup
	adds r5, r6, #0
	adds r5, #0x38
	ldr r2, _0805D680 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r4, #8
	orrs r0, r4
	ldr r1, _0805D684 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x10]
	add r3, sp, #0x10
	ldr r0, [r3, #4]
	ands r0, r2
	orrs r0, r4
	str r0, [r3, #4]
	mov r0, r8
	str r0, [sp, #0x18]
	add r1, sp, #0x18
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _0805D688 @ =0x00002001
	movs r0, #0x10
	str r0, [sp]
	str r3, [sp, #4]
	str r1, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	ldr r1, _0805D68C @ =FUN_0805d5dc
	adds r0, r5, #0
	adds r2, r6, #0
	bl Hitbox_SetHandler
	mov r0, r8
	str r0, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r1, #0xa
	movs r2, #0x14
	movs r3, #0
	bl Hitbox_SetAttack
	add sp, #0x20
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0805D67C: .4byte 0x05000002
_0805D680: .4byte 0xFFFF0000
_0805D684: .4byte 0x0000FFFF
_0805D688: .4byte 0x00002001
_0805D68C: .4byte FUN_0805d5dc

	thumb_func_start FUN_0805d690
FUN_0805d690: @ 0x0805D690
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r0, r1, #0
	adds r5, r2, #0
	ldr r1, [r0, #0xc]
	movs r4, #1
	orrs r1, r4
	str r1, [r0, #0xc]
	adds r0, #0xc
	bl AuxSprite_Remove
	lsls r4, r5
	ldr r0, [r6, #0x18]
	bics r0, r4
	str r0, [r6, #0x18]
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start Entity0805d79c_Update
Entity0805d79c_Update: @ 0x0805D6B4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	mov r6, r8
	adds r6, #0x38
	movs r7, #0
	adds r5, r6, #0
_0805D6C4:
	movs r1, #1
	lsls r1, r7
	mov r2, r8
	ldr r0, [r2, #0x18]
	ands r0, r1
	cmp r0, #0
	beq _0805D716
	adds r4, r6, #0
	adds r4, #0x38
	adds r1, r6, #0
	adds r1, #0x28
	ldrh r0, [r5, #4]
	ldrh r2, [r5, #0x28]
	adds r0, r0, r2
	strh r0, [r5, #0x28]
	ldrh r0, [r5, #6]
	ldrh r2, [r5, #0x2a]
	adds r0, r0, r2
	strh r0, [r5, #0x2a]
	ldrh r0, [r5, #8]
	ldrh r2, [r5, #0x2c]
	adds r0, r0, r2
	strh r0, [r5, #0x2c]
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	ldr r0, [r5]
	cmp r0, #0x3b
	bls _0805D712
	mov r0, r8
	adds r1, r6, #0
	adds r2, r7, #0
	bl FUN_0805d690
	b _0805D716
_0805D712:
	adds r0, #1
	str r0, [r5]
_0805D716:
	adds r7, #1
	adds r5, #0x88
	adds r6, #0x88
	cmp r7, #0x1f
	ble _0805D6C4
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity0805d79c_Destroy
Entity0805d79c_Destroy: @ 0x0805D72C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x38
	movs r4, #0
_0805D736:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r6, #0x18]
	ands r0, r1
	cmp r0, #0
	beq _0805D74C
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0805d690
_0805D74C:
	adds r4, #1
	adds r5, #0x88
	cmp r4, #0x1f
	ble _0805D736
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start Entity0805d79c_Init
Entity0805d79c_Init: @ 0x0805D75C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r0, #0
	str r0, [r6, #0x18]
	adds r4, r6, #0
	adds r4, #0x1c
	ldr r1, _0805D798 @ =0x0000848F
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r0, r4, #0
	movs r1, #0xdb
	bl Video_SetAuxSpritePltt
	adds r5, r6, #0
	adds r5, #0x38
	movs r4, #0
_0805D77E:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0805d5e4
	adds r4, #1
	adds r5, #0x88
	cmp r4, #0x1f
	ble _0805D77E
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0805D798: .4byte 0x0000848F

	thumb_func_start Entity0805d79c_Create
Entity0805d79c_Create: @ 0x0805D79C
	push {r4, lr}
	ldr r1, _0805D7C8 @ =0x00001138
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0805D7D4
	ldr r1, _0805D7CC @ =Entity0805d79c_Update
	ldr r2, _0805D7D0 @ =Entity0805d79c_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity0805d79c_Init
	cmp r0, #0
	bge _0805D7D4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0805D7D6
	.align 2, 0
_0805D7C8: .4byte 0x00001138
_0805D7CC: .4byte Entity0805d79c_Update
_0805D7D0: .4byte Entity0805d79c_Destroy
_0805D7D4:
	adds r0, r4, #0
_0805D7D6:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805d7dc
FUN_0805d7dc: @ 0x0805D7DC
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r3, #0x38
	movs r2, #0
	movs r5, #1
	ldr r4, [r0, #0x18]
_0805D7E8:
	adds r0, r5, #0
	lsls r0, r2
	ands r0, r4
	cmp r0, #0
	bne _0805D7F8
	str r2, [r1]
	adds r0, r3, #0
	b _0805D804
_0805D7F8:
	adds r2, #1
	adds r3, #0x88
	cmp r2, #0x1f
	ble _0805D7E8
	movs r0, #0
	str r0, [r1]
_0805D804:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0805d80c
FUN_0805d80c: @ 0x0805D80C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	mov sb, r1
	adds r5, r2, #0
	adds r7, r3, #0
	adds r6, r0, #0
	add r1, sp, #8
	bl FUN_0805d7dc
	adds r3, r0, #0
	cmp r3, #0
	bne _0805D830
	movs r0, #1
	rsbs r0, r0, #0
	b _0805D90A
_0805D830:
	movs r0, #0x38
	adds r0, r0, r3
	mov r8, r0
	movs r0, #0
	adds r4, r3, #0
	stm r4!, {r0}
	ldr r2, _0805D858 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _0805D85C
	asrs r1, r0, #0xc
	b _0805D862
	.align 2, 0
_0805D858: .4byte gSineTable
_0805D85C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805D862:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _0805D87E
	asrs r0, r0, #0xc
	b _0805D884
_0805D87E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805D884:
	strh r0, [r4, #4]
	ldr r2, [sp, #0x28]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r3, #0x28]
	str r1, [r3, #0x2c]
	adds r0, r5, #0
	adds r0, #0x60
	movs r1, #0xff
	ands r0, r1
	lsrs r2, r0, #4
	cmp r2, #8
	bls _0805D8AA
	movs r0, #0x10
	subs r0, r0, r2
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	movs r4, #1
	b _0805D8AC
_0805D8AA:
	movs r4, #0
_0805D8AC:
	adds r1, r3, #0
	adds r1, #0xc
	adds r0, r2, #4
	strh r0, [r1, #0x10]
	adds r2, r1, #0
	cmp r4, #0
	beq _0805D8C2
	ldr r0, [r3, #0xc]
	movs r1, #4
	orrs r0, r1
	b _0805D8CA
_0805D8C2:
	ldr r0, [r3, #0xc]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0805D8CA:
	str r0, [r3, #0xc]
	ldr r0, [r3, #0xc]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3, #0xc]
	adds r0, r2, #0
	movs r1, #0
	bl Video_AddAuxSpriteIntoDrawList
	movs r0, #0
	str r0, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	mov r0, r8
	mov r1, sb
	movs r2, #0x14
	movs r3, #0
	bl Hitbox_SetAttack
	mov r0, r8
	ldr r1, [sp, #0x28]
	movs r2, #0
	bl Hitbox_SetPos
	ldr r0, [sp, #8]
	movs r1, #1
	lsls r1, r0
	ldr r0, [r6, #0x18]
	orrs r0, r1
	str r0, [r6, #0x18]
	movs r0, #0
_0805D90A:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
