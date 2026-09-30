	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08051dfc
FUN_08051dfc: @ 0x08051DFC
	push {r4, lr}
	adds r3, r0, #0
	ldrb r0, [r3, #0x1d]
	cmp r0, #0
	beq _08051E20
	movs r0, #0
	strb r0, [r3, #0x1d]
	adds r1, r3, #0
	adds r1, #0x40
	movs r4, #1
	movs r2, #3
_08051E12:
	ldr r0, [r1, #8]
	orrs r0, r4
	str r0, [r1, #8]
	subs r2, #1
	adds r1, #0x60
	cmp r2, #0
	bge _08051E12
_08051E20:
	ldrb r0, [r3, #0x1e]
	cmp r0, #0
	beq _08051E2A
	movs r0, #0
	strb r0, [r3, #0x1e]
_08051E2A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08051e30
FUN_08051e30: @ 0x08051E30
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0x1d]
	cmp r0, #0
	beq _08051E5A
	movs r0, #0
	strb r0, [r5, #0x1d]
	adds r4, r5, #0
	adds r4, #0x40
	adds r1, r5, #0
	adds r1, #0x20
	adds r0, r4, #0
	movs r2, #0x45
	movs r3, #0
	bl MainSprite_SetPose
	ldr r0, [r4, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
_08051E5A:
	ldrb r0, [r5, #0x1e]
	cmp r0, #0
	beq _08051E6E
	movs r1, #0
	strb r1, [r5, #0x1e]
	strb r1, [r5, #0x1c]
	movs r0, #1
	strb r0, [r5, #0x1d]
	str r1, [r5, #0x18]
	b _08051E74
_08051E6E:
	ldr r0, [r5, #0x18]
	adds r0, #1
	str r0, [r5, #0x18]
_08051E74:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08051e7c
FUN_08051e7c: @ 0x08051E7C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0x1d]
	cmp r0, #0
	beq _08051EA6
	movs r0, #0
	strb r0, [r5, #0x1d]
	adds r4, r5, #0
	adds r4, #0x40
	adds r1, r5, #0
	adds r1, #0x20
	adds r0, r4, #0
	movs r2, #0x44
	movs r3, #0
	bl MainSprite_SetPose
	ldr r0, [r4, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
_08051EA6:
	ldr r1, [r5, #0x18]
	movs r0, #0x7f
	ands r1, r0
	cmp r1, #0x3f
	bne _08051EC4
	adds r4, r5, #0
	adds r4, #0x40
	adds r1, r5, #0
	adds r1, #0x20
	adds r0, r4, #0
	movs r2, #0x43
	movs r3, #0
	bl MainSprite_SetPose
	b _08051EDA
_08051EC4:
	cmp r1, #0x7f
	bne _08051EDA
	adds r4, r5, #0
	adds r4, #0x40
	adds r1, r5, #0
	adds r1, #0x20
	adds r0, r4, #0
	movs r2, #0x44
	movs r3, #0
	bl MainSprite_SetPose
_08051EDA:
	ldrb r0, [r5, #0x1e]
	cmp r0, #0
	beq _08051EEE
	movs r1, #0
	strb r1, [r5, #0x1e]
	strb r1, [r5, #0x1c]
	movs r0, #1
	strb r0, [r5, #0x1d]
	str r1, [r5, #0x18]
	b _08051EF4
_08051EEE:
	ldr r0, [r5, #0x18]
	adds r0, #1
	str r0, [r5, #0x18]
_08051EF4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08051efc
FUN_08051efc: @ 0x08051EFC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldrb r0, [r7, #0x1d]
	cmp r0, #0
	beq _08051FBC
	movs r0, #0
	strb r0, [r7, #0x1d]
	bl FUN_08050de8
	adds r5, r0, #0
	cmp r5, #1
	bne _08051F1E
	ldr r0, _08051FB0 @ =0x000002C2
	bl PlaySound_082406e0
_08051F1E:
	adds r6, r7, #0
	adds r6, #0x40
	adds r4, r7, #0
	adds r4, #0x20
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0x26
	movs r3, #0
	bl MainSprite_SetPose
	ldr r0, [r6, #8]
	movs r1, #2
	rsbs r1, r1, #0
	mov r8, r1
	ands r0, r1
	str r0, [r6, #8]
	adds r6, #0x60
	adds r0, r5, #0
	movs r1, #0xa
	bl Div
	adds r2, r0, #0
	adds r2, #0x27
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	adds r1, r4, #0
	movs r3, #0
	bl MainSprite_SetPose
	ldr r0, [r6, #8]
	mov r1, r8
	ands r0, r1
	str r0, [r6, #8]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r6, r7, r0
	adds r0, r5, #0
	movs r1, #0xa
	bl Mod
	adds r2, r0, #0
	adds r2, #0x27
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	adds r1, r4, #0
	movs r3, #0
	bl MainSprite_SetPose
	ldr r0, [r6, #8]
	mov r1, r8
	ands r0, r1
	str r0, [r6, #8]
	movs r0, #0x10
	strh r0, [r6, #0x20]
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r6, r7, r0
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0x4b
	movs r3, #0
	bl MainSprite_SetPose
	bl FUN_08050dfc
	cmp r0, #0
	beq _08051FB4
	ldr r0, [r6, #8]
	mov r1, r8
	ands r0, r1
	b _08051FBA
	.align 2, 0
_08051FB0: .4byte 0x000002C2
_08051FB4:
	ldr r0, [r6, #8]
	movs r1, #1
	orrs r0, r1
_08051FBA:
	str r0, [r6, #8]
_08051FBC:
	ldr r0, [r7, #0x18]
	cmp r0, #0x5a
	bne _08052006
	adds r6, r7, #0
	adds r6, #0x40
	adds r1, r7, #0
	adds r1, #0x20
	adds r0, r6, #0
	movs r2, #0x24
	movs r3, #0
	bl MainSprite_SetPose
	ldr r0, [r6, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #8]
	adds r6, #0x60
	ldr r0, [r6, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r6, #8]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r6, r7, r0
	ldr r0, [r6, #8]
	orrs r0, r1
	str r0, [r6, #8]
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r6, r7, r0
	ldr r0, [r6, #8]
	orrs r0, r1
	str r0, [r6, #8]
	ldr r0, _08052064 @ =0x000002C3
	bl PlaySound_082406e0
_08052006:
	ldr r0, [r7, #0x18]
	subs r0, #0x5a
	cmp r0, #7
	bhi _08052040
	adds r6, r7, #0
	adds r6, #0x40
	ldr r5, _08052068 @ =0x0203B400
	ldr r2, _0805206C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r4, _08052070 @ =0x000003FF
	ands r0, r4
	str r0, [r2]
	lsls r1, r0, #1
	adds r1, r1, r5
	ldrh r1, [r1]
	movs r3, #3
	ands r1, r3
	subs r1, #2
	strh r1, [r6, #0x20]
	adds r0, #1
	ands r0, r4
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r3
	subs r0, #2
	strh r0, [r6, #0x22]
_08052040:
	ldr r0, [r7, #0x18]
	cmp r0, #0x62
	bne _08052050
	adds r6, r7, #0
	adds r6, #0x40
	movs r0, #0
	strh r0, [r6, #0x20]
	strh r0, [r6, #0x22]
_08052050:
	ldrb r0, [r7, #0x1e]
	cmp r0, #0
	beq _08052074
	movs r1, #0
	strb r1, [r7, #0x1e]
	strb r1, [r7, #0x1c]
	movs r0, #1
	strb r0, [r7, #0x1d]
	str r1, [r7, #0x18]
	b _0805207A
	.align 2, 0
_08052064: .4byte 0x000002C3
_08052068: .4byte 0x0203B400
_0805206C: .4byte 0x030046B8
_08052070: .4byte 0x000003FF
_08052074:
	ldr r0, [r7, #0x18]
	adds r0, #1
	str r0, [r7, #0x18]
_0805207A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08052084
FUN_08052084: @ 0x08052084
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0x1d]
	cmp r0, #0
	beq _080520B4
	movs r0, #0
	strb r0, [r6, #0x1d]
	adds r7, r6, #0
	adds r7, #0x40
	adds r1, r6, #0
	adds r1, #0x20
	adds r0, r7, #0
	movs r2, #0x24
	movs r3, #0
	bl MainSprite_SetPose
	ldr r0, [r7, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7, #8]
	ldr r0, _08052110 @ =0x000002C3
	bl PlaySound_082406e0
_080520B4:
	ldr r0, [r6, #0x18]
	cmp r0, #7
	bhi _080520EC
	adds r7, r6, #0
	adds r7, #0x40
	ldr r5, _08052114 @ =0x0203B400
	ldr r2, _08052118 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r4, _0805211C @ =0x000003FF
	ands r0, r4
	str r0, [r2]
	lsls r1, r0, #1
	adds r1, r1, r5
	ldrh r1, [r1]
	movs r3, #3
	ands r1, r3
	subs r1, #2
	strh r1, [r7, #0x20]
	adds r0, #1
	ands r0, r4
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r3
	subs r0, #2
	strh r0, [r7, #0x22]
_080520EC:
	ldr r0, [r6, #0x18]
	cmp r0, #8
	bne _080520FC
	adds r7, r6, #0
	adds r7, #0x40
	movs r0, #0
	strh r0, [r7, #0x20]
	strh r0, [r7, #0x22]
_080520FC:
	ldrb r0, [r6, #0x1e]
	cmp r0, #0
	beq _08052120
	movs r1, #0
	strb r1, [r6, #0x1e]
	strb r1, [r6, #0x1c]
	movs r0, #1
	strb r0, [r6, #0x1d]
	str r1, [r6, #0x18]
	b _08052126
	.align 2, 0
_08052110: .4byte 0x000002C3
_08052114: .4byte 0x0203B400
_08052118: .4byte 0x030046B8
_0805211C: .4byte 0x000003FF
_08052120:
	ldr r0, [r6, #0x18]
	adds r0, #1
	str r0, [r6, #0x18]
_08052126:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805212c
FUN_0805212c: @ 0x0805212C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0x1d]
	cmp r0, #0
	beq _0805215E
	movs r0, #0
	strb r0, [r5, #0x1d]
	adds r4, r5, #0
	adds r4, #0x40
	adds r1, r5, #0
	adds r1, #0x20
	adds r0, r4, #0
	movs r2, #0x25
	movs r3, #0
	bl MainSprite_SetPose
	ldr r0, [r4, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
	movs r0, #0xa5
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0805215E:
	ldrb r0, [r5, #0x1e]
	cmp r0, #0
	beq _08052172
	movs r1, #0
	strb r1, [r5, #0x1e]
	strb r1, [r5, #0x1c]
	movs r0, #1
	strb r0, [r5, #0x1d]
	str r1, [r5, #0x18]
	b _08052178
_08052172:
	ldr r0, [r5, #0x18]
	adds r0, #1
	str r0, [r5, #0x18]
_08052178:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Entity08052250_Update
Entity08052250_Update: @ 0x08052180
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0804e59c
	cmp r0, #0
	bne _0805219C
	ldr r0, _080521A4 @ =0x085AB70C
	ldrb r1, [r4, #0x1c]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
_0805219C:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080521A4: .4byte 0x085AB70C

	thumb_func_start Entity08052250_Destroy
Entity08052250_Destroy: @ 0x080521A8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x40
	movs r5, #3
_080521B0:
	adds r0, r4, #0
	bl MainSprite_Remove
	subs r5, #1
	adds r4, #0x60
	cmp r5, #0
	bge _080521B0
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity08052250_Init
Entity08052250_Init: @ 0x080521C8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r6, r0, #0
	ldr r0, _080521E8 @ =0x0000CB05
	ldr r1, _080521EC @ =0x0000DCC1
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	bne _080521F0
	movs r0, #1
	rsbs r0, r0, #0
	b _08052244
	.align 2, 0
_080521E8: .4byte 0x0000CB05
_080521EC: .4byte 0x0000DCC1
_080521F0:
	adds r0, r6, #0
	adds r0, #0x20
	adds r1, r2, #0
	ldm r1!, {r3, r4, r5}
	stm r0!, {r3, r4, r5}
	ldm r1!, {r3, r4, r5}
	stm r0!, {r3, r4, r5}
	ldm r1!, {r3, r4}
	stm r0!, {r3, r4}
	adds r4, r6, #0
	adds r4, #0x20
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenMainSpriteFile
	adds r5, r6, #0
	adds r5, #0x40
	mov r8, r4
	movs r7, #0
	movs r4, #3
_08052218:
	str r7, [sp]
	str r7, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r7, [sp, #0xc]
	adds r0, r5, #0
	mov r1, r8
	movs r2, #0x43
	movs r3, #0x11
	bl MainSprite_Add
	subs r4, #1
	adds r5, #0x60
	cmp r4, #0
	bge _08052218
	movs r1, #0
	strb r1, [r6, #0x1c]
	movs r0, #1
	strb r0, [r6, #0x1d]
	str r1, [r6, #0x18]
	strb r1, [r6, #0x1e]
	movs r0, #0
_08052244:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity08052250_Create
Entity08052250_Create: @ 0x08052250
	push {r4, lr}
	movs r1, #0xe0
	lsls r1, r1, #1
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08052288
	ldr r1, _08052280 @ =Entity08052250_Update
	ldr r2, _08052284 @ =Entity08052250_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity08052250_Init
	cmp r0, #0
	bge _08052288
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0805228A
	.align 2, 0
_08052280: .4byte Entity08052250_Update
_08052284: .4byte Entity08052250_Destroy
_08052288:
	adds r0, r4, #0
_0805228A:
	pop {r4}
	pop {r1}
	bx r1

