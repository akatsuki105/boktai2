	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0804e7b4
FUN_0804e7b4: @ 0x0804E7B4
	ldr r0, _0804E7BC @ =0x030000E4
	ldr r0, [r0]
	bx lr
	.align 2, 0
_0804E7BC: .4byte 0x030000E4

	thumb_func_start FUN_0804e7c0
FUN_0804e7c0: @ 0x0804E7C0
	push {r4, lr}
	adds r4, r0, #0
	cmp r1, #0xe4
	ble _0804E7E6
	ldr r0, [r4, #0x1c]
	movs r3, #0x1f
	ands r3, r0
	movs r2, #0x3f
	adds r1, r0, #0
	cmp r3, #7
	ble _0804E82A
	movs r2, #0x40
	cmp r3, #0xf
	ble _0804E82A
	movs r2, #0x42
	cmp r3, #0x17
	bgt _0804E82A
	movs r2, #0x41
	b _0804E82A
_0804E7E6:
	cmp r1, #0x7e
	ble _0804E802
	ldr r0, [r4, #0x1c]
	movs r3, #0x1f
	ands r3, r0
	movs r2, #0x3f
	adds r1, r0, #0
	cmp r3, #9
	ble _0804E82A
	movs r2, #0x41
	cmp r3, #0x13
	bgt _0804E82A
	movs r2, #0x40
	b _0804E82A
_0804E802:
	cmp r1, #0x18
	ble _0804E81C
	ldr r0, [r4, #0x1c]
	movs r3, #0x1f
	ands r3, r0
	movs r2, #0x3e
	adds r1, r0, #0
	cmp r3, #9
	ble _0804E82A
	movs r2, #0x40
	cmp r3, #0x13
	bgt _0804E82A
	b _0804E828
_0804E81C:
	ldr r1, [r4, #0x1c]
	movs r0, #0x1f
	ands r0, r1
	movs r2, #0x3e
	cmp r0, #0xf
	bgt _0804E82A
_0804E828:
	movs r2, #0x3f
_0804E82A:
	adds r0, r1, #1
	str r0, [r4, #0x1c]
	ldr r0, [r4, #0x20]
	cmp r2, r0
	beq _0804E844
	str r2, [r4, #0x20]
	adds r0, r4, #0
	adds r0, #0x44
	adds r1, r4, #0
	adds r1, #0x24
	movs r3, #0
	bl Sprite_SetSprite
_0804E844:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804e84c
FUN_0804e84c: @ 0x0804E84C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0804E86C @ =0x03005800
	ldr r1, [r0]
	ldrb r0, [r1]
	cmp r0, #0
	bne _0804E870
	ldrb r1, [r1, #0xa]
	adds r0, r4, #0
	bl FUN_0804e7c0
	ldr r0, [r4, #0x4c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	b _0804E876
	.align 2, 0
_0804E86C: .4byte 0x03005800
_0804E870:
	ldr r0, [r4, #0x4c]
	movs r1, #1
	orrs r0, r1
_0804E876:
	str r0, [r4, #0x4c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804e880
FUN_0804e880: @ 0x0804E880
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	bl FUN_0804e59c
	cmp r0, #0
	bne _0804E90A
	movs r5, #0xff
	bl FUN_0804e3ec
	cmp r0, #0
	beq _0804E902
	ldr r0, _0804E8B8 @ =0x03005800
	ldr r2, [r0]
	ldrb r1, [r2]
	adds r7, r0, #0
	cmp r1, #0
	bne _0804E8BC
	bl FUN_0804e3c0
	ldr r1, [r7]
	adds r1, #0xa
	adds r1, r1, r0
	ldrb r5, [r1]
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0804e7c0
	b _0804E8F8
	.align 2, 0
_0804E8B8: .4byte 0x03005800
_0804E8BC:
	movs r1, #0
	ldrb r3, [r2, #2]
	movs r6, #1
	adds r2, #0xa
_0804E8C4:
	adds r0, r3, #0
	asrs r0, r1
	ands r0, r6
	cmp r0, #0
	beq _0804E8D8
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r5, r0
	ble _0804E8D8
	adds r5, r0, #0
_0804E8D8:
	adds r1, #1
	cmp r1, #3
	ble _0804E8C4
	ldr r0, [r7]
	ldrb r0, [r0, #2]
	cmp r0, #0
	bne _0804E8F0
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0804e7c0
	b _0804E8F8
_0804E8F0:
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0804e7c0
_0804E8F8:
	ldr r0, [r4, #0x4c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	b _0804E908
_0804E902:
	ldr r0, [r4, #0x4c]
	movs r1, #1
	orrs r0, r1
_0804E908:
	str r0, [r4, #0x4c]
_0804E90A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start Entity0804e9ac_Update
Entity0804e9ac_Update: @ 0x0804E910
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0804e880
	ldr r0, [r4, #0x18]
	adds r0, #1
	str r0, [r4, #0x18]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity0804e9ac_Destroy
Entity0804e9ac_Destroy: @ 0x0804E928
	push {lr}
	adds r0, #0x44
	bl FUN_0822f1c0
	ldr r1, _0804E93C @ =0x030000E4
	movs r0, #0
	str r0, [r1]
	pop {r1}
	bx r1
	.align 2, 0
_0804E93C: .4byte 0x030000E4

	thumb_func_start Entity0804e9ac_Init
Entity0804e9ac_Init: @ 0x0804E940
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, _0804E994 @ =0x030000E4
	str r5, [r0]
	ldr r0, _0804E998 @ =0x0000CB05
	ldr r1, _0804E99C @ =0x0000DCC1
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	beq _0804E9A0
	adds r1, r5, #0
	adds r1, #0x24
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	adds r4, r5, #0
	adds r4, #0x24
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenSpriteSetFile
	adds r0, r5, #0
	adds r0, #0x44
	movs r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	str r2, [sp, #0xc]
	adds r1, r4, #0
	movs r2, #0x3f
	movs r3, #0x11
	bl FUN_0822f3fc
	movs r0, #0
	b _0804E9A4
	.align 2, 0
_0804E994: .4byte 0x030000E4
_0804E998: .4byte 0x0000CB05
_0804E99C: .4byte 0x0000DCC1
_0804E9A0:
	movs r0, #1
	rsbs r0, r0, #0
_0804E9A4:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start Entity0804e9ac_Create
Entity0804e9ac_Create: @ 0x0804E9AC
	push {r4, lr}
	bl FUN_0804e7b4
	adds r4, r0, #0
	cmp r4, #0
	bne _0804E9EE
	movs r0, #0xb
	movs r1, #0xa4
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0804E9EC
	ldr r1, _0804E9E4 @ =Entity0804e9ac_Update
	ldr r2, _0804E9E8 @ =Entity0804e9ac_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity0804e9ac_Init
	cmp r0, #0
	bge _0804E9EC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0804E9EE
	.align 2, 0
_0804E9E4: .4byte Entity0804e9ac_Update
_0804E9E8: .4byte Entity0804e9ac_Destroy
_0804E9EC:
	adds r0, r4, #0
_0804E9EE:
	pop {r4}
	pop {r1}
	bx r1
