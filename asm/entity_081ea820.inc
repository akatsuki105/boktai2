	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_081ea688
FUN_081ea688: @ 0x081EA688
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r5, r0, #0
	mov r8, r2
	mov sl, r3
	ldr r0, _081EA740 @ =0x030001BC
	ldr r7, [r0]
	cmp r7, #0
	bne _081EA6AC
	bl Entity081ea820_Create
	adds r7, r0, #0
	cmp r7, #0
	beq _081EA748
_081EA6AC:
	adds r0, r7, #0
	bl FUN_081ea220
	adds r6, r0, #0
	cmp r6, #0
	beq _081EA748
	adds r0, #0xd2
	movs r4, #0
	movs r1, #1
	mov sb, r1
	mov r2, sb
	strb r2, [r0]
	mov r2, sp
	adds r2, #5
	adds r0, r5, #0
	add r1, sp, #4
	bl FUN_081ea4f4
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [r6, #0x2c]
	str r1, [r6, #0x30]
	adds r0, r6, #0
	adds r0, #0xd0
	strh r4, [r0]
	mov r2, r8
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r6, #0x34]
	str r1, [r6, #0x38]
	adds r0, r6, #0
	adds r0, #0x8c
	adds r1, r6, #0
	adds r1, #0x2c
	movs r2, #0
	bl ParticleShadow_Init
	ldr r0, [r6, #0x2c]
	ldr r1, [r6, #0x30]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	adds r1, r7, #0
	adds r1, #0x18
	adds r0, r6, #0
	movs r2, #0
	bl AuxSprite_Add
	movs r0, #3
	strh r0, [r6, #0x10]
	ldr r0, [r6, #0xc]
	ldr r1, _081EA744 @ =0x00000243
	bl Video_SetAuxSpritePltt
	ldr r0, [r6]
	mov r1, sb
	orrs r0, r1
	str r0, [r6]
	movs r0, #2
	strb r0, [r6, #7]
	ldr r0, [sp, #0x30]
	str r0, [sp]
	adds r0, r6, #0
	mov r1, sl
	ldr r2, [sp, #0x28]
	ldr r3, [sp, #0x2c]
	bl FUN_081ea184
	adds r0, r6, #0
	adds r0, #0xd3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	b _081EA74C
	.align 2, 0
_081EA740: .4byte 0x030001BC
_081EA744: .4byte 0x00000243
_081EA748:
	movs r0, #1
	rsbs r0, r0, #0
_081EA74C:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity081ea820_Update
Entity081ea820_Update: @ 0x081EA75C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x38
	ldr r0, [r5, #0x34]
	cmp r0, #0
	beq _081EA7AA
	movs r4, #0
	ldr r7, _081EA780 @ =0x085AE46C
_081EA76E:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r5, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _081EA784
	movs r0, #1
	b _081EA786
	.align 2, 0
_081EA780: .4byte 0x085AE46C
_081EA784:
	movs r0, #0
_081EA786:
	cmp r0, #0
	beq _081EA7A4
	movs r0, #0xd4
	adds r1, r4, #0
	muls r1, r0, r1
	adds r1, r1, r6
	adds r0, r1, #0
	adds r0, #0xd2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r2, [r0]
	adds r0, r5, #0
	bl _call_via_r2
_081EA7A4:
	adds r4, #1
	cmp r4, #7
	ble _081EA76E
_081EA7AA:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity081ea820_Destroy
Entity081ea820_Destroy: @ 0x081EA7B4
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
_081EA7BA:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _081EA7CA
	movs r0, #1
	b _081EA7CC
_081EA7CA:
	movs r0, #0
_081EA7CC:
	cmp r0, #0
	beq _081EA7E8
	movs r0, #0xd4
	adds r4, r5, #0
	muls r4, r0, r4
	adds r4, #0x38
	adds r4, r6, r4
	adds r0, r4, #0
	bl AuxSprite_Remove
	adds r4, #0x8c
	adds r0, r4, #0
	bl ParticleShadow_Remove
_081EA7E8:
	adds r5, #1
	cmp r5, #7
	ble _081EA7BA
	ldr r1, _081EA7FC @ =0x030001BC
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081EA7FC: .4byte 0x030001BC

	thumb_func_start Entity081ea820_Init
Entity081ea820_Init: @ 0x081EA800
	push {lr}
	movs r1, #0
	str r1, [r0, #0x34]
	ldr r1, _081EA818 @ =0x030001BC
	str r0, [r1]
	adds r0, #0x18
	ldr r1, _081EA81C @ =0x000084EE
	bl Video_GetAuxSprite
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_081EA818: .4byte 0x030001BC
_081EA81C: .4byte 0x000084EE

	thumb_func_start Entity081ea820_Create
Entity081ea820_Create: @ 0x081EA820
	push {r4, lr}
	ldr r0, _081EA858 @ =0x030001BC
	ldr r0, [r0]
	cmp r0, #0
	bne _081EA866
	movs r1, #0xdb
	lsls r1, r1, #3
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081EA864
	ldr r1, _081EA85C @ =Entity081ea820_Update
	ldr r2, _081EA860 @ =Entity081ea820_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity081ea820_Init
	cmp r0, #0
	bge _081EA864
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081EA866
	.align 2, 0
_081EA858: .4byte 0x030001BC
_081EA85C: .4byte Entity081ea820_Update
_081EA860: .4byte Entity081ea820_Destroy
_081EA864:
	adds r0, r4, #0
_081EA866:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081ea86c
FUN_081ea86c: @ 0x081EA86C
	ldr r1, _081EA874 @ =0x030001BC
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081EA874: .4byte 0x030001BC
