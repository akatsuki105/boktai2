	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0805ff04
FUN_0805ff04: @ 0x0805FF04
	push {r4, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	adds r4, #0x10
	movs r2, #0
	strb r2, [r1]
	movs r0, #1
	strb r0, [r1, #1]
	movs r0, #0
	strh r2, [r1, #2]
	strb r0, [r1, #8]
	strh r2, [r1, #4]
	strh r2, [r1, #6]
	strb r0, [r1, #9]
	adds r3, #0x28
	adds r0, r4, #0
	adds r1, r3, #0
	bl FUN_0822a4b0
	movs r0, #0x36
	strh r0, [r4, #0x10]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805ff34
FUN_0805ff34: @ 0x0805FF34
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r0, r1, #0
	adds r4, r2, #0
	adds r0, #0x10
	bl FUN_0822a4e0
	movs r1, #1
	lsls r1, r4
	ldr r0, [r5, #0x1c]
	bics r0, r1
	str r0, [r5, #0x1c]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805ff54
FUN_0805ff54: @ 0x0805FF54
	bx lr
	.align 2, 0

	thumb_func_start FUN_0805ff58
FUN_0805ff58: @ 0x0805FF58
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r7, r0, #0
	adds r6, r1, #0
	mov r8, r2
	movs r0, #0x10
	adds r0, r0, r6
	mov ip, r0
	ldrb r0, [r6, #1]
	cmp r0, #0
	beq _0805FFA8
	movs r4, #0
	strb r4, [r6, #1]
	ldr r5, _0805FFD8 @ =0x0203B400
	ldr r1, _0805FFDC @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ldr r3, _0805FFE0 @ =0x000003FF
	ands r0, r3
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	subs r0, #2
	strb r0, [r6, #9]
	strb r4, [r6, #0xb]
	ldr r0, [r1]
	adds r0, #1
	ands r0, r3
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r2
	adds r0, #7
	strb r0, [r6, #0xc]
_0805FFA8:
	ldrb r0, [r6, #9]
	ldrb r1, [r6, #8]
	adds r0, r0, r1
	strb r0, [r6, #8]
	mov r4, sp
	movs r3, #8
	ldrsb r3, [r6, r3]
	movs r0, #4
	ldrsh r5, [r6, r0]
	ldr r2, _0805FFE4 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0805FFE8
	asrs r1, r0, #0xc
	b _0805FFEE
	.align 2, 0
_0805FFD8: .4byte 0x0203B400
_0805FFDC: .4byte 0x030046B8
_0805FFE0: .4byte 0x000003FF
_0805FFE4: .4byte 0x085B0A08
_0805FFE8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805FFEE:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0806000A
	asrs r0, r0, #0xc
	b _08060010
_0806000A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08060010:
	strh r0, [r4, #4]
	ldrh r2, [r6, #6]
	mov r3, sp
	strh r2, [r3, #2]
	mov r1, sp
	mov r4, ip
	ldrh r0, [r4, #0x1c]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r4, #0x1c]
	mov r1, ip
	adds r1, #0x1c
	ldrh r0, [r4, #0x1e]
	adds r2, r2, r0
	strh r2, [r1, #2]
	ldrh r0, [r1, #4]
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r1, #4]
	ldrb r0, [r6, #0xb]
	adds r0, #1
	strb r0, [r6, #0xb]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r6, #0xc]
	cmp r0, r1
	blo _080600BA
	ldrb r3, [r6, #0xa]
	ldr r2, _08060064 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08060068 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r4, _0806006C @ =0x0203B400
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #0x7f
	bgt _08060070
	adds r1, r3, #1
	b _08060072
	.align 2, 0
_08060064: .4byte 0x030046B8
_08060068: .4byte 0x000003FF
_0806006C: .4byte 0x0203B400
_08060070:
	adds r1, r3, #2
_08060072:
	movs r0, #3
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080600A4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080600A8 @ =0x0203B400
	adds r0, r0, r1
	movs r1, #0
	ldrb r0, [r0]
	cmp r0, #0x7f
	ble _08060092
	movs r1, #1
_08060092:
	ldrb r0, [r6, #0xa]
	adds r0, #0x36
	strh r0, [r6, #0x20]
	cmp r1, #0
	beq _080600AC
	ldr r0, [r6, #0x10]
	movs r1, #4
	orrs r0, r1
	b _080600B4
	.align 2, 0
_080600A4: .4byte 0x000003FF
_080600A8: .4byte 0x0203B400
_080600AC:
	ldr r0, [r6, #0x10]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080600B4:
	str r0, [r6, #0x10]
	movs r0, #0
	strb r0, [r6, #0xb]
_080600BA:
	ldrh r0, [r6, #2]
	ldrh r4, [r6, #0xe]
	cmp r0, r4
	blo _080600D6
	adds r0, r7, #0
	adds r1, r6, #0
	mov r2, r8
	bl FUN_0805ff34
	movs r1, #0
	strb r1, [r6]
	movs r0, #1
	strb r0, [r6, #1]
	strh r1, [r6, #2]
_080600D6:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080600e4
FUN_080600e4: @ 0x080600E4
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x44
	movs r5, #0
	ldr r7, _08060124 @ =0x085ABAA4
_080600F0:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6, #0x1c]
	ands r0, r1
	cmp r0, #0
	beq _08060114
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r3, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl _call_via_r3
	ldrh r0, [r4, #2]
	adds r0, #1
	strh r0, [r4, #2]
_08060114:
	adds r5, #1
	adds r4, #0x3c
	cmp r5, #0x1f
	ble _080600F0
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08060124: .4byte 0x085ABAA4

	thumb_func_start FUN_08060128
FUN_08060128: @ 0x08060128
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x44
	movs r4, #0
_08060132:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r6, #0x1c]
	ands r0, r1
	cmp r0, #0
	beq _08060148
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0805ff34
_08060148:
	adds r4, #1
	adds r5, #0x3c
	cmp r4, #0x1f
	ble _08060132
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_08060158
FUN_08060158: @ 0x08060158
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r1, #0
	adds r5, r2, #0
	movs r0, #0
	str r0, [r6, #0x1c]
	adds r4, r6, #0
	adds r4, #0x28
	ldr r1, _080601A0 @ =0x000061F9
	adds r0, r4, #0
	bl Video_GetActorSprite
	ldr r1, _080601A4 @ =0x000002F6
	adds r0, r4, #0
	bl FUN_0822b20c
	cmp r5, #0
	beq _08060180
	strh r7, [r6, #0x2e]
	str r5, [r6, #0x34]
_08060180:
	adds r5, r6, #0
	adds r5, #0x44
	movs r4, #0
_08060186:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0805ff04
	adds r4, #1
	adds r5, #0x3c
	cmp r4, #0x1f
	ble _08060186
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080601A0: .4byte 0x000061F9
_080601A4: .4byte 0x000002F6

	thumb_func_start FUN_080601a8
FUN_080601a8: @ 0x080601A8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r1, _080601DC @ =0x000007C4
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080601E8
	ldr r1, _080601E0 @ =FUN_080600e4
	ldr r2, _080601E4 @ =FUN_08060128
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_08060158
	cmp r0, #0
	bge _080601E8
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080601EA
	.align 2, 0
_080601DC: .4byte 0x000007C4
_080601E0: .4byte FUN_080600e4
_080601E4: .4byte FUN_08060128
_080601E8:
	adds r0, r4, #0
_080601EA:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

